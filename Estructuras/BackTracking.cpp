//
// Created by dario1227 on 28/04/18.
//

#include <QtCore/QString>
#include <QtGui/QTextCursor>
#include <QtGui/QTextDocument>
#include <QtWidgets/QPlainTextEdit>
#include "BackTracking.h"
//separa la frase en palabras

static Lista<QString> *separate(QString *frase) {
    Lista<QString> *words = new Lista<QString>();
    QString word;
    int y = 0;
    while (y < frase->length()) {
        if (frase->at(y) != toascii(32)) {
            word.append(frase->at(y));
            y++;
        } else {
            words->add(word);
            word.clear();
            y++;
        }
    }
    words->add(word);
    return words;
}
//inicia el backtracking
Cancion *BackTracking::start(Lista<Cancion *> *Music, string frase) {
    Lista<QString> *words = separate(new QString(frase.c_str()));
    Nodo<Cancion *> *temp = Music->head;
    while (temp != nullptr) {
        if (temp->value->letra->contains(frase.c_str())) {
            return temp->value;
        }
        temp = temp->next;
    }
    temp = Music->head;
    Nodo<QString> *palabra = words->head;
    Cancion *result;
    int x = 0;
    while (temp != nullptr) {
        int y = x;
        x = 0;
        while (palabra != nullptr) {
            if (temp->value->letra->contains(palabra->value)) {
                x++;
            }
            palabra = palabra->next;
        }
        if (x > y) {
            result = temp->value;
        }
        palabra = words->head;
        temp = temp->next;
    }
    return result;


}