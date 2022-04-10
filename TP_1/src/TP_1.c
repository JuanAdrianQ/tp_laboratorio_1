

#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"
#include "validaciones.h"

//Quiroz Juan TP1 Div D

int main(void)
{
	setbuf(stdout, NULL);

	int primerPrecio;
	int segundoPrecio;
	int opcion;


	printf( "1. Ingresar Kilómetros: \n"
			"2. Ingresar Precio de Vuelos: \n"
			"3. Calcular todos los costos: \n"
			"4. Informar resultados\n"
			"5. Carga forzada de datos\n"
			"6. Salir\n");
	scanf("%d",&opcion);
	switch(opcion)
	{
	case 1:
		funcionKilometros();
		printf( "1. Ingresar Kilómetros: \n"
				"2. Ingresar Precio de Vuelos: \n"
				"3. Calcular todos los costos: \n"
				"4. Informar resultados\n"
				"5. Carga forzada de datos\n"
				"6. Salir\n");
		scanf("%d",&opcion);

		break;
	case 2:
		funcionPrecioVuelos();
		break;
	case 3:

		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;

	}


	return EXIT_SUCCESS;
}

