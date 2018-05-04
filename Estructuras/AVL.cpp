//
// Created by dario1227 on 01/05/18.
//

#include "AVL.h"
#include <iostream>
using namespace std;



// Poda: borrar todos los nodos a partir de uno, incluido
void AVL::Podar(NodoAVL* &nodo)
{
    // Algoritmo recursivo, recorrido en postorden
    if(nodo) {
        Podar(nodo->izquierdo); // Podar izquierdo
        Podar(nodo->derecho);   // Podar derecho
        delete nodo;            // Eliminar nodo
        nodo = NULL;
    }
}

// Insertar un dato en el árbol AVL
void AVL::Insertar(const int dat)
{
    NodoAVL *padre = NULL;

    cout << "Insertar: " << dat << endl;
    actual = raiz;
    // Buscar el dato en el árbol, manteniendo un puntero al nodo padre
    while(!Vacio(actual) && dat != actual->dato) {
        padre = actual;
        if(dat > actual->dato) actual = actual->derecho;
        else if(dat < actual->dato) actual = actual->izquierdo;
    }

    // Si se ha encontrado el elemento, regresar sin insertar
    if(!Vacio(actual)) return;
    // Si padre es NULL, entonces el árbol estaba vacío, el nuevo nodo será
    // el nodo raiz
    if(Vacio(padre)) raiz = new NodoAVL(dat);
        // Si el dato es menor que el que contiene el nodo padre, lo insertamos
        // en la rama izquierda
    else if(dat < padre->dato) {
        padre->izquierdo = new NodoAVL(dat, padre);
        Equilibrar(padre, IZQUIERDO, true);
    }
        // Si el dato es mayor que el que contiene el nodo padre, lo insertamos
        // en la rama derecha
    else if(dat > padre->dato) {
        padre->derecho = new NodoAVL(dat, padre);
        Equilibrar(padre, DERECHO, true);
    }
}

// Equilibrar árbol AVL partiendo del nodo nuevo
void AVL::Equilibrar(NodoAVL *nodo, int rama, bool nuevo)
{
    bool salir = false;

    // Recorrer camino inverso actualizando valores de FE:
    while(nodo && !salir) {
        if(nuevo)
            if(rama == IZQUIERDO) nodo->FE--; // Depende de si añadimos ...
            else                  nodo->FE++;
        else
        if(rama == IZQUIERDO) nodo->FE++; // ... o borramos
        else                  nodo->FE--;
        if(nodo->FE == 0) salir = true; // La altura de las rama que
            // empieza en nodo no ha variado,
            // salir de Equilibrar
        else if(nodo->FE == -2) { // Rotar a derechas y salir:
            if(nodo->izquierdo->FE == 1) RDD(nodo); // Rotación doble
            else RSD(nodo);                         // Rotación simple
            salir = true;
        }
        else if(nodo->FE == 2) {  // Rotar a izquierdas y salir:
            if(nodo->derecho->FE == -1) RDI(nodo); // Rotación doble
            else RSI(nodo);                        // Rotación simple
            salir = true;
        }
        if(nodo->padre)
            if(nodo->padre->derecho == nodo) rama = DERECHO; else rama = IZQUIERDO;
        nodo = nodo->padre; // Calcular FE, siguiente nodo del camino.
    }
}

// Rotación doble a derechas
void AVL::RDD(NodoAVL* nodo)
{
    cout << "RDD" << endl;
    NodoAVL *Padre = nodo->padre;
    NodoAVL *P = nodo;
    NodoAVL *Q = P->izquierdo;
    NodoAVL *R = Q->derecho;
    NodoAVL *B = R->izquierdo;
    NodoAVL *C = R->derecho;

    if(Padre)
        if(Padre->derecho == nodo) Padre->derecho = R;
        else Padre->izquierdo = R;
    else raiz = R;

    // Reconstruir árbol:
    Q->derecho = B;
    P->izquierdo = C;
    R->izquierdo = Q;
    R->derecho = P;

    // Reasignar padres:
    R->padre = Padre;
    P->padre = Q->padre = R;
    if(B) B->padre = Q;
    if(C) C->padre = P;

    // Ajustar valores de FE:
    switch(R->FE) {
        case -1: Q->FE = 0; P->FE = 1; break;
        case 0:  Q->FE = 0; P->FE = 0; break;
        case 1:  Q->FE = -1; P->FE = 0; break;
    }
    R->FE = 0;
}

// Rotación doble a izquierdas
void AVL::RDI(NodoAVL* nodo)
{
    cout << "RDI" << endl;
    NodoAVL *Padre = nodo->padre;
    NodoAVL *P = nodo;
    NodoAVL *Q = P->derecho;
    NodoAVL *R = Q->izquierdo;
    NodoAVL *B = R->izquierdo;
    NodoAVL *C = R->derecho;

    if(Padre)
        if(Padre->derecho == nodo) Padre->derecho = R;
        else Padre->izquierdo = R;
    else raiz = R;

    // Reconstruir árbol:
    P->derecho = B;
    Q->izquierdo = C;
    R->izquierdo = P;
    R->derecho = Q;

    // Reasignar padres:
    R->padre = Padre;
    P->padre = Q->padre = R;
    if(B) B->padre = P;
    if(C) C->padre = Q;

    // Ajustar valores de FE:
    switch(R->FE) {
        case -1: P->FE = 0; Q->FE = 1; break;
        case 0:  P->FE = 0; Q->FE = 0; break;
        case 1:  P->FE = -1; Q->FE = 0; break;
    }
    R->FE = 0;
}

// Rotación simple a derechas
void AVL::RSD(NodoAVL* nodo)
{
    cout << "RSD" << endl;
    NodoAVL *Padre = nodo->padre;
    NodoAVL *P = nodo;
    NodoAVL *Q = P->izquierdo;
    NodoAVL *B = Q->derecho;

    if(Padre)
        if(Padre->derecho == P) Padre->derecho = Q;
        else Padre->izquierdo = Q;
    else raiz = Q;

    // Reconstruir árbol:
    P->izquierdo = B;
    Q->derecho = P;

    // Reasignar padres:
    P->padre = Q;
    if(B) B->padre = P;
    Q->padre = Padre;

    // Ajustar valores de FE:
    P->FE = 0;
    Q->FE = 0;
}

// Rotación simple a izquierdas
void AVL::RSI(NodoAVL* nodo)
{
    cout << "RSI" << endl;
    NodoAVL *Padre = nodo->padre;
    NodoAVL *P = nodo;
    NodoAVL *Q = P->derecho;
    NodoAVL *B = Q->izquierdo;

    if(Padre)
        if(Padre->derecho == P) Padre->derecho = Q;
        else Padre->izquierdo = Q;
    else raiz = Q;

    // Reconstruir árbol:
    P->derecho = B;
    Q->izquierdo = P;

    // Reasignar padres:
    P->padre = Q;
    if(B) B->padre = P;
    Q->padre = Padre;

    // Ajustar valores de FE:
    P->FE = 0;
    Q->FE = 0;
}

// Eliminar un elemento de un árbol AVL

void AVL::InOrden(void (*func)(int&, int) , NodoAVL *nodo, bool r)
{
    if(r) nodo = raiz;
    if(nodo->izquierdo) InOrden(func, nodo->izquierdo, false);
    func(nodo->dato, nodo->FE);
    if(nodo->derecho) InOrden(func, nodo->derecho, false);
}

// Recorrido de árbol en preorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&, int);
void AVL::PreOrden(void (*func)(int&, int), NodoAVL *nodo, bool r)
{
    if(r) nodo = raiz;
    func(nodo->dato, nodo->FE);
    if(nodo->izquierdo) PreOrden(func, nodo->izquierdo, false);
    if(nodo->derecho) PreOrden(func, nodo->derecho, false);
}

// Recorrido de árbol en postorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&, int);
void AVL::PostOrden(void (*func)(int&, int), NodoAVL *nodo, bool r)
{
    if(r) nodo = raiz;
    if(nodo->izquierdo) PostOrden(func, nodo->izquierdo, false);
    if(nodo->derecho) PostOrden(func, nodo->derecho, false);
    func(nodo->dato, nodo->FE);
}

// Buscar un valor en el árbol
bool AVL::Buscar(const int dat)
{
    actual = raiz;

    // Todavía puede aparecer, ya que quedan nodos por mirar
    while(!Vacio(actual)) {
        if(dat == actual->dato) return true; // dato encontrado
        else if(dat > actual->dato) actual = actual->derecho; // Seguir
        else if(dat < actual->dato) actual = actual->izquierdo;
    }
    return false; // No está en árbol
}

// Calcular la altura del nodo que contiene el dato dat
int AVL::Altura(const int dat)
{
    int altura = 0;
    actual = raiz;

    // Todavía puede aparecer, ya que quedan nodos por mirar
    while(!Vacio(actual)) {
        if(dat == actual->dato) return altura; // dato encontrado
        else {
            altura++; // Incrementamos la altura, seguimos buscando
            if(dat > actual->dato) actual = actual->derecho;
            else if(dat < actual->dato) actual = actual->izquierdo;
        }
    }
    return -1; // No está en árbol
}

// Contar el número de nodos
const int AVL::NumeroNodos()
{
    contador = 0;

    auxContador(raiz); // FUnción auxiliar
    return contador;
}

// Función auxiliar para contar nodos. Función recursiva de recorrido en
//   preorden, el proceso es aumentar el contador
void AVL::auxContador(NodoAVL *nodo)
{
    contador++;  // Otro nodo
    // Continuar recorrido
    if(nodo->izquierdo) auxContador(nodo->izquierdo);
    if(nodo->derecho)   auxContador(nodo->derecho);
}

// Calcular la altura del árbol, que es la altura del nodo de mayor altura.
const int AVL::AlturaArbol()
{
    altura = 0;

    auxAltura(raiz, 0); // Función auxiliar
    return altura;
}

// Función auxiliar para calcular altura. Función recursiva de recorrido en
// postorden, el proceso es actualizar la altura sólo en nodos hojas de mayor
// altura de la máxima actual
void AVL::auxAltura(NodoAVL *nodo, int a)
{
    // Recorrido postorden
    if(nodo->izquierdo) auxAltura(nodo->izquierdo, a+1);
    if(nodo->derecho)   auxAltura(nodo->derecho, a+1);
    // Proceso, si es un nodo hoja, y su altura es mayor que la actual del
    // árbol, actualizamos la altura actual del árbol
    if(EsHoja(nodo) && a > altura) altura = a;
}

// Función de prueba para recorridos del árbol
void Mostrar(int &d, int FE)
{
    cout << d << "(" << FE << "),";
}
Lista<Cancion*>* AVL::Buscar(string artista) {
    Lista<Cancion*>*result= new Lista<Cancion*>();
    Cancion*temp;
    int c=0;
    while(c!=Cancion::Music->length){
        temp=Cancion::Music->get(c);
        if(temp->artista==artista){
            result->add(temp);
        }
        c++;
    }
    return result;
}
