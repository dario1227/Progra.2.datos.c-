//
// Created by dario1227 on 01/05/18.
//

#include "BinarySearch.h"
#include "Nodo.h"
#include "../data/Cancion.h"
#include "BubbleSort.h"
#include <iostream>
Nodo<Cancion*>*nodo=new Nodo<Cancion*>();

Nodo<Cancion*>* middle(Nodo<Cancion*>* start, Nodo<Cancion*>* last)
{
    if (start == NULL)
        return NULL;

    Nodo<Cancion*>* slow = start;
    Nodo<Cancion*>* fast = start -> next;

    while (fast != last)
    {
        fast = fast -> next;
        if (fast != last)
        {
            slow = slow -> next;
            fast = fast -> next;
        }
    }

    return slow;
}
Cancion* aux(string value)
{
    Lista<Cancion*>*lista=Cancion::Music;
    Nodo<Cancion*>* start = lista->head;
    Nodo<Cancion*>* last = NULL;

    do
    {
        // Find middle
        Nodo<Cancion*>* mid = middle(start, last);

        // If middle is empty
        if (mid == NULL)
            return NULL;

        // If value is present at middle
        if (mid -> value->album == value) {
            return mid->value;
        }

        else if (mid -> value->album< value) {
            start = mid->next;
        }

        else {
            last = mid;
        }

    } while (last == NULL ||
             last -> next != start);

    // value not present
    return nullptr;
}
Cancion* BinarySearch::start(string album){
    BubbleSort::start(Cancion::Music);
    return aux(album);
}