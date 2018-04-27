//
// Created by dario1227 on 21/04/18.
//
#include <iostream>
#include <sys/stat.h>
#include <zconf.h>
#include <pwd.h>
#include "Estructuras/Lista.h"
#include "data/Cancion.h"
#include "Estructuras/BubbleSort.h"
#include "Estructuras/Quicksort.h"
#include "Estructuras/RadixSort.h"
#include "data/JsonFactory.h"
using namespace std;
void print(Lista<Cancion*>*lista){
    Nodo<Cancion*>*temp=lista->head;
    int x=1;
    while(temp!= nullptr){
        struct passwd *pw = getpwuid(getuid());
        const char *homedir = pw->pw_dir;
        string name=homedir;
        string da=name+"/Songs";
        mkdir(da.c_str(), 0777);
        cout<<"############Cancion "<< x<<"##########"<<"\n";
        cout<<temp->value->nombre<<"\n";
        cout<<temp->value->artista<<"\n";
        cout<<temp->value->album<<"\n";
        temp=temp->next;
        x++;
    }
}
int main() {
    Lista<Cancion*>* prueba=new Lista<Cancion*>();
    prueba->add(new Cancion("Vicarious   ","10000Days  ","Tool     ",""));
    prueba->add(new Cancion("Master   ","Master ","Metallica    ",""));
    prueba->add(new Cancion("Hangar18   ","Rest in peace  ","Megadeth    ",""));
    prueba->add( new Cancion("Futile   ","Fear   ","Porcupine    ",""));
    prueba->add(new Cancion("Schism    ","Lateralus","Tool   ",""));
    User* user1= new User("dario","19","dario1227","holisperras");
    User* user2= new User("kenneth","18","kennethpapi","darksouls");
    User* user3= new User("Roger","18","Rogerbb","h12345");
    user1->addFriend(JsonFactory::makeUser(user2));
    user1->addFriend(JsonFactory::makeUser(user3));
    cout<<json_object_to_json_string(JsonFactory::makeUser(user1));
    Quicksort::start(prueba);
    print(prueba);
    RadixSort::start(prueba);
    print(prueba);
    BubbleSort::start(prueba);
    print(prueba);
    cout<<User::UserHash->Search(user2->num)->password;
    return 0;
}