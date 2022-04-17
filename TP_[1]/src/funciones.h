#ifndef FUNCIONES_H_
#define FUNCIONES_H_

int primerMenu();
/** \brief Muestra un menu con las opciones principales.
 *
 * \return int. El numero de la opcion seleccionada (de 1 a 6).
 */

int pedirKilometros();
/** \brief Pide al usuario que ingrese los kilometros del vuelo.
 *
 * \return int. La distancia del vuelo en km.
 */

int pedirPrecioAerolineas();
/** \brief Pide al usuario que ingrese el precio descripto por Aerolineas Argentinas.
 *
 * \return float. El costo de un vuelo por aerolineas argentinas.
 */

int pedirPrecioLatam();
/** \brief Pide al usuario que ingrese el precio descripto por Latam.
 *
 * \return float. El costo de un vuelo por Latam.
 */

float calculoPago(float precio, float multiplicador);
/** \brief Calcula un precio final aplicando descuento, interes o conversion.
 *
 *	\param precio float. El precio base.
 *	\param multiplicador float. El valor por el cual se multiplica al base para obtener el precio final.
 *	\return float. El precio final de la operacion.
 */

float calculoUnitario(float precio, int km);
/** \brief Calcula el precio unitario de cada kilometro de vuelo.
 *
 * \param float precio. El precio del vuelo.
 * \param int km. La distancia del vuelo en km.
 * \return float. El precio de cada kilometro de vuelo.
 */

float calculoDiferencia(float precio1, float precio2);
/** \brief Calcula la diferencia de precio entre ambas empresas (AA y Latam).
 *
 * \param float precio1. El costo de vuelo en una de las empresas.
 * \param float precio2. El costo de vuelo en la otra empresa.
 * \return float. La diferencia entre los precios.
 */

void calculaTodo(	int kilometros, float precioAerolineas, float precioLatam,
					float multiplicadorCredito, float multiplicadorDebito, float bitcoin,
					float *aerolineasCredito, float *aerolineasDebito, float *aerolineasBitcoin,
					float *aerolineasUnitario, float *latamCredito, float *latamDebito,
					float *latamBitcoin, float *latamUnitario, float *diferencia);
/** \brief Utiliza las funciones anteriores, calcula los datos y guarda sus valores en las variables correspondientes.
 *
 * \param int kilometros. La distancia del vuelo.
 * \param float precioAerolineas. El precio de un vuelo por Aerolineas Argentinas.
 * \param float precioLatam. El precio de un vuelo por Latam.
 * \param float multiplicadorCredito. El valor del aumento o descuento que se aplica por pagar con tarjeta de credito.
 * \param float multiplicadorDebito. El valor del aumento o descuento que se aplica por pagar con tarjeta de debito.
 * \param float bitcoin. El valor actual de un bitcoin en AR$.
 */
void muestraTodo(	int kilometros, float precioAerolineas, float precioLatam,
					float multiplicadorCredito, float multiplicadorDebito, float bitcoin,
					float aerolineasCredito, float aerolineasDebito, float aerolineasBitcoin,
					float aerolineasUnitario, float latamCredito, float latamDebito,
					float latamBitcoin, float latamUnitario, float diferencia);
/** \brief Muestra en pantalla Todos los datos de distancia, costos y diferencia.
 *
 * \param int kilometros. La distancia del vuelo.
 * \param float precioAerolineas. El precio de un vuelo por Aerolineas Argentinas.
 * \param float precioLatam. El precio de un vuelo por Latam.
 * \param float multiplicadorCredito. El valor del aumento o descuento que se aplica por pagar con tarjeta de credito.
 * \param float multiplicadorDebito. El valor del aumento o descuento que se aplica por pagar con tarjeta de debito.
 * \param float bitcoin. El valor actual de un bitcoin en AR$.
 * \param float aerolineasCredito. El precio final por AA pagando con tarjeta de credito.
 * \param float aerolineasDebito. El precio final por AA pagando con tarjeta de debito.
 * \param float aerolineasBitcoin. El precio final por AA pagando con bitcoins (en unidades de bitcoin).
 * \param float aerolineasUnitario. El valor de cada km de vuelo segun el precio de AA.
 * \param float latamCredito. El precio final por Latam pagando con tarjeta de credito.
 * \param float latamDebito. El precio final por Latam pagando con tarjeta de debito.
 * \param float latamBitcoin. El precio final por Latam pagando con bitcoins (en unidades de bitcoin).
 * \param float latamUnitario. El valor de cada km de vuelo segun el precio de Latam.
 * \param float diferencia. La diferencia entre los precios del vuelo segun AA y Latam.
 */

#endif /* FUNCIONES_H_ */
