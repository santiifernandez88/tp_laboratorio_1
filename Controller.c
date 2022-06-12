#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "Menus.h"
#include "Utn.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	FILE* pArchivo;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		pArchivo = fopen(path,"r");

		if(pArchivo!=NULL)
		{
			if(!parser_PassengerFromText(pArchivo, pArrayListPassenger))
			{
				printf("Se cargo con exito\n");
				retorno = 0;
			}
		}else
		{
			printf("Error al abrir el archivo\n");
		}
		fclose(pArchivo);
	}
	return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	FILE* pArchivo;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		pArchivo = fopen(path,"rb");

		if(pArchivo!= NULL)
		{
			if(!parser_PassengerFromBinary(pArchivo, pArrayListPassenger))
			{
				printf("Se cargo con exito\n");
				retorno=0;
			}
			fclose(pArchivo);
		}else
		{
			printf("Error al abrir el archivo\n");
		}
	}

    return retorno;
}

/** \brief Carga los IDs de los pasajeros desde el archivo ids.cvs (modo texto)
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \param id int*
 * \return int
 *
 */
int controller_loadFromTextID(char* path , LinkedList* pArrayListPassenger, int* id)
{
	int retorno = -1;
	FILE* pArchivo;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		pArchivo = fopen(path,"r");

		if(pArchivo!= NULL)
		{
			if(!parser_IdFromText(pArchivo,pArrayListPassenger,id))
			{
				retorno = 0;
			}
		}
		fclose(pArchivo);
	}

    return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger, int* id)
{
	int retorno = -1;
	int auxID;
	int opcion;
	int i=0;

	if(pArrayListPassenger!=NULL)
	{
		controller_loadFromTextID("ids.csv", pArrayListPassenger, id);
		auxID=*id;
		printf("ALTA DE PASAJEROS\n");
		utn_getInt("\n¿Cuantos pasajeros desea dar de alta?: ","\nError, reingrese: ",1,10,3,&opcion);
		do
		{
			if(!Passenger_add(pArrayListPassenger, &auxID))
			{
				*id = auxID;
				retorno = 0;
			}
			i++;
		}while(opcion!=i);

		if(!retorno)
		{
			printf("Se ha dado de alta correctamente");
		}else
		{
			printf("No se ha dado de alta un nuevo pasajero");
		}
	}
    return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;

	if(pArrayListPassenger!=NULL)
	{
		printf("MODIFICACION DE PASAJEROS\n");
		if(!Passenger_modify(pArrayListPassenger))
		{
			printf("Se ha modificado con exito");
		}
		else
		{
			printf("No se han podido actualizar los datos");
		}
	}
	return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int opcion;
	int i=0;

	if(pArrayListPassenger!=NULL)
	{
		printf("BAJA DE PASAJEROS\n");
		utn_getInt("\n¿Cuantos pasajeros desea dar de baja?: ","\nError, reingrese: ",1,10,3,&opcion);

		do
		{
			if(!Passenger_remove(pArrayListPassenger))
			{
				retorno=0;
			}
			i++;
		}while(opcion!=i);
	}

    return retorno;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;

	if(pArrayListPassenger!=NULL)
	{
		printf("LISTA DE PASAJEROS\n");
		if(Passenger_printList(pArrayListPassenger)!=0)
		{
			printf("No hay pasajeros para mostrar");
			retorno=0;
		}
	}

	return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{

	int retorno = -1;
	LinkedList* clon;
	if(pArrayListPassenger!=NULL)
	{
		clon = ll_clone(pArrayListPassenger);

		if(clon!=NULL)
		{
			Passenger_sortPassenger(clon);
		}
	}

	return retorno;

}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int i;
	int len;
	int auxiliarID;
	char auxiliarNombre[128];
	char auxiliarApellido[128];
	int auxiliarPrecio;
	char auxiliarTipoPasajero[128];
	char auxiliarCodigoVuelo[128];
	char auxiliarEstadoVuelo[128];
	FILE* pArchivo;
	Passenger* aux = NULL;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		pArchivo = fopen(path,"w");

		len = ll_len(pArrayListPassenger);

		if(pArchivo!= NULL && len>0)
		{
			fprintf(pArchivo,"id,nombre,apellido,precio,codigo de pasajero,tipo de pasajero,estado de vuelo\n");
			for(i=0; i<len ;i++)
			{
				aux = (Passenger*) ll_get(pArrayListPassenger,i);
				if(aux!=NULL)
				{
					if(!Passenger_getVerify(aux,&auxiliarID,auxiliarNombre,auxiliarApellido,&auxiliarPrecio,auxiliarCodigoVuelo,auxiliarTipoPasajero,auxiliarEstadoVuelo))
					{
						fprintf(pArchivo,"%d,%s,%s,%d,%s,%s,%s\n",auxiliarID,auxiliarNombre,auxiliarApellido,auxiliarPrecio,auxiliarCodigoVuelo,auxiliarTipoPasajero,auxiliarEstadoVuelo);
						retorno=0;
					}else
					{
						Passenger_delete(aux);
						printf("No se pudo guardar el archivo\n");
					}
				}
			}
		}else
		{
			printf("Error al abrir el archivo\n");
		}
		fclose(pArchivo);
	}

	if(!retorno)
	{
		printf("El archivo fue guardado con exito!\n");
	}
	return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int i;
	int len;
	FILE* pArchivo;
	Passenger* aux = NULL;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		len = ll_len(pArrayListPassenger);
		pArchivo = fopen(path,"wb");

		if(pArchivo!= NULL && len>0)
		{
			for(i=0; i<len ;i++)
			{
				aux = (Passenger*) ll_get(pArrayListPassenger,i);

				if(aux!=NULL)
				{
					fwrite(aux,sizeof(Passenger),1,pArchivo);
					retorno = 0;
				}
			}
		}else
		{
			printf("Error al abrir el archivo\n");
		}
		fclose(pArchivo);
		if(!retorno)
		{
			printf("Se guardo con exito\n");
		}
	}

    return retorno;
}

int controller_saveAsTextID(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int idMayor = 0;
	FILE* pArchivo;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		idMayor = Passenger_ObtenerMayorId(pArrayListPassenger);
		pArchivo = fopen(path,"w");

		if(pArchivo!= NULL)
		{
			fprintf(pArchivo,"Ultimo ID:\n");
			fprintf(pArchivo,"%d\n",idMayor);
			retorno = 0;
		}
		fclose(pArchivo);
	}

	return retorno;
}
