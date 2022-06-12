#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	char id[128] = "";
	char nombre[128]= "";
	char apellido[128]= "";
	char precio[128]= "";
	char tipoPasajero[128]= "";
	char codigoVuelo[128]= "";
	char estadoVuelo[128]= "";
	int cantidad = 0;
	Passenger* auxiliar = NULL;

	if(pFile!=NULL && pArrayListPassenger!=NULL)
	{
		cantidad = fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^,] , %[^,] , %[^,] , %[^\n]\n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);
		do
		{
			cantidad = fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^,] , %[^,] , %[^,] , %[^\n]\n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);

			if((cantidad == 7))
			{
				auxiliar = Passenger_newParametros(id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);

				if(auxiliar!=NULL)
				{
					ll_add(pArrayListPassenger, auxiliar);
					retorno=0;
				}else
				{
					Passenger_delete(auxiliar);
				}
			}
		}
		while(!feof(pFile));
	}

	return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	Passenger* auxiliar = NULL;

	if(pFile!=NULL && pArrayListPassenger!=NULL)
	{
		do
		{
			auxiliar = Passenger_new();

			if(auxiliar!=NULL)
			{
				if(fread(auxiliar,sizeof(Passenger),1,pFile))
				{
					ll_add(pArrayListPassenger,auxiliar);
					retorno=0;
				}else
				{
					Passenger_delete(auxiliar);
				}
			}
		}while(!feof(pFile));
	}

    return retorno;
}

int parser_IdFromText(FILE* pFile , LinkedList* pArrayListPassenger, int* id)
{
	int retorno = -1;
	char idTxt[128];
	int idInt;
	int cantidad = 0;

	if(pFile!=NULL && pArrayListPassenger!=NULL)
	{
		cantidad = fscanf(pFile,"%[^\n]\n",idTxt);
		do
		{
			cantidad = fscanf(pFile,"%[^\n]\n",idTxt);

			if(cantidad==1)
			{
				idInt = atoi(idTxt);

				if(idInt>*id)
				{
					*id=idInt;
					retorno = 0;
				}
			}
		}
		while(!feof(pFile));
	}

    return retorno;
}
