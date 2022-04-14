/*
 * cargaforzada.c
 *
 *  Created on: 11 abr. 2022
 *      Author: Adri123
 */
#include <stdio.h>
#include <stdlib.h>



 float CargaForzadaTarjetaDebitoAerolineas(int precioForzadoAerolineas)
 {
	 float precioTarjetaDebitoAerolineas;
	 float descuento;

	 descuento = 10;

	 precioTarjetaDebitoAerolineas = precioForzadoAerolineas - (precioForzadoAerolineas * descuento  / 100);

	 return precioTarjetaDebitoAerolineas;
 }
 float CargaForzadaTarjetaDebitoLatam(int precioForzadoLatam)
 {
	 float precioTarjetaDebitoLatam;
	 float descuento;

	 descuento = 10;

	 precioTarjetaDebitoLatam = precioForzadoLatam - (precioForzadoLatam * descuento / 100);

	 return precioTarjetaDebitoLatam;

 }
 float CargaForzadaTarjetaCreditoLatam(int precioForzadoLatam)
 {
	 float interes;
	 float precioTarjetaCreditoLatam;

	 interes = 25;

	 precioTarjetaCreditoLatam = precioForzadoLatam + (precioForzadoLatam * interes / 100);

	 return precioTarjetaCreditoLatam;
 }
 float CargaForzadaTarjetaCreditoAerolineas(int precioForzadoAerolineas)
 {
	 float interes;
	 float precioTarjetaCreditoAerolineas;

	 interes = 25;

	 precioTarjetaCreditoAerolineas = precioForzadoAerolineas + (precioForzadoAerolineas * interes / 100);

	 return precioTarjetaCreditoAerolineas;
 }
 float CargaForzadaBitcoinLatam(int precioForzadoLatam)
 {
	 float precioBitcoinForzadoLatam;

	 precioBitcoinForzadoLatam = precioForzadoLatam * 1 / 4606954.55;

	 return precioBitcoinForzadoLatam;
 }
 float CargaForzadaBitcoinAerolineas(int precioForzadoAerolineas)
 {
	 float precioBitcoinForzadoAerolineas;

	 precioBitcoinForzadoAerolineas = precioForzadoAerolineas * 1 / 4606954.55;

	 return precioBitcoinForzadoAerolineas;
 }
 float CargaForzadaPrecioUnitarioLatam(int precioForzadoLatam,int cantidadKilometros)
 {
	 float precioUnitarioForzadoLatam;

	 precioUnitarioForzadoLatam = (float)precioForzadoLatam * cantidadKilometros;

	 return precioUnitarioForzadoLatam;
 }
 float CargaForzadaPrecioUnitarioAerolineas(int precioForzadoAerolineas,int cantidadKilometros)
 {
	 float precioUnitarioForzadoAerolineas;

	 precioUnitarioForzadoAerolineas = (float)precioForzadoAerolineas * cantidadKilometros;

	 return precioUnitarioForzadoAerolineas;
 }
 float CargaForzadaDiferenciaIngresada(int precioForzadoAerolineas,int precioForzadoLatam)
 {
	 float diferenciaForzadoLatamAerolineas;

	 diferenciaForzadoLatamAerolineas = (float)precioForzadoLatam - precioForzadoAerolineas;

	 return diferenciaForzadoLatamAerolineas;
 }
