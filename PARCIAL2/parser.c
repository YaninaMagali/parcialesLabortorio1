#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "participantes.h"

/** \brief Carga el listado desde un archivo de texto
 *
 * \param pFile FILE* Recibe el puntero al archivo
 * \param pArrayList LinkedList* Recibe la lista donde se van a cargar los datos del archivo
 * \return int Devuelve un int que indica el resutado de la operacion: 1 exitosa, 0 no realizada.
 *
 */
int parser_FromText(FILE* pFile, LinkedList* pArrayList)
{
    int encabezado;
    int result;
    char AuxnumeroConcursante[50];
    char AuxanioNacimiento[50];
    char Auxnombre[50];
    char Auxdni[20];
    char AuxfechaPresentacion[50];
    char AuxtemaPresentacion [30];
    char AuxpuntajePrimeraRonda[50];
    eParticipante* pParticipante;
    encabezado = 0;

    result = 0;

    if(pArrayList != NULL
       && pFile!= NULL)
       {
        while(!feof(pFile))
        {
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", AuxnumeroConcursante, AuxanioNacimiento, Auxnombre, Auxdni, AuxfechaPresentacion, AuxtemaPresentacion, AuxpuntajePrimeraRonda);

            if(encabezado!=0)
            {
                pParticipante = newParameters(AuxnumeroConcursante, AuxanioNacimiento, Auxnombre, Auxdni, AuxfechaPresentacion, AuxtemaPresentacion, AuxpuntajePrimeraRonda);
                ll_add(pArrayList, pParticipante);
                result = 1;
            }
            encabezado++;

        }
       }

    return result;

}


/** \brief Guarda los empleados en un archivo de texto
 *
 * \param pArrayListEmployee LinkedList* Recibe listado que va a guardar
 * \param pFile FILE* Recibe el archivo ya abierto, donde lo va a guardar
 * \return int Devuelve un int que indica el resutado de la operacion: 1 exitosa, 0 no realizada.
 *
 */
int agregarParticipanteAFile(LinkedList* pArrayList, FILE* pFile)
{
    eParticipante* pParticipante = NULL;
    int len;
    int i;
    int result;
    int numeroConcursante;
    int anioNacimiento;
    char nombre[50];
    char dni[13];
    char fechaPresentacion[15];
    char temaPresentacion [30];
    int puntajePrimeraRonda;
    int puntajeSegundaRonda;
    float promedio;

    result = 0;

    len = ll_len(pArrayList);
    if(!feof(pFile) && pArrayList != NULL && pFile != NULL)
    {
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

            fprintf(pFile, "%d, %d, %s, %s, %s,%s, %d, %d, %.2f \n",
                    numeroConcursante, anioNacimiento, nombre, dni, fechaPresentacion, temaPresentacion, puntajePrimeraRonda, puntajeSegundaRonda, promedio);
            result = 1;
        }
    }

    return result;
}
