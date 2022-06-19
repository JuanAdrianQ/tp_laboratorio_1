#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#define TAM_NOMBRE 40
#define TAM_OTROSDATOS 45


Passenger* Passenger_new()
{
	Passenger* unPasajero;


	unPasajero = (Passenger*)malloc(sizeof(Passenger));


	return unPasajero;
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* tipoPasajeroStr,char* codigoVueloStr,char* estadoVueloStr)
{

	Passenger* unPasajero;
	unPasajero = Passenger_new();

	if(unPasajero != NULL)
	{
		if(Passenger_setId(unPasajero,atoi(idStr))== 0)
		{
			if(Passenger_setNombre(unPasajero,nombreStr)== 0)
			{
				if(Passenger_setApellido(unPasajero,apellidoStr)== 0)
				{
					if(Passenger_setPrecio(unPasajero,atof(precioStr))== 0)
					{
						if(Passenger_setTipoPasajero(unPasajero,atoi(tipoPasajeroStr))== 0)
						{
							if(Passenger_setCodigoVuelo(unPasajero,codigoVueloStr)==0)
							{
								if(Passenger_setEstadoVuelo(unPasajero,estadoVueloStr)==0)
								{
									return unPasajero;
								}
							}
						}

					}
				}
			}
		}
	}


	return unPasajero;

}
void Passenger_delete(Passenger* this)
{
	if(this != NULL)
	{
		free(this);
	}
}
int Passenger_setId(Passenger* this,int id)
{
	int retorno = -1;

	if(this != NULL && id > 0)
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}
int Passenger_getId(Passenger* this,int* id)
{
	int retorno = -1;

	if(this != NULL && id > 0)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}
int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this -> nombre,nombre);
		retorno = 0;
	}

	return retorno;
}
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		retorno = 0;
	}

	return retorno;
}
int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno = -1;

	if(this != NULL && apellido != NULL)
	{
		strcpy(this -> apellido,apellido);
		retorno = 0;
	}

	return retorno;
}
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno = -1;

	if(this != NULL && apellido != NULL)
	{
		strcpy(apellido,this->apellido);
		retorno = 0;
	}

	return retorno;
}
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;

	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(this -> codigoVuelo,codigoVuelo);
		retorno = 0;
	}


	return retorno;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;

	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(codigoVuelo,this->codigoVuelo);
		retorno = 0;
	}

	return retorno;
}
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int retorno = -1;

	if(this != NULL)
	{
		this->tipoPasajero = tipoPasajero;
		retorno = 0;
	}

	return retorno;
}
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int retorno = -1;

	if(this != NULL && tipoPasajero > 0)
	{
		*tipoPasajero = this->tipoPasajero;
		retorno = 0;
	}

	return retorno;
}
int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno = -1;

	if(this != NULL && precio > 0)
	{
		this->precio = precio;
		retorno = 0;
	}
	return retorno;
}
int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno = -1;

	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		retorno = 0;
	}
	return retorno;
}
int Passenger_setEstadoVuelo(Passenger *this,char *estadoVuelo)
{
	int retorno = -1;

	if(this != NULL && estadoVuelo != NULL)
	{
		strcpy(this->estadoVuelo,estadoVuelo);
		retorno = 0;
	}


	return retorno;
}
int Passenger_getEstadoVuelo(Passenger *this,char *estadoVuelo)
{
	int retorno = -1;

	if(this != NULL && estadoVuelo != NULL)
	{
		strcpy(estadoVuelo,this->estadoVuelo);
		retorno = 0;
	}

	return retorno;
}


void Passenger_printOne(Passenger* this)
{
	if(this != NULL)
	{
		int idPasajero;
		char nombrePasajero[TAM_NOMBRE];
		char apellidoPasajero[TAM_NOMBRE];
		float precio;
		int tipoPasajero;
		char tipoPasajeroChar[TAM_OTROSDATOS];
		char codigoVuelo[TAM_OTROSDATOS];
		char estadoVuelo[TAM_OTROSDATOS];

		if(Passenger_getId(this,&idPasajero)== 0)
		{
			if(Passenger_getNombre(this,nombrePasajero)== 0)
			{
				if(Passenger_getApellido(this,apellidoPasajero)==0)
				{
					if(Passenger_getPrecio(this,&precio)==0)
					{
						if(Passenger_getCodigoVuelo(this,codigoVuelo)==0)
						{
							if(Passenger_getEstadoVuelo(this,estadoVuelo)==0)
							{
								if(Passenger_getTipoPasajero(this,&tipoPasajero)==0)
								{
									if(tipoPasajero == 1)
									{
										strcpy(tipoPasajeroChar, "FirstClass");
									}
									else
									{
										if(tipoPasajero == 2)
										{
											strcpy(tipoPasajeroChar, "ExecutiveClass");
										}
										else
										{
											strcpy(tipoPasajeroChar, "EconomyClass");
										}

									}
									printf("%-10d %-15s %-15s %-15.2f %-15s %-15s %-15s\n",idPasajero,nombrePasajero,apellidoPasajero,precio,codigoVuelo,tipoPasajeroChar,estadoVuelo);

								}
							}

						}
					}
				}
			}
		}



	}

}
int Passenger_find(LinkedList* this,int id)
{
	int retorno = -1;
	int lenLinked;
	Passenger* pasajeroReemplazo;
	if(this != NULL && id > 0)
	{
		lenLinked = ll_len(this);
		for(int i = 0;i < lenLinked;i++)
		{
			pasajeroReemplazo = ll_get(this,i);
			if(pasajeroReemplazo->id == id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
int Passenger_sortById(void* primerPasajero,void* segundoPasajero)
{
	int retorno = -1;
	int idPrimerPasajero;
	int idSegundoPasajero;

	if(primerPasajero != NULL && segundoPasajero != NULL)
	{
		if(Passenger_getId(primerPasajero,&idPrimerPasajero)==0)
		{
			if(Passenger_getId(segundoPasajero,&idSegundoPasajero)==0)
			{
				if(idPrimerPasajero > idSegundoPasajero)
				{
					retorno = 1;
				}
				else
				{
					retorno = -1;
				}
			}

		}
	}

	return retorno;
}
int Passenger_sortByApellido(void* pasajeroUno, void* pasajeroDos)
{
	int retorno = -1;
	char apellidoAuxUno[TAM_NOMBRE];
	char nombreAuxUno[TAM_NOMBRE];
	char apellidoAuxDos[TAM_NOMBRE];
	char nombreAuxDos[TAM_NOMBRE];

	if(pasajeroUno != NULL && pasajeroDos != NULL)
	{
		if(Passenger_getApellido(pasajeroUno, apellidoAuxUno) == 0)
		{
			if(Passenger_getApellido(pasajeroDos, apellidoAuxDos) == 0)
			{
				retorno = strcmp(apellidoAuxUno, apellidoAuxDos);
				if(retorno == 0)
				{
					if(Passenger_getNombre(pasajeroUno, nombreAuxUno) == 0)
					{
						if(Passenger_getNombre(pasajeroDos, nombreAuxDos) == 0)
						{
							retorno = strcmp(nombreAuxUno, nombreAuxDos);
							if(retorno == 0)
							{
								retorno = Passenger_sortById(pasajeroUno, pasajeroDos);
							}
						}
					}
				}
			}
		}
	}

	return retorno;
}
int Passenger_sortByTipoPasajero(void* primerPasajero, void* segundoPasajero)
{
	int retorno = -1;
	int tipoPasajeroUno;
	int tipoPasajeroDos;

	if(primerPasajero != NULL && segundoPasajero != NULL)
	{
		if(Passenger_getTipoPasajero(primerPasajero, &tipoPasajeroUno) == 0)
		{
			if(Passenger_getTipoPasajero(segundoPasajero, &tipoPasajeroDos) == 0)
			{
				if(tipoPasajeroUno > tipoPasajeroDos)
				{
					retorno = 1;
				}
				else
				{
					if(tipoPasajeroDos > tipoPasajeroUno)
					{
						retorno = -1;
					}
					else
					{
						retorno = Passenger_sortByApellido(primerPasajero, segundoPasajero);
					}
				}
			}
		}
	}

	return retorno;
}
int Passenger_sortByCodigoVuelo(void* primerPasajero, void* segundoPasajero)
{
	int retorno = -1;
	char codigoVueloAuxUno[TAM_CHAR];
	char codigoVueloAuxDos[TAM_CHAR];

	if(primerPasajero != NULL && segundoPasajero != NULL)
	{
		if(Passenger_getCodigoVuelo(primerPasajero, codigoVueloAuxUno) == 0)
		{
			if(Passenger_getCodigoVuelo(segundoPasajero, codigoVueloAuxDos) == 0)
			{
				retorno = strcmp(codigoVueloAuxUno, codigoVueloAuxDos);
				if(retorno == 0)
				{
					retorno = Passenger_sortByApellido(primerPasajero, segundoPasajero);
				}
			}
		}
	}

	return retorno;
}
