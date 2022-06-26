

#ifndef FUNCIONES_UTN_H_
#define FUNCIONES_UTN_H_

int utn_getName(char* cadena,char* mensaje,char* mensajeError);

int getFloat(float *Resultado);

int utn_getFloat(float *Resultado, char *mensaje,char *mensajeError,float minimo,float maximo);

int utn_getInt(int *Resultado, char *mensaje, char *mensajeError, int minimo, int maximo);

int getInt(int* Resultado);

void pedirCodigoDeVuelo(char codigoDeVuelo[10], char* mensaje);

int verificaCadNumeros(char* cadena);

int myGets(char* cadena, int len);

#endif /* FUNCIONES_UTN_H_ */


