#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paises.h"
#include "pedirDatos.h"


void hardcodearPaises(ePais lista[], int tamanioListaPaises)
{
    int idPais[5] = {1,2,3,4,5};
    char nombrePais[5][11] = {"Tailandia", "Alemania", "Persia", "Belgica", "Argentina"};
    char continentePais[5][10] = {"Asia", "Europa", "Asia", "Europa", "America"};
    int codigoArea[5] = {66, 49, 98, 32, 54};
    int cantidadMascotas[5] = {1,2,2,1,1};

    int i;

    for(i = 0; i < 5; i++)
    {
        lista[i].idPais =  idPais[i];
        strcpy(lista[i].nombrePais, nombrePais[i]);
        strcpy(lista[i].continentePais, continentePais[i]);
        lista[i].codigoArea = codigoArea[i];
        lista[i].cantidadMascotas =  cantidadMascotas[i];
    }
}

void mostrarPaises(ePais paisData)
{
    printf("%4d %10s %12d\n", paisData.idPais, paisData.nombrePais, paisData.cantidadMascotas);
}


void mostrarListaPaises(ePais lista[],  int tamanioLista)
{
    int i;

    printf("|ID|      PAIS      |     CANTIDAD MASCOTAS\n");

    for(i = 0; i < tamanioLista; i++)
    {
        printf("%d", i);
        mostrarPaises(lista[i]);

    }
}

int buscarIndicePaisPorId(int idABuscar, ePais listaPaises[], int tamanioLista)
{
    int i;
    int indice;

    indice = -1;

    for(i = 0; i< tamanioLista; i++)
    {
        if(idABuscar == listaPaises[i].idPais)
        {
            indice = i;
        }

    }
    return indice;
}


int elegirPaisOrigenRaza(ePais listaPaises[], int tamanioLista)
{
    int idPaisABuscar;
    int idPais;


    printf("Ingresa la opcion correspondiente al pais de origen de la raza \n");
    mostrarListaPaises(listaPaises, tamanioLista);
    idPaisABuscar = pedirEntero(" ");

    if(buscarPaisPorId(idPaisABuscar, listaPaises, tamanioLista) == -1)
    {
        printf("Pais invalido.\n");
        idPais = -1;
    }
    else
    {
        idPais = idPaisABuscar;
    }
    return idPais;
}


int buscarIdPaisConMayorCantidadMascotas(ePais listaPaises[], int tamanioListaPaises)
{
    int maximaCantidadMascotas;
    int idPaisMaximaCantidadMascotas;
    int i;

    for(i = 0; i < tamanioListaPaises; i++)
    {
        if(i == 0 || listaPaises[i].cantidadMascotas > maximaCantidadMascotas)
        {
            maximaCantidadMascotas = listaPaises[i].cantidadMascotas;
            idPaisMaximaCantidadMascotas = listaPaises[i].idPais;
        }
    }
    return idPaisMaximaCantidadMascotas;
}


void mostrarPaisPorIdPais(ePais listaPaises[], int tamanioListaPaises, int idPais)
{
    int i;
    for(i = 0; i < tamanioListaPaises; i++)
    {
        if(listaPaises[i].idPais == idPais)
        {
            printf(" %15s %17s %19d\n", listaPaises[i].nombrePais, listaPaises[i].continentePais, listaPaises[i].codigoArea);
        }
    }
}


void mostrarPaisConMayorCantidadMascotas(ePais listaPaises[], int tamanioListaPaises)
{
    int idPais;

    idPais = buscarIdPaisConMayorCantidadMascotas(listaPaises, tamanioListaPaises);
    mostrarPaisPorIdPais(listaPaises, tamanioListaPaises, idPais);
}

int IncrementarCantidadMascotaPorPais(ePais listaPais[], int tamanioListaPais, int idPais)
{
    int i;

    for(i = 0; i < tamanioListaPais; i++)
    {
        if(listaPais[i].idPais == idPais)
        {
            listaPais[i].cantidadMascotas = listaPais[i].cantidadMascotas + 1;
        }
    }
}

int decrementarCantidadMascotaPorPais(ePais listaPais[], int tamanioListaPais, int idPais)
{
    int i;

    for(i = 0; i < tamanioListaPais; i++)
    {
        if(listaPais[i].idPais == idPais)
        {
            listaPais[i].cantidadMascotas = listaPais[i].cantidadMascotas - 1;
        }
    }
}

//no va
void ordenarPaisPorCodigoArea(ePais listaPais[], int tamanioListaPais)
{
    int i;
    int j;
    ePais aux;

    for(i = 0; i < tamanioListaPais; i++)
    {
        for(j = i+1; j < tamanioListaPais; j++)
        {
            if(listaPais[i].codigoArea < listaPais[j].codigoArea)
            {
                aux = listaPais[i];
                listaPais[i] = listaPais[j];
                listaPais[j] = aux;
            }
        }
    }
}

int buscarPaisPorId(int idABuscar, ePais listaPaises[], int tamanioLista)
{
    int i;
    int resultado;

    resultado = -1;

    for(i = 0; i< tamanioLista; i++)
    {
        if(idABuscar == listaPaises[i].idPais)
        {
            resultado = 1;
        }

    }
    return resultado;
}
