#include <ncurses.h>
#include <unistd.h>

#define RETARDO 175000

void instrucciones(WINDOW *window){
	mvwprintw(window, 5, 5, "Bienvenido al juego Pong");
	mvwprintw(window, 7, 7, "JUGADOR 1 - Controles con Q y A");
	mvwprintw(window, 9, 7, "JUGADOR 2 - Controles con O y L");
	mvwprintw(window, 11, 5, "Pulse cualquier tecla para empezar");
	mvwprintw(window, 13, 5, "¡Gana el primero que llegue a 7 puntos!");
	wrefresh(window);
	getch();
}

void dibujaPalas(int ancho, int fila_j1, int fila_j2){
	mvprintw(fila_j1, 0, "|");
	mvprintw(fila_j1+1, 0, "|");
	mvprintw(fila_j1+2, 0, "|");
	mvprintw(fila_j1+3, 0, "|");
	mvprintw(fila_j1+4, 0, "|");

	mvprintw(fila_j2, ancho-1, "|");
	mvprintw(fila_j2+1, ancho-1, "|");
	mvprintw(fila_j2+2, ancho-1, "|");
	mvprintw(fila_j2+3, ancho-1, "|");
	mvprintw(fila_j2+4, ancho-1, "|");
}

void dibujaLinea(int ancho, int alto){
	int i=0;
	for (i; i < alto; i++){
		mvprintw(i, ancho/2, "|");
	}
}

void dibujaPuntuaciones(int p1, int p2, int ancho){
	mvprintw(1, ancho/2 - 2, "%i", p1);
	mvprintw(1, ancho/2 + 2, "%i", p2);
}

int main(int argc, char *argv[]){
	int filas, columnas;
	int puntuacion1 = 0, puntuacion2 = 0;
	int fila_j1 = 3;
	int fila_j2 = 3;
	bool parar = false;
	int bola_x = 20;
	int bola_y = 20;
	int direccion_bola = 4;
	int siguiente_direccion = 1;
	bool punto = false;
	int jugador_punto = 1;
	
	//Iniciar y borrar pantalla
	initscr();
	noecho();
	curs_set(FALSE);
	clear();
	refresh();

	//Crear nueva ventana
	getmaxyx(stdscr, filas, columnas);
	WINDOW *window = newwin(filas,columnas,0,0);
	box(window, '*', '-');

	//Mostrar instrucciones
	instrucciones(window);
	
	nodelay(stdscr,1); 
	clear();
	
	bola_x = columnas/2;
	direccion_bola = 3;

	while(!parar){
		if(puntuacion1 > 6 || puntuacion2 > 6){
			parar = true;
		}

		clear();

		dibujaPalas(columnas, fila_j1, fila_j2);

		dibujaLinea(columnas, filas);

		dibujaPuntuaciones(puntuacion1, puntuacion2, columnas);


		//Determinar siguiente direccion
		switch (direccion_bola)
		{
		case 1:
			if(bola_x == columnas-1 && bola_y == 0){//Esquina superior derecha
				if(bola_y < fila_j2 || bola_y > fila_j2+4){
					punto = true;
					puntuacion1++;
					jugador_punto = 1;
				}
				siguiente_direccion = 3;
			}
			else if(bola_y == 0){
				siguiente_direccion = 2;
			}
			else if(bola_x == columnas-1){//Llega al fondo
				if(bola_y < fila_j2 || bola_y > fila_j2+4){
					punto = true;
					puntuacion1++;
					jugador_punto = 1;
				}
				siguiente_direccion = 4;
			}
			else{//No ha rebotado
				siguiente_direccion = 1;
			}
			break;
		case 2:
			if(bola_x == columnas-1 && bola_y == filas-1){
				if(bola_y < fila_j2 || bola_y > fila_j2+4){
					punto = true;
					puntuacion1++;
					jugador_punto = 1;
				}
				siguiente_direccion = 4;
			}
			else if(bola_y == filas-1){
				siguiente_direccion = 1;
			}
			else if(bola_x == columnas-1){
				if(bola_y < fila_j2 || bola_y > fila_j2+4){
					punto = true;
					puntuacion1++;
					jugador_punto = 1;
				}
				siguiente_direccion = 3;
			}
			else{
				siguiente_direccion = 2;
			}
			break;
		case 3:
			if(bola_x == 0 && bola_y == filas-1){
				if(bola_y < fila_j1 || bola_y > fila_j1+4){
					punto = true;
					puntuacion2++;
					jugador_punto = 2;
				}
				siguiente_direccion = 1;
			}
			else if(bola_y == filas-1){
				siguiente_direccion = 4;
			}
			else if(bola_x == 0){
				if(bola_y < fila_j1 || bola_y > fila_j1+4){
					punto = true;
					puntuacion2++;
					jugador_punto = 2;
				}
				siguiente_direccion = 2;
			}
			else{
				siguiente_direccion = 3;
			}
			break;
		case 4:
			if(bola_x == 0 && bola_y == 0){
				if(bola_y < fila_j1 || bola_y > fila_j1+4){
					punto = true;
					puntuacion2++;
					jugador_punto = 2;
				}
				siguiente_direccion = 2;
			}
			else if(bola_y == 0){
				siguiente_direccion = 3;
			}
			else if(bola_x == 0){
				if(bola_y < fila_j1 || bola_y > fila_j1+4){
					punto = true;
					puntuacion2++;
					jugador_punto = 2;
				}
				siguiente_direccion = 1;
			}
			else{
				siguiente_direccion = 4;
			}
			break;
		}

		//Si es punto se inicia el juego
		if(punto){
			bola_x = columnas/2;
			bola_y = 0;
			if(jugador_punto == 1){
				direccion_bola = 3;
			}
			else{
				direccion_bola = 2;
			}
			punto=false;
		}
		else{
			//Calcular nuevas coordenadas
			switch (siguiente_direccion)
			{
			case 1:
				bola_x++;
				bola_y--;
				break;
			case 2:
				bola_x++;
				bola_y++;
				break;
			case 3:
				bola_x--;
				bola_y++;
				break;
			case 4:
				bola_x--;
				bola_y--;
				break;
			}

			direccion_bola = siguiente_direccion;
		}

		//Mover las palas con las pulsaciones
		switch (getch()){
			case 'q':          
				if(fila_j1 > 0){
					fila_j1--;
				}
				break;
				
			case 'a':		
				if(fila_j1+4 < filas-1){
					fila_j1++;
				}
				break;

			case 'o':          
				if(fila_j2 > 0){
					fila_j2--;
				}
				break;
				
			case 'l':		
				if(fila_j2+4 < filas-1){
					fila_j2++;
				}
				break;
		}


		mvprintw(bola_y, bola_x, "o");

		refresh();

		usleep(RETARDO);

	}

	endwin();
	return 0;
	
}
