//
// Created by dario1227 on 24/04/18.
//

#include "RadixSort.h"
static void countingSort(string arr[],int index){
    char lower='a';
    char upper='z';
    int countArray[(upper-lower)+2];
    string tempArray[arr->length()];

    //increase count for char at index
    for(int i=0;i<arr->length();i++){
        int charIndex = (arr[i].length()-1 < index) ? 0 : ((arr[i].at(index) - lower)+1);
        countArray[charIndex]++;
    }

    //sum up countArray;countArray will hold last index for the char at each strings index
    for(int i=1;i<(upper-lower)+2;i++){
        countArray[i] += countArray[i-1];
    }

    for(int i=arr->length()-1;i>=0;i--){
        int charIndex = (arr[i].length()-1 < index) ? 0 : (arr[i].at(index) - lower)+1;
        tempArray[countArray[charIndex]-1] = arr[i];
        countArray[charIndex]--;
    }

    for(int i=0;i<tempArray->length();i++){
        arr[i] = tempArray[i];
    }
}

static void radixSort(string arr[], int size){
    int maxIndex = 0;
    int i=0;
    while(i<size){
        if(size-1> maxIndex){
            maxIndex = size-1;
        }
        i++;
    }
    for(maxIndex;maxIndex>=0;maxIndex--){
        cout<<maxIndex;
        countingSort(arr,maxIndex);
    }
}
void swap(Lista<Cancion *> *lista, string arr[]){
    Nodo<Cancion*>*temp;
    int y=0;
    temp=lista->head;
    Lista<Cancion*> *tempList= new Lista<Cancion*>();
    while(y!= lista->length){
        while(temp!= nullptr){
            if(temp->value->artista==arr[y]){
                tempList->add(temp->value);
            }
            temp=temp->next;
        }
        temp=lista->head;
        y++;

    }
    temp=lista->head;
   Nodo<Cancion*>* temp2=tempList->head;
    while(temp!= nullptr){
        temp=temp2;
        temp=temp->next;
        temp2=temp2->next;
    }
}
void RadixSort::start(Lista<Cancion *> *Lista) {
    Nodo<Cancion*>* temp=Lista->head;
    string copy[Lista->length];
    int y=0;
    while(temp!= nullptr){
        copy[y]=temp->value->artista;
        temp=temp->next;
        y++;
    }
    int x=0;
    while(x!=Lista->length){
        cout<<copy[x];
        x++;
    }
    radixSort(copy, Lista->length);
    x=0;
    while(x!=Lista->length){
        cout<<copy[x];
        x++;
    }
    swap(Lista,copy);

}
