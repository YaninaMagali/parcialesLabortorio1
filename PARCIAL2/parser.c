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
