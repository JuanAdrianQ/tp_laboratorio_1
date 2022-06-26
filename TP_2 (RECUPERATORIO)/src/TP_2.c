/*Enunciado: Una aerolínea requiere un sistema para administrar los pasajeros de cada vuelo. Se sabe que
no puede tener más de 2000 pasajeros.
El sistema deberá tener el siguiente menú de opciones:

1. ALTAS: Se debe permitir ingresar un pasajero calculando automáticamente el
número de Id. El resto de los campos se le pedirá al usuario.
2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
o Precio o Tipo de pasajero o Código de vuelo
3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
4. INFORMAR:
1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.
2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio
promedio.
3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’


1-NOTA: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la
carga de algún pasajero.
2-NOTA: Es deseable generar una segunda entidad y utilizarla en el programa.
*/


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
	StatusFlightAndTypePassenger estadoVueloYTipoPasajero[CANT_MAX_TIPO];
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
	int ControladorPasajero = 0;
	int contadorCargaForzada = 0;

	if(initPassengers(arrayPasajeros,CANT_ELEM)==0)
	{
		printf("\nSe inicializaron los pasajeros correctamente.\n");
	}
	else
	{
		printf("\nHubo un error al intentar inicializar los pasajeros.\n");
	}
	if(initStatusFlightAndTypePassenger(estadoVueloYTipoPasajero, CANT_MAX_TIPO) != 0)
	{
		printf("\nError al inicializar la estructura StatusFlightAndTypePassenger.\n");
	}

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

				utn_getName(nombrePasajero,"\nIngrese el nombre del pasajero: ","Error.Ingrese un nombre valido: ");

				utn_getName(apellidoPasajero,"Ingrese el apellido del pasajero: ","Error.Ingrese un apellido valido: ");

				utn_getFloat(&precio,"Ingrese el precio del vuelo: ","Error.Ingrese un precio valido: ",1,9999999999);

				pedirCodigoDeVuelo(flycode,"Ingrese el codigo de vuelo: ");

				utn_getInt(&tipoPasajero,"Ingrese su tipo de pasajero(1-Si es Primera Clase,2- Si es Clase Economica,3- Si es Clase Turista): ",
										"Error. Ingrese una opcion valida.\n", 1, 3);

				utn_getInt(&estadoVuelo,"Ingrese su tipo de estado de vuelo(1- Si es Activo,2- Si es Inactivo,3- Si esta Demorado): ",
				"Error. Ingrese una opcion valida.\n",1,3);

				 if(addPassenger(arrayPasajeros,CANT_ELEM,idPasajero,nombrePasajero,apellidoPasajero,precio,tipoPasajero,flycode,estadoVuelo) == 0)
				 {
					 printf("\nSe ha agregado un pasajero al sistema\n");
					 ControladorPasajero++;
				 }
				 else
				 {
					 printf("\nSe ha producido un error al intentar agregar al pasajero\n");
				 }
				break;
			case 2:
				if(ControladorPasajero > 0)
				{
					do
					{
						printf("\nMenu de modificaciones de pasajero:\n"
								"1.Nombre\n"
								"2.Apellido\n"
								"3.Precio\n"
								"4.Tipo de pasajero\n"
								"5.Codigo de vuelo\n"
								"6.Volver al menu principal\n"
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
						   if(modificarPasajero(arrayPasajeros,CANT_ELEM,indiceModificar,opcionMenu)== 0)
						   {
							   printf("\nSe ha modificado al pasajero con exito.\n");
						   }
						   else
						   {
							   printf("\nHubo un error al intentar modificar al pasajero.\n");
						   }
					   }
					   else
					   {
						   printf("\nEl ID ingresado no coincide con el de ningun pasajero.\n");
					   }
					   break;
					   case 6:
						   printf("\nVolviendo al menu principal.\n");
						   break;
					   }
					}while(opcionMenu != 6);
				}
				else
				{
					printf("\nDebe dar de alta un pasajero antes de modificar!!!\n");
				}
				break;
			case 3:
				if(ControladorPasajero > 0)
				{
					printf("Ingrese el ID del pasajero que quiere dar de baja: ");
					fflush(stdin);
					scanf("%d",&opcionIdBaja);
					indiceBaja = findPassengerId(arrayPasajeros,CANT_ELEM,opcionIdBaja);
					if(indiceBaja > -1)
					{
						if(removePassenger(arrayPasajeros,CANT_ELEM,indiceBaja) == 0)
						{
							printf("\nSe dio de baja el pasajero con exito.\n");
						}
						else
						{
							printf("\nOcurrio un error al dar de baja el pasajero.\n");
						}
					}
					else
					{
						printf("\nEl ID ingresado no coincide con ningun pasajero.\n");
					}
				}
				else{
					printf("\nPorfavor dé de alta un pasajero para poder acceder a esta opcion!!!\n");
				}
				break;
			case 4:
				if(ControladorPasajero > 0 || contadorCargaForzada > 0)
				{
					do
					{
						printf("\nMenu para informar pasajeros:\n\n"
								"1.Listado de los pasajeros ordenados alfabeticamente por Apellido y Tipo de pasajero.\n"
								"2.Total y promedio de los precios de los pasajes,y cuantos pasajeros superan el precio promedio.\n"
								"3.Listado de los pasajeros por Codigo de vuelo y estados de vuelos 'ACTIVO'\n"
								"4.Volver al menu principal\n"
								"\nElija una opcion: ");
						fflush(stdin);
						scanf("%d",&opcionMenuInformar);
						switch(opcionMenuInformar)
						{
						case 1:
							if(sortPassengersByLastName(arrayPasajeros,CANT_ELEM, 1) == 0)
							{
								printf("\nSe ordenaron los pasajeros por apellido y tipo de pasajero correctamente.\n");
								if(printPassenger(arrayPasajeros,estadoVueloYTipoPasajero,CANT_ELEM,CANT_MAX_TIPO)==0)
								{
									printf("\nSe listaron los pasajeros ordenados por apellido y tipo de pasajero correctamente.\n");
								}
								else
								{
									printf("\nHubo un error al intentar listar los pasajeros.\n");
								}
							}
							else{
								printf("\nHubo un error al intentar ordenar los pasajeros por apellido y tipo de pasajero.\n");
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
				}
				else
				{
					printf("\nDebe dar de alta un pasajero por lo menos para poder acceder a esta opcion!!!\n");
				}
				break;
			case 5://Forzar datos
				idPasajero++;
				addPassenger(arrayPasajeros,CANT_ELEM,idPasajero,"Adrian","Quiroz",12000.12,2,"FRKX-11",1);
				idPasajero++;
				addPassenger(arrayPasajeros,CANT_ELEM,idPasajero,"Pablo","Quiroz",20120.11,3,"SDKA-22",3);
				idPasajero++;
				addPassenger(arrayPasajeros,CANT_ELEM,idPasajero,"Ivan","Fernandez",60343.02,1,"PTKS-82",2);
				idPasajero++;
				addPassenger(arrayPasajeros,CANT_ELEM,idPasajero,"Gonzalo","Carvajal",81727.91,2,"FRKX-11",3);

				contadorCargaForzada++;
				printf("\nSe cargaron los datos forzados correctamente.\n");
				break;
			case 6:
				printf("\nCerrando el sistema...\n");
				break;
			default:
				printf("\nElija una opcion valida.\n");

		}
	}while(opcion != 6);

	return EXIT_SUCCESS;
}


