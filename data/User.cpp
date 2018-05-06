//
// Created by dario1227 on 26/04/18.
//

#include "User.h"

static int counter = 0;
HashMap *User::UserHash=new HashMap();
Lista<User*>*User::Users=new Lista<User*>();
void User::addFriend(json_object *compa) {
    json_object_array_add(this->compas,compa);
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