//
// Created by kenneth on 24/04/18.
//

#ifndef PROGRA_2_DATOS_C_BTREE_H
#define PROGRA_2_DATOS_C_BTREE_H


#include <clocale>
#include "BTreeNode.h"

class BTree {
    BTreeNode *root; // Pointer to root node
    int t;  // Minimum degree
public:
    BTree(int _t)
    {
        root = nullptr;
        t = _t;
    }
    void traverse()
    {
        if (root != nullptr) root->traverse();
    }
    BTreeNode* search(int k)
    {
        return (root == nullptr)? nullptr : root->search(k);
    }
    void insert(int k);
    void remove(int k);
};


#endif //PROGRA_2_DATOS_C_BTREE_H
