//
// Created by kenneth on 24/04/18.
//

#ifndef PROGRA_2_DATOS_C_BTREENODE_H
#define PROGRA_2_DATOS_C_BTREENODE_H


class BTreeNode {
    int *keys;  //Array que debe ser cambiado a chars
    int t;      // minimo grado
    BTreeNode **C; // pointers a otros nodos
    int n;     // Numero actual de keys
    bool leaf;
public:

    BTreeNode(int _t, bool _leaf);   // Constructor

    void traverse();

    BTreeNode *search(int k);

    int findKey(int k);

    void insertNonFull(int k);

    void splitChild(int i, BTreeNode *y);

    void remove(int k);

    void removeFromLeaf(int idx);

    void removeFromNonLeaf(int idx);

    int getPred(int idx);

    int getSucc(int idx);

    void fill(int idx);

    void borrowFromPrev(int idx);

    void borrowFromNext(int idx);

    void merge(int idx);

    friend class BTree;
};


#endif //PROGRA_2_DATOS_C_BTREENODE_H
