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

    do
    {
        if(getInt(&menuOption, "\nSelecciona una opcion\n 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto) \n 2.Mostrar\n 3.Asignar puntaje ronda 2\n 4.Calcular promedio\n 10. Salir\n" ,"Opcion invalida\n", 1, 10, 20) == 1)
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
                    if(ll_map(lista, asignarSegundoPuntajeRandom) == 0)
                    {
                        printf("Puntaje asignado\n");
                    }
                    else
                    {
                        printf("No se pudo asignar puntaje\n");
                    }
                    break;
                case 4:
                    if(ll_map(lista, calcularPromedio) == 0)
                    {
                        printf("Promedio calculado\n");
                    }
                    else
                    {
                        printf("No se pudo calcular el promedio\n");
                    }
                    break;
            }
        }
    }
    while(menuOption!=10);
}
