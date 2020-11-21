#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "menu.h"
#include "participantes.h"
#include "getDataBase.h"

void menu(void)
{
    printf("SIMULACRO PARCIAL\n");

    LinkedList* lista = NULL;

    int menuOption;

    lista = ll_newLinkedList();
    int num;

    do
    {
        if(getInt(&menuOption, "\nSelecciona una opcion\n 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto) \n 2.Mostrar\n 10. Salir\n" ,"Opcion invalida\n", 1, 10, 20) == 1)
        {
            switch(menuOption)
            {
                case 1:
                    if(loadFromText("misiones.csv", lista) == 1)
                    {
                        printf("Carga exoitosa\n");
                    }
                    else
                    {
                        printf("No se pudo cargar el archivo\n");
                    }
                    break;
                case 2:
                    if(ListarParticipantes(lista) != 1 || ll_len(lista) == 0)
                    {
                        printf("No se pudo mostrar la lista\n");
                    }
                    break;
                case 3:
                    //num = generarNumeroRandom();
                    if(ll_map(lista, asignarSegundoPuntajeRandom) == 1)
                    {
                        printf("Puntaje asignado\n");
                    }
                    else
                    {
                        printf("No se pudo asignar puntaje\n");
                    }
                    //printf("generarNumeroRandom %d", num);
                    break;
            }
        }
    }
    while(menuOption!=10);
}
