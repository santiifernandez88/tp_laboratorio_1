#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "Menus.h"
#include "Utn.h"

#define REALIZADO 1
#define NO_REALIZADO 0

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    char confirmar[4];
	int id = 1000;
    int flagTxt = NO_REALIZADO;
    int flagBin = NO_REALIZADO;
	int flagSaveTxt = NO_REALIZADO;
	int flagSaveBin = NO_REALIZADO;

    LinkedList* listaPasajeros = ll_newLinkedList();
    do{
        switch(Menu())
        {
            case 1:
                if(ll_isEmpty(listaPasajeros) || (flagTxt==NO_REALIZADO && flagBin==NO_REALIZADO))
				{
                	if(!controller_loadFromText("data.csv", listaPasajeros))
					{
						flagTxt=REALIZADO;
					}else
					{
						flagTxt=NO_REALIZADO;
					}
				}else
				{
					printf("No puedes cargar el archivo dos veces");
				}
                system("pause");
            break;
            case 2:
            	if(ll_isEmpty(listaPasajeros) || (flagBin==NO_REALIZADO && flagTxt==NO_REALIZADO))
				{
					if(!controller_loadFromBinary("data.bin",listaPasajeros))
					{
						flagBin=REALIZADO;
					}else
					{
						flagBin=NO_REALIZADO;
					}
				}else
				{
					printf("No puedes cargar el archivo dos veces");
				}
            	system("pause");
            break;
            case 3:
            	controller_addPassenger(listaPasajeros,&id);
			break;
            case 4:
				if(!ll_isEmpty(listaPasajeros))
				{
					controller_editPassenger(listaPasajeros);
				}else
				{
					printf("No hay pasajeros para modificar");
				}
			break;
            case 5:
				if(!ll_isEmpty(listaPasajeros))
				{
					controller_removePassenger(listaPasajeros);
				}else
				{
					printf("No hay pasajeros para dar de baja");
				}
			break;
            case 6:
            	if(!ll_isEmpty(listaPasajeros))
				{
            		controller_ListPassenger(listaPasajeros);
				}else
				{
					printf("No hay pasajeros para mostrar");
				}
            	system("pause");
            break;
            case 7:
				if(!ll_isEmpty(listaPasajeros))
				{
					controller_sortPassenger(listaPasajeros);
				}else
				{
					printf("No hay pasajeros para mostrar");
				}
			break;
            case 8:
				if(!ll_isEmpty(listaPasajeros))
				{
					controller_saveAsText("data.csv",listaPasajeros);
					controller_saveAsTextID("ids.csv",listaPasajeros);
					flagSaveTxt = REALIZADO;
				}else
				{
					printf("No hay pasajeros para guardar");
				}
			break;
            case 9:
				if(!ll_isEmpty(listaPasajeros))
				{
					controller_saveAsBinary("data.bin",listaPasajeros);
					controller_saveAsTextID("ids.csv",listaPasajeros);
					flagSaveBin = REALIZADO;
				}else
				{
					printf("No hay pasajeros para guardar");
				}
			break;
            case 10:
            	if(flagSaveTxt==NO_REALIZADO && flagSaveBin==NO_REALIZADO)
				{
					utn_getString("\n¿Esta seguro que desea salir sin guardar?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,3,confirmar);
					if((stricmp(confirmar,"si")))
					{
						utn_getInt("1. Guardar modo texto\n"
								   "2. Guardar modo binario\n",
								   "Respuesta invalida, ingrese [1/2]\n",1,2,3,&option);
						if(option==1)
						{
							controller_saveAsText("data.csv",listaPasajeros);
							controller_saveAsTextID("ids.csv",listaPasajeros);
							strcpy(confirmar,"si");
						}else
						{
							controller_saveAsBinary("data.bin",listaPasajeros);
							controller_saveAsTextID("ids.csv",listaPasajeros);
							strcpy(confirmar,"si");
						}
					}
				}else
				{
					strcpy(confirmar,"si");
				}
            break;
        }
    }while(stricmp(confirmar,"si"));
    return 0;
}
