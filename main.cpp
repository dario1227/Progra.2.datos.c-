//
// Created by dario1227 on 21/04/18.
//
#include <iostream>
#include <sys/stat.h>
#include <zconf.h>
#include <pwd.h>
#include <QtWidgets/QApplication>
#include "Estructuras/Lista.h"
#include "data/Cancion.h"
#include "Estructuras/BubbleSort.h"
#include "Estructuras/Quicksort.h"
#include "Estructuras/RadixSort.h"
#include "data/JsonFactory.h"
#include "Estructuras/BackTracking.h"
#include "data/PruebasXML.h"
#include "server/XML_handler.h"
#include "data/XML_generator.h"
#include "Estructuras/ArbolB.h"
#include "Estructuras/BinarySearch.h"

using namespace std;
void print(Lista<Cancion*>*lista){
    Nodo<Cancion*>*temp=lista->head;
    while(temp!= nullptr){
        struct passwd *pw = getpwuid(getuid());
        const char *homedir = pw->pw_dir;
        string name=homedir;
        string da=name+"/Songs";
        mkdir(da.c_str(), 0777);
        cout<<"\n############Cancion "<< temp->value->pos<<"##########"<<"\n";
        cout<<temp->value->nombre<<"\n";
        cout<<temp->value->artista<<"\n";
        cout<<temp->value->album<<"\n";
        temp=temp->next;
    }
}
int main(int argc, char **argv) {
   // PruebasXML::prueba2();
    Lista<Cancion*>* canciones = new Lista<Cancion*>();
    canciones->add( new Cancion("Vicarious","10000Days  Y MAD COADADAHFKLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFUWWWWWWWWWWWWWW","Tool     "," que ella amor"));
    canciones->add(new Cancion("Master","Master ","Megadeth","DALE LA MADRE QUE TE TRAKP"));
    canciones->add(new Cancion("Hangar 18","Rest in peace","Tool","1000 anos sin ti"));
    XML_generator::create_Music_list(canciones);
//    QApplication app(argc, argv);
//    new Cancion("Vicarious   ","10000Days  ","Tool     "," que ella amor");
//    new Cancion("Master   ","Master ","Metallica    ","amor");
//    new Cancion("Hangar18   ","Rest in peace  ","Megadeth    ","dale");
//    new Cancion("Futile   ","Fear   ","Porcupine    ","dale duro que ella quiere amor");
//    new Cancion("Schism    ","Lateralus","Tool   ","dale duro que ella quiere");
//    User* user1= new User("dario","19","dario1227","holisperras");
//    User* user2= new User("kenneth","18","kennethpapi","darksouls");
//    User* user3= new User("Roger","18","Rogerbb","h12345");
//    user1->addFriend(JsonFactory::makeUser(user2));
//    user1->addFriend(JsonFactory::makeUser(user3));
//    cout<<json_object_to_json_string(JsonFactory::makeUser(user1));
//    Quicksort::start(Cancion::Music);
//    print(Cancion::Music);
//    RadixSort::start(Cancion::Music);
//    print(Cancion::Music);
//    BubbleSort::start(Cancion::Music);
//    print(Cancion::Music);
//    string dta="dale duro que ella quiere amor";
//    cout<<BackTracking::start(Cancion::Music,dta)->nombre;
    cout<<Cancion::arbolb->Buscar_Nodo("Vicarious")->length;
    cout<<Cancion::avl->Buscar("Megadeth")->length;
    cout<<BinarySearch::start("Rest in peace")->album;
    return 0;
}