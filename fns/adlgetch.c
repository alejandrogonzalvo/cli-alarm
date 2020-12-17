#include "adlgetch.h"

/* Inicializa un nuevo terminal i/o settings */
void initTermios(int echo)
{
  tcgetattr(0, &old); /* salvar los parametros de la terminal i/o settings */
  new = old; /* poner en new los parametros guardados */
  new.c_lflag &= ~ICANON; /* deshabilitar la opción de buffer i/o */
  if (echo) {
      new.c_lflag |= ECHO; /* poner el modo echo */
  } else {
      new.c_lflag &= ~ECHO; /* quitar el modo echo */
  }
  tcsetattr(0, TCSANOW, &new); /* usar los nuevos i/o settings */
}

/* restaurar los parametros salvados en old */
void resetTermios(void)
{
  tcsetattr(0, TCSANOW, &old);
}

/* Leer un caracter desde teclado, con o sin echo */
char getch_(int echo)
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

/* lee un caracter sin echo */
char getch(void)
{
  return getch_(0);
}

/* lee un caracter con echo */
char getche(void)
{
  return getch_(1);
}

/* para testear funciones */
/*
int main(void) {
  char c;
  printf("(getche ) escribe un caracter (con echo): ");
  c = getche();
  printf(("\nHas pulsado: %c\n", c);
  printf("(getch ) pulsa una letra...");
  c = getch();
  printf("\nHas pulsado: %c\n", c);
  return 0;
}
*/
