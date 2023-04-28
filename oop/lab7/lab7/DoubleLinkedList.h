#pragma once
#include "Node.h"

template <typename T>
class DoubleLinkedList {
public:
    DoubleLinkedList() : prim(nullptr), ultim(nullptr), k(0) {}
    ~DoubleLinkedList() {
        while (prim) {
            Node<T> *a = prim->urm;
            delete prim;
            prim = a;
        }
    }
    void PushOnFront(const T &val) {
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
    void PushOnBack(const T &val) {
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
    T PopFromBack() {
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
    void PrintAll(void (*printFunc)(const T&)) {
        printf("Elements: %d => ", k);
        Node<T> *a = prim;
        while (a) {
            printFunc(a->val);
            a = a->urm;
        }
        printf("\n");
    }
    int GetCount() {
        return k;
    }

private:
    Node<T> *prim;
    Node<T> *ultim;
    int k;
};

