#ifndef Bicola_ENLA_H
#define Bicola_ENLA_H

#include <cstddef> //size_t
#include <utility> //swap
#include <cassert>

template <typename T>
class Bicola
{
public:
    Bicola();
    bool vacia() const;
    size_t tama() const;
    const T &frente() const;
    void pop_frente();
    void pop_final();
    void push_final(const T &x);          // Requiere T copiable
    void push_frente(const T &x);
    Bicola(const Bicola &C);            // Ctor. de copia, req. T copiable
    Bicola &operator=(const Bicola &C); // Asig. entre Bicolas, req. T copiable
    ~Bicola();                        // Destructor

private:
    struct nodo
    {
        T elto;
        nodo *sig;
        nodo(const T &e, nodo *p = nullptr) : elto(e), sig(p) {}
    };

    nodo *inicio, *fin;
    size_t n_eltos;
};

template <typename T>
inline Bicola<T>::Bicola() : inicio(nullptr), n_eltos(0) {}

template <typename T>
inline bool Bicola<T>::vacia() const
{
    return inicio == nullptr;
}

template <typename T>
inline size_t Bicola<T>::tama() const
{
    return n_eltos;
}

template <typename T>
inline const T &Bicola<T>::frente() const
{
    assert(!vacia());
    return inicio->elto;
}

//elimina el elemento del frende de la bicola
template <typename T>
inline void Bicola<T>::pop_frente()
{
    assert(!vacia());
    nodo *p = inicio;
    inicio = p->sig;
    delete p;
    --n_eltos;
}

//elimina el elemento del final de la cola
template <typename T>
inline void Bicola<T>::pop_final()
{
    assert(!vacia());
    if (inicio == fin) {
        // Solo hay un elemento
        delete fin;
        inicio = fin = nullptr;
    } else {
        // Más de un elemento: buscar el anterior al último
        nodo *p = inicio;
        while (p->sig != fin)
            p = p->sig;
        delete fin;
        fin = p;
        fin->sig = nullptr;
    }
    --n_eltos;
}

//inserción por el final de la cola
template <typename T>
inline void Bicola<T>::push_final(const T &x)
{
    if (vacia())
    {
        inicio = fin = new nodo(x);
    }
    else
    {
        fin = fin->sig = new nodo(x);
    }
    ++n_eltos;
}

//inserción por el frente de la cola
template <typename T>
inline void Bicola<T>::push_frente(const T &x)
{
    if (vacia())
    {
        inicio = fin = new nodo(x);
    }
    else
    {
        inicio = new nodo(x, inicio);
    }
    ++n_eltos;
}

// constructor de copia
template <typename T>
Bicola<T>::Bicola(const Bicola &C) : Bicola()
{
    if (!C.vacia())
    {
        // copiar primer elemento
        inicio = fin = new nodo(C.inicio->elto);
        // copiar el resto de elementos hasta el final de C
        for (nodo *p = C.inicio->sig; p; p = p->sig)
        {
            fin = fin->sig = new nodo(p->elto);
        }
        n_eltos = C.n_eltos;
    }
}

// asignación entre Bicolas
template <typename T>
inline Bicola<T> &Bicola<T>::operator=(const Bicola &C)
{
    Bicola D(C);
    std::swap(inicio, D.inicio);
    std::swap(fin, D.fin);
    std::swap(n_eltos, D.n_eltos);
    return *this;
}

// destructor: vacia la Bicola
template <typename T>
Bicola<T>::~Bicola()
{
    nodo *p;
    while (inicio)
    {
        p = inicio->sig;
        delete inicio;
        inicio = p;
    }
    n_eltos = 0;
}

#endif // Bicola_ENLA_H