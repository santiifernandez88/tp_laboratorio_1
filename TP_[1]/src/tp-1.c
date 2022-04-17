#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void) {
	setbuf(stdout,NULL);

	//Constantes
	float multiplicadorCredito = 1.25; //Con 25% de interes.
	float multiplicadorDebito = 0.9; //Con 10% de descuento.
	float bitcoin = (1/4606954.55); //Esta como fraccion para poder multiplicar el valor usando funciones ya definidas.

	//Variables que se piden al usuario
	int kilometros;
	float precioAerolineas;
	float precioLatam;

	//Variables que se van a modificar en el programa
	float aerolineasCredito;
	float aerolineasDebito;
	float aerolineasBitcoin;
	float aerolineasUnitario;
	float latamCredito;
	float latamDebito;
	float latamBitcoin;
	float latamUnitario;
	float diferencia;

	//Banderas
	int flagKilometros = 0;
	int flagAerolineas = 0;
	int flagLatam = 0;
	int flagCalculo = 0;
	char flagSalida = 'N';


	do{
		switch(primerMenu()){
			case 1:
				while (flagKilometros == 0){
					system("cls");
					kilometros = pedirKilometros();
					if (kilometros > 0){
						flagKilometros = 1;
					} else {
						printf("No se ingresó una distancia valida.\n\n");
						system("pause");
					}
				}

				break;

			case 2:
				while (flagAerolineas == 0){
					system("cls");
					precioAerolineas = pedirPrecioAerolineas();
					if (precioAerolineas > 0) {
						flagAerolineas = 1;
					} else {
						printf("No se ingreso un monto valido.\n\n");
						system("pause");
					}
				}

				while (flagLatam == 0){
					system("cls");
					precioLatam = pedirPrecioLatam();
					if (precioLatam > 0) {
						flagLatam = 1;
					} else {
						printf("No se ingreso un monto valido.\n\n");
						system("pause");
					}
				}

				printf("Precios cargados.\n\n");
				system("pause");
				break;

			case 3:
				system("cls");
				if((flagKilometros == 1) && (flagAerolineas == 1) && (flagLatam == 1)){

					calculaTodo(kilometros, precioAerolineas, precioLatam, multiplicadorCredito, multiplicadorDebito, bitcoin, &aerolineasCredito, &aerolineasDebito, &aerolineasBitcoin, &aerolineasUnitario, &latamCredito, &latamDebito, &latamBitcoin, &latamUnitario, &diferencia);

					flagCalculo = 1;

					printf("Hecho!\n\n");
					system("pause");

				} else {
					system("cls");
					printf("Primero debe ingresar los datos de kilometraje y el precio de cada aerolinea.\n\n");
					system("pause");
				}
				break;

			case 4:
				if(flagCalculo == 1){
					system("cls");

					muestraTodo(kilometros, precioAerolineas, precioLatam, multiplicadorCredito, multiplicadorDebito, bitcoin, aerolineasCredito, aerolineasDebito, aerolineasBitcoin, aerolineasUnitario, latamCredito, latamDebito, latamBitcoin, latamUnitario, diferencia);

					system("pause");
				} else {
					system("cls");
					printf("Primero debe calcular los costos.\n\n");
					system("pause");
				}
				break;

			case 5:

				kilometros= 7090;
				precioAerolineas= 162965;
				precioLatam= 159339;
				calculaTodo(kilometros, precioAerolineas, precioLatam, multiplicadorCredito, multiplicadorDebito, bitcoin, &aerolineasCredito, &aerolineasDebito, &aerolineasBitcoin, &aerolineasUnitario, &latamCredito, &latamDebito, &latamBitcoin, &latamUnitario, &diferencia);
				muestraTodo(kilometros, precioAerolineas, precioLatam, multiplicadorCredito, multiplicadorDebito, bitcoin, aerolineasCredito, aerolineasDebito, aerolineasBitcoin, aerolineasUnitario, latamCredito, latamDebito, latamBitcoin, latamUnitario, diferencia);
				break;

			case 6:
				do{
					printf("Confirma salida?, ingrese: (S/N)\n");
					fflush(stdin);
					scanf("%c",&flagSalida);
					system("pause");
				}while(flagSalida!='N' && flagSalida!='S');
				break;

			default:
				printf("Opcion invalida. Ingrese nuevamente.\n\n");
				system("pause");
				break;
		}
	} while (flagSalida == 'N');
}
