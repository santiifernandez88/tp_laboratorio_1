#include <string.h>
#include "ArrayPassenger.h"

int GenerarID(void)
{
	static int idIncremental = 1;
	return idIncremental++;
}

int initPassengers(sPassenger passengerList[], int size)
{
	int retorno = -1;

	if(passengerList != NULL && size > 0)
	{
		for(int i=0; i<size; i++)
		{
			passengerList[i].isEmpty = LIBRE;
		}
		retorno = 0;
	}

	return retorno;
}

int BuscarEspacio(sPassenger passengerList[], int size)
{
	int retorno = -1;
	for(int i=0; i<size; i++)
	{
		if(passengerList[i].isEmpty == LIBRE)
		{
			retorno = i;
		}
	}
	return retorno;
}

sPassenger CargarUnPasajero()
{
	sPassenger pasajero;
	getString(pasajero.name, "Ingrese nombre del pasajero: ");
	getString(pasajero.lastName, "Ingrese apellido del pasajero: ");
	pasajero.price = PedirFlotante("Ingresar precio del vuelo: ");
	getString(pasajero.flyCode,"Ingrese el código de vuelo: ");
	pasajero.typePassenger = PedirEntero("\n1- Ejecutivo\n2- Primera Clase\nIngrese el tipo de pasajero: ");
	pasajero.statusFlight = PedirEntero("\n1- Activo\n2- Cancelado\n Ingrese el estado del vuelo: ");


	return pasajero;
}

int addPassenger(sPassenger passengerList[], int size)//carga de un pasajero en la lista
{
	 int retorno = -1;
	 int indice = BuscarEspacio(passengerList, size);

	 if(passengerList != NULL && size > 0)
	 {
	   if(indice != -1)
	   {
		   passengerList[indice] = CargarUnPasajero();
		   passengerList[indice].id = GenerarID();
		   passengerList[indice].isEmpty = OCUPADO;

		   retorno = 0;
	   }
	 }
	return retorno;
}

int findPassengerById(sPassenger passengerList[], int size, int id)//Busca un pasajero recibiendo como parámetro de búsqueda su Id.
{
	int retorno = -1;

	if(passengerList != NULL && size > 0)
	{
		for(int i=0; i<size; i++)
		{
			if(passengerList[i].id==id && passengerList[i].isEmpty == OCUPADO)
			{
				retorno = i;
			}
		}
	}

	return retorno;
}

int ModificarPasajero(sPassenger passengerList[], int size)
{
	int id;
	int index;
	int retorno = -1;
	int opcion;

	printf("Ingrese el ID del pasajero que desea modificar: ");
	scanf("%d",&id);

	index = findPassengerById(passengerList,size, id);

	printf("\nSe modificará al siguiente pasajero: \n"
			"\nID: %d\n"
			"\nNOMBRE: %s\n"
			"\nAPELLIDO: %s\n"
			"\nCÓDIGO DE VUELO: %s\n"
			,passengerList[index].id
			,passengerList[index].name
			,passengerList[index].lastName
			,passengerList[index].flyCode);

	printf("\n1.Nombre\n2.Apellido\n3.Precio\n4.Tipo de pasajero\n5.Código de vuelo\nSeñale lo que desea modificar: ");
	scanf("%d",&opcion);

	if(opcion == 1){
		printf("Ingrese el nuevo nombre del pasajero: ");
		fflush(stdin);
		scanf("%[^\n]s",passengerList[index].name);
		retorno = 0;}
	else if(opcion == 2){
		printf("Ingrese el nuevo apellido del pasajero: ");
		fflush(stdin);
		scanf("%[^\n]s",passengerList[index].lastName);
		retorno = 0;}
	else if(opcion == 3){
		printf("Ingrese el nuevo precio del vuelo: ");
		scanf("%f",&passengerList[index].price);
		retorno = 0;}
	else if(opcion == 4){
		printf("Ingrese el nuevo tipo de pasajero: ");
		scanf("%d",&passengerList[index].typePassenger);
		retorno = 0;}
	else if(opcion == 5){
		printf("Ingrese el nuevo codigo de vuelo: ");
		fflush(stdin);
		scanf("%[^\n]s",passengerList[index].flyCode);
		retorno = 0;}

	return retorno;
}

int removePassenger(sPassenger passengerList[], int size, int id)//Elimina de manera lógica (isEmpty Flag en 1) un pasajero recibiendo como parámetro su Id.
{
	int retorno = -1;
	int index;
	index = findPassengerById(passengerList, size, id);

	if(index != -1)
	{
		for(int i=0; i<size; i++)
		{
			if(passengerList[index].isEmpty == OCUPADO && passengerList[index].id == id)
			{
				printf("\nSe eliminará al siguiente pasajero: \n"
					"\nID: %d\n"
					"\nNOMBRE: %s\n"
					"\nAPELLIDO: %s\n"
					"\nCÓDIGO DE VUELO: %s\n"
					,passengerList[index].id
					,passengerList[index].name
					,passengerList[index].lastName
					,passengerList[index].flyCode);

				passengerList[index].isEmpty = LIBRE;
				retorno = 0;
			}
		}
	}
	return retorno;
}

void OrdenarDecreciente(sPassenger passengerList[], int size)
{
	sPassenger auxiliar;
	for(int i=0; i<size-1; i++)
	{
	   for(int j=i+1; j<size; j++)
	   {
	      if(strcmp(passengerList[i].lastName,passengerList[j].lastName)<0) //  ordena no - alfabeticamente
	      {
	        auxiliar = passengerList[i];
	        passengerList[i] = passengerList[j];
	        passengerList[j] = auxiliar;
	      }
	      else if(strcmp(passengerList[i].lastName,passengerList[j].lastName)==0) // doble criterio si son iguales, ordena de mayor a menor el type
	      {
	    	  if(passengerList[i].typePassenger<passengerList[j].typePassenger)
	          {
	            auxiliar = passengerList[i];
	            passengerList[i] = passengerList[j];
	            passengerList[j] = auxiliar;
	          }
	      }
	   }
	}
}

void OrdenarCreciente(sPassenger passengerList[], int size)
{
	sPassenger auxiliar;
    for(int i=0; i<size-1; i++)
    {
        for(int j=i+1; j<size; j++)
        {
            if(strcmp(passengerList[i].lastName,passengerList[j].lastName)>0) //  ordena alfabeticamente
            {
            	auxiliar = passengerList[i];
            	passengerList[i] = passengerList[j];
            	passengerList[j] = auxiliar;
            }
            else if(strcmp(passengerList[i].lastName,passengerList[j].lastName)==0) // doble criterio si son iguales, ordena de menor a mayor el type
            {
            	if(passengerList[i].typePassenger>passengerList[j].typePassenger)
            	{
            		auxiliar = passengerList[i];
            		passengerList[i] = passengerList[j];
            		passengerList[j] = auxiliar;
            	}
            }
        }
    }
}

int sortPassengers(sPassenger passengerList[], int size, int order)//Ordena el array de pasajeros por apellido y tipo de pasajero de manera ascendente o descendente.
{
	int retorno = -1;
	if(passengerList != NULL && size > 0)
	{
		if(order == 1){
			OrdenarCreciente(passengerList, size);
			retorno = 0;
		}
		else if(order == 0){
			OrdenarDecreciente(passengerList, size);
			retorno = 0;
		}
	}
	return retorno;
}

void CalcularPromedioPrecio(sPassenger passengerList[], int size)
{
	int contadorPasajeros = 0;
	float acumuladorPrecio = 0;
	float promedioPrecio;
	int contadorSuperaPromedio=0;

	if(passengerList != NULL && size > 0)
	{
		for(int i=0; i<size; i++)
		{
			if(passengerList[i].isEmpty == OCUPADO)
			{
				contadorPasajeros++;
				acumuladorPrecio += passengerList[i].price;
			}
		}

	}

	printf("\nEl total de precios es de: %.2f",acumuladorPrecio);
	promedioPrecio = acumuladorPrecio / contadorPasajeros;
	printf("\nEl promedio de precios es de: %.2f",promedioPrecio);

	for(int i=0; i<size; i++)
	{
		if(passengerList[i].price > promedioPrecio)
		{
			contadorSuperaPromedio++;
		}
	}
	printf("\nLa cantidad de pasajeros que superan el precio promedio es de: %d\n",contadorSuperaPromedio);
}


void OrdenarDecrecienteByCode(sPassenger passengerList[], int size)
{
	sPassenger auxiliar;
		for(int i=0; i<size-1; i++)
		{
		   for(int j=i+1; j<size; j++)
		   {
		      if(strcmp(passengerList[i].flyCode,passengerList[j].flyCode)<0) //  ordena no-alfabeticamente
		      {
		            auxiliar = passengerList[i];
		            passengerList[i] = passengerList[j];
		            passengerList[j] = auxiliar;
		      }
		      else if(strcmp(passengerList[i].flyCode,passengerList[j].flyCode)==0) // doble criterio si son iguales, ordena de mayor a menor el status
		      {
				  if(passengerList[i].statusFlight < passengerList[j].statusFlight)
				  {
					  	auxiliar = passengerList[i];
						passengerList[i] = passengerList[j];
						passengerList[j] = auxiliar;
				  }
		      }
		   }
		}
}

void OrdenarCrecienteByCode(sPassenger passengerList[], int size)
{
	sPassenger auxiliar;
	for(int i=0; i<size-1; i++)
	{
	   for(int j=i+1; j<size; j++)
	   {
	      if(strcmp(passengerList[i].flyCode,passengerList[j].flyCode)>0) //  ordena alfabeticamente
	      {
	            	auxiliar = passengerList[i];
	            	passengerList[i] = passengerList[j];
	            	passengerList[j] = auxiliar;
	      }
	      else if(strcmp(passengerList[i].flyCode,passengerList[j].flyCode)==0) // doble criterio si son iguales, ordena de menor a mayor el status
	      {
			  if(passengerList[i].statusFlight>passengerList[j].statusFlight)
			  {
					auxiliar = passengerList[i];
					passengerList[i] = passengerList[j];
					passengerList[j] = auxiliar;
			  }
	      }
	   }
	}
}

int sortPassengersByCode(sPassenger passengerList[], int size, int order)
{
	int retorno = -1;
	if(passengerList != NULL && size > 0)
	{
		if(order == 1){
			OrdenarCrecienteByCode(passengerList, size);
			retorno = 0;
		}
		else if(order == 0){
			OrdenarDecrecienteByCode(passengerList, size);
			retorno = 0;
		}
	}
	return retorno;
}

void MostrarUnPasajero(sPassenger pasajero)
{
	printf("\n%d %s %s %.2f %s %d %d\n",pasajero.id,pasajero.name,pasajero.lastName,pasajero.price,pasajero.flyCode,pasajero.typePassenger,pasajero.statusFlight);
}

int printPassengers(sPassenger passengerList[], int size)//Imprime el array de pasajeros de forma encolumnada.
{
	int retorno = -1;
	if(passengerList != NULL && size > 0)
	{
		for(int i=0; i<size; i++)
		{
			if(passengerList[i].isEmpty == OCUPADO)
			{
				MostrarUnPasajero(passengerList[i]);
				retorno = 0;
			}
		}
	}

	return retorno;
}

void CargaForzadaPasajeros(sPassenger passengerList[])
{
	sPassenger auxiliar[7] = {{1,"Carlos","Martínez",965.5,"iubnjhuio",1,1,OCUPADO}
								,{2,"Eduardo","Miranda",500.5,"pohjdfpoi",2,1,OCUPADO}
								,{3,"María","Lopez",860.3,"cbdgwytyu",2,1,OCUPADO}
								,{4,"Juan","Barrionuevo",1200.5,"hjyutrnbv",1,1,OCUPADO}
								,{5,"Rosa","Alaniz",682.5,"afrityfgh",2,1,OCUPADO}
								,{6,"Marcos","Perez",754.5,"poyujityu",1,1,OCUPADO}
								,{7,"Tiziana","Avila",990.5,"refituqwe",2,1,OCUPADO}};
	for(int i=0; i<7;i++)
	{
		passengerList[i] = auxiliar[i];
	}
}
