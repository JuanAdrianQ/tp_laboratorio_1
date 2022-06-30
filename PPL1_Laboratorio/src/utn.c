#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int myGets(char *cadena,int longitud)
{
	int retorno = -1;
	char bufferString[4096];

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
		}
			if(bufferString[strlen(bufferString) -1] == '\n')
			{
				bufferString[strlen(bufferString) -1] = '\0';
			}
			if(strlen(bufferString) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno = 0;
			}
	}

	return retorno;
}
int esNumerica(char* cadena)
{
	int retorno = 1;
	int i = 0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if(isalpha(cadena[i]) != 0)
			{
				retorno = 0;
				break;
			}
			i++;
		}
	}


	return retorno;
}
int getInt(int *pResultado)
{
	int retorno = -1;
	char bufferString[50];

	if(pResultado != NULL)
	{
		if(myGets(bufferString,sizeof(bufferString)) == 0)
		{
			if(esNumerica(bufferString))
			{
				*pResultado = atoi(bufferString);
				retorno = 0;
			}

		}
	}
	return retorno;
}
int utn_getNumero(int *pResultado,char *mensaje,char *mensajeError,int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	int bufferInt;

	do
	{
		printf("%s",mensaje);
		if(getInt(&bufferInt)== 0 && bufferInt >= minimo && bufferInt <= maximo)
		{
			*pResultado = bufferInt;
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
		reintentos--;
	}while(reintentos >= 0);

	return retorno;
}
int getFloat(int *pResultado)
{
	int retorno = -1;
	char bufferString[50];

	if(pResultado != NULL)
	{
		if(myGets(bufferString,sizeof(bufferString)) == 0)
		{
			if(esNumerica(bufferString))
			{
				*pResultado = atof(bufferString);
				retorno = 0;
			}
		}
	}

	return retorno;
}
int utn_getFloat(int *pResultado,char *mensaje,char *mensajeError,int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	int bufferFloat;

	do
	{
		printf("%s",mensaje);
		if(getFloat(&bufferFloat)== 0 && bufferFloat >= minimo && bufferFloat <= maximo)
		{
			*pResultado = bufferFloat;
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
		reintentos--;
	}while(reintentos >= 0);

	return retorno;
}
int utn_getString(char* cadena, char* mensaje, char* mensajeError)
{
	int retorno = -1;

	while(retorno != 0)
	{
		printf(mensaje);
		fflush(stdin);
		gets(cadena);
		for (int i = 0; i < strlen(cadena); i++)
		{
			if(isalpha(cadena[i]) == 0 && isspace(cadena[i]) == 0 && cadena[i] != 'ñ')
			{
				retorno = -1;
				printf(mensajeError);
				break;
			}
			retorno = 0;
		}
	}

	return retorno;
}
