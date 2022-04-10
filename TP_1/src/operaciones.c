/*
 * operaciones.c
 *
 *  Created on: 8 abr. 2022
 *      Author: Adri123
 */

#include <stdio.h>
#include <stdlib.h>

void funcionKilometros(void)
{
	int kilometrosIngresados;

	printf("Ingrese la cantidad de kilometros a recorrer: ");
	scanf("%d",&kilometrosIngresados);
	printf("1. Ingresar Kilómetros: (km = %d)\n",kilometrosIngresados);

}

void funcionPrecioVuelos(void)
{
	int opcion2;
	int precioAerolineasArgentinas;
	int precioAerolineasLatam;
	int opcion3;

	printf("\n2. Ingresar Precio de Vuelos: ");
			printf("\nDonde desea ingresar el precio de vuelo: "
					"\n1. Aerolineas Argetinas"
					"\n2. Latam\n");
			scanf("%d",&opcion2);
			if(opcion2 == 1)
			{
				printf("-Precio vuelo Aerolineas: ");
				scanf("%d",&precioAerolineasArgentinas);

			}
			printf("\n2. Ingresar Precio de Vuelos: ");
			printf("\nDonde desea ingresar el precio de vuelo: "
							"\n1. Aerolineas Argetinas"
							"\n2. Latam\n");
			scanf("%d",&opcion3);
			if(opcion3 == 2)
			{
				printf("-Precio vuelo Latam: ");
				scanf("%d",&precioAerolineasLatam);

			}
			printf("Ingresar Precio de Vuelos: (Aerolineas = %d,Latam = %d)",precioAerolineasArgentinas,precioAerolineasLatam);

}

