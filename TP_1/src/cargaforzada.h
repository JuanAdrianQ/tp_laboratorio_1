/*
 * cargaforzada.h
 *
 *  Created on: 11 abr. 2022
 *      Author: Adri123
 */

#ifndef CARGAFORZADA_H_
#define CARGAFORZADA_H_

/**
 * @fn float CargaForzadaTarjetaDebitoAerolineas(int)
 *
 * Esta funcion recibe un parametro fijo de tipo entero la cual es utilizada para
 * realizar un calculo de descuento. Esta misma retorna un flotante.
 *
 */
float CargaForzadaTarjetaDebitoAerolineas(int);
float CargaForzadaTarjetaDebitoLatam(int);
 /**
  * @fn float CargaForzadaTarjetaCreditoLatam(int)
  *
  * Esta funcion recibe un parametro fijo de tipo entero la cual es utilizada para realizar un
  * calculo de aumento.
  * Esta misma retorno un flotante.
  *
  */
 float CargaForzadaTarjetaCreditoLatam(int);
 /**
   * @fn float CargaForzadaTarjetaCreditoAerolineas(int)
  *
  * Esta funcion recibe un parametro fijo de tipo entero la cual es utilizada para realizar un calculo de aumento de precio,
  * se calcula el precio con un interes y se devuelve un flotante.
  *
  */
 float CargaForzadaTarjetaCreditoAerolineas(int);
 /**
   * @fn float CargaForzadaBitcoinLatam(int)
  *
  * Esta funcion recibe un parametro fijo de tipo entero la cual es utilizada para realizar un calculo de pasaje.
  * La funcion retorna un flotante.
  *
  */
 float CargaForzadaBitcoinLatam(int);
 float CargaForzadaBitcoinAerolineas(int);
 float CargaForzadaPrecioUnitarioLatam(int,int);
 /**
   * @fn float CargaForzadaPrecioUnitarioAerolineas(int, int)
  *
  * Esta funcion recibe dos parametros fijos, tanto el precio "Latam"  como "cantidad de kilometros" para posteriormente realizar su respectivo
  * calculo y guardarlo en una variable. Esta funcion retorna un flotante.
  *
  */
 float CargaForzadaPrecioUnitarioAerolineas(int,int);
 /**
   * @fn float CargaForzadaDiferenciaIngresada(int, int)
  *
  *  Esta funcion recibe dos parametros fijos, ambos precios de vuelo, realiza la diferencia de ambos valores
  *  y retorna un flotante.
  */
 float CargaForzadaDiferenciaIngresada(int,int);

#endif /* CARGAFORZADA_H_ */
