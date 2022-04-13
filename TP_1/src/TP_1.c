
#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"
#include "cargaforzada.h"
#include "validaciones.h"

//Quiroz Juan TP1 Div D

int main(void)
{
	setbuf(stdout, NULL);


	int opcion;
	int opcion2;
	int opcion3;
	float kilometrosIngresados;
	float precioAerolineas;
	float precioLatam;
	float cantidadKilometros;
	float precioForzadoLatam;
	float precioForzadoAerolineas;

	kilometrosIngresados = 0;
	precioAerolineas = 0;
	precioLatam = 0;
	cantidadKilometros = 5064;
	precioForzadoLatam = 1320542.22;
	precioForzadoAerolineas = 2102354.67;
	while(opcion != 6)
	{
		printf("1. Ingresar Kilómetros: (km = %f)\n"
	          "2. Ingresar Precio de Vuelos:(Aerolineas = %f,Latam = %f)\n"
			  "3. Calcular todos los costos: \n"
		      "4. Informar resultados\n"
		      "5. Carga forzada de datos\n"
		      "6. Salir\n"
			  "\nSeleccione una opción: ",kilometrosIngresados,precioAerolineas,precioLatam);
			scanf("%d",&opcion);
			switch(opcion)
			{
			case 1:
				printf("Ingrese la cantidad de kilometros: ");
				scanf("%f",&kilometrosIngresados);

				break;
			case 2:
				printf("Donde desea ingresar el precio:\n"
						"1- Aerolineas Argentinas: \n"
						"2- Latam: \n");
						scanf("%d",&opcion2);
						switch(opcion2)
						{
						case 1:
							printf("-Precio vuelo Aerolineas: ");
							scanf("%f",&precioAerolineas);

							break;
						case 2:
							printf("-Precio vuelo Latam: ");
							scanf("%f",&precioLatam);
							break;

						}
				break;
			case 3:
				printf("\na) Tarjeta de débito\n"
						"b) Tarjeta de crédito\n"
						"c) Bitcoin\n"
						"d) Mostrar precio por km\n"
						"e) Mostrar diferencia de precio ingresada\n"
						"\n\n1. Calcular todos los costos... 1");
						scanf("%d",&opcion3);
				switch(opcion3)
				{
				case 1:
					CalculoTarjetaDebitoLatam(precioLatam);
					CalculoTarjetaDebitoAerolineas(precioAerolineas);
					CalculoTarjetaCreditoLatam(precioLatam);
					CalculoTarjetaCreditoAerolineas(precioAerolineas);
					CalculoBitcoinLatam(precioLatam);
					CalculoBitcoinAerolineas(precioAerolineas);
					CalculoPrecioUnitarioLatam(precioLatam,kilometrosIngresados);
					CalculoPrecioUnitarioAerolineas(precioLatam,kilometrosIngresados);
					CalculoDiferenciaLatamAerolineas(precioLatam,precioAerolineas);

				}
				break;
			case 4:
				printf("\nLatam:\n"
						"a)Precio con tarjeta de débito: %.2f\n"
						"b)Precio con tarjeta de crédito: %.2f\n"
						"c)Precio pagando con bitcoin: %f\n"
						"d)Precio unitario: %.2f\n"
						"\nAerolíneas:\n"
						"a)Precio con tarjeta de débito: %.2f\n"
						"b)Precio con tarjeta de crédito: %.2f\n"
						"c)Precio pagando con bitcoin: %f\n"
						"d)Precio unitario: %.2f\n"
						"La diferencia de precio es: %.2f\n\n",CalculoTarjetaDebitoLatam(precioLatam),CalculoTarjetaCreditoLatam(precioLatam),CalculoBitcoinLatam(precioLatam),CalculoPrecioUnitarioLatam(precioLatam,kilometrosIngresados),CalculoTarjetaDebitoAerolineas(precioAerolineas),CalculoTarjetaCreditoAerolineas(precioAerolineas),CalculoBitcoinAerolineas(precioAerolineas),CalculoPrecioUnitarioAerolineas(precioLatam,kilometrosIngresados),CalculoDiferenciaLatamAerolineas(precioLatam,precioAerolineas));
				break;
			case 5:
				printf("\nkMs Ingresados: %.2f\n\n"
						"Precio Aerolineas: %.2f\n"
						"a)Precio con tarjeta de debito: %.2f\n"
						"b)Precio con tarjeta de credito: %.2f\n"
						"c)Precio pagando con bitcoin: %f\n"
						"d)Mostrar precio unitario: %.2f\n"
						"\n\nPrecio Latam: %.2f\n"
						"a)Precio con tarjeta de debito: %.2f\n"
						"b)Precio con tarjeta de credito: %.2f\n"
						"c)Precio pagando con bitcoin: %f\n"
						"d)Mostar precio unitario: %.2f\n"
						"La diferencia de precio es: %.2f\n\n",cantidadKilometros,precioForzadoAerolineas,CargaForzadaTarjetaDebitoAerolineas(precioForzadoAerolineas),CargaForzadaTarjetaCreditoAerolineas(precioForzadoAerolineas),CargaForzadaBitcoinAerolineas(precioForzadoAerolineas),CargaForzadaPrecioUnitarioAerolineas(precioForzadoAerolineas,cantidadKilometros),precioForzadoLatam,CargaForzadaTarjetaDebitoLatam(precioForzadoLatam),CargaForzadaTarjetaCreditoLatam(precioForzadoLatam),CargaForzadaBitcoinLatam(precioForzadoLatam),CargaForzadaPrecioUnitarioLatam(precioForzadoLatam,cantidadKilometros),CargaForzadaDiferenciaIngresada(precioForzadoAerolineas,precioForzadoLatam));

				break;

			}
	}

	printf("\nGracias por elegirnos.Vuelva Pronto!!!.");

	return EXIT_SUCCESS;
}

