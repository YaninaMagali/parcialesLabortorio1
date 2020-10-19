#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED
typedef struct
{
    int idMascota;
    char nombreMascota[20];
    int edadMascota;
    char sexoMascota;
    float pesoMascota;
    char tipoMascota[15];
    int idRaza;
    int estaVacio;
}eMascota;

void hardcodearMascota(eMascota lista[], int tamanioListaMascota);
void inicializarArrayComoVacio(eMascota listaMascota[], int T);
int buscarPrimerEspacioVacioEnListado(eMascota listaMascota[], int T);
int buscarIndiceMascotaPorId(eMascota listaMascota[], int tamanioLista, int idSolicitado);
int cambiarEstadoEstaVacio(eMascota mascotaData);

float sumarPesoTotalPorTipo(eMascota listaMascota[], int tamanioListaMascota, char tipo[]);
float contarCantidadMascotasPorTipo(eMascota listaMascota[], int tamanioListaMascota, char tipo[]);

int buscarIdMascotaPorIdRaza(eMascota listaMascota[], int tamanioListaMascota, int idRazaRecibido);

void mostrarSumaPesosCantidadYPromedioPorTipo(eMascota listaMascota[], int tamanioListaMascota);
#endif // MASCOTAS_H_INCLUDED
