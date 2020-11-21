#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "participantes.h"
#include "parser.h"

eParticipante* new()
{
    eParticipante* pParticipante  = NULL;

    pParticipante = (eParticipante*)malloc(sizeof(eParticipante));

    return pParticipante;
}

eParticipante* newParameters(char* AuxnumeroConcursante, char* AuxanioNacimiento, char* Auxnombre, char* Auxdni, char*  AuxfechaPresentacion, char*  AuxtemaPresentacion,char* AuxpuntajePrimeraRonda)
{
    eParticipante* pParticipante = NULL;

    pParticipante = new();

    if(pParticipante != NULL)
    {
        if(setNumeroConcursante(pParticipante, AuxnumeroConcursante) == 1)
        {
            if(setAnioNacimiento(pParticipante, AuxanioNacimiento) == 1)
            {
                if(setNombre(pParticipante, Auxnombre) == 1)
                {
                    if(setDNI(pParticipante, Auxdni) == 1)
                    {
                        if(setFechaPresentacion(pParticipante, AuxfechaPresentacion) == 1)
                        {
                            if(setTemaPresentacion(pParticipante, AuxtemaPresentacion) == 1)
                            {
                                setPuntajePrimeraRonda(pParticipante, AuxpuntajePrimeraRonda);
                            }
                        }
                    }
                }
            }
        }

    }
    return pParticipante;
}


/** \brief Abre un archivo de texto, lo lee y luego lo cierra
 *
 * \param path char* Recibe el path del archivo
 * \param pArrayListEmployee LinkedList* Recibe una lista donde se guardan los datos leidos
 * \param fileLoaded int Flag que indica si el archivo ya fue abierto previamente
 * \return int Devuelve un int que indica el resutado de la operacion: 1 exitosa, 0 no realizada.
 *
 */
int loadFromText(char* path, LinkedList* pArrayList)
{
    FILE* pFile;
    int result;

    result = 0;
    pFile = fopen(path,"r");

    if(path != NULL
       && pArrayList != NULL
       && parser_FromText(pFile, pArrayList) == 1)
       {
           result = 1;
       }
    fclose(pFile);
    return result;
}

int ListarParticipantes(LinkedList* pArrayList)
{

    int numeroConcursante;
    int anioNacimiento;
    char nombre[50];
    char dni[13];
    char fechaPresentacion[15];
    char temaPresentacion [30];
    int puntajePrimeraRonda;
    int puntajeSegundaRonda;
    float promedio;
    eParticipante* pParticipante = NULL;
    int result;
    int len;
    int i;

    result = 0;

    if(pArrayList != NULL)
    {
        len = ll_len(pArrayList);
        if(len > 0)
        {
            printf(" |    |     |      |   \n");
            for(i = 0; i < len; i++)
            {
                pParticipante = (eParticipante*)ll_get(pArrayList, i);
                getnumeroConcursante(pParticipante, &numeroConcursante);
                getAnioNacimiento(pParticipante, &anioNacimiento);
                getNombre(pParticipante, nombre);
                getDNI(pParticipante, dni);
                getFechaPresentacion(pParticipante, fechaPresentacion);
                getTemaPresentacion(pParticipante, temaPresentacion);
                getPuntajeUno(pParticipante, &puntajePrimeraRonda);
                getPuntajeDos(pParticipante, &puntajeSegundaRonda);
                getPromedio(pParticipante, &promedio);

                printf("%2d, %5d, %11s, %12s, %13s, %22s, %20d, %20d %21.2f\n",numeroConcursante, anioNacimiento, nombre, dni, fechaPresentacion, temaPresentacion, puntajePrimeraRonda, puntajeSegundaRonda, promedio);
                result = 1;
            }
        }

    }

    return result;
}



int getNombre(eParticipante* this, char* nombre)
{
    int resultado;
    resultado = 0;

    if(this!= NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        resultado = 1;
    }

    return resultado;
}

int getDNI(eParticipante* this, char* dni)
{
    int resultado;
    resultado = 0;

    if(this!= NULL && dni != NULL)
    {
        strcpy(dni, this->dni);
        resultado = 1;
    }

    return resultado;
}

int getFechaPresentacion(eParticipante* this, char* fecha)
{
    int resultado;
    resultado = 0;

    if(this!= NULL && fecha != NULL)
    {
        strcpy(fecha, this->fechaPresentacion);
        resultado = 1;
    }

    return resultado;
}

int getTemaPresentacion(eParticipante* this, char* tema)
{
    int resultado;
    resultado = 0;

    if(this!= NULL && tema != NULL)
    {
        strcpy(tema, this->temaPresentacion);
        resultado = 1;
    }

    return resultado;
}

int getnumeroConcursante(eParticipante* this,int* numero)
{
    int resultado;
    resultado = 0;

    if(this!= NULL && numero != NULL)
    {
        *numero = this->numeroConcursante;
        resultado = 1;
    }

    return resultado;
}

int getAnioNacimiento(eParticipante* this,int* anio)
{
    int resultado;
    resultado = 0;

    if(this!= NULL && anio != NULL)
    {
        *anio = this->anioNacimiento;
        resultado = 1;
    }

    return resultado;
}

int getPuntajeUno(eParticipante* this,int* puntos)
{
    int resultado;
    resultado = 0;

    if(this!= NULL && puntos != NULL)
    {
        *puntos = this->puntajePrimeraRonda;
        resultado = 1;
    }

    return resultado;
}

int getPuntajeDos(eParticipante* this,int* puntos)
{
    int resultado;
    resultado = 0;

    if(this!= NULL && puntos != NULL)
    {
        *puntos = this->puntajeSegundaRonda;
        resultado = 1;
    }

    return resultado;
}

int getPromedio(eParticipante* this,float* promedio)
{
    int resultado;
    resultado = 0;

    if(this!= NULL && promedio != NULL)
    {
        *promedio = this->promedio;
        resultado = 1;
    }

    return resultado;
}

int setNumeroConcursante(eParticipante* this, char* numero)
{
    int resultado;
    resultado = 0;
    if(this!= NULL && numero > 0)
    {
        this->numeroConcursante = atoi(numero);
        resultado = 1;
    }
    return resultado;
}

int setAnioNacimiento(eParticipante* this, char* anio)
{
    int resultado;
    resultado = 0;
    if(this!= NULL && anio > 0)
    {
        this->anioNacimiento = atoi(anio);
        resultado = 1;
    }
    return resultado;
}


int setNombre(eParticipante* this, char* nombre)
{
    int resultado;
    resultado = 0;

    if(this!= NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        resultado = 1;
    }
    return resultado;
}

int setDNI(eParticipante* this, char* dni)
{
    int resultado;
    resultado = 0;

    if(this!= NULL && dni != NULL)
    {
        strcpy(this->dni, dni);
        resultado = 1;
    }
    return resultado;
}

int setFechaPresentacion(eParticipante* this, char* fecha)
{
    int resultado;
    resultado = 0;

    if(this!= NULL && fecha != NULL)
    {
        strcpy(this->fechaPresentacion, fecha);
        resultado = 1;
    }
    return resultado;
}

int setTemaPresentacion(eParticipante* this, char* tema)
{
    int resultado;
    resultado = 0;

    if(this!= NULL && tema != NULL)
    {
        strcpy(this->temaPresentacion, tema);
        resultado = 1;
    }
    return resultado;
}

int setPuntajePrimeraRonda(eParticipante* this, char* puntos)
{
    int resultado;
    resultado = 0;
    if(this!= NULL && puntos > 0)
    {
        this->puntajePrimeraRonda = atoi(puntos);
        resultado = 1;
    }
    return resultado;
}

int setPuntajeSegundaRonda(eParticipante* this, int puntos)
{
    int resultado;
    resultado = 0;

    if(this!= NULL && puntos >= 0)
    {
        this->puntajeSegundaRonda = puntos;
        resultado = 1;
    }
    return resultado;
}

int setPromedio(eParticipante* this, float promedio)
{
    int resultado;
    resultado = 0;

    if(this!= NULL && promedio >= 0)
    {
        this->promedio = promedio;
        resultado = 1;
    }
    return resultado;
}

int generarNumeroRandom()
{
    int numero;

    numero = rand() % 11;

    return numero;
}

int asignarSegundoPuntajeRandom(void* pParticipante)
{
    int puntos;
    int result;
    result = 0;

    pParticipante = (eParticipante*)pParticipante;

    if(pParticipante != NULL)
    {
        puntos = generarNumeroRandom();
        //printf("generarNumeroRandom %d", puntos);
        setPuntajeSegundaRonda(pParticipante, puntos);
        result = 1;
    }
    return result;
}


int calcularPromedio(void* pParticipante)
{
    int result;
    int puntaje1;
    int* pPuntaje1;
    pPuntaje1 = &puntaje1;
    int puntaje2;
    int* pPuntaje2;
    pPuntaje2 = &puntaje2;

    float promedio;
    result = 0;

    if(pParticipante != NULL)
    {
        pParticipante = (eParticipante*)pParticipante;

        if(getPuntajeUno(pParticipante, pPuntaje1) == 1)
        {
            if(getPuntajeDos(pParticipante, pPuntaje2) == 1)
            {
                promedio = (*pPuntaje1 + *pPuntaje2) / 2;

                if(setPromedio(pParticipante, promedio) == 1)
                {
                    result = 1;
                }
            }
        }
    }
    return result;
}
