#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "pedirDatos.h"

float pedirNumeroFlotante(char mensaje[])
{
    float numeroIngresado;

    printf(mensaje);
    scanf("%f", &numeroIngresado);

    return numeroIngresado;
}

char obtenerUnCaracter(char mensaje[])
{
    char caracter;

     printf(mensaje);
     fflush(stdin);
     scanf("%c", &caracter);
     caracter = toupper(caracter);

     return caracter;
}

 int pedirEntero(char mensaje[])
 {
     int entero;

     printf(mensaje);
     scanf("%d", &entero);

     return entero;
}

void obtenerCadena(char msj[], char mensajeError[], char cadena[], int TAMANIO_CADENA)
{
    printf(msj);
    fflush(stdin);
    fgets(cadena, TAMANIO_CADENA, stdin);
    while(validarSiEsChar(cadena)== 0)
    {
        printf(mensajeError);
        fflush(stdin);
        fgets(cadena, TAMANIO_CADENA, stdin);
    }
    remmplazarSaltoPorEspacio(cadena);
    formatearNombrePropio(cadena);
}

int validarSiEsChar(char cadena[])
{
    int i;
    int esCaracter;
    int T;

    T = strlen(cadena)-1;

    for(i=0; i< T; i++)
    {
        if(isalpha(cadena[i])==0)
        {
            esCaracter = 0;
            break;
        }
        else
        {
            esCaracter = 1;
        }
    }
    return esCaracter;
}

char remmplazarSaltoPorEspacio(char string[])
{
    int i;
    for(i=0;string[i] != '\0';i++)
    {
        if(string[i] == '\n')
        {
            string[i] = '\0';
        }
    }
    return string[i];
}

void formatearNombrePropio(char cadena[])
{
    strlwr(cadena);
    cadena[0] = toupper(cadena[0]);
}

int confirmarAccionUsuario(void)
{
    int continuar;
    char respuesta;

    printf("Para continuar ingresar S, para cancelar presionar cualquier tecla \n");
    fflush(stdin);
    scanf("%c", &respuesta);

    if(respuesta == 's' || respuesta == 'S')
    {
        continuar = 1;
    }
    else
    {
        continuar = 0;
    }
    return continuar;
}

int generarId(int* ultimoId)
{
    int idActual;

    idActual = *ultimoId + 1;

    return idActual;
}

float calcularPromedio(float valorUno, float valorDos)
{
    float promedio;

    promedio = valorUno / valorDos;

    return promedio;
}
