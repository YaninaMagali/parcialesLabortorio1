#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pedirDatos.h"
#include "menu.h"
#include "MascotasRazasPaises.h"
#define TAM_LISTA_PAISES 5
#define TAM_LISTA_RAZA 10
#define TAM_LISTA_MASCOTA 10
#define TAMANIO_DESC_RAZA 15
#define TAMANIO_TAMANIO_RAZA 15

void menu(void)
{
    int opcion;
    ePais listaPaises[TAM_LISTA_PAISES];
    eRaza listaRazas[TAM_LISTA_RAZA];
    eMascota listaMascota[TAM_LISTA_MASCOTA];
    int fila;
    int filaRaza;
    int ultimoIdMascota;
    int idRaza;
    int idRazaSolicitada;
    int idMascotaSolicitado;
    float sumaPesosPerros;
    float sumaPesosGatos;
    float cantidadTotalPerros;
    float cantidadTotalGatos;
    float promedioPesoPerros;
    float promedioPesoGatos;
    char tamanioRaza[TAMANIO_TAMANIO_RAZA];
    float sumaPesosPorTamanio;

    ultimoIdMascota = 5;
    idRaza = 4;
    sumaPesosPorTamanio=0;

    inicializarArrayComoVacio(listaMascota, TAM_LISTA_MASCOTA);
    inicializarArrayRazaComoVacio(listaRazas, TAM_LISTA_RAZA);
    hardcodearPaises(listaPaises, TAM_LISTA_PAISES);
    hardcodearMascota(listaMascota, TAM_LISTA_MASCOTA);
    hardcodearRazas(listaRazas, TAM_LISTA_RAZA);
    printf("FIN SETTING\n");

    do
    {
        opcion = pedirEntero("\nOPCIONES MENU.\n 1. CARGAR MASCOTAS\n 2. BORRAR MASCOTA\n 3. EDITAR MASCOTA\n 4. MOSTRAR MASCOTAS\n 5. MOSTRAR MASCOTAS POR RAZA\n 6. MOSTRAR MASCOTAS POR PESO\n 7. MOSTRAR MASCOTAS POR COD AREA\n 8. CARGAR RAZA\n 9. BORRAR RAZA\n 10. MOSTRAR RAZAS\n 11. MOSTRAR PAISES\n 12. MOSTRAR POR TIPO y PESO\n 13. MOSTRAR POR TAMANIO\n 0. SALIR\n");

        switch(opcion)
        {
        case 1: // CARGAR MASCOTAS
            fila = buscarPrimerEspacioVacioEnListado(listaMascota, TAM_LISTA_MASCOTA);
            if(fila == -1 || fila == TAM_LISTA_MASCOTA)
            {
                printf("No hay mas espacio en el listado\n");
            }
            else
            {
                listaMascota[fila] = cargarMascota(listaMascota[fila], ultimoIdMascota, listaRazas, TAM_LISTA_RAZA, listaPaises, TAM_LISTA_PAISES);
            }
            break;
        case 2: // BORRAR MASCOTA
            idMascotaSolicitado = pedirIdMascota(listaMascota, TAM_LISTA_MASCOTA, listaRazas, TAM_LISTA_RAZA, listaPaises, TAM_LISTA_PAISES);
            if(borrarMascota(idMascotaSolicitado, listaMascota, TAM_LISTA_MASCOTA, listaRazas, TAM_LISTA_RAZA, listaPaises, TAM_LISTA_PAISES)==0)
            {
                printf("La mascota se elimino correctamente\n");
            }
            break;
        case 3: // EDITAR MASCOTAS
            editarMascota(listaMascota, TAM_LISTA_MASCOTA, listaRazas, TAM_LISTA_RAZA, listaPaises, TAM_LISTA_PAISES);
            break;
        case 4:
            printf("\nID|  NOMBRE   |   EDAD    |   SEXO   |   PESO    |   TIPO   |   RAZA   |   TAMANIO   |  ORIGEN    |     CONTINENTE    |   COD  AREA\n");
            mostrarListaMascota(listaMascota, TAM_LISTA_MASCOTA, listaRazas, TAM_LISTA_RAZA, listaPaises, TAM_LISTA_PAISES);
            break;
        case 5:
            mostrarListaMascotasPorRaza(listaMascota, TAM_LISTA_MASCOTA, listaRazas, TAM_LISTA_RAZA, listaPaises, TAM_LISTA_PAISES);
            break;
        case 6:
            printf("\nID|  NOMBRE   |   EDAD    |   SEXO   |   PESO    |   TIPO   |   RAZA   |  TAMANIO   |  ORIGEN    |     CONTINENTE    |   COD  AREA\n");
            mostrarMascotaOrdenadaPorPeso(listaMascota, TAM_LISTA_MASCOTA, listaRazas, TAM_LISTA_RAZA, listaPaises, TAM_LISTA_PAISES);
            break;
        case 7:
            //mostrarMascotaOrdenadaPorCodigoArea(listaPaises, TAM_LISTA_PAISES, listaRazas, TAM_LISTA_RAZA, listaMascota, TAM_LISTA_MASCOTA);
            break;
        case 8: // CARGAR RAZAS
            filaRaza = buscarPrimerEspacioVacioEnListadoRaza(listaRazas, TAM_LISTA_RAZA);
            if(filaRaza == -1 || filaRaza == TAM_LISTA_RAZA)
            {
                printf("No hay mas espacio en el listado\n");
            }
            else
            {
                listaRazas[filaRaza] = cargarRaza(listaRazas[filaRaza], idRaza, listaPaises, TAM_LISTA_PAISES);
            }
            break;
        case 9: // BORRAR RAZAS
            idRazaSolicitada = pedirRaza(listaRazas, TAM_LISTA_RAZA, listaPaises, TAM_LISTA_PAISES);

            if(borrarRaza(listaMascota, TAM_LISTA_MASCOTA, idRazaSolicitada, listaRazas, TAM_LISTA_RAZA, listaPaises, TAM_LISTA_PAISES)==0)
            {
                printf("La raza se elimino correctamente\n");
            }
            break;
        case 10:// MOSTRAR RAZAS
            mostrarListaRazas(listaRazas,TAM_LISTA_RAZA, listaPaises, TAM_LISTA_PAISES);
            break;
        case 11:
            mostrarListaPaises(listaPaises, TAM_LISTA_PAISES);
            printf("\nEl pais con mayor cantidad de mascotas registradas es:");
            mostrarPaisConMayorCantidadMascotas(listaPaises, TAM_LISTA_PAISES);
            break;
        case 12: // SUMA TOTAL DE PESOS POR TIPO PASAR TODO ESTO A UNA FUNCION
            sumaPesosPerros = sumarPesoTotalPorTipo(listaMascota, TAM_LISTA_MASCOTA, "Perro");
            sumaPesosGatos = sumarPesoTotalPorTipo(listaMascota, TAM_LISTA_MASCOTA, "Gato");
            cantidadTotalPerros = contarCantidadMascotasPorTipo(listaMascota, TAM_LISTA_MASCOTA, "Perro");
            cantidadTotalGatos = contarCantidadMascotasPorTipo(listaMascota, TAM_LISTA_MASCOTA, "Gato");
            promedioPesoPerros = calcularPromedio(sumaPesosPerros, cantidadTotalPerros);
            promedioPesoGatos = calcularPromedio(sumaPesosGatos, cantidadTotalGatos);

            printf("\n       |  PESO TOTAL POR TIPO  |  CANTIDAD POR TIPO  |  PROMEDIO POR TIPO");
            printf("\nPERROS %16.2f %21.2f %22.2f\n", sumaPesosPerros,cantidadTotalPerros, promedioPesoPerros);
            printf("GATOS  %16.2f %21.2f %22.2f\n", sumaPesosGatos,cantidadTotalGatos, promedioPesoGatos);
            break;
        case 13:
            if(pedirTamanioRaza(tamanioRaza)== 0)
            {
                printf("\nID|  NOMBRE   |   EDAD    |   SEXO   |   PESO    |   TIPO   |   RAZA   |   TAMANIO   |  ORIGEN    |     CONTINENTE    |   COD  AREA\n");
                mostrarMascotaPorTamanio(tamanioRaza, listaMascota, TAM_LISTA_MASCOTA, listaRazas, TAM_LISTA_RAZA, listaPaises, TAM_LISTA_PAISES);
                sumaPesosPorTamanio = sumarPesoTotalPorTamanio(tamanioRaza, listaMascota, TAM_LISTA_MASCOTA, listaRazas, TAM_LISTA_RAZA);
                printf("sumaPesosPorTamanio es %.2f", sumaPesosPorTamanio);
            }
            break;
        }
    }
    while(opcion!=0);
}
