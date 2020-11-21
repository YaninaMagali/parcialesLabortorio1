#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "getDataBase.h"
#include "validateDataBase.h"

/** \brief - Pide al usuario ingresar una cadena de caracteres. Valida que la direccion de memoria sea valida y si encuenta un salto de linea lo reemplaza por un espacio
 *
 * \param cadena char* - Recibe lugar donde se va a guardar el numero ingresado
 * \param TAMANIO_CADENA int - Recibe tamanio de la cadena
 * \return int - - Devuelve resultado de la operacion: o operacion exitosa, sino -1
 *
 */
int getBase(char* string, int stringSize)
{
    int result;
    char bufferString[2000];

    result = -1;

    if(string != NULL && stringSize > 0)
    {
        fflush(stdin);
        if(fgets(bufferString, sizeof(bufferString), stdin) != NULL)
        {
            if(bufferString[strlen(bufferString)-1] == '\n')
            {
                bufferString[strlen(bufferString)-1] = '\0';
            }
            if(strlen(bufferString) <= stringSize)
            {
                strncpy(string, bufferString, stringSize);
                result = 0;
            }
        }
    }
    return result;
}

/** \brief Pide al usuario ingresar una cadena de caracteres. Si son solo letras se asigna a un puntero a char.
 *
 * \param pChar char* Recibe puntero a char donde se va a almacenar el dato ingresado por el usuario
 * \param stringSize int Recibe tamanio del string
 * \param message[] char Mensaje a mostrar al usuario
 * \param errorMessage[] char Mensaje a mostrar al usuario en caso de error
 * \param attempts int Cantidad de intentos
 * \return int - - Devuelve resultado de la operacion: 1 operacion exitosa, sino 0
 *
 */
int getString(char* pChar, int stringSize, char message[], char errorMessage[], int attempts)
 {
    char string;
    int result;

    result = 0;

     do
     {
        printf(message);
        fflush(stdin);
        fgets(&string, stringSize, stdin);
        if(validateIsAlpha(&string) != 0)
        {
            remmplazarSaltoPorEspacio(&string);
            strncpy(pChar, &string, stringSize);
            result = 1;
            break;
        }
         printf(errorMessage);
         attempts--;
     }
     while(attempts > 0);

     return result;
 }

/** \brief Pide al usuario ingresar una numero como cadena de caracteres. Si son solo numeros, se convierte a int y se asigna a un puntero a int.
 *
 * \param pNumber int* Puntero a int donde se guarda el numero ingresado
 * \param message[] char Mensaje a mostrar al usuario
 * \param errorMessage[] char Mensaje a mostrar al usuario en caso de error
 * \param min int Valor minimo
 * \param max int Valor maximo
 * \param attempts int
 * \* \return int - - Devuelve resultado de la operacion: 1 operacion exitosa, sino 0
 *
 */
int getInt(int* pNumber, char message[], char errorMessage[], int min, int max, int attempts)
{
    char string[50];
    int result;
    result = 0;

     do
     {
        printf(message);
        fflush(stdin);
        fgets(string, sizeof(string), stdin);
        if(validateIsNumber(string) == 1)
        {
            *pNumber = atoi(string);
            if(*pNumber >= min && *pNumber <= max)
            {
                result = 1;
                break;
            }
        }
        printf(errorMessage);
        attempts--;
     }
     while(attempts > 0);

     return result;
 }

/** \brief Pide al usuario ingresar un numero como cadena de caracteres. Si son solo numeros se asigna a un puntero a char.
 *
 * \param pChar char* Recibe puntero a char donde se va a almacenar el dato ingresado por el usuario
 * \param stringSize int Recibe tamanio del string
 * \param message[] char Mensaje a mostrar al usuario
 * \param errorMessage[] char Mensaje a mostrar al usuario en caso de error
 * \param attempts int Cantidad de intentos
 * \return int - - Devuelve resultado de la operacion: 1 operacion exitosa, sino 0
 *
 */
int getNumber(char* pChar, int stringSize, char message[], char errorMessage[], int attempts)
 {
    char string;
    int result;

    result = 0;

     do
     {
        printf(message);
        fflush(stdin);
        fgets(&string, stringSize, stdin);
        if(validateIsNumber(&string) == 1)
        {
            strncpy(pChar, &string, stringSize);
            result = 1;
            break;
        }
         printf(errorMessage);
         attempts--;
     }
     while(attempts > 0);

     return result;
 }

 /*VALIDAR*/

/** \brief - Reemplaza saltos de linea por espacios
 *
 * \param string[] char - Recibe una cadena de caracteres
 * \return char - Devuelve la cadena con espacios en lugar de saltos
 *
 */
char remmplazarSaltoPorEspacio(char string[])
{
    int i;
    for(i=0;string[i] != '\0';i++)
    {
        if(string[i] == '\n')
        {
            string[i] = '\0';
        }
    }
    return string[i];
}
