#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "Utn.h"
#include "Menus.h"

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* codigoVueloStr,char* tipoPasajeroStr,char* estadoVuelo)
{
	Passenger* pPasajeroParam = NULL;

	if(idStr!=NULL && nombreStr!=NULL && apellidoStr!=NULL && precioStr!=NULL && tipoPasajeroStr!=NULL && codigoVueloStr!=NULL && estadoVuelo!=NULL)
	{
		pPasajeroParam = Passenger_new();

		if(pPasajeroParam!=NULL)
		{
			if((Passenger_setVerifyChar(pPasajeroParam,idStr,nombreStr,apellidoStr,precioStr,codigoVueloStr,tipoPasajeroStr,estadoVuelo))!=0)
			{
				Passenger_delete(pPasajeroParam);
			}
		}
	}

	return pPasajeroParam;
}

Passenger* Passenger_new()
{
	Passenger* this = (Passenger*) malloc(sizeof(Passenger)*1);

    if(this != NULL)
    {
        this->id = 0;
        strcpy(this->nombre, "");
        strcpy(this->apellido, "");
        this->precio = 0;
        strcpy(this->codigoVuelo, "");
        strcpy(this->tipoPasajero, "");
        strcpy(this->estadoVuelo, "");
    }
    return this;
}

int Passenger_setVerifyChar(Passenger* this, char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* codigoVueloStr,char* tipoPasajeroStr,char* estadoVuelo)
{
	int retorno = -1;

	if((!(Passenger_setId(this,atoi(idStr))) &&
		!(Passenger_setNombre(this,nombreStr)) &&
		!(Passenger_setApellido(this,apellidoStr)) &&
		!(Passenger_setPrecio(this,atoi(precioStr))) &&
		!(Passenger_setCodigoVuelo(this,codigoVueloStr)) &&
		!(Passenger_setTipoPasajero(this,tipoPasajeroStr))  &&
		!(Passenger_setEstadoVuelo(this,estadoVuelo))))
	{
		retorno = 0;
	}

	return retorno;
}

int Passenger_setVerifyInt(Passenger* this, int idStr,char* nombreStr,char* apellidoStr,int precioStr,char* codigoVueloStr,char* tipoPasajeroStr,char* estadoVuelo)
{
	int retorno = -1;

	if(this!=NULL && idStr>0 && nombreStr!=NULL && apellidoStr!=NULL && precioStr>0 && tipoPasajeroStr!=NULL && codigoVueloStr!=NULL && estadoVuelo!=NULL)
	{
		if((!(Passenger_setId(this,idStr)) &&
			!(Passenger_setNombre(this,nombreStr)) &&
			!(Passenger_setApellido(this,apellidoStr)) &&
			!(Passenger_setPrecio(this,precioStr)) &&
			!(Passenger_setCodigoVuelo(this,codigoVueloStr)) &&
			!(Passenger_setTipoPasajero(this,tipoPasajeroStr)) &&
			!(Passenger_setEstadoVuelo(this,estadoVuelo))))
		{
			retorno = 0;
		}
	}

	return retorno;
}

int Passenger_getVerify(Passenger* this, int* idStr,char* nombreStr,char* apellidoStr,int* precioStr,char* codigoVueloStr,char* tipoPasajeroStr,char* estadoVuelo)
{
	int retorno = -1;

	if(this!=NULL && idStr!=NULL && nombreStr!=NULL && apellidoStr!=NULL && precioStr!=NULL && tipoPasajeroStr!=NULL && codigoVueloStr!=NULL && estadoVuelo!=NULL)
	{
		if((!(Passenger_getId(this,idStr)) &&
			!(Passenger_getNombre(this,nombreStr)) &&
			!(Passenger_getApellido(this,apellidoStr)) &&
			!(Passenger_getPrecio(this,precioStr)) &&
			!(Passenger_getCodigoVuelo(this,codigoVueloStr)) &&
			!(Passenger_getTipoPasajero(this,tipoPasajeroStr)) &&
			!(Passenger_getEstadoVuelo(this,estadoVuelo))))
		{
			retorno = 0;
		}
	}

	return retorno;
}

int Passenger_ObtenerMayorId(LinkedList* listaPasajeros)
{
	int mayorId=0;
	int id;
	int len;
	int i;
	Passenger* aux;

	if(listaPasajeros!=NULL)
	{
		len = ll_len(listaPasajeros);

		if(len>0)
		{
			for(i=0;i<len;i++)
			{
				aux = (Passenger*)ll_get(listaPasajeros,i);
				Passenger_getId(aux,&id);

				if(i==0 || (mayorId<id))
				{
					mayorId=id;
				}
			}
		}
	}

	return mayorId;
}

int Passenger_findID(LinkedList* listaPasajeros, int id)
{
	int i;
	int len;
	int index;
	Passenger* auxiliar;

	if(listaPasajeros!=NULL)
	{
		len = ll_len(listaPasajeros);

		if(len>0)
		{
			for(i=0; i<len ;i++)
			{
				auxiliar = (Passenger*)ll_get(listaPasajeros,i);
				if(auxiliar->id==id)
				{
					index=i;
					break;
				}
			}
		}
	}

	return index;
}

int Passenger_add(LinkedList* listaPasajeros, int* id)
{
	int retorno = -1;
	char respuesta[4];
	int auxiliarID;
	char auxiliarNombre[128];
	char auxiliarApellido[128];
	int auxiliarPrecio;
	char auxiliarTipoPasajero[128];
	char auxiliarCodigoVuelo[128];
	char auxiliarEstadoVuelo[128];
	Passenger* auxPasajero = NULL;

	if(listaPasajeros!=NULL && id!=NULL)
	{
		auxPasajero = Passenger_new();

		if(auxPasajero!=NULL)
		{
			auxiliarID = *id;
			auxiliarID+=1;
			//auxiliarID = Passenger_ObtenerMayorId(listaPasajeros);
			//auxiliarID+=1;
			printf("\nEl nuevo pasajero obtendra la ID: %d\n", auxiliarID);
			if((!(utn_getString("\nIngrese el nombre: ","\nError, reingrese: ",50,3,auxiliarNombre)) &&
				!(utn_getString("\nIngrese el apellido: ","\nError, reingrese: ",50,3,auxiliarApellido)) &&
				!(utn_getInt("\nIngrese precio: ","\nError, reingrese: ",1,1000000,3,&auxiliarPrecio)) &&
				!(pedirCadena("\nIngrese el codigo de vuelo: ","\nError, reingrese: ",10,auxiliarCodigoVuelo)) &&
				!(utn_getString("\nIngrese el tipo de pasajero: ","\nError, reingrese: ",20,3,auxiliarTipoPasajero)) &&
				!(utn_getString("\nIngrese el estado de vuelo: ","\nError, reingrese: ",20,3,auxiliarEstadoVuelo))))
			{
				SizeString(auxiliarNombre);
				SizeString(auxiliarApellido);
				SizeString(auxiliarTipoPasajero);
				SizeString(auxiliarEstadoVuelo);

				if(!Passenger_setVerifyInt(auxPasajero,auxiliarID,auxiliarNombre,auxiliarApellido,auxiliarPrecio,auxiliarCodigoVuelo,auxiliarTipoPasajero,auxiliarEstadoVuelo))
				{
					Passenger_printOnePassenger(auxPasajero);
					utn_getString("\n¿Esta seguro que desea guardar este empleado?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,3,respuesta);

					if(!(stricmp(respuesta,"si")))
					{
						ll_add(listaPasajeros, auxPasajero);
						controller_saveAsTextID("ids.csv",listaPasajeros);
						retorno=0;
					}else
					{
						Passenger_delete(auxPasajero);
					}
				}
			}else
			{
				printf("\nReintente nuevamente");
			}
		}else
		{
			printf("No hay espacio para un nuevo empleado");
		}
	}

	return retorno;
}

int Passenger_remove(LinkedList* listaPasajeros)
{
	int retorno = -1;
	int id;
	int index = -1;
	char respuesta[4];
	Passenger* aux = NULL;

	if(listaPasajeros!=NULL)
	{
		Passenger_printList(listaPasajeros);
		utn_getInt("Ingrese el ID para dar de baja: \n","Error, ID invalido\n",1,5000,3,&id);
		index = Passenger_findID(listaPasajeros,id);

		if(index!=-1)
		{
			aux = ll_get(listaPasajeros,index);
			Passenger_printOnePassenger(aux);
			utn_getString("\n¿Esta seguro que desea eliminar este empleado?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,3,respuesta);

			if(!(stricmp(respuesta,"si")))
			{
				ll_remove(listaPasajeros,index);
				printf("Baja realizada con exito\n");
			}else
			{
				printf("Baja cancelada\n");
			}
		}else
		{
			printf("No se pudo encontrar el ID\n");
		}
	}

	return retorno;
}

int Passenger_modify(LinkedList* listaPasajeros)
{
	int retorno = -1;
	int id;
	int index = -1;
	char respuesta[4];
	char confirmar[4];
	Passenger* aux;
	Passenger auxiliar;
	strcpy(confirmar,"no");

	if(listaPasajeros!=NULL)
	{
		Passenger_printList(listaPasajeros);
		utn_getInt("Ingrese el ID para modificar\n","Error, ID invalido\n",1,5000,3,&id);
		index = Passenger_findID(listaPasajeros,id);

		if(index!=-1)
		{
			aux = (Passenger*) ll_get(listaPasajeros,index);
			auxiliar=*aux;
			Passenger_printOnePassenger(&auxiliar);
			utn_getString("\n¿Esta seguro que desea editar este pasajero?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,3,respuesta);

			if(!(stricmp(respuesta,"si")))
			{
				do
				{
					switch(Passenger_menuModify())
					{
						case 1:
							Passenger_caseNombre(listaPasajeros,index,auxiliar);
							break;
						case 2:
							Passenger_caseApellido(listaPasajeros,index,auxiliar);
							break;
						case 3:
							Passenger_casePrecio(listaPasajeros,index,auxiliar);
							break;
						case 4:
							Passenger_caseTipoPasajero(listaPasajeros,index,auxiliar);
							break;
						case 5:
							Passenger_caseCodigoVuelo(listaPasajeros,index,auxiliar);
							break;
						case 6:
							utn_getString("\n¿Esta seguro que desea salir?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,3,confirmar);
							break;
					}
				}while(stricmp(confirmar,"si"));
				printf("Modificacion realizada con exito\n");
			}else
			{
				printf("Modificacion cancelada\n");
			}
		}else
		{
			printf("No se pudo encontrar el ID\n");
		}
	}else
	{
		printf("Error. Imposible realizar una modificacion\n");
	}

	return retorno;
}

void Passenger_delete(Passenger* this)
{
	if(this!=NULL)
	{
		free(this);
		this=NULL;
	}
}

int Passenger_printOnePassenger(Passenger* this)
{
	int retorno = -1;
	int auxiliarID;
	char auxiliarNombre[128];
	char auxiliarApellido[128];
	int auxiliarPrecio;
	char auxiliarTipoPasajero[128];
	char auxiliarCodigoVuelo[128];
	char auxiliarEstadoVuelo[128];

	if(this!=NULL)
	{
		if(!Passenger_getVerify(this,&auxiliarID,auxiliarNombre,auxiliarApellido,&auxiliarPrecio,auxiliarCodigoVuelo,auxiliarTipoPasajero,auxiliarEstadoVuelo))
		{
			printf("%-5d %-15s %-15s %-13d %-16s %-16s %-16s\n" ,auxiliarID
																,auxiliarNombre
																,auxiliarApellido
																,auxiliarPrecio
																,auxiliarCodigoVuelo
																,auxiliarTipoPasajero
																,auxiliarEstadoVuelo);
			retorno = 0;
		}
		else
		{
			printf("Error para mostrar el Pasajero");
		}
	}
	return retorno;
}

int Passenger_printList(LinkedList* listaPasajeros)
{
	int retorno = -1;
	int len;
	int i;
	Passenger* aux = NULL;

	if(listaPasajeros!=NULL)
	{
		len = ll_len(listaPasajeros);

		if(len>0)
		{
			printf("%-5s %-15s %-14s %-9s %-17s %-17s %-17s\n",
				      "ID",    "Nombre",      "Apellido",     "Precio",  "Codigo de vuelo"  ,  "Tipo de pasajero"  ,  "Estado de Vuelo");

			for(i=0; i<len ;i++)
			{
				aux = (Passenger*) ll_get(listaPasajeros,i);

				if(aux != NULL)
				{
					Passenger_printOnePassenger(aux);
					retorno=0;
				}
			}
		}
	}

	return retorno;
}

int Passenger_caseNombre(LinkedList* listaPasajeros, int index, Passenger auxiliar)
{
	int retorno = -1;
	char auxNombre[128];
	int opciones;

	if(listaPasajeros!=NULL && index!=-1)
	{
		printf("\t****MODIFICAR NOMBRE****\t\n");
		utn_getString("Ingrese el nuevo nombre\n","Error, nombre invalido\n",50,3,auxNombre);
		SizeString(auxNombre);

		strcpy(auxiliar.nombre,auxNombre);
		Passenger_printOnePassenger(&auxiliar);

		utn_getInt("\n¿Esta seguro que desea modificarlo? [1/0]\n","\nRespuesta invalida, ingrese [1/0]\n",0,1,3,&opciones);
		if(opciones)
		{
			Passenger_modifyNombre(listaPasajeros,index,auxNombre);
			retorno=0;
		}else
		{
			printf("Modificacion cancelada");
		}
	}

	return retorno;
}

int Passenger_caseApellido(LinkedList* listaPasajeros, int index, Passenger auxiliar)
{
	int retorno = -1;
	char auxApellido[128];
	int opciones;

	if(listaPasajeros!=NULL && index!=-1)
	{
		printf("\t****MODIFICAR APELLIDO****\t\n");
		utn_getString("Ingrese el nuevo apellido\n","Error, apellido invalido\n",50,3,auxApellido);
		SizeString(auxApellido);

		strcpy(auxiliar.nombre,auxApellido);
		Passenger_printOnePassenger(&auxiliar);

		utn_getInt("\n¿Esta seguro que desea modificarlo? [1/0]\n","\nRespuesta invalida, ingrese [1/0]\n",0,1,3,&opciones);
		if(opciones)
		{
			Passenger_modifyApellido(listaPasajeros,index,auxApellido);
			retorno=0;
		}else
		{
			printf("Modificacion cancelada");
		}
	}

	return retorno;
}

int Passenger_casePrecio(LinkedList* listaPasajeros, int index, Passenger auxiliar)
{
	int retorno = -1;
	int auxPrecio;
	int opciones;

	if(listaPasajeros!=NULL && index!=-1)
	{
		printf("\t****MODIFICAR PRECIO****\t\n");
		utn_getInt("Ingrese el nuevo precio \n","Error, cantidad invalida\n",1,100000,3,&auxPrecio);
		auxiliar.precio = auxPrecio;
		Passenger_printOnePassenger(&auxiliar);
		utn_getInt("\n¿Esta seguro que desea modificarlo? [1/0]\n","\nRespuesta invalida, ingrese [1/0]\n",0,1,3,&opciones);
		if(opciones)
		{
			Passenger_modifyPrecio(listaPasajeros,index,auxPrecio);
			retorno=0;
		}else
		{
			printf("Modificacion cancelada");
		}
	}
	return retorno;
}

int Passenger_caseTipoPasajero(LinkedList* listaPasajeros, int index, Passenger auxiliar)
{
	int retorno = -1;
	char auxTipoPasajero[128];
	int opciones;

	if(listaPasajeros!=NULL && index!=-1)
	{
		printf("\t****MODIFICAR TIPO DE PASAJERO****\t\n");
		utn_getString("Ingrese el nuevo tipo de pasajero\n","Error, tipo de pasajero invalido\n",20,3,auxTipoPasajero);
		SizeString(auxTipoPasajero);

		strcpy(auxiliar.nombre,auxTipoPasajero);
		Passenger_printOnePassenger(&auxiliar);

		utn_getInt("\n¿Esta seguro que desea modificarlo? [1/0]\n","\nRespuesta invalida, ingrese [1/0]\n",0,1,3,&opciones);
		if(opciones)
		{
			Passenger_modifyTipoPasajero(listaPasajeros,index,auxTipoPasajero);
			retorno=0;
		}else
		{
			printf("Modificacion cancelada");
		}
	}

	return retorno;
}

int Passenger_caseCodigoVuelo(LinkedList* listaPasajeros, int index, Passenger auxiliar)
{
	int retorno = -1;
	char auxCodigoVuelo[128];
	int opciones;

	if(listaPasajeros!=NULL && index!=-1)
	{
		printf("\t****MODIFICAR CODIGO DE VUELO****\t\n");

		pedirCadena("Ingrese el nuevo codigo de vuelo\n","Error, codigo de vuelo invalido\n",10,auxCodigoVuelo);

		strcpy(auxiliar.nombre,auxCodigoVuelo);
		Passenger_printOnePassenger(&auxiliar);

		utn_getInt("\n¿Esta seguro que desea modificarlo? [1/0]\n","\nRespuesta invalida, ingrese [1/0]\n",0,1,3,&opciones);
		if(opciones)
		{
			Passenger_modifyCodigoVuelo(listaPasajeros,index,auxCodigoVuelo);
			retorno=0;
		}else
		{
			printf("Modificacion cancelada");
		}
	}

	return retorno;
}

//-------------------------------------------MODIFICADORES-------------------------------------------
int Passenger_modifyNombre(LinkedList* listaPasajeros, int index, char* auxNombre)
{
	int retorno = -1;
	Passenger* aux;

	if(listaPasajeros!=NULL && index>=0 && auxNombre!=NULL)
	{
		aux = (Passenger*) ll_get(listaPasajeros,index);
		SizeString(auxNombre);

		if(aux!=NULL)
		{
			if(!Passenger_setNombre(aux,auxNombre))
			{
				printf("Se cargo correctamente el nuevo nombre\n");
			}else
			{
				printf("No se pudo modificar el nombre\n");
			}
			retorno=0;
		}
	}

	return retorno;
}

int Passenger_modifyApellido(LinkedList* listaPasajeros, int index, char* auxApellido)
{
	int retorno = -1;
	Passenger* aux;

	if(listaPasajeros!=NULL && index>=0 && auxApellido!=NULL)
	{
		aux = (Passenger*) ll_get(listaPasajeros,index);
		SizeString(auxApellido);

		if(aux!=NULL)
		{
			if(!Passenger_setApellido(aux,auxApellido))
			{
				printf("Se cargo correctamente el nuevo apellido\n");
			}else
			{
				printf("No se pudo modificar el apellido\n");
			}
			retorno=0;
		}
	}

	return retorno;
}

int Passenger_modifyPrecio(LinkedList* listaPasajeros, int index, int auxPrecio)
{
	int retorno = -1;
	Passenger* aux;

	if(listaPasajeros!=NULL && index>=0 && auxPrecio>=1000)
	{
		aux = (Passenger*) ll_get(listaPasajeros,index);

		if(aux!=NULL)
		{
			if(!Passenger_setPrecio(aux,auxPrecio))
			{
				printf("Se cargo correctamente el nuevo precio\n");
			}
			else{
				printf("No se pudo modificar el precio\n");
			}
			retorno=0;
		}
	}
    return retorno;
}

int Passenger_modifyTipoPasajero(LinkedList* listaPasajeros, int index, char* auxTipoPasajero)
{
	int retorno = -1;
	Passenger* aux;

	if(listaPasajeros!=NULL && index>=0 && auxTipoPasajero!=NULL)
	{
		aux = (Passenger*) ll_get(listaPasajeros,index);
		SizeString(auxTipoPasajero);

		if(aux!=NULL)
		{
			if(!Passenger_setTipoPasajero(aux,auxTipoPasajero))
			{
				printf("Se cargo correctamente el nuevo tipo de pasajero\n");
			}else
			{
				printf("No se pudo modificar el tipo de pasajero\n");
			}
			retorno=0;
		}
	}

	return retorno;
}

int Passenger_modifyCodigoVuelo(LinkedList* listaPasajeros, int index, char* auxCodigoVuelo)
{
	int retorno = -1;
	Passenger* aux;

	if(listaPasajeros!=NULL && index>=0 && auxCodigoVuelo!=NULL)
	{
		aux = (Passenger*) ll_get(listaPasajeros,index);

		if(aux!=NULL)
		{
			if(!Passenger_setCodigoVuelo(aux,auxCodigoVuelo))
			{
				printf("Se cargo correctamente el nuevo codigo de vuelo\n");
			}else
			{
				printf("No se pudo modificar el tipo de codigo de vuelo\n");
			}
			retorno=0;
		}
	}

	return retorno;
}

//---------------------------------------------SETTERS---------------------------------------------
int Passenger_setId(Passenger* this, int id)
{
	int isOk = -1;

	if(this!=NULL && id>0)
	{
		this->id = id;
		isOk=0;
	}

	return isOk;
}

int Passenger_setNombre(Passenger* this, char* nombre)
{
	int isOk = -1;

	if(this!=NULL && nombre!=NULL)
	{
		strcpy(this->nombre,nombre);
		isOk=0;
	}

	return isOk;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int isOk = -1;

	if(this!=NULL && apellido!=NULL)
	{
		strcpy(this->apellido,apellido);
		isOk=0;
	}

	return isOk;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int isOk = -1;

	if(this!=NULL && codigoVuelo!=NULL)
	{
		strcpy(this->codigoVuelo,codigoVuelo);
		isOk=0;
	}

	return isOk;
}

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int isOk = -1;

	if(this!=NULL && tipoPasajero!=NULL)
	{
		strcpy(this->tipoPasajero,tipoPasajero);
		isOk=0;
	}

	return isOk;
}

int Passenger_setPrecio(Passenger* this,int precio)
{
	int isOk = -1;

	if(this!=NULL && precio>0)
	{
		this->precio = precio;
		isOk=0;
	}

	return isOk;
}

int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int isOk = -1;

	if(this!=NULL && estadoVuelo!=NULL)
	{
		strcpy(this->estadoVuelo,estadoVuelo);
		isOk=0;
	}

	return isOk;
}

//---------------------------------------------GETTERS---------------------------------------------
int Passenger_getId(Passenger* this,int* id)
{
	int isOk = -1;

	if(this!=NULL && id!=NULL)
	{
		*id = this->id;
		isOk=0;
	}

	return isOk;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int isOk = -1;

	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre,this->nombre);
		isOk=0;
	}

	return isOk;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int isOk = -1;

	if(this!=NULL && apellido!=NULL)
	{
		strcpy(apellido,this->apellido);
		isOk=0;
	}

	return isOk;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int isOk = -1;

	if(this!=NULL && codigoVuelo!=NULL)
	{
		strcpy(codigoVuelo,this->codigoVuelo);
		isOk=0;
	}

	return isOk;
}

int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int isOk = -1;

	if(this!=NULL && tipoPasajero!=NULL)
	{
		strcpy(tipoPasajero,this->tipoPasajero);
		isOk=0;
	}

	return isOk;
}

int Passenger_getPrecio(Passenger* this,int* precio)
{
	int isOk = -1;

	if(this!=NULL && precio!=NULL)
	{
		*precio = this->precio;
		isOk=0;
	}

	return isOk;
}

int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int isOk = -1;

	if(this!=NULL && estadoVuelo!=NULL)
	{
		strcpy(estadoVuelo,this->estadoVuelo);
		isOk=0;
	}

	return isOk;
}

int Passenger_sortPassenger(LinkedList* clon)
{
	int retorno = -1;
	int opcion;
	char confirmar[4];
	strcpy(confirmar,"no");
	do
	{
		opcion = Passenger_menuOrden();
		switch(opcion)
		{
			case 1:
				Passenger_caseCompareApellido_Tipo(clon);
				printf("Ordenando...\n");
				controller_ListPassenger(clon);
				system("pause");
			break;
			case 2:
				Passenger_caseCompareMaxPromedio(clon);
				system("pause");
			break;
			case 3:
				Passenger_caseCompareCodigo_Estado(clon);
				printf("Ordenando...\n");
				controller_ListPassenger(clon);
			break;
			case 5:
				utn_getString("\n¿Esta seguro que desea salir?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,3,confirmar);
				ll_deleteLinkedList(clon);
			break;
		}
	}while(stricmp(confirmar,"si"));
	return retorno;
}

void Passenger_caseCompareApellido_Tipo(LinkedList* clon)
{
	int orden;

	orden = Passenger_subMenuOrden();

	if(!ll_sort(clon,Passenger_compareByApellido,orden) && !ll_sort(clon,Passenger_compareByTipoPasajero,orden))
	{
		if(orden)
		{
			printf("Se ha ordenado la lista por nombre de A-Z");
		}else
		{
			if(!orden)
			{
				printf("Se ha ordenado la lista por nombre de Z-A");
			}
		}
	}
}

int Passenger_caseCompareMaxPromedio(LinkedList* clon)
{
	int resultado = 0;
	float promedio;
	int len;
	Passenger* pasajero = NULL;

	len = ll_len(clon);

	if(len > 0)
	{
		promedio = Passenger_TotalPasajesYPromedio(clon,pasajero,len);
		system("pause");
		Passenger_MaxPrecio(clon,pasajero,promedio,len);
		resultado = 0;
	}

	return resultado;
}

int Passenger_TotalPasajesYPromedio(LinkedList* clon, Passenger* pasajero, int len)
{
	int precio;
	float promedio;
	float precioFloat;
	float precioTotal = 0;
	float contadorPasajeros = 0;

	for(int i=0; i<len; i++)
	{
		pasajero = (Passenger*) ll_get(clon,i);

		if(!Passenger_getPrecio(pasajero,&precio))
		{
			if(precio > 0)
			{
				precioFloat = (float)precio;
				precioTotal = precioFloat + precioTotal;
				contadorPasajeros++;
			}
		}
	}
	promedio = precioTotal/contadorPasajeros;
	printf( "\nPrecio total de los pasajes: %.2f"
			"\nPrecio promedio de los pasajes: %.2f\n\n",precioTotal,promedio);
	return promedio;
}

int Passenger_MaxPrecio(LinkedList* clon, Passenger* pasajero, float promedio, int len)
{
	int resultado = -1;
	int precio;

	printf("Ordenando...");
	for(int i=0; i<len; i++)
	{
		pasajero = (Passenger*) ll_get(clon,i);

		if(!Passenger_getPrecio(pasajero,&precio))
		{
			if(precio > promedio)
			{
				ll_set(clon,i,pasajero);
				Passenger_printOnePassenger(pasajero);
				resultado = 0;
			}
		}
	}
	return resultado;
}

void Passenger_caseCompareCodigo_Estado(LinkedList* clon)
{
	int orden;

	orden = Passenger_subMenuOrden();

	if(!ll_sort(clon,Passenger_compareByCodigoVuelo,orden) && !ll_sort(clon,Passenger_compareByEstadoVuelo,orden))
	{
		if(orden)
		{
			printf("Se ha ordenado la lista por nombre de A-Z");
		}else
		{
			if(!orden)
			{
				printf("Se ha ordenado la lista por nombre de Z-A");
			}
		}
	}
}

int Passenger_compareByApellido(void* pasajero1, void* pasajero2)
{
	int resultado = -1;
	char nombre1[128];
	char nombre2[128];
	Passenger* p1 = NULL;
	Passenger* p2 = NULL;

	if(pasajero1!=NULL && pasajero2!=NULL)
	{
		p1 = (Passenger*) pasajero1;
		p2 = (Passenger*) pasajero2;

		if((!Passenger_getApellido(p1,nombre1)) && (!Passenger_getApellido(p2,nombre2)))
		{
			resultado = strcmp(nombre1,nombre2);
		}
	}

	return resultado;
}

int Passenger_compareByTipoPasajero(void* pasajero1, void* pasajero2)
{
	int resultado = -1;
	char tipoPasajero1[128];
	char tipoPasajero2[128];
	Passenger* p1 = NULL;
	Passenger* p2 = NULL;

	if(pasajero1!=NULL && pasajero2!=NULL)
	{
		p1 = (Passenger*) pasajero1;
		p2 = (Passenger*) pasajero2;

		if((!Passenger_getTipoPasajero(p1,tipoPasajero1)) && (!Passenger_getTipoPasajero(p2,tipoPasajero2)))
		{
			resultado = strcmp(tipoPasajero1,tipoPasajero2);
		}
	}

	return resultado;
}

int Passenger_compareByCodigoVuelo(void* pasajero1, void* pasajero2)
{
	int resultado = -1;
	char codigoVuelo1[128];
	char codigoVuelo2[128];
	Passenger* p1 = NULL;
	Passenger* p2 = NULL;

	if(pasajero1!=NULL && pasajero2!=NULL)
	{
		p1 = (Passenger*) pasajero1;
		p2 = (Passenger*) pasajero2;

		if((!Passenger_getCodigoVuelo(p1,codigoVuelo1)) && (!Passenger_getCodigoVuelo(p2,codigoVuelo2)))
		{
			resultado = strcmp(codigoVuelo1,codigoVuelo2);
		}
	}

	return resultado;
}

int Passenger_compareByEstadoVuelo(void* pasajero1, void* pasajero2)
{
	int resultado = -1;
	char estadoVuelo1[128];
	char estadoVuelo2[128];
	Passenger* p1 = NULL;
	Passenger* p2 = NULL;

	if(pasajero1!=NULL && pasajero2!=NULL)
	{
		p1 = (Passenger*) pasajero1;
		p2 = (Passenger*) pasajero2;

		if((!Passenger_getEstadoVuelo(p1,estadoVuelo1)) && (!Passenger_getEstadoVuelo(p2,estadoVuelo2)))
		{
			resultado = strcmp(estadoVuelo1,estadoVuelo2);
		}
	}

	return resultado;
}
