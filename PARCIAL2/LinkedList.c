#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

/** \brief Ejecuta la funcion criterio recibida por parametro por cada elemento de la lista. Si dicha funcion devuelve 1, el elemento se agrega a una nueva lista
 *
 * \param Recibe un puntero a LinkedList, y un puntero a funcion
 * \return LinkedList* Devuelve un puntero a nueva LinkedList si pudo agregar al menos un elemento a la nueva lista, sino NULL
 *
 */
LinkedList* ll_filter(LinkedList* this, int (*pFunc) (void* element))
{
    int i;
    int len;
    void* pElement;
    LinkedList* nuevaLista = NULL;

    if(this != NULL && pFunc != NULL)
    {
        len = ll_len(this);
        nuevaLista = ll_newLinkedList();
        for(i = 0; i < len; i++)
        {
            pElement = ll_get(this, i);
            if(nuevaLista != NULL && pFunc(pElement) == 1)
            {
                ll_add(nuevaLista, pElement);
            }
        }
    }
    return nuevaLista;
}


/** \brief Ejecuta la funci�n recibida como par�metro por cada elemento de la lista, y en cada llamada le pasa dicho elemento
 *
 * \param  Recibe un puntero a LinkedList, y un puntero a funcion
 * \return Devuelve 0 si pudo realizar la operacion, sino -1
 *
 */
int ll_map(LinkedList* this, int (*pFunc)(void*))
{
    int i;
    int len;
    void* pElement;
    int result;

    result =  -1;
    if(this != NULL && pFunc != NULL)
    {
        len = ll_len(this);
        for(i = 0; i < len; i++)
        {
            pElement = ll_get(this, i);
            pFunc(pElement);
            result = 0;
        }
    }
    return result;
}

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;

    this = (LinkedList*) malloc(sizeof(LinkedList));
    if(this!=NULL)
    {
        this->size = 0;
        this->pFirstNode = NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int i;

    if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
    {
        pNode = this -> pFirstNode;
        for(i = 0; i < nodeIndex; i++)
        {
            pNode = pNode -> pNextNode;
        }
    }

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* prev;
    Node* next;
    Node* nuevoNodo;

    prev = getNode(this, nodeIndex - 1);
    next = getNode(this, nodeIndex); //a next le asignas el nodo que contiene el indice que recibiste

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
        nuevoNodo = (Node*)malloc(sizeof(Node));
        if(nuevoNodo != NULL)
        {
            if(nodeIndex == 0)
            {
                this->pFirstNode = nuevoNodo;
                nuevoNodo->pNextNode = next;
            }
            else
            {
                nuevoNodo->pNextNode = next;
                prev->pNextNode  = nuevoNodo;
            }
            nuevoNodo->pElement = pElement;
            this->size++;
            returnAux = 0;
        }
    }
    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int indice = 0;

    if(this != NULL)
    {
        indice = ll_len(this);
        returnAux = addNode(this, indice, pElement);
    }
    return returnAux;
}


/** \brief Obtiene el elemento de una lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* auxNode;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        auxNode = getNode(this, index);
        if(auxNode != NULL)
        {
           returnAux = auxNode->pElement;
        }
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    Node* actual;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        actual = getNode(this, index);
        if(actual != NULL)
        {
            actual->pElement = pElement;
            returnAux = 0;
        }
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* prev;
    Node* next;
    Node* actual;
    int len;

    len = ll_len(this);
    prev = getNode(this, index-1);
    next = getNode(this, index+1);
    actual = getNode(this, index);

    if(this != NULL && index >=0 &&  index < len)
    {
        if(index == 0)
        {
            this->pFirstNode = next;
        }
        else
        {
            if(index == len-1)
            {
                prev -> pNextNode = NULL;
            }
            else
            {
                prev -> pNextNode = next;
            }
        }
        free(actual);
        this -> size--;
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;
    int len;

    if(this != NULL)
    {
        len = ll_len(this)-1;
        if(len >= 0)
        {
            for(i = len; i >=    0; i--)
            {
                if(ll_remove(this, i) == 0)
                {
                    returnAux = 0;
                }
            }
        }
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{

    int returnAux = -1;

    if(this != NULL)
    {
        //antes de hacer el free tengo q remover los elementos con remove, de atras para adelante
        free(this);
        returnAux = 0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    int len;
    void* auxElement;

    len = ll_len(this);
    auxElement = NULL;

    if(this != NULL)
    {
        for(i = 0; i< len; i++)
        {
            auxElement = ll_get(this, i);
            if(auxElement == pElement)
            {
                returnAux = i;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        if( ll_len(this))
        {
            returnAux = 0;
        }
        else
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this != NULL && index >= 0 && index <= ll_len(this))
    {
        addNode(this, index, pElement);
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    //Node* nodo;

    if(this != NULL)
    {
        returnAux = ll_get(this, index);
        ll_remove(this, index);
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
        if(ll_indexOf(this, pElement)!= -1) // indexOf porque ya busca un elemento, y si esta devuelve distinto de -1
        {
            returnAux = 1;
        }
        else
        {
            returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;
    //Node* nodo;
    int len;
    void* pElement;

    len = ll_len(this2);

    if(this != NULL && this2 != NULL)
    {
        returnAux = 1;
        for(i = 0; i < len; i++)
        {
            returnAux = 1;
            pElement = ll_get(this2, i);
            if(ll_contains(this, pElement) == 0)
            {
                returnAux = 0;
                break;
            }
        }
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;
    void* pElement;
    int len;

    len = ll_len(this);

    if(this != NULL && from >= 0 && to <= len)
    {
        cloneArray = ll_newLinkedList();
        if(cloneArray != NULL)
        {
            for(i = from; i < to; i++)
            {
                pElement = ll_get(this, i);
                ll_add(cloneArray, pElement);
            }
        }
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int from;
    int to;

    from = 0;

    if(this != NULL)
    {
        to = ll_len(this);
        cloneArray = ll_subList(this, from, to);
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente -
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;
    void* pAux;
    int len;
    int i;
    int j;
    void* e1;
    void* e2;

    if(this != NULL && pFunc != NULL && (order == 0 || order == 1))
    {
        len = ll_len(this);
        for(i = 0; i < len-1; i++)
        {
            for(j = i+1; j < len; j++)
            {
                e1 = ll_get(this, i);
                e2 = ll_get(this, j);
                if(order == 0 && pFunc(e1, e2) == -1) //[0] Indica orden descendente. en comprareBy, si e1>e2, return 1
                {
                    pAux = e1;
                    ll_set(this, i, e2);
                    ll_set(this, j, pAux);
                }
                if(order == 1 && pFunc(e1, e2) == 1) //[1] Indica orden ascendente. en comprareBy, si e1<e2, return -1
                {
                    pAux = e1;
                    ll_set(this, i, e2);
                    ll_set(this, j, pAux);
                }
            }
        }

        returnAux = 0;
    }


    return returnAux;
}

