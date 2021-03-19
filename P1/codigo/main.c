#include "p1.c"
#define BYTE unsigned char
int main(){

	textcolor(0x04);
	textbackground(0x02);
	printf("Pulsa una tecla... ");
	getche(1);
	printf("\nPulse una tecla para borrar pantalla...");
	getche(0);
	clrsrc();
	return 0;
}
