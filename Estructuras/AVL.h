//
// Created by dario1227 on 01/05/18.
//

#ifndef PROGRA_2_DATOS_C_ARBOLAVL_H
#define PROGRA_2_DATOS_C_ARBOLAVL_H

#include <iostream>
#include "../data/Cancion.h"

using namespace std;

class Cancion;

class NodoAVL {
public:
    // Constructor:
    NodoAVL(const int dat, NodoAVL *pad = NULL, NodoAVL *izq = NULL, NodoAVL *der = NULL) :
            dato(dat), padre(pad), izquierdo(izq), derecho(der), FE(0) {}

    // Miembros:
    int dato;
    int FE;
    NodoAVL *izquierdo;
    NodoAVL *derecho;
    NodoAVL *padre;

    friend class AVL;
};

class AVL {
private:
    enum {
        IZQUIERDO, DERECHO
    };
    // Punteros de la lista, para cabeza y nodo actual:
    NodoAVL *raiz;
    NodoAVL *actual;
    int contador;
    int altura;

public:
    AVL() : raiz(NULL), actual(NULL) {}

    ~AVL() { Podar(raiz); }

    void Insertar(const int dat);

    bool Buscar(const int dat);

    bool Vacio(NodoAVL *r) { return r == NULL; }

    // Comprobar si es un nodo hoja:
    bool EsHoja(NodoAVL *r) { return !r->derecho && !r->izquierdo; }

    const int NumeroNodos();

    const int AlturaArbol();

    int Altura(const int dat);

    int &ValorActual() { return actual->dato; }

    void Raiz() { actual = raiz; }

    Lista<Cancion *> *Buscar(string artista);

    void InOrden(void (*func)(int &, int), NodoAVL *nodo = NULL, bool r = true);

    void PreOrden(void (*func)(int &, int), NodoAVL *nodo = NULL, bool r = true);

    void PostOrden(void (*func)(int &, int), NodoAVL *nodo = NULL, bool r = true);

private:
    // Funciones de equilibrado:
    void Equilibrar(NodoAVL *nodo, int, bool);

    void RSI(NodoAVL *nodo);

    void RSD(NodoAVL *nodo);

    void RDI(NodoAVL *nodo);

    void RDD(NodoAVL *nodo);

    // Funciones auxiliares
    void Podar(NodoAVL *&);

    void auxContador(NodoAVL *);

    void auxAltura(NodoAVL *, int);

};


#endif //PROGRA_2_DATOS_C_ARBOLAVL_H
