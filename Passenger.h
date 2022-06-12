/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	int precio;
	char tipoPasajero[20];
	char codigoVuelo[10];
	char estadoVuelo[20];
}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* codigoVueloStr,char* tipoPasajeroStr,char* estadoVuelo);
int Passenger_add(LinkedList* listaPasajeros, int* id);
int Passenger_remove(LinkedList* listaPasajeros);
int Passenger_modify(LinkedList* listaPasajeros);
void Passenger_delete(Passenger* this);

int Passenger_caseNombre(LinkedList* listaPasajeros, int index, Passenger auxiliar);
int Passenger_caseApellido(LinkedList* listaPasajeros, int index, Passenger auxiliar);
int Passenger_casePrecio(LinkedList* listaPasajeros, int index, Passenger auxiliar);
int Passenger_caseTipoPasajero(LinkedList* listaPasajeros, int index, Passenger auxiliar);
int Passenger_caseCodigoVuelo(LinkedList* listaPasajeros, int index, Passenger auxiliar);

int Passenger_modifyNombre(LinkedList* listaPasajeros, int index, char* auxNombre);
int Passenger_modifyApellido(LinkedList* listaPasajeros, int index, char* auxApellido);
int Passenger_modifyPrecio(LinkedList* listaPasajeros, int index, int auxPrecio);
int Passenger_modifyTipoPasajero(LinkedList* listaPasajeros, int index, char* auxTipoPasajero);
int Passenger_modifyCodigoVuelo(LinkedList* listaPasajeros, int index, char* auxCodigoVuelo);

int Passenger_printOnePassenger(Passenger* this);
int Passenger_printList(LinkedList* listaPasajeros);

int Passenger_ObtenerMayorId(LinkedList* listaPasajeros);
int Passenger_findID(LinkedList* listaPasajeros, int id);

int Passenger_getVerify(Passenger* this, int* idStr,char* nombreStr,char* apellidoStr,int* precioStr,char* codigoVueloStr,char* tipoPasajeroStr,char* estadoVuelo);
int Passenger_setVerifyChar(Passenger* this, char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* codigoVueloStr,char* tipoPasajeroStr,char* estadoVuelo);
int Passenger_setVerifyInt(Passenger* this, int idStr,char* nombreStr,char* apellidoStr,int precioStr,char* codigoVueloStr,char* tipoPasajeroStr,char* estadoVuelo);

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);

int Passenger_setPrecio(Passenger* this,int precio);
int Passenger_getPrecio(Passenger* this,int* precio);

int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo);

int Passenger_sortPassenger(LinkedList* clon);
void Passenger_caseCompareApellido_Tipo(LinkedList* clon);
int Passenger_caseCompareMaxPromedio(LinkedList* clon);
int Passenger_TotalPasajesYPromedio(LinkedList* clon, Passenger* pasajero, int len);
int Passenger_MaxPrecio(LinkedList* clon, Passenger* pasajero, float promedio, int len);
void Passenger_caseCompareCodigo_Estado(LinkedList* clon);

int Passenger_compareByApellido(void* pasajero1, void* pasajero2);
int Passenger_compareByTipoPasajero(void* pasajero1, void* pasajero2);
int Passenger_compareByCodigoVuelo(void* pasajero1, void* pasajero2);
int Passenger_compareByEstadoVuelo(void* pasajero1, void* pasajero2);

#endif /* PASSENGER_H_ */
