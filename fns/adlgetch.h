#include <termios.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

static struct termios old, new;

void initTermios(int echo);// Inicializa un nuevo terminal i/o settings
void resetTermios(void);// restaurar los parametros salvados en old
char getch_(int echo);// Leer un caracter desde teclado, con o sin echo
char getch(void);// Leer un caracter desde teclado sin echo
char getche(void);//Leer un caracter desde teclado con echo
