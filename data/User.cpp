//
// Created by dario1227 on 26/04/18.
//

#include "User.h"
static int count=0;
HashMap *User::UserHash=new HashMap();
void User::addFriend(json_object *compa) {
    json_object_array_add(this->compas,compa);
}
User::User(string name, string age, string ID, string password){
this->compas=json_object_new_array();
this->password=password;
this->name=name;
this->ID=ID;
this->age=age;
this->num=count;
UserHash->Insert(count,this);
count++;

}
User::User(){
    this->age= "";
    this->ID= "";
    this->name= "";
    this->password= "";
    this->compas=json_object_new_array();
    this->num=count;
    UserHash->Insert(count,this);
    count++;
}