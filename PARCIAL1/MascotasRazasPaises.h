#ifndef MASCOTASRAZASPAISES_H_INCLUDED
#define MASCOTASRAZASPAISES_H_INCLUDED
#include "mascotas.h"
#include "razas.h"
#include "paises.h"
eRaza cargarRaza(eRaza razaData, int ultimoIdRaza, ePais listaPaises[], int tamanioListaPaises);

int pedirRaza(eRaza listaRazas[], int tamanioListaRaza, ePais listaPaises[], int tamanioListaPaises);
int pedirIdMascota(eMascota listaMascota[], int tamanioLista, eRaza listaRazas[], int tamanioListaRaza, ePais listaPaises[], int tamanioListaPaises);

void mostrarRazas(eRaza razaData, ePais listaPaises[], int tamanioListaPaises);
void mostrarListaRazas(eRaza listaRazas[],  int tamanioListaRaza, ePais listaPaises[], int tamanioListaPaises);
void mostrarUnaMascotaPorIdRaza(eMascota listaMascota[], int tamanioListaMascota, int idRazaRecibido, eRaza listaRazas[],  int tamanioListaRaza, ePais listaPaises[], int tamanioListaPaises);
void mostrarListaMascotasPorRaza(eMascota listaMascota[], int tamanioListaMascota, eRaza listaRazas[],  int tamanioListaRaza, ePais listaPaises[], int tamanioListaPaises);
void mostrarMascota(eMascota mascotaData, eRaza listaRazas[],  int tamanioListaRaza, ePais listaPaises[], int tamanioListaPaises);
void mostrarListaMascota(eMascota listaMascota[], int tamanioLista, eRaza listaRazas[], int tamanioListaRaza, ePais listaPaises[], int tamanioListaPaises);
void mostrarMascotaOrdenadaPorPeso(eMascota listaMascota[], int tamanioLista, eRaza listaRazas[],  int tamanioListaRaza, ePais listaPaises[], int tamanioListaPaises);
void mostrarMascotaOrdenadaPorCodigoArea(ePais listaPaises[], int tamanioListaPaises, eRaza listaRazas[],  int tamanioListaRaza, eMascota listaMascota[], int tamanioListaMascota);
void mostrarMascotaPorTamanio(char tamanio[],eMascota listaMascota[], int tamanioListaMascota, eRaza listaRazas[],int tamanioListaRaza, ePais listaPaises[], int tamanioListaPaises);

eMascota cargarMascota(eMascota mascotaData, int idMascota, eRaza listaRazas[], int tamanioListaRaza, ePais listaPaises[], int tamanioListaPais);
int borrarMascota(int idMascota, eMascota listaMascota[], int tamanioLista, eRaza listaRazas[],  int tamanioListaRaza, ePais listaPaises[], int tamanioListaPais);
int editarMascota(eMascota listaMascota[], int tamanioLista, eRaza listaRazas[], int tamanioListaRaza, ePais listaPaises[], int tamanioListaPais);

int buscarIndicePorIdRaza(eRaza listaRazas[], int tamanioListaRaza, int idRaza);
int buscarIdMascotaPorIdRaza(eMascota listaMascota[], int tamanioListaMascota, int idRazaRecibido);





#endif // MASCOTASRAZASPAISES_H_INCLUDED
