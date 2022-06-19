#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "utn.h"

#define TAM_CHAR 40
#define TAM_OTROSDATOS 45

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		FILE* pArchivo;

		pArchivo = fopen(path,"r");
		if(pArchivo != NULL)
		{
			if(parser_PassengerFromText(pArchivo,pArrayListPassenger)== 0)
			{
				retorno = 0;
			}

		}
		fclose(pArchivo);
	}
    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		FILE* pArchivo;

		pArchivo = fopen(path,"rb");

		if(pArchivo != NULL)
		{
			if(parser_PassengerFromBinary(pArchivo,pArrayListPassenger)== 0)
			{
				printf("Hola");
				retorno = 0;
			}
		}
		fclose(pArchivo);

	}

	return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;

	Passenger* unPasajero;
	int id;
	char idChar[TAM_OTROSDATOS];
	char nombrePasajero[TAM_CHAR];
	char apellidoPasajero[TAM_CHAR];
	char precioPasajero[TAM_OTROSDATOS];
	int  tipoPasajero;
	char tipoPasajeroChar[TAM_OTROSDATOS];
	char codigoVuelo[TAM_OTROSDATOS];
	int estadoVuelo;
	char estadoVueloChar[TAM_OTROSDATOS];
	int len;

	len = ll_len(pArrayListPassenger);
	id = len + 1;
	itoa(id,idChar,10);

	if(pArrayListPassenger != NULL)
	{
		if(utn_getString(nombrePasajero,"\nIngrese su nombre: ","Error.Ingrese un nombre valido.")== 0)
		{
			if(utn_getString(apellidoPasajero,"Ingrese su apellido: ","Error.Ingrese un apellido valido.")==0)
			{
				if(utn_getFloat(precioPasajero,"Ingrese el precio del vuelo: ","Error.Ingrese un precio valido.",1,999999999,5)==0)
				{
					if(utn_getNumero(&tipoPasajero,"Ingrese su tipo de pasajero (1. Si perteneceze a First Class, 2.Executive Class, 3. Economy Class) : ","Error.Ingrese un tipo valido.",1,3,5)==0)
					{
						switch(tipoPasajero)
						{
						case 1:
							strcpy(tipoPasajeroChar,"First Class");
							break;
						case 2:
							strcpy(tipoPasajeroChar,"Executive Class");
							break;
						case 3:
							strcpy(tipoPasajeroChar,"Economy Class");
							break;

						}

						if(utn_getString(codigoVuelo,"Ingrese su codigo de vuelo: ","Error.Ingrese un codigo de vuelo valido.")==0)
						{
							if(utn_getNumero(&estadoVuelo,"Ingrese su estado de vuelo(1.Si su vuelo esta Aterrizado,2. Si esta en Horario,3. Si esta en Vuelo,4.Si esta Demorado) : ","Error.Ingrese un estado de vuelo valido.",1,4,5)==0)
							{
								switch(estadoVuelo)
								{
								case 1:

									strcpy(estadoVueloChar,"Aterrizado");

									break;
								case 2:
									strcpy(estadoVueloChar,"En horario");
									break;
								case 3:
									strcpy(estadoVueloChar,"En vuelo");
									break;
								case 4:
									strcpy(estadoVueloChar,"Demorado");
									break;
								}

								unPasajero = Passenger_newParametros(idChar,nombrePasajero,apellidoPasajero,precioPasajero,tipoPasajeroChar,codigoVuelo,estadoVueloChar);

								if(unPasajero != NULL)
								{
									ll_add(pArrayListPassenger,unPasajero);
									retorno = 0;
								}
							}

						}

					}

				}
			}
		}
	}

 	return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;

	if(pArrayListPassenger != NULL)
	{
		int lenLinke;
		int id;
		int idAModificar;
		char nombre[TAM_CHAR];
		char apellido[TAM_CHAR];
		char precio[TAM_OTROSDATOS];
		char codigoVuelo[TAM_CHAR];
		int tipoPasajero;
		int estadoVuelo;
		char estadoVueloChar[TAM_CHAR];
		int menuOpcionesModificacion;
		Passenger* pasajeroReemplazo;

		lenLinke = ll_len(pArrayListPassenger);

		if(lenLinke > 0)
		{
			if(utn_getNumero(&id,"Ingrese el id del pasajero que desea modificar: ","Error.El id ingresado no es valido.",1,lenLinke,5)==0)
			{
				idAModificar = Passenger_find(pArrayListPassenger,id);
				if(idAModificar > 0)
				{
					pasajeroReemplazo = ll_get(pArrayListPassenger,idAModificar);

					if(pasajeroReemplazo != NULL)
					{
						printf("El pasajero que quiere modificar es: ");
						Passenger_printOne(pasajeroReemplazo);
						do
						{
							printf("\nMenu de opciones.Modificacion\n"
									"1-Nombre\n"
									"2-Apellido\n"
									"3-Precio de vuelo\n"
									"4-Tipo de pasajero\n"
									"5-Codigo de vuelo\n"
									"6-Estado de vuelo\n"
									"7-Guardar cambios\n"
									"Elija la opcion que desea modificar: ");
							scanf("%d",&menuOpcionesModificacion);
							switch(menuOpcionesModificacion)
							{
							case 1:
								if(utn_getString(nombre,"Ingrese su nuevo nombre: ","Error.Ingrese un nombre valido.")== 0)
								{
									if(Passenger_setNombre(pasajeroReemplazo,nombre)==0)
									{
											printf("\nEl nombre del pasajero fue modificado\n");
									}
									else
									{
										printf("\nNo se pudo modificar el nombre\n");
									}
								}
								break;
							case 2:
								if(utn_getString(apellido,"Ingrese su nuevo apellido: ","Error.Ingrese un apellido valido.")==0)
								{
									if(Passenger_setApellido(pasajeroReemplazo,apellido)==0)
									{
										printf("\nEl apellido del pasajero fue modificado\n");
									}
									else
									{
										printf("\nNo se pudo modificar el apellido del pasajero\n");
									}
								}
								break;
							case 3:
								if(utn_getFloat(precio,"Ingrese el nuevo precio: ","Error.Ingrese un precio valido.",1,9999999,5)==0)
								{
									if(Passenger_setPrecio(pasajeroReemplazo,atof(precio))==0)
									{
										printf("\nEl precio de vuelo fue modificado\n");
									}
									else
									{
										printf("\nNo se pudo modificar el precio de vuelo\n");
									}
								}
								break;
							case 4:
								if(utn_getNumero(&tipoPasajero,"Ingrese su nuevo tipo de pasajero(1- First Class,2- Executive Class,3- Economy Class: ","Error.Ingrese un tipo de pasajer valido",1,3,5)== 0)
								{
									if(Passenger_setTipoPasajero(pasajeroReemplazo,tipoPasajero)==0)
									{
										printf("\nEl tipo de pasajero fue modificado con exito\n");
									}
									else
									{
										printf("\nNo se pudo modificar el tipo de pasajero\n");
									}
								}
								break;
							case 5:
								if(utn_getString(codigoVuelo,"Ingrese el codigo de vuelo: ","Error.Ingrese un codigo de vuelo valido.")==0)
								{
									if(Passenger_setCodigoVuelo(pasajeroReemplazo,codigoVuelo)==0)
									{
										printf("\nEl codigo de vuelo a sido modificado con exito\n");
									}
									else
									{
										printf("\nNo se pudo modificar el codigo de vuelo\n");
									}
								}
								break;
							case 6:
								if(utn_getNumero(&estadoVuelo,"Ingrese su nuevo estado de vuelo(1- Aterrizado,2- En horario,3- En vuelo,-4 Demorado: ","Error.Ingrese un estado de vuelo valido.",1,4,5)==0)
								{
									switch(estadoVuelo)
									{
									case 1:
										strcpy(estadoVueloChar,"Aterrizado");
										break;
									case 2:
										strcpy(estadoVueloChar,"En horario");
										break;
									case 3:
										strcpy(estadoVueloChar,"En vuelo");
										break;
									case 4:
										strcpy(estadoVueloChar,"Demorado");
										break;
									}
									if(Passenger_setEstadoVuelo(pasajeroReemplazo,estadoVueloChar)== 0)
									{
										printf("\nEl estado de vuelo se modifico con exito\n");
									}
									else
									{
										printf("\nNo se pudo modificar el estado de vuelo\n");
									}
								}
								break;
							case 7:
								if(ll_set(pArrayListPassenger,idAModificar,pasajeroReemplazo)==0)
								{
									retorno = 0;
								}
								else
								{
									retorno = -1;
								}
								break;
							}
						}while(menuOpcionesModificacion != 7);
					}
				}
			}
		}
	}

    return retorno;

}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;

	if(pArrayListPassenger != NULL)
	{
		int lenLinke;
		int id;
		int indiceAModificar;
		int MenuBaja;
		Passenger* pasajeroAEliminar;

		lenLinke = ll_len(pArrayListPassenger);

		if(lenLinke > 0)
		{
			if(utn_getNumero(&id,"Ingrese el id del pasajero que quiere modificar: ","Error.Ingrese un id valido.",1,lenLinke,5)==0)
			{
				indiceAModificar = Passenger_find(pArrayListPassenger,id);
				if(indiceAModificar > 0)
				{
					pasajeroAEliminar = ll_get(pArrayListPassenger,indiceAModificar);
					if(pasajeroAEliminar != NULL)
					{
						printf("El pasajero que se va a dar de baja es: ");
						Passenger_printOne(pasajeroAEliminar);

						printf("Seguro que desea darlo de baja"
								"1- Si"
								"2- No");
						scanf("%d",&MenuBaja);
						switch(MenuBaja)
						{
						case 1:
							if(ll_remove(pArrayListPassenger, indiceAModificar) == 0)
							{
								Passenger_delete(pasajeroAEliminar);
								retorno = 0;
							}
							break;
						case 2:
							retorno = -2;
							break;

						}
					}
				}
			}
		}


	}

	return retorno;

}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;

	if(pArrayListPassenger != NULL)
	{
		int cantElementosPasajeros;
		Passenger* unPasajero;

		cantElementosPasajeros = ll_len(pArrayListPassenger);

		for(int i = 0; i < cantElementosPasajeros; i++)
		{
			unPasajero = (Passenger*) ll_get(pArrayListPassenger, i);
			Passenger_printOne(unPasajero);
		}
	}

    return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int opcionesOrden;
	int orden;


	if(pArrayListPassenger != NULL)
	{
		do
		{
			printf("Opciones para ordenar el pasajero"
					"1-Ordenar por id"
					"2-Ordenar por Apellido"
					"3-Ordenar por tipo de pasajero"
					"4-Ordenar por codigo de vuelo"
					"Ingrese como desea ordenar: ");
			scanf("%d",&opcionesOrden);
			utn_getNumero(&orden,"Ingrese tipo de ordenamiento(1-Ascendente,0-Descendente","Error.Ingrese un tipo de ordenamiento valido.",0,1,5);

			switch(opcionesOrden)
			{
			case 1:
				if(ll_sort(pArrayListPassenger, Passenger_sortById, orden) == 0)
				{
					retorno = 1;
				}
				break;
			case 2:
				if(ll_sort(pArrayListPassenger, Passenger_sortByApellido, orden) == 0)
				{
					retorno = 2;
				}
				break;
			case 3:
				if(ll_sort(pArrayListPassenger, Passenger_sortByTipoPasajero, orden) == 0)
				{
					retorno = 3;
				}
				break;
			case 4:
				if(ll_sort(pArrayListPassenger, Passenger_sortByCodigoVuelo, orden) == 0)
				{
					retorno = 4;
				}
				break;
			default:
					printf("Ingrese un tipo de orden valido");
				break;
			}
		}while(opcionesOrden != 4);

	}

	return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

