#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "parser.h"
#include "Passenger.h"
#include "LinkedList.h"


/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);

	int opcion = 0;
	int salidaBaja;
	int salidaOrdenamiento;

    LinkedList* listaPasajeros = ll_newLinkedList();

    do{
    	printf("\nMenu:\n"
    			"1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
    			"2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n"
    			"3. Alta de pasajero\n"
    			"4. Modificar datos de pasajero\n"
    			"5. Baja de pasajero\n"
    			"6. Listar pasajeros\n"
    			"7. Ordenar pasajeros\n"
    			"8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
    			"9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n"
    			"10. Salir\n"
    			"\nElija una opcion: ");
    	fflush(stdin);
    	scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
            	if(controller_loadFromText("data.csv",listaPasajeros)==0)
            	{
            		printf("Se cargaron los datos de pasajeros en modo texto con exito.");
            	}
            	else
            	{
            		printf("No se pudo cargar los datos debido a un error.");
            	}
                break;
            case 2:
            	if(controller_loadFromBinary("data.bin",listaPasajeros)==0)
            	{
            		printf("Se cargaron los datos de pasajeros en modo binario con exito.");
            	}
            	else
            	{
            		printf("Error");
            	}
            	break;
            case 3: //Alta de pasajero

            	if(controller_addPassenger(listaPasajeros)==0)
            	{
            		printf("\nSe agrego un pasajero exitosamente.\n");
            	}
            	else
            	{
            		printf("\nNo se pudo agregar el pasajero al sistema.\n");
            	}
            	break;
            case 4: //Modificar pasajero
            	if(controller_editPassenger(listaPasajeros)==0)
            	{
            		printf("\nSe modifico correctamente al pasajero.\n");
            	}
            	else
            	{
            		printf("\nNo se pudo modificar al pasajero.\n");
            	}
            	break;
            case 5: // Baja de pasajero
            	salidaBaja = controller_removePassenger(listaPasajeros);
            	if(salidaBaja == 0)
            	{
            		printf("\nSe a eliminado al pasajero del sistema con exito\n");
            	}
            	else
				{
            		printf("\nOcurrio un error al intentar eliminar al pasajero\n");
				}
            	break;
            case 6:
            	if(controller_ListPassenger(listaPasajeros)==0)
            	{
            		printf("\nLista de pasajeros mostrada con exito.\n");
            	}
            	else
            	{
            		printf("\nOcurrio un error al intentar listar los pasajeros.\n");
            	}
            	break;
            case 7: //Ordenar pasajeros
            salidaOrdenamiento = controller_sortPassenger(listaPasajeros);
            switch(salidaOrdenamiento)
            {
            case 1:
            	printf("\nSe ordeno los pasajeros por id con exito\n");
            	break;
            case 2:
            	printf("\nSe ordeno los pasajeros por apellido con exito\n");
            	break;
            case 3:
            	printf("\nSe ordeno los pasajeros por tipo de pasajero con exito\n");
            	break;
            case 4:
            	printf("\nSe ordeno los pasajeros por codigo de vuelo con exito\n");
            	break;
            default:
            	printf("\nOcurrio un error al intentar ordenar los pasajeros\n");
            	break;
            }
            	break;
            case 8: //Guardar los datos de pasajeros en modo texto

            	break;
            case 9://Guardar los datos de pasajeros en modo binario

            	break;
            case 10: //Salir
            	printf("\nCerrando el sistema...\n");
            	exit(1);
            	break;

        }
    }while(opcion != 10);



    return 0;
}

