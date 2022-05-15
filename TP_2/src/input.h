#ifndef INPUT_H_
#define INPUT_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/// @brief pide una cadena y envia un mensaje
///
/// @param cadena
/// @param mensaje
void getString(char cadena[],char mensaje[]);

/// @brief pide un numero entero y envia un mensaje
///
/// @param mensaje
/// @return
int PedirEntero (char mensaje[]);

/// @brief pide un numero flotante y envia un mensaje
///
/// @param mensaje
/// @return
float PedirFlotante (char mensaje[]);

#endif /* INPUT_H_ */
