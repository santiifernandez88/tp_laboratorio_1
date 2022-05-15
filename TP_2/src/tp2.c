#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "input.h"
#include "ArrayPassenger.h"

#define SIZE 2000

int main(void) {

	setbuf(stdout,NULL);

	int opcion;
	int retorno;
	int id;
	int order;

	sPassenger passengerList[SIZE];
	initPassengers(passengerList, SIZE);

	do{
		printf("1.Ingresar pasajero\n2.Modificar pasajero\n3.Eiminar pasajero\n4.Informar\n5.Alta forzada de pasajeros\n6.SALIR\nElija una opci�n:");
		scanf("%d",&opcion);

		switch(opcion)
		{
			case 1://ALTAS
				retorno = addPassenger(passengerList, SIZE);
				switch(retorno){
					case -1:
						printf("\n\nNo hay espacio para cargar pasajeros\n\n");
						break;
					case 0:
						printf("\n\nEl pasajero se carg� exitosamente\n\n");
						break;}
			break;

			case 2://MODIFICAR
				retorno = ModificarPasajero(passengerList, SIZE);
				switch(retorno){
					case -1:
						printf("\n\nNo se encontr� el ID\n\n");
					break;
					case 0:
						printf("\n\nEl pasajero se modific� exitosamente\n\n");
					break;}
			break;

			case 3://BAJA:
				id = PedirEntero("Ingrese el ID del pasajero que desea eliminar: ");
				retorno = removePassenger(passengerList, SIZE, id);
				switch(retorno){
					case -1:
						printf("\n\nNo se encontr� el ID\n\n");
					break;
					case 0:
						printf("\n\nEl pasajero se elimin� exitosamente\n\n");
					break;}
			break;

			case 4://INFORMAR:
				printf("\nINFORMAR:\n1.Listado de pasajeros ordenados alfab�ticamente por Apellido y Tipo de pasajero.\n2.Total y promedio de los precios de los pasajes, y cu�ntos pasajeros superan el precio promedio\n3.Listado de los pasajeros por C�digo de vuelo  y estados de vuelos �ACTIVO�\n\nElija una opci�n:");					scanf("%d",&opcion);
				switch(opcion)
				{
					case 1:
						order = PedirEntero("\n0. Ordena de forma decreciente\n1. Ordena de forma creciente\n Seleccione opci�n: ");
						retorno = sortPassengers(passengerList, SIZE, order);
					break;
					case 2:
						CalcularPromedioPrecio(passengerList, SIZE);
					break;
					case 3:
						order = PedirEntero("\n0. Ordena de forma decreciente\n1. Ordena de forma creciente\n Seleccione opci�n: ");
						retorno = sortPassengersByCode(passengerList, SIZE, order);
					break;
				}
				retorno = printPassengers(passengerList, SIZE);
				switch(retorno)
				{
					case -1:
						printf("\n\nNo es posible ordenar\n\n");
					break;
					case 0:
						printf("\n\nSe orden� exitosamente\n\n");
					break;
				}
			break;

			case 5:// CARGA FORZADA
				CargaForzadaPasajeros(passengerList);
			break;

			case 6://SALIR
				printf("\n\nGracias por usar el programa...");
				opcion = 6;
			break;
		}
	}while(opcion!=6);

	return EXIT_SUCCESS;
}
