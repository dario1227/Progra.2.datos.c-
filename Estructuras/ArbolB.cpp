//
// Created by dario1227 on 01/05/18.
//

#include "ArbolB.h"
#include "../data/Cancion.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_LONG 90
#define ARRIBA 72
#define ABAJO 80
#define ENTER 13
#define M 5
struct nodo
{
    int n;
    int arreglo_claves[M-1];
    struct nodo *p[M];
}*root=NULL;

enum Estado_Clave { Duplicado,SearchFailure,Exacto,Insertado,LessKeys };
enum Estado_Clave ins(struct nodo *r, int x, int* y, struct nodo** u);
int  BuscarPosicion(int x,int *key_arr, int n);
void ArbolB::Insertar_Nodo(int clave)
{
    struct nodo *newnodo;
    int upKey;
    enum Estado_Clave value;
    value = ins(root, clave, &upKey, &newnodo);
    if (value == Duplicado)//si ingresamos un valor duplicado
        printf("La clave ya esta insertada\n");
    if (value == Insertado)//si es nuevo,asigno memoria y creo la clave
    {
        struct nodo *uproot = root;
        root=new struct nodo;
        root->n = 1;
        root->arreglo_claves[0] = upKey;
        root->p[0] = uproot;
        root->p[1] = newnodo;
    }
}

//le asignamos un estado a la clave(ya sea que esta duplicada,etc)
enum Estado_Clave ins(struct nodo *ptr, int clave, int *upKey,struct nodo**newnodo)
{
    struct nodo *newPtr, *lastPtr;
    int pos, i, n,splitPos;
    int nueva_clave, ultima_clave;
    enum Estado_Clave value;
    if (ptr == NULL)
    {
        *newnodo = NULL;
        *upKey = clave;
        return Insertado;
    }
    n = ptr->n;
    pos = BuscarPosicion(clave, ptr->arreglo_claves, n);
    if (pos < n && clave == ptr->arreglo_claves[pos])
        return Duplicado;
    value = ins(ptr->p[pos], clave, &nueva_clave, &newPtr);
    if (value != Insertado)
        return value;

    //Si la clave en el nodo es menor que M-1 donde M es el orden de B tree
    if (n < M - 1)
    {
        pos = BuscarPosicion(nueva_clave, ptr->arreglo_claves, n);
        //Desplazamiento de una clave y puntero(derecha) inserta una nueva clave
        for (i=n; i>pos; i--)
        {
            ptr->arreglo_claves[i] = ptr->arreglo_claves[i-1];
            ptr->p[i+1] = ptr->p[i];
        }
        //La clave es insertada en su puesto exacto
        ptr->arreglo_claves[pos] = nueva_clave;
        ptr->p[pos+1] = newPtr;
        ++ptr->n;//incrementamos el numero de claves en el nodo
        return Exacto;//exact0
    }
    //Si la clave es la mayor,la posición del nodo es insertada al final
    if (pos == M - 1)
    {
        ultima_clave = nueva_clave;
        lastPtr = newPtr;
    }
    else /*If keys in node are maximum and position of node to be inserted is not last*/
    {
        ultima_clave = ptr->arreglo_claves[M-2];
        lastPtr = ptr->p[M-1];
        for (i=M-2; i>pos; i--)
        {
            ptr->arreglo_claves[i] = ptr->arreglo_claves[i-1];
            ptr->p[i+1] = ptr->p[i];
        }
        ptr->arreglo_claves[pos] = nueva_clave;
        ptr->p[pos+1] = newPtr;
    }
    splitPos = (M - 1)/2;//Dividimos
    (*upKey) = ptr->arreglo_claves[splitPos];
    (*newnodo)=new struct nodo;/*Nodo a la derecha después de dividir*/
    ptr->n = splitPos; /*N º de teclas para el nodo dividido a la izquierda*/
    (*newnodo)->n = M -1-splitPos;/*No. of keys for right splitted node*/
    for (i=0; i < (*newnodo)->n; i++)
    {
        (*newnodo)->p[i] = ptr->p[i + splitPos + 1];
        if(i < (*newnodo)->n - 1)
            (*newnodo)->arreglo_claves[i] = ptr->arreglo_claves[i + splitPos + 1];
        else
            (*newnodo)->arreglo_claves[i] = ultima_clave;
    }
    (*newnodo)->p[(*newnodo)->n] = lastPtr;
    return Insertado;
}
Lista<Cancion*>*ArbolB::Buscar_Nodo(string nombre){
    Lista<Cancion*>*result= new Lista<Cancion*>();
    Cancion*temp;
    int c=0;
    while(c!=Cancion::Music->length){
        temp=Cancion::Music->get(c);
        if(temp->nombre==nombre){
            result->add(temp);
        }
        c++;
    }
    return result;
}
int Buscar_Nodo(int clave)
{
    int pos, i, n;
    struct nodo *ptr = root;
    printf(" El camino del arbol:\n");
    while (ptr)
    {
        n = ptr->n;
        for (i=0; i < ptr->n; i++)
            printf("\t%d",ptr->arreglo_claves[i]);
        printf("\n");
        pos = BuscarPosicion(clave, ptr->arreglo_claves, n);
        int c=ptr->arreglo_claves[pos];
        if (pos < n && clave== ptr->arreglo_claves[pos])
        {
            return clave ;
        }
        ptr = ptr->p[pos];
    }
}

int BuscarPosicion(int clave, int *key_arr, int n)
{
    int pos=0;
    while (pos < n && clave > key_arr[pos])
        pos++;
    return pos;
}


