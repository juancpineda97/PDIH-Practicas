#include "p1.c"
#include <stdlib.h>
#define BYTE unsigned char
int main(){
    int i, j, r;
    int numero_pixeles_fila = 0;
    srand(time(NULL));

    setvideomode(0x04);

    for(j = 50; j < 150; j++){
        r = (rand() % 3)+1;
        for(i = 160-numero_pixeles_fila; i < 161 + numero_pixeles_fila; i++){
            pixel(i,j,r);
        }
        numero_pixeles_fila++;
    }

    getche(0); //Al pulsar una tecla se sale del modo grafico
    setvideomode(0X03);
	clrsrc();

	return 0;
}