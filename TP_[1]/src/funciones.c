#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int primerMenu(){

	int opcion;
	system("cls");

	printf("Seleccione opcion: \n\n");
	printf("1- Kilometros del vuelo.\n");
	printf("2- Precio de Vuelos:.\n");
	printf("3- Calcular todos los costos.\n");
	printf("4- Informar resultados.\n");
	printf("5- Carga forzada de datos.\n");
	printf("6- Salir.\n");

	scanf("%d", &opcion);
	return opcion;
}

int pedirKilometros(){

	int km;
	system("cls");
	printf("Ingrese los kilometros del vuelo.\n");
	scanf("%d", &km);

	return km;
}

int pedirPrecioAerolineas(){

	int precioAero;
	system("cls");
	printf("Ingrese el precio del vuelo por Aerolineas Argentinas.\n");
	scanf("%d", &precioAero);

	return precioAero;
}

int pedirPrecioLatam(){

	int precioLatam;
	system("cls");
	printf("Ingrese el precio del vuelo por Latam.\n");
	scanf("%d", &precioLatam);

	return precioLatam;
}

float calculoPago(float precio, float multiplicador){
	float pagoCalculado = (precio * multiplicador);
	return pagoCalculado;
}

float calculoUnitario(float precio, int km){
	float unitarioCalculado = (precio / km);
	return unitarioCalculado;
}

float calculoDiferencia(float precio1, float precio2){
	float diferenciaParcial = (precio1 - precio2);
	float diferenciaCalculado;
	if (diferenciaParcial < 0){
		diferenciaCalculado = (diferenciaParcial * (-1));
	} else {
		diferenciaCalculado = diferenciaParcial;
	}
	return diferenciaCalculado;
}

void calculaTodo(int kilometros, float precioAerolineas, float precioLatam, float multiplicadorCredito, float multiplicadorDebito, float bitcoin, float *aerolineasCredito, float *aerolineasDebito, float *aerolineasBitcoin, float *aerolineasUnitario, float *latamCredito, float *latamDebito, float *latamBitcoin, float *latamUnitario, float *diferencia){
    *aerolineasCredito = calculoPago(precioAerolineas, multiplicadorCredito);
    *aerolineasDebito = calculoPago(precioAerolineas, multiplicadorDebito);
    *aerolineasBitcoin = calculoPago(precioAerolineas, bitcoin);
    *aerolineasUnitario = calculoUnitario(precioAerolineas, kilometros);
    *latamCredito = calculoPago(precioLatam, multiplicadorCredito);
    *latamDebito = calculoPago(precioLatam, multiplicadorDebito);
    *latamBitcoin = calculoPago(precioLatam, bitcoin);
    *latamUnitario = calculoUnitario(precioLatam, kilometros);
    *diferencia = calculoDiferencia(precioAerolineas, precioLatam);
}

void muestraTodo(int kilometros, float precioAerolineas, float precioLatam, float multiplicadorCredito, float multiplicadorDebito, float bitcoin, float aerolineasCredito, float aerolineasDebito, float aerolineasBitcoin, float aerolineasUnitario, float latamCredito, float latamDebito, float latamBitcoin, float latamUnitario, float diferencia){
	printf("Kms ingresados: %d\n\n", kilometros);
	printf("Precio Aerolineas Argentinas: $%.2f\n",precioAerolineas);
	printf("a) Precio con tarjeta de debito: $%.2f\n",aerolineasDebito);
	printf("b) Precio con tarjeta de credito: $%.2f\n", aerolineasCredito);
	printf("c) Precio pagando con bitcoin: $%.6f\n",aerolineasBitcoin);
	printf("d) Precio unitario por kilometro: $%.2f\n\n",aerolineasUnitario);
	printf("Precio Latam: $%.2f\n",precioLatam);
	printf("a) Precio con tarjeta de debito: $%.2f\n",latamDebito);
	printf("b) Precio con tarjeta de credito: $%.2f\n",latamCredito);
	printf("c) Precio pagando con bitcoin: $%.6f\n",latamBitcoin);
	printf("d) Precio unitario por kilometro: $%.2f\n\n",latamUnitario);
	printf("La diferencia de precio es: $%.2f\n\n",diferencia);
}
