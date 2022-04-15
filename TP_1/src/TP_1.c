
#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"
#include "cargaforzada.h"


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
	int cantidadKilometros;
	float precioForzadoLatam;
	float precioForzadoAerolineas;


	kilometrosIngresados = 0;
	precioAerolineas = 0;
	precioLatam = 0;
	cantidadKilometros = 5064;
	precioForzadoLatam = 2102354.67;
	precioForzadoAerolineas = 1320542.22;


	while(opcion != 6)
	{

		printf("\n1. Ingresar Kilómetros: (km = %.2f)\n"
	          "2. Ingresar Precio de Vuelos:(Aerolineas = %.2f,Latam = %.2f)\n"
			  "3. Calcular todos los costos: \n"
		      "4. Informar resultados\n"
		      "5. Carga forzada de datos\n"
		      "6. Salir\n"
			  "\nSeleccione una opción: ",kilometrosIngresados,precioAerolineas,precioLatam);
			scanf("%d",&opcion);
			switch(opcion)
			{
			case 1:
				printf("\nIngresar Kilómetros: ");
				scanf("%f",&kilometrosIngresados);


				break;
			case 2:
				printf("\nDonde desea ingresar el precio:\n"
						"1- Aerolineas Argentinas \n"
						"2- Latam \n"
						"\nSeleccione una opción: ");
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
				if(precioAerolineas > 0 && precioLatam > 0 && kilometrosIngresados > 0)
				{
					printf("\na) Tarjeta de débito\n"
						"b) Tarjeta de crédito\n"
						"c) Bitcoin\n"
						"d) Mostrar precio por km\n"
						"e) Mostrar diferencia de precio ingresada\n"
						"\n1. Calcular todos los costos... \n"
						"\nSeleccione una opción: ");
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
				}
				else
				{
					printf("\nNo se pudo realizar el calculo.Por favor ingrese bien los precios del vuelo o cantidad de kilometros!!!\n");

				}

				break;
			case 4:
				if(precioAerolineas > 0 && precioLatam > 0 && kilometrosIngresados > 0)
				{
					printf("\nLatam:\n"
					"a)Precio con tarjeta de débito: $ %.2f\n"
					"b)Precio con tarjeta de crédito: $ %.2f\n"
					"c)Precio pagando con bitcoin: $ %f\n"
					"d)Precio unitario: $ %.2f\n"
					"\nAerolíneas:\n"
					"a)Precio con tarjeta de débito: $ %.2f\n"
					"b)Precio con tarjeta de crédito: $ %.2f\n"
					"c)Precio pagando con bitcoin: $ %f\n"
					"d)Precio unitario: $ %.2f\n"
					"La diferencia de precio es: $ %.2f\n\n",CalculoTarjetaDebitoLatam(precioLatam)
					,CalculoTarjetaCreditoLatam(precioLatam)
					,CalculoBitcoinLatam(precioLatam)
					,CalculoPrecioUnitarioLatam(precioLatam,kilometrosIngresados)
					,CalculoTarjetaDebitoAerolineas(precioAerolineas)
					,CalculoTarjetaCreditoAerolineas(precioAerolineas)
					,CalculoBitcoinAerolineas(precioAerolineas)
					,CalculoPrecioUnitarioAerolineas(precioAerolineas,kilometrosIngresados)
					,CalculoDiferenciaLatamAerolineas(precioLatam,precioAerolineas));
				}
				else
				{
					printf("\nNo se pudo informar los resultados.Por favor asegurese de que ingreso precios del vuelo o cantidad de kilometros!!!\n");
				}
				break;
			case 5:
				printf("\nkMs Ingresados: %d km\n\n"
						"Precio Aerolineas: $%.2f\n"
						"a)Precio con tarjeta de debito: $ %.2f\n"
						"b)Precio con tarjeta de credito: $ %.2f\n"
						"c)Precio pagando con bitcoin: $ %f\n"
						"d)Mostrar precio unitario: $ %.2f\n"
						"\n\nPrecio Latam: $%.2f\n"
						"a)Precio con tarjeta de debito: $ %.2f\n"
						"b)Precio con tarjeta de credito: $ %.2f\n"
						"c)Precio pagando con bitcoin: $ %f\n"
						"d)Mostar precio unitario: $ %.2f\n"
						"La diferencia de precio es: $ %.2f\n\n",cantidadKilometros,precioForzadoAerolineas,CargaForzadaTarjetaDebitoAerolineas(precioForzadoAerolineas),CargaForzadaTarjetaCreditoAerolineas(precioForzadoAerolineas),CargaForzadaBitcoinAerolineas(precioForzadoAerolineas),CargaForzadaPrecioUnitarioAerolineas(precioForzadoAerolineas,cantidadKilometros),precioForzadoLatam,CargaForzadaTarjetaDebitoLatam(precioForzadoLatam),CargaForzadaTarjetaCreditoLatam(precioForzadoLatam),CargaForzadaBitcoinLatam(precioForzadoLatam),CargaForzadaPrecioUnitarioLatam(precioForzadoLatam,cantidadKilometros),CargaForzadaDiferenciaIngresada(precioForzadoAerolineas,precioForzadoLatam));

				break;

			}
			while(kilometrosIngresados < 0)
				{
					printf("Error.Ingresar una cantidad de kilometros valida: ");
					scanf("%f",&kilometrosIngresados);
				}
			while(precioAerolineas < 0)
			{
				printf("-Error.Ingrese un precio vuelo Aerolineas valido: ");
				scanf("%f",&precioAerolineas);
			}
			while(precioLatam < 0)
			{
				printf("-Error.Ingrese un precio vuelo Latam valido: ");
				scanf("%f",&precioLatam);
			}

	}

	printf("\nGracias por elegirnos.Vuelva Pronto!!!.");

	return EXIT_SUCCESS;
}

