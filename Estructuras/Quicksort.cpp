//
// Created by dario1227 on 24/04/18.
//

#include "Quicksort.h"

Nodo<Cancion>*partition(Nodo<Cancion>*head, Nodo<Cancion> *end,
                        Nodo<Cancion> **newHead, Nodo<Cancion> **newEnd) {
    Nodo<Cancion> *pivot = end;
    Nodo<Cancion> *prev = NULL, *cur = head, *tail = pivot;
    while (cur != pivot) {
        if (cur->value->nombre < pivot->value->nombre) {
            if ((*newHead) == NULL)
                (*newHead) = cur;

            prev = cur;
            cur = cur->next;
        }
        else
        {
            if (prev)
                prev->next = cur->next;
            Nodo<Cancion>*tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if ((*newHead) == NULL)
        (*newHead) = pivot;

    (*newEnd) = tail;

    return pivot;
}

Nodo<Cancion> *getTail (Nodo<Cancion> *cur){
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}
Nodo<Cancion> *quickSortRecur(Nodo<Cancion>*head, Nodo<Cancion>*end)
{
    if (!head || head == end)
        return head;

    Nodo<Cancion>* newHead = NULL, *newEnd = NULL;

    Nodo<Cancion> *pivot = partition(head, end, &newHead, &newEnd);
    if (newHead != pivot)
    {
        Nodo<Cancion> *tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;

        newHead = quickSortRecur(newHead, tmp);
        tmp = getTail(newHead);
        tmp->next =  pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}
void Quicksort::start(Lista<Cancion> *lista) {
    Nodo<Cancion> **headRef=&lista->head;
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
    return;
}