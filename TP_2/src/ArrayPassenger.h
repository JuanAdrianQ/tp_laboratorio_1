
#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
struct{

	int id;
	char name[51];
	char lastname[51];
	float price;
	char flycode[10];
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


int initPassengers(Passenger* list, int len);

int initStatusFlightAndTypePassenger(StatusFlightAndTypePassenger* statusType, int len);

int addPassenger(Passenger* list,int len,int id,char name[],char lastName[],float price,int typePassenger,char flycode[],int statusFlight);

int findPassengerId(Passenger* list,int len, int id);

int modificarPasajero(Passenger* list, int len, int indice, int opcion);

int modificacionPasajero(Passenger* list,int len);

int mostrarPasajeros(Passenger* list,int len);

int removePassenger(Passenger* list, int len, int id);

int sortPassengersByLastName(Passenger* list, int len, int order);

int ordenamientoPasajeroXCodigo(Passenger* list, int len, int order);

int printPassenger(Passenger* list, StatusFlightAndTypePassenger* status, int length, int lenStatusType);

int averagePassenger(Passenger* list, int len, float* totalPrice, float* average);

int cantidadEncimaPromedioPasajeros(Passenger* list, int len, float promedio);
