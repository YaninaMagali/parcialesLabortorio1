#ifndef RAZAS_H_INCLUDED
#define RAZAS_H_INCLUDED

typedef struct
{
    int idRaza;
    char descripcionRaza[15];
    char tamanioRaza[8];
    int idPaisOrigen;
    int estaVacio;
}eRaza;

void hardcodearRazas(eRaza lista[], int tamanioListaRaza);
int ElegirRazaAAsignar(eRaza listaRazas[], int tamanioListaRaza);

void inicializarArrayRazaComoVacio(eRaza listaRazas[], int T);
int buscarPrimerEspacioVacioEnListadoRaza(eRaza listaRazas[], int T);
int cambiarEstadoRazaEstaVacio(eRaza razaData);

int buscarIdRazaPorIndice(eRaza listaRazas[],  int tamanioListaRaza, int indice);
int buscarIdPaisOrigenPorIdRaza(eRaza listaRazas[],  int tamanioListaRaza, int idRaza);
int buscarRazaPorId(eRaza listaRazas[],  int tamanioListaRaza, int idRaza);
int buscarRazaPorIdPais(eRaza listaRazas[],  int tamanioListaRaza, int idPais);

void mostrarRazaPorIdRaza(eRaza listaRazas[],  int tamanioListaRaza, int idRaza);

//VER ESTAS DOS
void mostrarDescripcionRazas(eRaza razaData);
void mostrarListaDescripcionRazas(eRaza listaRazas[],  int tamanioListaRaza);


int pedirTamanioRaza(char* tamanioRaza);


#endif // RAZAS_H_INCLUDED
