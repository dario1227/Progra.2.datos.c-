//
// Created by kenneth on 4/27/18.
//

#include <QtCore/QString>
#include "Binary_search_tree.h"

User *Binary_search_tree::search(string name) {
    Node *actual = root;
    while (actual != nullptr) {
        std::cout << "___________________________________________________________________" << std::endl;
        std::cout << actual->data << std::endl;
        if (QString(actual->data.c_str()).contains(name.c_str())) {
            return actual->usuario;
        } else if (actual->data > name) {
            actual = actual->right;
        } else {
            actual = actual->right;
        }
    }
    return nullptr;
}

void Binary_search_tree::insertar(string numero, User *usuario) {
    Node *newNode = new Node(usuario, numero);

    if (root == nullptr) {
        root = newNode;
        return;
    }
    Node *current = root;
    Node *parent = nullptr;
    while (true) {
        parent = current;
        if (numero < current->data) {
            current = current->left;
            if (current == nullptr) {
                parent->left = newNode;
                return;
            }
        } else {
            current = current->right;
            if (current == nullptr) {
                parent->right = newNode;
                return;
            }
        }
    }
}