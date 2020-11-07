#include <string.h>
#include <stdio.h>
#include "MascotasRazasPaises.h"
#include "pedirDatos.h"
#define TAMANIO_NOMBRE 50
#define TAMANIO_NOMBRE 50
#define TAMANIO_TIPO 15
#define TAMANIO_DESC_RAZA 15
#define TAMANIO_TAMANIO_RAZA 15
#define TAMANIO_ORIGEN_RAZA 20

int pedirRaza(eRaza listaRazas[], int tamanioListaRaza, ePais listaPaises[], int tamanioListaPaises)
{
    int idSolicitado;

    printf("Ingresa el ID de la raza: \n");
    mostrarListaRazas(listaRazas, tamanioListaRaza, listaPaises, tamanioListaPaises);
    idSolicitado = pedirEntero(" ");

    return idSolicitado;

}

int pedirIdMascota(eMascota listaMascota[], int tamanioLista, eRaza listaRazas[], int tamanioListaRaza, ePais listaPaises[], int tamanioListaPaises)
{
    int idSolicitado;

    printf("Ingresa el ID de la mascota: \n");
    mostrarListaMascota(listaMascota, tamanioLista, listaRazas, tamanioListaRaza, listaPaises, tamanioListaPaises);
    idSolicitado = pedirEntero(" ");

    return idSolicitado;

}

void mostrarRazas(eRaza razaData, ePais listaPaises[], int tamanioListaPaises)
{
    printf("%4d %10s %19s", razaData.idRaza , razaData.descripcionRaza , razaData.tamanioRaza);
    mostrarPaisPorIdPais(listaPaises, tamanioListaPaises, razaData.idPaisOrigen);
}

void mostrarListaRazas(eRaza listaRazas[],  int tamanioListaRaza, ePais listaPaises[], int tamanioListaPaises)
{
    int i;

    printf("\n|ID|   DESCRIPCION     |     TAMANIO      |    ORIGEN   |     CONTINENTE    |   COD  AREA\n");

    for(i = 0; i < tamanioListaRaza; i++)
    {
        if(listaRazas[i].estaVacio == 0)
        {
            mostrarRazas(listaRazas[i], listaPaises, tamanioListaPaises);
        }
    }
}

void mostrarUnaMascotaPorIdRaza(eMascota listaMascota[], int tamanioListaMascota, int idRazaRecibido, eRaza listaRazas[],  int tamanioListaRaza, ePais listaPaises[], int tamanioListaPaises)
{
    int i;
    for(i = 0; i < tamanioListaMascota; i++)
    {
        if(listaMascota[i].idRaza == idRazaRecibido && listaMascota[i].estaVacio == 0)
        {
            mostrarMascota(listaMascota[i], listaRazas, tamanioListaRaza, listaPaises, tamanioListaPaises);
        }
    }
}

void mostrarListaMascotasPorRaza(eMascota listaMascota[], int tamanioListaMascota, eRaza listaRazas[],  int tamanioListaRaza, ePais listaPaises[], int tamanioListaPaises)
{
    int i;
    for(i = 0; i<tamanioListaRaza; i++)
    {
        if(listaRazas[i].estaVacio == 0)
        {
            mostrarUnaMascotaPorIdRaza(listaMascota, tamanioListaMascota, listaRazas[i].idRaza , listaRazas, tamanioListaRaza, listaPaises, tamanioListaPaises);
        }

    }
}

void mostrarMascota(eMascota mascotaData, eRaza listaRazas[],  int tamanioListaRaza, ePais listaPaises[], int tamanioListaPaises)
{
    int idPais;

    idPais = buscarIdPaisOrigenPorIdRaza(listaRazas, tamanioListaRaza, mascotaData.idRaza);
    printf("%1d %8s %9d %10c %11.2f %11s", mascotaData.idMascota, mascotaData.nombreMascota, mascotaData.edadMascota, mascotaData.sexoMascota, mascotaData.pesoMascota, mascotaData.tipoMascota);
    mostrarRazaPorIdRaza(listaRazas, tamanioListaRaza, mascotaData.idRaza);
    mostrarPaisPorIdPais(listaPaises, tamanioListaPaises, idPais);
}

void mostrarListaMascota(eMascota listaMascota[], int tamanioLista, eRaza listaRazas[], int tamanioListaRaza, ePais listaPaises[], int tamanioListaPaises)
{
    int i;

    for(i=0; i< tamanioLista; i++)
    {
        if(listaMascota[i].estaVacio == 0)
        {
            mostrarMascota(listaMascota[i], listaRazas, tamanioListaRaza, listaPaises, tamanioListaPaises);
        }
    }
}

void mostrarMascotaOrdenadaPorPeso(eMascota listaMascota[], int tamanioLista, eRaza listaRazas[],  int tamanioListaRaza, ePais listaPaises[], int tamanioListaPaises)
{
    int i;
    int j;
    eMascota aux;

    for(i = 0; i < tamanioLista; i++)
    {
        for(j = i+1; j < tamanioLista; j++)
        {
            if(listaMascota[i].pesoMascota < listaMascota[j].pesoMascota)
            {
                aux = listaMascota[i];
                listaMascota[i] = listaMascota[j];
                listaMascota[j] = aux;
            }
        }
    }
    mostrarListaMascota(listaMascota, tamanioLista, listaRazas, tamanioListaRaza, listaPaises, tamanioListaPaises);
}

void mostrarMascotaPorTamanio(char tamanio[],eMascota listaMascota[], int tamanioListaMascota, eRaza listaRazas[],int tamanioListaRaza, ePais listaPaises[], int tamanioListaPaises)
{
    int i;
    for(i = 0; i < tamanioListaRaza; i++)
    {
        if(strcmp(listaRazas[i].tamanioRaza, tamanio) == 0)
        {
           mostrarUnaMascotaPorIdRaza(listaMascota, tamanioListaMascota, listaRazas[i].idRaza , listaRazas, tamanioListaRaza, listaPaises, tamanioListaPaises);
        }
    }

}

void mostrarMascotaOrdenadaPorCodigoArea(eMascota listaMascota[], int tamanioListaMascota, eRaza listaRazas[],  int tamanioListaRaza, ePais listaPaises[], int tamanioListaPaises)
{
    int i;
    int j;
    int idPaisI;
    int indicePaisI;
    int idPaisJ;
    int indicePaisJ;
    eMascota aux;

    for(i = 0; i < tamanioListaMascota; i++)
    {

        for(j = i+1; j < tamanioListaMascota; j++)
        {
            idPaisI = buscarIdPaisOrigenPorIdRaza(listaRazas, tamanioListaRaza, listaMascota[i].idRaza);
            indicePaisI = buscarIndicePaisPorId(idPaisI, listaPaises, tamanioListaPaises);
            idPaisJ = buscarIdPaisOrigenPorIdRaza(listaRazas, tamanioListaRaza, listaMascota[j].idRaza);
            indicePaisJ = buscarIndicePaisPorId(idPaisJ, listaPaises, tamanioListaPaises);

            if(listaPaises[indicePaisI].codigoArea < listaPaises[indicePaisJ].codigoArea)
            {
                aux = listaMascota[i];
                listaMascota[i] = listaMascota[j];
                listaMascota[j] = aux;

            }
        }
    }
    mostrarListaMascota(listaMascota, tamanioListaMascota, listaRazas, tamanioListaRaza, listaPaises, tamanioListaPaises);
}

/*
* Carga una mascota en el listado de mascotas.
* Recibe el id de la raza, el id de la mascota y el lugar donde se va a guardar la mascota
* Devuelve la mascota cargada
*/
eMascota cargarMascota(eMascota mascotaData, int* idMascota, eRaza listaRazas[], int tamanioListaRaza, ePais listaPaises[], int tamanioListaPais)
{
    int idRaza;
    int idPais;

    idRaza = ElegirRazaAAsignar(listaRazas, tamanioListaRaza);
    idPais = buscarIdPaisOrigenPorIdRaza(listaRazas, tamanioListaRaza, idRaza);

    if(idRaza != -1)
    {
        obtenerCadena("Nombre: ", "Error! Solo se pueden ingresar letras ", mascotaData.nombreMascota, TAMANIO_NOMBRE);
        mascotaData.edadMascota = pedirEntero("Edad: ");
        while(mascotaData.edadMascota < 0 || mascotaData.edadMascota > 20)
        {
            mascotaData.edadMascota = pedirEntero("Error! Edad debe ser menor a 20. Ingresar nuevamente: ");
        }
        mascotaData.sexoMascota = obtenerUnCaracter("Sexo> F o M: ");
        while(mascotaData.sexoMascota != 'M' && mascotaData.sexoMascota != 'F')
        {
            mascotaData.sexoMascota = obtenerUnCaracter("Error! Se puede ingresar F o M. Intentar nuevamente: ");
        }
        mascotaData.pesoMascota = pedirNumeroFlotante("Ingresar el peso de la mascota");
        while(mascotaData.pesoMascota <1)
        {
            mascotaData.pesoMascota = pedirNumeroFlotante("Error, el peso debe ser mayor a cero. Ingresar nuevamente: ");
        }
        obtenerCadena("Tipo > Perro, Gato, etc: ", "Error! Solo se pueden ingresar letras ", mascotaData.tipoMascota, TAMANIO_TIPO);
        mascotaData.estaVacio = cambiarEstadoEstaVacio(mascotaData);
        mascotaData.idMascota = generarId(idMascota);
        *idMascota = generarId(idMascota);
        mascotaData.idRaza = idRaza;//ElegirRazaAAsignar(listaRazas, tamanioListaRazas);

        IncrementarCantidadMascotaPorPais(listaPaises, tamanioListaPais, idPais);
    }
    return mascotaData;
}

int borrarMascota(int IdMascota, eMascota listaMascota[], int tamanioLista, eRaza listaRazas[],  int tamanioListaRaza, ePais listaPaises[], int tamanioListaPais)
{
    int indiceABorrar;
    int idRaza;
    int idPais;
    int resultado;

    resultado = -1;

    indiceABorrar = buscarIndiceMascotaPorId(listaMascota, tamanioLista, IdMascota);

    if(indiceABorrar!= -1)
    {
        if(confirmarAccionUsuario()== 1)
        {
            listaMascota[indiceABorrar].estaVacio = cambiarEstadoEstaVacio(listaMascota[indiceABorrar]);
            idRaza = listaMascota[indiceABorrar].idRaza;
            idPais = buscarIdPaisOrigenPorIdRaza(listaRazas, tamanioListaRaza, idRaza);
            decrementarCantidadMascotaPorPais(listaPaises, tamanioListaPais, idPais);
            resultado = 0;
        }
        else
        {
            printf("Operacion cancelada\n");
        }
    }
    else
    {
        printf("La mascota no esta en la lista\n");
    }
    return resultado;
}

int editarMascota(eMascota listaMascota[], int tamanioLista, eRaza listaRazas[], int tamanioListaRaza, ePais listaPaises[], int tamanioListaPais)
{
    int idMascotaIngresado;
    int indiceAEditar;
    int datoAModificar;
    int idRazaActual;
    int idPaisActual;
    int idNuevoPais;
    int resultado;
    char charAux[TAMANIO_NOMBRE];
    int intAux;
    float floatAux;
    char cAux;


    resultado = -1;

    idMascotaIngresado = pedirIdMascota(listaMascota, tamanioLista, listaRazas, tamanioListaRaza, listaPaises, tamanioListaPais);
    indiceAEditar = buscarIndiceMascotaPorId(listaMascota, tamanioLista, idMascotaIngresado);

    if(indiceAEditar!= -1)
    {
        datoAModificar = pedirEntero("Ingresar opcion de acuerdo al dato que se desea modificar \n 1. NOMBRE\n 2. EDAD\n 3. SEXO\n 4. PESO\n 5. TIPO MASCOSA\n 6. RAZA\n");
        switch(datoAModificar)
        {
            case 1:
                obtenerCadena("Nombre: ", "Error! Solo se pueden ingresar letras ", charAux, TAMANIO_NOMBRE);
                if(confirmarAccionUsuario()== 1)
                {
                    strcpy(listaMascota[indiceAEditar].nombreMascota, charAux);
                    resultado = 0;
                    printf("El nombre fue modificado exitosamente\n");
                }
            break;
            case 2:
                intAux = pedirEntero("Edad: ");
                if(confirmarAccionUsuario()== 1)
                {
                    listaMascota[indiceAEditar].edadMascota = intAux;
                    resultado = 0;
                    printf("La edad fue modificada exitosamente\n");
                 }
                break;
            case 3://Esto se podria mejorar. Tener una funcion qe pida sexo para llamarla tanto desde la carga como desde la edicion
                cAux = obtenerUnCaracter("Sexo> F o M: ");
                while(cAux != 'M' && cAux != 'F' && cAux != 'm' && cAux != 'f')
                {
                    cAux = obtenerUnCaracter("Error! Se puede ingresar F o M. Intentar nuevamente: ");
                }
                if(confirmarAccionUsuario()== 1)
                {
                    listaMascota[indiceAEditar].sexoMascota = cAux;
                    resultado = 0;
                    printf("El sexo fue modificado exitosamente\n");
                }
                break;
            case 4://PESO
                floatAux = pedirNumeroFlotante("Peso: ");
                while(floatAux <1)
                {
                    floatAux = pedirNumeroFlotante("Error, el peso debe ser mayor a cero. Ingresar nuevamente: ");
                }
                if(confirmarAccionUsuario()== 1)
                {
                    listaMascota[indiceAEditar].pesoMascota = floatAux;
                    resultado = 0;
                    printf("El peso fue modificado exitosamente\n");
                }
            break;
            case 5://TIPO
                obtenerCadena("Tipo: ", "Error! Solo se pueden ingresar letras ", charAux, TAMANIO_NOMBRE);
                if(confirmarAccionUsuario()== 1)
                {
                    strcpy(listaMascota[indiceAEditar].tipoMascota, charAux);
                    resultado = 0;
                    printf("El tipo fue modificado exitosamente\n");
                }
            break;
            case 6://RAZA
                intAux = ElegirRazaAAsignar(listaRazas, tamanioListaRaza);
                if(confirmarAccionUsuario() == 1)
                {
                    idRazaActual = listaMascota[indiceAEditar].idRaza;
                    idPaisActual = buscarIdPaisOrigenPorIdRaza(listaRazas, tamanioListaRaza, idRazaActual);
                    decrementarCantidadMascotaPorPais(listaPaises, tamanioListaPais, idPaisActual);

                    idNuevoPais = buscarIdPaisOrigenPorIdRaza(listaRazas, tamanioListaRaza, intAux);
                    IncrementarCantidadMascotaPorPais(listaPaises, tamanioListaPais, idNuevoPais);

                    listaMascota[indiceAEditar].idRaza = intAux;
                    resultado = 0;
                    printf("El tipo fue modificado exitosamente\n");
                }
                else
                {
                    printf("Operacion cancelada\n");
                }
            break;
            default:
            break;
        }
    }
    else
    {
        printf("La mascota no esta en la lista\n");
    }

    return resultado;
}

eRaza cargarRaza(eRaza razaData, int ultimoIdRaza, ePais listaPaises[], int tamanioListaPaises)
{
    int idRaza;
    int idPaisOrigen;

    idRaza = generarId(ultimoIdRaza);
    idPaisOrigen = elegirPaisOrigenRaza(listaPaises, tamanioListaPaises);
    if(idPaisOrigen != -1)
    {
        obtenerCadena("Descripcion: ", "Error! Solo se pueden ingresar letras ", razaData.descripcionRaza, TAMANIO_DESC_RAZA);
        obtenerCadena("Tamanio: ", "Error! Solo se pueden ingresar letras ", razaData.tamanioRaza, TAMANIO_TAMANIO_RAZA);
        razaData.idPaisOrigen = idPaisOrigen;
        razaData.idRaza = idRaza;
        razaData.estaVacio = cambiarEstadoRazaEstaVacio(razaData);
    }
    return razaData;
}

int borrarRaza(eMascota listaMascota[], int tamanioListaMascota, int idRazaSolicitada, eRaza listaRazas[],  int tamanioListaRaza, ePais listaPaises[], int tamanioListaPais)
{
    int i;
    int indiceABorrar;
    int resultado;

    resultado = -1;

    indiceABorrar = buscarIndicePorIdRaza(listaRazas, tamanioListaRaza, idRazaSolicitada);

    if(indiceABorrar!= -1)
    {
        for(i = 0; i < tamanioListaMascota; i++)
        {
           if(listaMascota[i].idRaza == listaRazas[indiceABorrar].idRaza)
           {
               borrarMascota(listaMascota[i].idMascota, listaMascota, tamanioListaMascota, listaRazas, tamanioListaRaza, listaPaises, tamanioListaPais);
               listaRazas[indiceABorrar].estaVacio = cambiarEstadoRazaEstaVacio(listaRazas[indiceABorrar]);
               resultado = 0;
           }
        }
    }
    else
    {
        printf("La mascota no esta en la lista\n");
    }
    return resultado;
}


float sumarPesoTotalPorTamanio(char tamanioMascota[], eMascota listaMascota[], int tamanioListaMascota,  eRaza listaRazas[],  int tamanioListaRaza)
{
    float sumaPesos;
    int i;
    int indice;

    sumaPesos = 0;

    for(i = 0; i < tamanioListaMascota; i++)
    {
        indice = buscarIndicePorIdRaza(listaRazas, tamanioListaRaza, listaMascota[i].idRaza);
        if(strcmp(listaRazas[indice].tamanioRaza, tamanioMascota) == 0)
        {
            sumaPesos = sumaPesos + listaMascota[i].pesoMascota;
        }
    }
    return sumaPesos;
}

