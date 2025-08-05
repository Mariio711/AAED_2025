#ifndef COLA_BICOLA_H
#define COLA_BICOLA_H

#include <cstddef> //size_t
#include <utility> //swap
#include <cassert>
#include "bicola.h"

template <typename T>
class ColaBicola
{
public:
    ColaBicola();
    bool vacia() const;
    size_t tama() const;
    const T &frente() const;
    void pop();
    void push(const T &x);          // Requiere T copiable
    ColaBicola(const ColaBicola &C);            // Ctor. de copia, req. T copiable
    ColaBicola &operator=(const ColaBicola &C); // Asig. entre ColaBicolas, req. T copiable
    ~ColaBicola();                        // Destructor
private:
    Bicola<T> B;
};


template <typename T>
inline ColaBicola<T>::ColaBicola() {}

template <typename T>
inline bool ColaBicola<T>::vacia() const
{
    return B.inicio == nullptr;
}

template <typename T>
inline size_t ColaBicola<T>::tama() const
{
    return B.n_eltos;
}

template <typename T>
inline const T &ColaBicola<T>::frente() const
{
    assert(!vacia());
    return B.inicio->elto;
}

template <typename T>
inline void ColaBicola<T>::pop()
{
    B.pop_frente();
}

template <typename T>
inline void ColaBicola<T>::push(const T &x)
{
    B.push_final(x);
}

// constructor de copia
template <typename T>
ColaBicola<T>::ColaBicola(const ColaBicola &C) : B(C.B) {}

// asignación entre ColaBicolas
template <typename T>
inline ColaBicola<T> &ColaBicola<T>::operator=(const ColaBicola &C)
{
    if (this != &C)
        B = C.B;
    return *this;
}

// destructor: vacia la ColaBicola
template <typename T>
ColaBicola<T>::~ColaBicola() = default;

#endif