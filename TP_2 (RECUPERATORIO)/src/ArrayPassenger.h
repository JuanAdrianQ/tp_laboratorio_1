
#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
struct{

	int id;
	char name[51];
	char lastname[51];
	float price;
	char flycode[20];
	int typePassenger;
	int statusFlight;
	int isEmpty;


}typedef Passenger;
struct
{
	int statusFlight;
	char descriptionSF[15];
	int typePassenger;
	char descriptionTP[15];



}typedef StatusFlightAndTypePassenger;


#endif /* ARRAYPASSENGER_H_ */
/** \brief Inicializa a los pasajeros en -1 (VACIO)
 * \param Passenger* list puntero a la lista de pasajeros
 *  \param len tamaño de la lista de pasajeros
 *  \return int retorna -1 si fallo,0 si cumplio con su funcion.
 */
int initPassengers(Passenger* list, int len);
/** \brief Inicializa la estructura StatusFlightAndTypePassenger asignandoles valores a los campos.
 * 	\param StatusFlightAndTypePassenger* statusType puntero a la lista de tipos de estado de vuelo y tipos de pasajeros.
 *  \param len tamaño de la lista
 *	\return int retorna -1 si fallo,0 si cumplio con su funcion.
 */
int initStatusFlightAndTypePassenger(StatusFlightAndTypePassenger* statusType, int len);
/** \brief Busca un espacio libre en el array de pasajeros.
 *	\param Passenger* list puntero a la lista de pasajeros
 *	\len tamaño de la lista.
 *	\return int retorna -1 si fallo y el indice si cumplio con su funcion.
 */
int findFreeSlot(Passenger* list,int len);
/**	\brief Añade un pasajero al array de pasajeros
 *  \param Passenger* list puntero a la lista de pasajeros
 *  \param len tamaño de la lista
 *  \param id id del pasajero
 *  \param name[] nombre del pasajero
 *  \param lastName[] apellido del pasajero
 *  \param price precio del vuelo
 *  \param typePassenger tipo de pasajero
 *  \param  flycode[] codigo de vuelo del pasajero
 *  \param statusFlight estado de vuelo del pasajero
 *  \return int retorna -1 si fallo y 0 si cumplio con su funcion.
 */
int addPassenger(Passenger* list,int len,int id,char name[],char lastName[],float price,int typePassenger,char flycode[],int statusFlight);
/** \brief Verifica si el ID pasado por parametro existe en el array de pasajeros.
 * 	\param Passenger* list puntero a la lista de pasajeros
 * 	\param len tamaño de la lista
 * 	\param id id a comparar para verificar existencia
 * 	\return int retorna -1 en caso de error y el ID en caso de que exista tal ID.
 */
int findPassengerId(Passenger* list,int len, int id);
/** brief Modifica un pasajero
 * \param Passenger* list puntero a la lista de pasajeros
 * \param len tamaño de la lista
 * \param indice indice del array en el cual se quieren realizar dichas modificaciones
 * \param opcion Variedad de opciones de modificacion (nombre,apellido,etc)
 * \return int retorna -1 en caso de error y 0 si se pudo realizar la modificacion.
 */
int modificarPasajero(Passenger* list, int len, int indice, int opcion);
/** brief Hace el listado de los pasajeros
 * \param Passenger* list puntero a la lista de pasajeros
 * \param len tamaño de la lista
 * \return retorna -1 en caso de error y 0 si pudo mostrar los pasajeros
 */
int mostrarPasajeros(Passenger* list,int len);
/**	brief Elimina un pasajero de la lista
 * \param Passenger* lis t puntero a la lista de pasajeros
 * \param len tamaño de la lista
 * \param id id del pasajero que se quiere eliminar
 * \return retorna -1 en caso de error y 0 si se pudo eliminar el pasajero
 */
int removePassenger(Passenger* list, int len, int id);
/** brief Ordena los pasajeros por Apellido
 * \param Passenger* list puntero a la lista de pasajeros
 * \param len tamaño de la lista
 * \param order 0 o 1 para un ordenamiento ascendente o descendente
 * \return int -1 en caso de error y 0 en caso de que se halla podido ordenar los pasajeros correctamente.
 */
int sortPassengersByLastName(Passenger* list, int len, int order);
/**	\brief Ordena los pasajeros por el codigo de vuelo
 * \param Passenger* list puntero a la lista de pasajeros
 * \param len tamaño de la lista
 * \param order 0 o 1 para un ordenamiento ascendente o descendente
 * \return int -1 en caso de error y 0 en caso de que se halla ordenado los codigos de vuelo correctamente.
 */
int ordenamientoPasajeroXCodigo(Passenger* list, int len, int order);
/** \brief Informa los pasajeros cargados en la lista
 * \param Passenger* list puntero a la lista de pasajeros
 * \param StatusFlightAndTypePassenger* status puntero a la estructura de estado de vuelo y tipo de pasajero
 * \param lenght tamaño de la lista de pasajeros
 * \param lenStatusType tamaño del array estadod de vuelo y tipo de pasajero
 * \return int retorna -1 en caso de error y 0 en caso de exito
 */
int printPassenger(Passenger* list, StatusFlightAndTypePassenger* status, int length, int lenStatusType);
/** \brief Calcula el promedio de precio vuelo de los pasajeros
 *	\param Passenger* list puntero a la lista de pasajeros
 *	\param len tamaño de la lista
 *	\param totalPrice precio total de los pasajeros
 *	\param promedio precio de los pasajeros
 *	\return retorna -1 en caso de error y 0 en caso de exito.
 */
int averagePassenger(Passenger* list, int len, float* totalPrice, float* average);
/** \brief Calcula la cantidad de pasajeros que superan el promedio del vuelo entre los pasajeros
 * \param Passenger* list puntero a la lista de pasajeros
 * \param len tamaño de la lista
 * \param promedio promedio precio de vuelo
 * \return retorna -1 en caso de error y 0 en caso de exito.
 */
int cantidadEncimaPromedioPasajeros(Passenger* list, int len, float promedio);
