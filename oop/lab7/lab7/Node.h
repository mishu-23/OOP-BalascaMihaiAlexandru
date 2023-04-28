#pragma once
template <typename T>
struct Node {
    T val;
    Node<T> *urm;
    Node<T> *ant;
};