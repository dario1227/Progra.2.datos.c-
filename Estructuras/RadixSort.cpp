//
// Created by dario1227 on 24/04/18.
//

#include "RadixSort.h"

size_t getMax(string arr[], int n) {
    size_t max = arr[0].size();
    for (int i = 1; i < n; i++) {
        if (arr[i].size() > max)
            max = arr[i].size();
    }
    return max;
}

void countSort(string a[], int size, size_t k) {
    string *b = NULL;
    int *c = NULL;
    b = new string[size];
    c = new int[257];


    for (int i = 0; i < 257; i++) {
        c[i] = 0;
    }
    for (int j = 0; j < size; j++) {
        c[k < a[j].size() ? (int) (unsigned char) a[j][k] + 1 : 0]++;            //a[j] is a string
    }

    for (int f = 1; f < 257; f++) {
        c[f] += c[f - 1];
    }

    for (int r = size - 1; r >= 0; r--) {
        b[c[k < a[r].size() ? (int) (unsigned char) a[r][k] + 1 : 0] - 1] = a[r];
        c[k < a[r].size() ? (int) (unsigned char) a[r][k] + 1 : 0]--;
    }

    for (int l = 0; l < size; l++) {
        a[l] = b[l];
    }

    delete[] b;
    delete[] c;
}


void radixSort(string b[], int r) {
    size_t max = getMax(b, r);
    for (size_t digit = max; digit > 0; digit--) {
        countSort(b, r, digit - 1);
    }

}

void swap(Lista<Cancion *> *lista, string arr[]) {
    Nodo<Cancion *> *temp;
    int y = 0;
    temp = lista->head;
    Lista<Cancion *> *tempList = new Lista<Cancion *>();
    while (y != lista->length) {
        while (temp != nullptr) {
            if (temp->value->artista == arr[y]) {
                tempList->add(temp->value);
            }
            temp = temp->next;
        }
        temp = lista->head;
        y++;

    }
    lista->head = tempList->head;
}

void RadixSort::start(Lista<Cancion *> *Lista) {
    Nodo<Cancion *> *temp = Lista->head;
    string copy[Lista->length];
    int y = 0;
    while (temp != nullptr) {
        copy[y] = temp->value->artista;
        temp = temp->next;
        y++;
    }
    int x = 0;
    while (x != Lista->length) {
        x++;
    }
    radixSort(copy, (int) (sizeof(copy) / sizeof(copy[0])));
    swap(Lista, copy);
    Cancion::order(Lista);
}