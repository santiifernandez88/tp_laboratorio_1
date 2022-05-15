#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include <ctype.h>
#include <stdio.h>
#include"input.h"

#define LIBRE 0
#define OCUPADO 1

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flyCode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}sPassenger;

/// @brief genera un id a mendida que se cargan datos
/// @return un id incremental
int GenerarID(void);

/// @brief inicializa la estructura liberando todos las posiciones
/// @param passengerList
/// @param size- int tamaño del vector de pasajeros
/// @return 0 si se realizo correctamente, -1 si hubo un error
int initPassengers(sPassenger passengerList[], int size);

/// @brief localiza el espacio libre en el vector
/// @param passengerList
/// @param size- int tamaño del vector de pasajeros
/// @return el indice del espacio libre, -1 si no se encontro espacio disponible
int BuscarEspacio(sPassenger passengerList[], int size);

/// @brief Solicita que se carguen los datos de un pasajero
/// @return una estructura con los datos de un pasajero
sPassenger CargarUnPasajero();

/// @brief Carga los datos de un pasajero en la lista de pasajeros
/// @param passengerList
/// @param size- int tamaño del vector de pasajeros
/// @return 0 si se realizo correctamente, -1 si hubo un error
int addPassenger(sPassenger passengerList[], int size);

/// @brief Busca en la lista de pasajeros el id solicitado
/// @param passengerList
/// @param size- int tamaño del vector de pasajeros
/// @param id
/// @return 0 si se realizo correctamente, -1 si hubo un error
int findPassengerById(sPassenger passengerList[], int size, int id);

/// @brief Modifica los datos de un pasajero mediante la solicitacion del id
/// @param passengerList
/// @param size- int tamaño del vector de pasajeros
/// @return 0 si se realizo correctamente, -1 si hubo un error
int ModificarPasajero(sPassenger passengerList[], int size);

/// @brief Elimina el registro de un pasajero mediante la solicitacion del id
/// @param passengerList
/// @param size- int tamaño del vector de pasajeros
/// @param id
/// @return 0 si se realizo correctamente, -1 si hubo un error
int removePassenger(sPassenger passengerList[], int size, int id);

/// @brief Ordena decrecientemente los apellidos y,si son iguales, ordena de mayor a menor el tipo de pasajero
/// @param passengerList
/// @param size- int tamaño del vector de pasajeros
void OrdenarDecreciente(sPassenger passengerList[], int size);

/// @brief Ordena crecientemente los apellidos y, si son iguales, ordena de menor a mayor el tipo de pasajero
/// @param passengerList
/// @param size- int tamaño del vector de pasajeros
void OrdenarCreciente(sPassenger passengerList[], int size);

/// @brief Ordena el array de pasajeros por apellido y tipo de pasajero de manera ascendente o descendente.
/// @param passengerList
/// @param size- int tamaño del vector de pasajeros
/// @param order int [1] indicate UP - [0] indicate DOWN
/// @return 0 si se realizo correctamente, -1 si hubo un error
int sortPassengers(sPassenger passengerList[], int size, int order);

/// @brief Calcula el promedio de los precios y cuenta la cantidad de pasajeros cuyo precio de vuelo esta por encima del promedio
/// @param passengerList
/// @param size- int tamaño del vector de pasajeros
void CalcularPromedioPrecio(sPassenger passengerList[], int size);

/// @brief Ordena decrecientemente los codigo de vuelo y,si son iguales, ordena de mayor a menor el estatus de vuelo
/// @param passengerList
/// @param size - int tamaño del vector de pasajeros
void OrdenarDecrecienteByCode(sPassenger passengerList[], int size);

/// @brief Ordena crecientemente los codigo de vuelo y,si son iguales, ordena de menor a mayor el estatus de vuelo
/// @param passengerList
/// @param size- int tamaño del vector de pasajeros
void OrdenarCrecienteByCode(sPassenger passengerList[], int size);

/// @brief Ordena el array de pasajeros por código de vuelo y estado de vuelo de manera ascendente o descendente.
/// @param passengerList
/// @param size- int tamaño del vector de pasajeros
/// @param order int [1] indicate UP - [0] indicate DOWN
/// @return 0 si se realizo correctamente, -1 si hubo un error
int sortPassengersByCode(sPassenger passengerList[], int size, int order);

/// @brief Imprime los datos de un pasajero
/// @param pasajero
void MostrarUnPasajero(sPassenger pasajero);

/// @brief Imprime todos los datos de los pasajeros cargados
/// @param passengerList
/// @param size- int tamaño del vector de pasajeros
/// @return 0 si se realizo correctamente, -1 si hubo un error
int printPassengers(sPassenger passengerList[], int size);

///@brief  Se relaiza una carga forzada de pasajeros
/// @param passengerList
void CargaForzadaPasajeros(sPassenger passengerList[]);

#endif /* ARRAYPASSENGER_H_ */
