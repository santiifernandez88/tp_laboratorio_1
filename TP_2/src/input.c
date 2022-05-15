#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "input.h"

void getString(char cadena[],char mensaje[])
{
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%[^\n]s",cadena);
}

int PedirEntero (char mensaje[])
{
    int entero;
    printf("%s",mensaje);
    scanf("%d",&entero);
    return entero;
}

float PedirFlotante (char mensaje[])
{
    float flotante;
    printf("%s",mensaje);
    scanf("%f",&flotante);
    return flotante;
}
