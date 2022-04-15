/*
 * operaciones.h
 *
 *  Created on: 8 abr. 2022
 *      Author: Adri123
 */

#ifndef OPERACIONES_H_
#define OPERACIONES_H_

/**
 * @fn float CalculoTarjetaDebitoLatam(int)
 *
 * Esta funcion recibe un parametro para realizar su descuento.
 * Esta funcion retorna un flotante. Por lo cual se debera de castear una de sus variables al
 * momento de su calculo.
 */
 float CalculoTarjetaDebitoLatam(int);
 float CalculoTarjetaDebitoAerolineas(int);
 /**
   * @fn float CalculoTarjetaCreditoLatam(int)
   *
   * Esta funcion recibe un parametro para realizar su calculo de interes.
   * La funcion retorna un flotante. Por lo cual se debera de castear una de sus variables al
   * momento de su calculo.
   *
   */
 float CalculoTarjetaCreditoLatam(int);
 float CalculoTarjetaCreditoAerolineas(int);
 /**
   * @fn float CalculoBitcoinLatam(int)
   *
   * Esta funcion recibe un parametro (precio Latam) la cual es pasada a Bitcoin.
   * Este valor se guarda en una variable de tipo flotante  y se retorna.
   *
   */
 float CalculoBitcoinLatam(int);
 float CalculoBitcoinAerolineas(int);
 /**
  * @fn float CalculoPrecioUnitarioLatam(int, int)
  *
  * Esta funcion recibe dos parametros (el precio de latam y la cantidad de kilometros).
  * Se realiza el calculo debido y se retorna la variable siendo de tipo flotante.
  *
  */
 float CalculoPrecioUnitarioLatam(int,int);
 float CalculoPrecioUnitarioAerolineas(int,int);
 /**
  * @fn float CalculoDiferenciaLatamAerolineas(int, int)
  *
  *  Esta funcion recibe dos parametros (el precio de latam y de aerolineas), dentro del desarrollo de la misma se realiza
  *  la diferencia y se retorna el resultado de tipo flotante.
  *
  */
 float CalculoDiferenciaLatamAerolineas(int,int);

#endif /* OPERACIONES_H_ */


