

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"
#define VACIO -1
#define OCUPADO 0
int initPassengers(Passenger* list, int len)
{
	int retorno = 0;
	int i;

	if(list != NULL && len > 0)
	{
		for(i = 0;i < len;i++)
			{
			list[i].isEmpty = VACIO;

			}
	}
	else
	{
		retorno = 1;
	}

	return retorno;
}
int initStatusFlightAndTypePassenger(StatusFlightAndTypePassenger* statusType, int len)
{
	int retorno = -1;
	if (statusType != NULL)
	{
		if (len >= 0)
		{
			statusType[0].statusFlight = 1;
			strcpy(statusType[0].descriptionSF, "ACTIVO");
			statusType[0].typePassenger = 1;
			strcpy(statusType[0].descriptionTP, "Primera Clase");

			statusType[1].statusFlight = 2;
			strcpy(statusType[1].descriptionSF, "INACTIVO");
			statusType[1].typePassenger = 2;
			strcpy(statusType[1].descriptionTP, "Clase Económica");

			statusType[2].statusFlight = 3;
			strcpy(statusType[2].descriptionSF, "DEMORADO");
			statusType[2].typePassenger = 3;
			strcpy(statusType[2].descriptionTP, "Clase Turista");

			retorno = 0;
		}
	}
	return retorno;
}
int addPassenger(Passenger* list,int len,int id,char name[],char lastName[],float price,int typePassenger,char flycode[],int statusFlight)
{

	int i;
	int retorno = 1;

	for(i = 0;i < len;i++)
	{
		if(list[i].isEmpty == -1)
		{
			list[i].id = id;
			list[i].price = price;
			list[i].typePassenger = typePassenger;
			strcpy(list[i].name, name);
			strcpy(list[i].lastname, lastName);
			strcpy(list[i].flycode, flycode);
			retorno = 0;
		}
	}
	return retorno;
}

int findPassengerId(Passenger* list,int len, int id)
{
	int retorno = -1;
	if(list != NULL && len > 0)
	{
		for(int i = 0;i < len;i++)
			{
				if(list[i].id == id && list[i].isEmpty == VACIO)
				{
					retorno = i;
				}
			}
	}

	return retorno;
}

//int modificacionPasajero(Passenger* list,int len)
//{
//	int retorno = 0;
//	int idPedida;
//	int indice;
//	char auxNombre[51];
//	char auxApellido[51];
//	float precio;
//	char auxCodigoVuelo[10];
//	int auxTipoPasajero;
//
//	if(list != NULL && len > 0)
//	{
//
//	}
//}
//int mostrarPasajeros(Passenger* list,int len)
//{
//	if(list != NULL && len > 0)
//	{
//		for(int i = 0; i < len;i++)
//			{
//
//			}
//	}
//
//}
int modificarPasajero(Passenger* list, int len, int indice, int opcion)
{
		int retorno = -1;
		char nuevoNombre[51];
		float nuevoPrecio;
		int nuevoTipoPasajero;

		if (list != NULL)
		{
			if (len >= 0)
			{
				switch(opcion)
				{
					case 1:
						utn_getName(nuevoNombre, "Ingrese el nuevo nombre del pasajero: ",
								"Error. Ingrese correctamente el nombre.\n");
						strcpy(list[indice].name, nuevoNombre );
						break;
					case 2:
						utn_getName(nuevoNombre, "Ingrese el nuevo apellido del pasajero: ",
								"Error. Ingrese correctamente el apellido.\n");
						strcpy(list[indice].lastname, nuevoNombre);
						break;
					case 3:
						utn_getFloat(&nuevoPrecio, "Ingrese el nuevo precio del vuelo: ",
								"Error. Ingrese un dato valido.\n", 1, 999999999999999);
						list[indice].price = nuevoPrecio;
						break;
					case 4:
						utn_getInt(&nuevoTipoPasajero, "Ingrese 1 si es Primera Clase, 2 si es Clase Economica"
								", 3 si es Clase Turista: ",	"Error. Ingrese una opción valida.\n", 1, 3);
						list[indice].typePassenger = nuevoTipoPasajero;
						break;
					default:
						pedirCodigoDeVuelo(list[indice].flycode, "Ingrese el nuevo codigo de vuelo: ");
				}
				retorno = 0;
			}
		}
		return retorno;
}
int removePassenger(Passenger* list, int len, int id)
{
	int retorno = -1;
	if(list != NULL)
	{
		if(len >= 0)
		{
			list[id].isEmpty = VACIO;
			retorno = 0;
		}
	}
	return retorno;
}
int sortPassengersByLastName(Passenger* list, int len, int order)
{
	Passenger auxiliar;
	int retorno = -1;

	if (list != NULL)
		{
			if (len >= 0)
			{
				if (order == 1)
				{
					for (int i = 0; i < len; i++)
					{
						for(int j = i + 1; j < len - 1; j++)
						{
							if (strcmp(list[i].lastname, list[j].lastname) > 0)
							{
								auxiliar = list[j];
								list[j] = list[i];
								list[i] = auxiliar;
							}
							if(strcmp(list[i].lastname, list[j].lastname) == 0)
							{
								if(list[i].typePassenger > list[j].typePassenger)
								{
									auxiliar = list[j];
									list[j] = list[i];
									list[i] = auxiliar;
								}
							}
						}
					}
				}
				else
				{
					for (int i = 0; i < len; i++)
					{
						for(int j = i + 1; j < len - 1; j++)
						{
							if (strcmp(list[i].lastname, list[j].lastname) < 0)
							{
								auxiliar = list[j];
								list[j] = list[i];
								list[i] = auxiliar;
							}
							if(strcmp(list[i].lastname, list[j].lastname) == 0)
							{
								if(list[i].typePassenger > list[j].typePassenger)
								{
									auxiliar = list[j];
									list[j] = list[i];
									list[i] = auxiliar;
								}
							}
						}
					}
				}
				retorno = 0;
			}
		}

	return retorno;
}
int ordenamientoPasajeroXCodigo(Passenger* list, int len, int order)
{
	Passenger auxiliar;
	int retorno = -1;

	if (list != NULL)
		{
			if (len >= 0)
			{
				if (order == 1)
				{
					for (int i = 0; i < len; i++)
					{
						for(int j = i + 1; j < len - 1; j++)
						{
							if (strcmp(list[i].flycode, list[j].flycode) > 0)
							{
								auxiliar = list[j];
								list[j] = list[i];
								list[i] = auxiliar;
							}
							if(strcmp(list[i].flycode, list[j].flycode) == 0)
							{
								if(list[i].statusFlight > list[j].statusFlight)
								{
									auxiliar = list[j];
									list[j] = list[i];
									list[i] = auxiliar;
								}
							}
						}
					}
				}
				else
				{
					for (int i = 0; i < len; i++)
					{
						for(int j = i + 1; j < len - 1; j++)
						{
							if (strcmp(list[i].flycode, list[j].flycode) < 0)
							{
								auxiliar = list[j];
								list[j] = list[i];
								list[i] = auxiliar;
							}
							if(strcmp(list[i].flycode, list[j].flycode) == 0)
							{
								if(list[i].statusFlight > list[j].statusFlight)
								{
									auxiliar = list[j];
									list[j] = list[i];
									list[i] = auxiliar;
								}
							}
						}
					}
				}
				retorno = 0;
			}
		}

	return retorno;
}
int printPassenger(Passenger* list, StatusFlightAndTypePassenger* statusType ,int length, int lenStatusType)
{
	int retorno = -1;
	int i;

	if (list != NULL)
	{
		if (length >= 0)
		{
			printf("\nID     Nombre \t\t Apellido \t    Precio \t Codigo de Vuelo\tTipo de Pasajero \tEstado del vuelo\n");
			for (i = 0; i < length; i++)
			{
				if(list[i].isEmpty == OCUPADO)
				{
					for(int j = 0; j < lenStatusType; j++)
					{
						if(list[i].statusFlight == statusType[j].statusFlight)
						{
							for(int k = 0; k < lenStatusType; k++)
							{
								if(list[i].typePassenger == statusType[k].typePassenger)
								{
									printf("%-6d %-17s %-18s %-12.2f %-22s %-23s %s\n", list[i].id, list[i].lastname, list[i].name,
												list[i].price, list[i].flycode, statusType[k].descriptionTP, statusType[j].descriptionTP);
									break;
								}
							}
							break;
						}
					}
					retorno = 0;
				}
			}
		}
	}

	return retorno;
}
int averagePassenger(Passenger* list, int len, float* totalPrice, float* average)
{
	int retorno = -1;
	int contador = 0;
	float TotalPrice;

	if(list != NULL)
	{
		if(len > 0)
		{
			for(int i = 0; i < len; i++)
			{
				if(list[i].isEmpty == OCUPADO && list[i].price >= 0)
				{
					contador++;
					TotalPrice+= list[i].price;
					retorno = 0;
				}
			}
		}
	}
	*average = TotalPrice / contador;
	*totalPrice = TotalPrice;

	return retorno;
}
int cantidadEncimaPromedioPasajeros(Passenger* list, int len, float promedio)
{
	int retorno = -1;
	int contador = 0;

	if(list != NULL)
	{
		if(len > 0)
		{
			for(int i = 0; i < len; i++)
			{
				if(list[i].isEmpty == OCUPADO && list[i].price > promedio)
				{
					contador++;
					retorno = contador;
				}
			}
		}
	}

	return retorno;
}
