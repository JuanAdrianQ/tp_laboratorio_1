#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#define TAM_CHAR 40
#define TAM_OTROSDATOS 45

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		char id[TAM_CHAR];
		char nombre[TAM_CHAR];
		char apellido[TAM_CHAR];
		char precio[TAM_CHAR];
		char estado[TAM_CHAR];
		char tipoPasajero[TAM_CHAR];
		char codigo[TAM_CHAR];
		Passenger* unPasajero;


		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, apellido, precio, codigo, tipoPasajero, estado);
		while(1)
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, apellido, precio, codigo, tipoPasajero, estado)== 7)
			{
				if(strcmp(tipoPasajero,"FirstClass")==0)
				{
					strcpy(tipoPasajero,"1");
				}
				else
				{
					if(strcmp(tipoPasajero,"ExecutiveClass")==0)
					{
						strcpy(tipoPasajero,"2");
					}
					else
					{
						strcpy(tipoPasajero,"3");
					}
				}
				unPasajero = Passenger_newParametros(id,nombre,apellido,precio,tipoPasajero,codigo,estado);

				if(unPasajero != NULL)
				{
					ll_add(pArrayListPassenger,unPasajero);
					retorno = 0;
				}

			}
			if(feof(pFile) != 0)
			{
				break;
			}

		}
	}

    return retorno;

}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		while(1)
		{
			Passenger* pasajeroAux = Passenger_new();
			if(pasajeroAux != NULL)
			{
				if(fread(pasajeroAux,sizeof(Passenger),1,pFile)!=0)
				{
					ll_add(pArrayListPassenger,pasajeroAux);

				}
				retorno = 0;
			}
			if(feof(pFile)!= 0)
			{
				break;
			}
		}
	}

	return retorno;
}
