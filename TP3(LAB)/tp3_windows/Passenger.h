#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#define TAM_CHAR 40
#define TAM_OTROSDATOS 45

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[TAM_CHAR];
	char apellido[TAM_CHAR];
	float precio;
	int tipoPasajero;
	char codigoVuelo[TAM_OTROSDATOS];
	char estadoVuelo[TAM_OTROSDATOS];

}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* tipoPasajeroStr,char* codigoVueloStr,char* estadoVueloStr);

void Passenger_delete(Passenger* this);

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo);


void Passenger_printOne(Passenger* this);

int Passenger_find(LinkedList* this,int id);

int Passenger_sortById(void* primerPasajero,void* segundoPasajero);

int Passenger_sortByApellido(void* primerPasajero,void* segundoPasajero);

int Passenger_sortByTipoPasajero(void* primerPasajero, void* segundoPasajero);

int Passenger_sortByCodigoVuelo(void* primerPasajero, void* segundoPasajero);



#endif /* PASSENGER_H_ */
