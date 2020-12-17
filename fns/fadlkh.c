#include "fadlkh.h"
                
void ver_menu(int numlineas, char *unmenu[])
{
    int i;
    printf("\n");
    for (i = 0; i < numlineas; i++ )
        {
            printf("%s",unmenu[i]);
        }
}

int leerOpcion(){
    int opc=0, asci=48;
    opc= (int) getch() - asci ;
    printf("opc: %d\n",opc);
    return opc;
}
