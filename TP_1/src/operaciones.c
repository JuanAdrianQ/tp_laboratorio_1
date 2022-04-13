/*
 * operaciones.c
 *
 *  Created on: 8 abr. 2022
 *      Author: Adri123
 */

#include <stdio.h>
#include <stdlib.h>


float CalculoTarjetaDebitoLatam(int precioLatam)
{
	int descuento;
	float precioFinalDebito;

	descuento = 10;

	precioFinalDebito = precioLatam - (precioLatam * descuento / 100);


	return precioFinalDebito;
}
float CalculoTarjetaDebitoAerolineas(int precioAerolineas)
{
	int descuento;
	float precioFinalDebitoAerolineas;

	descuento = 10;

	precioFinalDebitoAerolineas = precioAerolineas - (precioAerolineas * descuento / 100);

	return precioFinalDebitoAerolineas;
}
float CalculoTarjetaCreditoLatam(int precioLatam)
{
	int interes;
	float precioFinalCreditoLatam;


	interes = 25;

	precioFinalCreditoLatam = precioLatam + (precioLatam * interes / 100);

	return precioFinalCreditoLatam;
}
float CalculoTarjetaCreditoAerolineas(int precioAerolineas)
{
	int interes;
	float precioFinalCreditoAerolineas;

	interes = 25;

	precioFinalCreditoAerolineas = precioAerolineas + (precioAerolineas * interes / 100);

	return precioFinalCreditoAerolineas;
}
float CalculoBitcoinLatam(int precioLatam)
{
	float precioBitcoinLatam;

	precioBitcoinLatam = precioLatam * 1 / 4606954.55;

	return precioBitcoinLatam;
}
float CalculoBitcoinAerolineas(int precioAerolineas)
{
	float precioBitcoinAerolineas;

	precioBitcoinAerolineas = precioAerolineas * 1 / 4606954.55;

	return precioBitcoinAerolineas;
}
float CalculoPrecioUnitarioLatam(int precioLatam, int kilometrosIngresados)
{
	float precioUnitarioLatam;

	precioUnitarioLatam = precioLatam * kilometrosIngresados;

	return precioUnitarioLatam;
}
float CalculoPrecioUnitarioAerolineas(int precioAerolineas,int kilometrosIngresados)
{
	float precioUnitarioAerolineas;

	precioUnitarioAerolineas = precioAerolineas * kilometrosIngresados;

	return precioUnitarioAerolineas;
}
float CalculoDiferenciaLatamAerolineas(int precioLatam,int precioAerolineas)
{
	float diferenciaPrecioLatamAerolineas;

	diferenciaPrecioLatamAerolineas = precioLatam - precioAerolineas;

	return diferenciaPrecioLatamAerolineas;
}

