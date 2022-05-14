
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"
#include "Funciones_UTN.h"
#define VACIO -1
#define OCUPADO 0
#define CANT_ELEM 2000
#define CANT_MAX_TIPO 3

int main(void)
{
	setbuf(stdout, NULL);

	Passenger arrayPasajeros[CANT_ELEM];

	int idPasajero = 0;
	char nombrePasajero[51];
	char apellidoPasajero[51];
	float precio;
	int tipoPasajero;
	char flycode[10];
	int estadoVuelo;
	int opcion;
	int opcionMenu;
	int indiceModificar;
	int opcionIDModificar;
	int opcionIdBaja;
	int indiceBaja;
	int opcionMenuInformar;
	float precioTotal;
	float precioPromedio;
	int cantidadDePasajerosPorEncimaPromedio;

	initPassengers(arrayPasajeros,CANT_ELEM);
	StatusFlightAndTypePassenger estadoVueloYTipoPasajero[CANT_MAX_TIPO];

	do
	{
		printf("\n1-Ingresar pasajero\n"
				"2-Modificar pasajero\n"
				"3-Eliminar pasajero\n"
				"4-Informar pasajeros\n"
				"5-Carga forzada de pasajeros\n"
				"6-Salir\n"
				"Ingrese una opcion: ");
		scanf("%d",&opcion);
		fflush(stdin);


		switch(opcion)
		{
			case 1:
				idPasajero++;

				utn_getName(nombrePasajero,"Ingrese el nombre del pasajero: ","Error.Ingrese un nombre valido: ");

				utn_getName(apellidoPasajero,"Ingrese el apellido del pasajero: ","Error.Ingrese un apellido valido: ");

				utn_getFloat(&precio,"Ingrese el precio del vuelo: ","Error.Ingrese un precio valido: ",1,9999999999);

				utn_getInt(&tipoPasajero,"Ingrese 1 si es de Primera lase, 2 si es Clase Economica, 3 si es Clase Turista: ",
						"Error. Ingrese una opcion valida.\n", 1, 3);

				pedirCodigoDeVuelo(flycode,"Ingrese el codigo de vuelo: ");

				utn_getInt(&estadoVuelo,"Ingrese 1 si el vuelo esta Activo, 2 si esta Inactivo, 3 si esta Demorado: ",
				"Error. Ingrese una opcion valida.\n",1,3);


				 if(addPassenger(arrayPasajeros,CANT_ELEM,idPasajero,nombrePasajero,apellidoPasajero,precio,tipoPasajero,flycode,estadoVuelo) == 0)
				 {
					 printf("Se ha agregado un pasajero al sistema");
				 }
				 else
				 {
					 printf("Se ha producido un error al intentar agregar al pasajero");
				 }
				break;
			case 2:
				do
				{
					printf("\nMenu de modificaciones de pasajero:\n"
							"1.Nombre\n"
							"2.Applied\n"
							"3.Precio\n"
							"4.Tipo de pasajero\n"
							"5.Codigo de vuelo\n"
							"Escoja una opcion: ");
					fflush(stdin);
					scanf("%d",&opcionMenu);
				   switch(opcionMenu)
				   {
				   case 1:
				   case 2:
				   case 3:
				   case 4:
				   case 5:
					   printf("Indique la ID del pasajero a modificar: ");
					   fflush(stdin);
					   scanf("%d", &opcionIDModificar);
					   indiceModificar = findPassengerId(arrayPasajeros,CANT_ELEM,opcionIDModificar);
					   if(indiceModificar > -1)
					   {
						   if(modificarPasajero(arrayPasajeros,CANT_ELEM,indiceModificar,opcionIDModificar)== 0)
						   {
							   printf("Se ha modificado al pasajero con exito.");
						   }
						   else
						   {
							   printf("Hubo un error al intentar modificar al pasajero.");
						   }
					   }
					   else
					   {
						   printf("El ID ingresado no coincide con el de ningun pasajero.");
					   }
					   break;
				   default:
					   printf("Elija una opcion valida.");
					   break;
				   }
				}while(opcionMenu != 5);
				break;
			case 3:
				printf("Ingrese el ID del pasajero que quiere dar de baja: ");
				fflush(stdin);
				scanf("%d",&opcionIdBaja);
				indiceBaja = findPassengerId(arrayPasajeros,CANT_ELEM,opcionIdBaja);
				if(indiceBaja > -1)
				{
					if(removePassenger(arrayPasajeros,CANT_ELEM,indiceBaja) == 0)
					{
						printf("Se dio de baja el pasajero con exito.");
					}
					else
					{
						printf("Ocurrio un error al dar de baja el pasajero.");
					}
				}
				else
				{
					printf("El ID ingresado no coincide con ningun pasajero.");
				}
				break;
			case 4:
				do
				{
					printf("\nMenu para informar pasajeros:\n"
							"1.Listado de los pasajeros ordenados alfabeticamente por Apellido y Tipo de pasajero.\n"
							"2.Total y promedio de los precios de los pasajes,y cuantos pasajeros superan el precio promedio.\n"
							"3.Listado de los pasajeros por Codigo de vuelo y estados de vuelos 'ACTIVO'\n"
							"4.Volver al menu principal\n"
							"Elija una opcion: ");
					fflush(stdin);
					scanf("%d",&opcionMenuInformar);
					switch(opcionMenuInformar)
					{
					case 1:
						if(sortPassengersByLastName(arrayPasajeros,CANT_ELEM, 1) == 0)
						{
							printPassenger(arrayPasajeros,estadoVueloYTipoPasajero,CANT_ELEM,CANT_MAX_TIPO);
						}
						break;
					case 2:
						if(averagePassenger(arrayPasajeros,CANT_ELEM ,&precioTotal, &precioPromedio) == 0)
						{
							cantidadDePasajerosPorEncimaPromedio = cantidadEncimaPromedioPasajeros(arrayPasajeros, CANT_ELEM,precioPromedio);
							printf("\nEl precio total de todos los vuelos fue de $%.2f.\nEn promedio cada pasajero pago$%.2f."
							"\nEn total hay %d pasajeros que paga por encima del promedio.\n", precioTotal, precioPromedio, cantidadDePasajerosPorEncimaPromedio);
						}
						else
						{
							printf("\nOcurrio un error al intentar mostrar la informacion.\n");
						}
						break;
					case 3:
						if(ordenamientoPasajeroXCodigo(arrayPasajeros, CANT_ELEM, 1) == 0)
						{
							if(printPassenger(arrayPasajeros, estadoVueloYTipoPasajero ,CANT_ELEM, CANT_MAX_TIPO) != 0)
							{
								printf("\nLa lista de pasajeros esta vacia.\n");
							}
						}
						else
						{
							printf("\nHubo un error al intentar ordenar los pasajeros por codigo de vuelo.\n");
						}
						break;
					case 4:
						printf("\nRegresando al menu principal.\n");
						break;
					default:
						printf("\nElija una opcion valida.\n");
						break;
					}
				}while(opcionMenuInformar != 4);
				break;
			case 6:
				printf("\nFin del sistema.\n");
				break;
			default:
				printf("\nElija una opcion valida.\n");

		}
	}while(opcion != 6);

	return EXIT_SUCCESS;
}


