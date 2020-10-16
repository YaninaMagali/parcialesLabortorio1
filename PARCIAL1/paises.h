#ifndef PAISES_H_INCLUDED
#define PAISES_H_INCLUDED
typedef struct
{
    int idPais;
    int cantidadMascotas;
    char nombrePais[20];
    char continentePais[10];
    int codigoArea;
}ePais;

void hardcodearPaises(ePais lista[], int tamanioListaPaises);
void mostrarPaises(ePais paisData);
void mostrarListaPaises(ePais lista[],  int tamanioLista);
void mostrarPaisPorIdPais(ePais listaPaises[], int tamanioListaPaises, int idPais);
void mostrarPaisConMayorCantidadMascotas(ePais listaPaises[], int tamanioListaPaises);

int elegirPaisOrigenRaza(ePais listaPaises[], int tamanioLista);
int buscarPaisPorId(int idABuscar, ePais listaPaises[], int tamanioLista);
int buscarIndicePaisPorId(int idABuscar, ePais listaPaises[], int tamanioLista);
int buscarIdPaisConMayorCantidadMascotas(ePais listaPaises[], int tamanioListaPaises);

int IncrementarCantidadMascotaPorPais(ePais listaPais[], int tamanioListaPais, int idPais);
int decrementarCantidadMascotaPorPais(ePais listaPais[], int tamanioListaPais, int idPais);

void ordenarPaisPorCodigoArea(ePais listaPais[], int tamanioListaPais);




#endif // PAISES_H_INCLUDED
