#include <string.h>
#include <stdio.h>
#include "mascotas.h"
#include "pedirDatos.h"
#define TAMANIO_NOMBRE 50
#define TAMANIO_TIPO 15


/*
* Carga 5 mascotas en el listado
* Recibe el array donde se van a guardar las mascotas
* Sin retorno
*/
void hardcodearMascota(eMascota lista[], int tamanioListaMascota)
{
    int id[7] = {1, 2, 3, 4, 5, 6, 7};
    char nombreMascota[7][20] = {"Pepito", "Jaimito","Lola", "Pelu","Daisy", "Milito", "Swarz"};
    int edadMascota[7] = {3, 8, 2, 1, 3, 9,1};
    char sexoMascota[7] = {'M', 'M', 'F', 'F', 'F', 'M','M'};
    float pesoMascota[7] = {4.5, 3.1, 2.00, 8.23, 6.87, 8.87, 1.3};
    char tipoMascota[7][15] = {"Gato", "Gato","Gato", "Perro", "Perro", "Perro", "Perro"};
    int idRaza[7] = {6, 3, 3, 2, 4, 5, 6};
    int estaVacio[7] = {0,0,0,0,0,0,0};

    int i;

    for(i = 0; i < 7; i++)
    {
        lista[i].idMascota =  id[i];
        strcpy(lista[i].nombreMascota, nombreMascota[i]);
        lista[i].edadMascota = edadMascota[i];
        lista[i].sexoMascota = sexoMascota[i];
        lista[i].pesoMascota = pesoMascota[i];
        strcpy(lista[i].tipoMascota, tipoMascota[i]);
        lista[i].idRaza = idRaza[i];
        lista[i].estaVacio = estaVacio[i];
    }
}

/*
* Inicializa el listado mascotas como vacio
* Recibe listado de mascotas
* Sin retorno
*/
void inicializarArrayComoVacio(eMascota listaMascota[], int T)
{
    int i;

    for(i = 0 ; i < T; i++)
    {
        listaMascota[i].estaVacio = 1;
    }
}

/*
* Busca el primer lugar vacio dentro del array
* Recibe el listado de mascotas
* Sin retorno
*/
int buscarPrimerEspacioVacioEnListado(eMascota listaMascota[], int T)
{
    int i;

    for(i = 0; i< T; i++)
    {
        if(listaMascota[i].estaVacio == 1 && i != T)
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

/*
* Modifica el estado vacio de una mascota, teniendo en cuenta el estado actual
* Recibe la mascota
* Devuelve el nuevo estado
*/
int cambiarEstadoEstaVacio(eMascota mascotaData)
{
    int estaVacioLocal;

    if(mascotaData.estaVacio == 0)
    {
        estaVacioLocal = 1;
    }
    else
    {
        estaVacioLocal = 0;
    }
    return estaVacioLocal;
}


/*
* Busca el indice donde esta cargada la mascota por medio del ID y lo devuelve
* Recibe el id de la mascota, el listado y su tamanio
* Devuelve el indice
*/
int buscarIndiceMascotaPorId(eMascota listaMascota[], int tamanioLista, int idSolicitado)
{
    int i;
    int indice;

    for(i = 0; i< tamanioLista; i++)
    {
        if(listaMascota[i].idMascota == idSolicitado && listaMascota[i].estaVacio == 0)
        {
            indice = i;
            break;
        }
        else
        {
            indice = -1;
        }
    }
    return indice;
}
// El prob es uque itera en el for sin punto de corte. PERO si le pongo un BREAK cuando vuelva a iterar va a mostrar el indice 0.
// se ve cuando tengo mas de una mascota con el mismo IDRaza
int buscarIdMascotaPorIdRaza(eMascota listaMascota[], int tamanioListaMascota, int idRazaRecibido)
{
    int i;
    int idMascota;

    for(i=0 ; i < tamanioListaMascota; i++)
    {
        if(idRazaRecibido == listaMascota[i].idRaza && listaMascota[i].estaVacio == 0)
        {
            idMascota = listaMascota[i].idMascota;
        }
    }

    return idMascota;
}

float sumarPesoTotalPorTipo(eMascota listaMascota[], int tamanioListaMascota, char tipo[])
{
    float sumaPesos;
    int i;

    sumaPesos = 0;

    for(i = 0; i < tamanioListaMascota; i++)
    {
        if(strcmp(listaMascota[i].tipoMascota,tipo) == 0)
        {
            sumaPesos = sumaPesos + listaMascota[i].pesoMascota;
        }
    }

    return sumaPesos;
}


float contarCantidadMascotasPorTipo(eMascota listaMascota[], int tamanioListaMascota, char tipo[])
{
    float contadorMascotas;
    int i;

    contadorMascotas = 0;

    for(i = 0; i < tamanioListaMascota; i++)
    {
        if(strcmp(listaMascota[i].tipoMascota, tipo) == 0)
        {
            contadorMascotas = contadorMascotas+1;
        }
    }

    return contadorMascotas;
}

float calcularPesoPorIdRaza(int idRaza, eMascota listaMascotas[], int tamanioListaMascotas)
{
    int i;
    float sumaTotalPesosPorId;

    sumaTotalPesosPorId = 0;

    for(i = 0; i < tamanioListaMascotas; i++)
    {
        if(idRaza == listaMascotas[i].idRaza)
        {
            sumaTotalPesosPorId = sumaTotalPesosPorId + listaMascotas[i].pesoMascota;
        }
    }
    return sumaTotalPesosPorId;
}

void mostrarSumaPesosCantidadYPromedioPorTipo(eMascota listaMascota[], int tamanioListaMascota)
{
    float sumaPesosPerros;
    float sumaPesosGatos;
    float cantidadTotalPerros;
    float cantidadTotalGatos;
    float promedioPesoPerros;
    float promedioPesoGatos;

    sumaPesosPerros = sumarPesoTotalPorTipo(listaMascota, tamanioListaMascota, "Perro");
    sumaPesosGatos = sumarPesoTotalPorTipo(listaMascota, tamanioListaMascota, "Gato");
    cantidadTotalPerros = contarCantidadMascotasPorTipo(listaMascota, tamanioListaMascota, "Perro");
    cantidadTotalGatos = contarCantidadMascotasPorTipo(listaMascota, tamanioListaMascota, "Gato");
    promedioPesoPerros = calcularPromedio(sumaPesosPerros, cantidadTotalPerros);
    promedioPesoGatos = calcularPromedio(sumaPesosGatos, cantidadTotalGatos);

    printf("\n       |  PESO TOTAL POR TIPO  |  CANTIDAD POR TIPO  |  PROMEDIO POR TIPO");
    printf("\nPERROS %16.2f %21.2f %22.2f\n", sumaPesosPerros,cantidadTotalPerros, promedioPesoPerros);
    printf("GATOS  %16.2f %21.2f %22.2f\n", sumaPesosGatos,cantidadTotalGatos, promedioPesoGatos);
}
