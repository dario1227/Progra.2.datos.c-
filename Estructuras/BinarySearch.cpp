//
// Created by dario1227 on 01/05/18.
//

#include "BinarySearch.h"
#include "Nodo.h"
#include "../data/Cancion.h"
#include "BubbleSort.h"
#include <iostream>

Nodo<Cancion *> *nodo = new Nodo<Cancion *>();

Nodo<Cancion *> *middle(Nodo<Cancion *> *start, Nodo<Cancion *> *last) {
    if (start == NULL)
        return NULL;

    Nodo<Cancion *> *slow = start;
    Nodo<Cancion *> *fast = start->next;

    while (fast != last) {
        fast = fast->next;
        if (fast != last) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    return slow;
}

Cancion *aux(string value) {
    Lista<Cancion *> *lista = Cancion::Music;
    Nodo<Cancion *> *start = lista->head;
    Nodo<Cancion *> *last = NULL;

    do {
        // Find middle
        Nodo<Cancion *> *mid = middle(start, last);

        // If middle is empty
        if (mid == NULL)
            return NULL;

        // If value is present at middle
        if (mid->value->album == value) {
            return mid->value;
        } else if (mid->value->album < value) {
            start = mid->next;
        } else {
            last = mid;
        }

    } while (last == NULL ||
             last->next != start);

    // value not present
    return nullptr;
}

//busca una cancion con esos dos atributos
Cancion *BinarySearch::search(string name, string artist) {
    Nodo<Cancion *> *temp = Cancion::Music->head;
    while (temp != nullptr) {
        if (temp->value->nombre == name && temp->value->artista == artist) {
            return temp->value;
        }
        temp = temp->next;
    }
    return nullptr;

}

Lista<Cancion *> *BinarySearch::start(string album) {
    BubbleSort::start(Cancion::Music);
    Cancion *find = aux(album);
    Lista<Cancion *> *result = new Lista<Cancion *>();
    Nodo<Cancion *> *temp = Cancion::Music->head;
    while (temp != nullptr) {
        if (temp->value->album == find->album) {
            result->add(temp->value);
        }
        temp = temp->next;
    }
    return result;
}