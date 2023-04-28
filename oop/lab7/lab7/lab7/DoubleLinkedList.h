#pragma once
#include "Node.h"

template <typename T>
class DoubleLinkedList {
public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    void PushOnFront(const T &val);
    void PushOnBack(const T &val);
    T PopFromBack();
    void PrintAll(void (*printFunc)(const T &));
    int GetCount();

private:
    Node<T> *prim;
    Node<T> *ultim;
    int k;
};

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList() : prim(nullptr), ultim(nullptr), k(0) {}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList() {
    while (prim) {
        Node<T> *a = prim->urm;
        delete prim;
        prim = a;
    }
}

template <typename T>
void DoubleLinkedList<T>::PushOnFront(const T &val) {
    Node<T> *a = new Node<T>{ val, nullptr, nullptr };
    if (prim == nullptr) {
        prim = a;
        ultim = a;
    }
    else {
        a->urm = prim;
        prim->ant = a;
        prim = a;
    }
    k++;
}

template <typename T>
void DoubleLinkedList<T>::PushOnBack(const T &val) {
    Node<T> *a = new Node<T>{ val, nullptr, nullptr };
    if (ultim == nullptr) {
        prim = a;
        ultim = a;
    }
    else {
        a->ant = ultim;
        ultim->urm = a;
        ultim = a;
    }
    k++;
}

template <typename T>
T DoubleLinkedList<T>::PopFromBack() {
    T a = ultim->val;
    if (prim == ultim) {
        delete ultim;
        prim = ultim = nullptr;
    }
    else {
        ultim = ultim->ant;
        delete ultim->urm;
        ultim->urm = nullptr;
    }
    k--;
    return a;
}

template <typename T>
void DoubleLinkedList<T>::PrintAll(void (*printFunc)(const T&)) {
    printf("Elements: %d => ", k);
    Node<T> *a = prim;
    while (a) {
        printFunc(a->val);
        a = a->urm;
    }
    printf("\n");
}

template <typename T>
int DoubleLinkedList<T>::GetCount() {
    return k;
}
