#include<dos.h>
#include<string.h>
#include<stdio.h>
#define BYTE unsigned char

BYTE letra_c=7; //variable con el color de la letra, inicialmente gris claro
BYTE fondo_c=0; //variable con el color de fondo de letra, inicialmente negro

int numero_filas_texto=25; //en modo de texto el numero de filas es siempre la misma

//-- 1º --
//coloca el cursor en una posición determinada
void gotoxy(int x, int y){
  union REGS inregs, outregs;
  
  //Paso de parámetros a dh y dl
  inregs.h.dh=y;
  inregs.h.dl=x;
  
  //subfunción 2
  inregs.h.ah=0x02;
  inregs.h.bh=0x00;

  int86(0x10, &inregs, &outregs);
}

//-- 2º --
//fijar el aspecto del cursor, debe admitir tres valores: 1:INVISIBLE, 2:NORMAL y 3:GRUESO.
void setcursortype(int tipo){

  union REGS inregs, outregs;
 
  switch (tipo)
	{

    case 1:
				inregs.h.ch=010;
    		inregs.h.cl=000;
        break;
    case 2:
				inregs.h.ch=010;
    		inregs.h.cl=010;
        break;
    case 3:
				inregs.h.ch=000;
    		inregs.h.cl=010;
        break;
    default:
    		printf("Tipo no permitido ");
    		return;
	}

  //subfunción 1
  inregs.h.ah=0x01;

  int86(0x10, &inregs, &outregs);
  return;
}

//-- 3º --
//fija el modo de video deseado
void setvideomode(BYTE mode){
  union REGS inregs, outregs;
  
  //subfunción 0
  inregs.h.ah = 0x00;
  
  //Paso de parametro
  inregs.h.al = mode;
  
  int86(0x10,&inregs,&outregs);
}

//-- 4º --
//obtiene el modo de video actual
int getvideomode(){
  union REGS inregs, outregs;
  int mode;
  
  //subfuncion F 
  inregs.h.ah = 0x0F;
  
  int86(0x10,&inregs,&outregs);
  
  //salida modo
  mode=outregs.h.al;
  
  return mode;
}

//-- 5º --
//modifica el color de primer plano con que se mostrarán los caracteres
void textcolor(int c){
  letra_c=c;
  return;
}

//-- 6º --
//modifica el color de fondo con que se mostrarán los caracteres
void textbackground(int c){
  fondo_c=c;
  return;
}

//-- 7º --
//borra toda la pantalla
void clrsrc(){
  union REGS inregs, outregs;
  
  //subfuncion 6
  inregs.h.ah = 0x06;

  //parametros
  inregs.h.al = 0x00;
  inregs.h.bh = fondo_c;
  inregs.h.ch = 0x00;
  inregs.h.cl = 0x00;
  inregs.h.dh = getfilas()-1;
  inregs.h.dl = getcolumnas()-1;

  int86(0x10,&inregs,&outregs);

  gotoxy(0,getfilas());

  return;
}

//-- 8º --
//escribe un carácter en pantalla con el color indicado actualmente
void cputchar(char caracter){
  union REGS inregs, outregs;

  //Combinar color de texto y fondo en un solo Byte
  BYTE color_fondo_byte;
  BYTE color_final;

  color_fondo_byte = fondo_c;

  color_fondo_byte = color_fondo_byte << 4;

  color_final = color_fondo_byte | letra_c;

  //subfuncion 9
  inregs.h.ah = 0x09;
  
  //parametros
  inregs.h.al = caracter;
  inregs.h.bl = color_final;
  inregs.h.bh = 0x00;
  inregs.x.cx = 1;
  
  int86(0x10, &inregs, &outregs);
}

//-- 9º --
//obtiene un carácter de teclado y lo muestra en pantalla
void getche(int imprimir){
  union REGS inregs, outregs;
  char caracter;

  //subfuncion 1
  inregs.h.ah = 0x01;
  
  int86(0x21, &inregs, &outregs);

  caracter = outregs.h.al;

  if(imprimir == 1){
    printf("\nCaracter pulsado: ");
    cputchar(caracter);
  }
}

//-- OPCIONAL --
//dibuja un recuadro en la pantalla en modo texto
void dibuja(int x1, int y1, int x2, int y2, int c1, int c2){
  union REGS inregs, outregs;
  int i,j;
  BYTE color_fondo_original = fondo_c;

  clrsrc();

  for (i = 0; i < getfilas(); i++){
    for (j = 0; j < getcolumnas(); j++){
      gotoxy(j,i);
      if ((i+1 >= y1) && (i < y2) && (j+1 >= x1) && (j < x2)){
        textbackground(c1);
      }
      else{
        textbackground(c2);
      }
      cputchar(' ');
    }
  }

  textbackground(color_fondo_original);

}

//------- AUXILIARES -------

//obtener numero filas (modo texto)
int getfilas(){
  return numero_filas_texto;
}

//obtener numero columnas (modo texto)
int getcolumnas(){
  union REGS inregs, outregs;
  int n_columnas;

  //subfuncion F
  inregs.h.ah = 0x0F;

  int86(0x10,&inregs,&outregs);

  //salida
  n_columnas = outregs.h.ah;

  return n_columnas;
}

//dibujar pixel en modo grafico
void pixel(int x, int y, BYTE color){
  union REGS inregs, outregs;

  //subfuncion C
  inregs.h.ah = 0x0C;

  //parametros
  inregs.x.cx = x;
  inregs.x.dx = y;
  inregs.h.al = color;

  int86(0x10, &inregs, &outregs);
}