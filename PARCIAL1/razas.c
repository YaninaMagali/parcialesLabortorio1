#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "razas.h"
#include "pedirDatos.h"
#define TAMANIO_DESC_RAZA 15
#define TAMANIO_TAMANIO_RAZA 15
#define TAMANIO_ORIGEN_RAZA 20

/*
* Carga 4 razas en el listado de razas
* Recibe el array donde se van a guardar las razas
* Sin retorno
*/
void hardcodearRazas(eRaza lista[], int tamanioListaRaza)
{
    int idRaza[6] = {1,2,3,4, 5, 6};
    char descripcionRaza[6][15] = {"Siames", "Doberman", "Persa", "PastorBelga", "DogoArgentino", "PastorAleman"};
    char tamanioRaza[6][9] = {"Chico", "Grande", "Mediano", "Grande", "Grande", "Grande"};
    int idPaisOrigen[6] = {1, 2, 3, 4, 5, 2};
    int estaVacio [6] = {0,0,0,0,0,0};

    int i;

    for(i = 0; i < 6; i++)
    {
        lista[i].idRaza =  idRaza[i];
        strcpy(lista[i].descripcionRaza, descripcionRaza[i]);
        strcpy(lista[i].tamanioRaza, tamanioRaza[i]);
        lista[i].idPaisOrigen = idPaisOrigen[i];
        lista[i].estaVacio = estaVacio[i];

    }
}


void inicializarArrayRazaComoVacio(eRaza listaRazas[], int T)
{
    int i;

    for(i = 0 ; i < T; i++)
    {
        listaRazas[i].estaVacio = 1;
    }
}

int buscarPrimerEspacioVacioEnListadoRaza(eRaza listaRazas[], int T)
{
    int i;

    for(i = 0; i< T; i++)
    {
        if(listaRazas[i].estaVacio == 1 && i != T)
        {
            break;
        }
        if(i == T)
        {
            i = -1;
        }
    }
    return i;
}


int cambiarEstadoRazaEstaVacio(eRaza razaData)
{
    int estaVacioLocal;

    if(razaData.estaVacio == 0)
    {
        estaVacioLocal = 1;
    }
    else
    {
        estaVacioLocal = 0;
    }
    return estaVacioLocal;
}


int chequearExistenciaRazaPorId(eRaza listaRazas[],  int tamanioListaRaza, int idRaza)//cambiar nombre, ya que esto en realidad SOLO chequea si existe
{
    int i;
    int resultadoBusqueda;

    resultadoBusqueda = -1;

    for(i = 0; i < tamanioListaRaza; i++)
    {
        if(listaRazas[i].idRaza  == idRaza)
        {
            resultadoBusqueda = 1;
        }
    }
    return resultadoBusqueda;
}

///////////// PODRIA BORRAR ESTA FUNCION
void mostrarDescripcionRazas(eRaza razaData)
{
    printf("%1d %4s %9s\n", razaData.idRaza, razaData.descripcionRaza, razaData.tamanioRaza);
}

///////////// PODRIA BORRAR ESTA FUNCION
void mostrarListaDescripcionRazas(eRaza listaRazas[],  int tamanioListaRaza)
{
    int i;

    for(i = 0; i < tamanioListaRaza; i++)
    {
        if(listaRazas[i].estaVacio == 0)
        {
            mostrarDescripcionRazas(listaRazas[i]);
        }
    }
}


int ElegirRazaAAsignar(eRaza listaRazas[], int tamanioListaRaza)
{
    int id;
    int idAAsignar;

    idAAsignar = -1;

    printf("Ingresar opcion correspondiente a la raza que desea cargar: \n");
    mostrarListaDescripcionRazas(listaRazas,tamanioListaRaza);


    id = pedirEntero(" ");

    if(chequearExistenciaRazaPorId(listaRazas,tamanioListaRaza, id) == -1)
    {
        printf("Raza inexistente.");
    }
    else
    {
        idAAsignar = id;
    }
    return idAAsignar;
}

int buscarIdPaisOrigenPorIdRaza(eRaza listaRazas[],  int tamanioListaRaza, int idRaza)
{
    int i;
    int idPais;

    for(i = 0; i< tamanioListaRaza; i++)
    {
        if(listaRazas[i].idRaza == idRaza)
        {
            idPais = listaRazas[i].idPaisOrigen;
        }
    }
    return idPais;
}



int buscarIndicePorIdRaza(eRaza listaRazas[],  int tamanioListaRaza, int idRaza)
{
    int i;
    int indice;

    for(i = 0; i< tamanioListaRaza; i++)
    {
        if(listaRazas[i].idRaza == idRaza)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarRazaPorIdRaza(eRaza listaRazas[],  int tamanioListaRaza, int idRaza)
{
    int i;

    for(i = 0; i < tamanioListaRaza; i++)
    {
        if(listaRazas[i].idRaza == idRaza)
        {
            printf("%14s %16s", listaRazas[i].descripcionRaza , listaRazas[i].tamanioRaza);
        }
    }
}

int buscarRazaPorIdPais(eRaza listaRazas[],  int tamanioListaRaza, int idPais)
{
    int i;
    int idPaisEncontrado;
    for(i = 0; i < tamanioListaRaza; i++)
    {
        if(listaRazas[i].idPaisOrigen == idPais)
        {
            idPaisEncontrado = listaRazas[i].idPaisOrigen;
            break;
        }
    }
    return idPaisEncontrado;
}

int pedirTamanioRaza(char tamanioRaza[])
{
    int resultado;

    resultado = -1;
    obtenerCadena("Ingresa el tamanio de la raza, puede ser Grande, Mediano o chico\n", "Error,solo letras\n", tamanioRaza, TAMANIO_TAMANIO_RAZA);
    formatearNombrePropio(tamanioRaza);
    if(strcmp(tamanioRaza, "Grande")== 0 || strcmp(tamanioRaza, "Mediano")== 0 || strcmp(tamanioRaza, "Chico")== 0)
    {
        resultado = 0;
    }
    else
    {
        printf("Tamanio ingresado no es valido\n");
    }
    return resultado;
}

