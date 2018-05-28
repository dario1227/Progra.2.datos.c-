//
// Created by dario1227 on 26/04/18.
//

#include <algorithm>
#include "User.h"
#include "Data_Holder.h"

static int counter = 0;
HashMap *User::UserHash=new HashMap();
Lista<User*>*User::Users=new Lista<User*>();
void User::addFriend(json_object *compa) {
    json_object_array_add(this->compas,compa);
}
bool User::contains(User *amigo) {
    Lista<frien*>*lista=this->getFriends();
    Nodo<frien*>*temp= lista->head;
    bool result=false;
    while(temp!= nullptr){
        if(amigo->ID==temp->value->ID){
            result= true;
            return result;
        }
        temp=temp->next;
    }
    return  result;

}
string chop2(string data){
    string name=data;
    name.resize(name.length()-1);
    std::reverse(name.begin(), name.end());
    name.resize(name.length()-1);
    std::reverse(name.begin(), name.end());
    return name;

}
Lista<frien*>* User::getFriends() {
    Lista<frien*>* result=new Lista<frien*>();
    int y=0;
    while(y!=json_object_array_length(this->compas)) {
        json_object*Frien=json_object_array_get_idx(this->compas,y);
        string ID=json_object_to_json_string(json_object_object_get(Frien,"ID"));
        string password=json_object_to_json_string(json_object_object_get(Frien,"password"));
        string name=json_object_to_json_string(json_object_object_get(Frien,"name"));
        string age=json_object_to_json_string(json_object_object_get(Frien,"age"));
        string favorites=json_object_to_json_string(json_object_object_get(Frien,"favorites"));
        frien*dato=new frien();
        dato->password=chop2(password);
        dato->favorites=chop2(favorites);
        dato->age=chop2(age);
        dato->name=chop2(name);
        dato->ID=chop2(ID);
        result->add(dato);
        y++;
    }
    return result;

}
User::User(string name, string age, string ID, string password){
this->compas=json_object_new_array();
this->password=password;
this->name=name;
this->ID=ID;
this->age=age;
    this->num = counter;
    UserHash->Insert(counter, this);
    User::Users->add(this);
    counter++;
    Data_Holder::users->insertar(name,this);


}
User::User(){
    this->age= "";
    this->ID= "";
    this->name= "";
    this->password= "";
    this->compas=json_object_new_array();
    this->num = counter;
    UserHash->Insert(counter, this);
    User::Users->add(this);
    counter++;
}