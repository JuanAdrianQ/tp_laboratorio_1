#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"


int utn_getName(char* cadena,char* mensaje,char* mensajeError)
{
	int retorno;

	printf(mensaje);
	fflush(stdin);
	gets(cadena);
	for(int i = 0;i < strlen(cadena);i++)
	{
		if(isalpha(cadena[i]) == 0 && isspace(cadena[i]) == 0)
		{
			printf(mensajeError);
			retorno = 1;
			break;
		}
		retorno = 0;

	}

	return retorno;
}
int verificaCadNumeros(char *cadena)
{
	int i = 0;
	int retorno = 1;
	if (cadena != NULL && strlen(cadena) > 0)
	{
		while (cadena[i] != '\0')
		{
			if (isalpha(cadena[i]) != 0)
			{
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}
int myGets(char *cadena, int len)
{
	int retorno = -1;
	if (cadena != NULL && len > 0 && fgets(cadena, len, stdin) == cadena)
	{
		fflush(stdin);
		if (cadena[strlen(cadena) - 1] == '\n')
		{
			cadena[strlen(cadena) - 1] = '\0';
		}
		retorno = 0;
	}
	return retorno;
}
int getFloat(float *Resultado)
{
	int retorno = -1;
	char buffer[64];

	if(Resultado != NULL)
	{
		if(myGets(buffer,sizeof(buffer)) == 0 && verificaCadNumeros(buffer))
		{
			*Resultado = atof(buffer);
			retorno = 0;

		}
	}

	return retorno;
}
int utn_getFloat(float *Resultado, char *mensaje, char *mensajeError, float minimo, float maximo)
{
	float bufferFloat;
	int retorno = -1;

	while (retorno != 0)
	{
		printf("%s", mensaje);
		if (getFloat(&bufferFloat) == 0)
		{
			if (bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*Resultado = bufferFloat;
				retorno = 0;
				break;
			}
		}
		printf("%s", mensajeError);
	}
	return retorno;
}
int getInt(int* Resultado)
{
	int retorno = -1;
	char buffer[64];

	if(Resultado != NULL)
	{
		if (myGets(buffer, sizeof(buffer)) == 0 && verificaCadNumeros(buffer))
		{
			*Resultado = atoi(buffer);
			retorno = 0;
		}
	}
	return retorno;
}
int utn_getInt(int *Resultado, char *mensaje, char *mensajeError, int minimo, int maximo)
{
	int bufferInt;
	int retorno = -1;

	while (retorno != 0)
	{
		printf("%s", mensaje);
		if (getInt(&bufferInt) == 0)
		{
			if (bufferInt >= minimo && bufferInt <= maximo)
			{
				*Resultado = bufferInt;
				retorno = 0;
				break;
			}
		}
		printf("%s", mensajeError);
	}
	return retorno;
}
void pedirCodigoDeVuelo(char codigoVuelo[10], char* mensaje)
{
	printf(mensaje);
	fflush(stdin);
	gets(codigoVuelo);
}
