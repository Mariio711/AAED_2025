#ifndef LISTA_ENLA1_H
#define LISTA_ENLA1_H
#include <cstddef> // size_t
#include <utility> // swap
#include <cassert>

template <typename T> class Lista {
    struct nodo; // Declaración adelantada privada
public:
    typedef nodo* posicion; // Posición de un elemento
    Lista(); // Constructor, req. ctor. T()
    bool vacia() const;
    size_t tama() const;
    void insertar(const T& x, posicion p); // Requiere T copiable
    void eliminar(posicion p);
    const T& elemento(posicion p) const;   // Lec. elto. en Lista const
    T& elemento(posicion p);               // Lec/Esc elto. en Lista no-const
    posicion siguiente(posicion p) const;
    posicion anterior(posicion p) const;
    posicion primera() const;
    posicion fin() const;                  // Posición después del último
    Lista(const Lista& Lis);               // Ctor. de copia, req. T() y T copiable
    Lista& operator =(const Lista& Lis);   // Asig., req. T() y T copiable
    ~Lista();                              // Destructor
private:
    struct nodo {
        T elto;
        nodo* sig;
        nodo(const T& e = T(), nodo* p = nullptr) : elto(e), sig(p) {}
    };
    nodo* L;    // Lista enlazada con cabecera
    size_t n;   // Longitud de la lista
};
template <typename T>
inline Lista<T>::Lista() :
    L(new nodo), // Crear cabecera
    n(0)
{}

template <typename T>
inline bool Lista<T>::vacia() const {
    return n == 0;
}

template <typename T>
inline size_t Lista<T>::tama() const {
    return n;
}

template <typename T>
const T& Lista<T>::elemento(posicion p) const {
    assert(p->sig != nullptr); // p no es fin()
    return p->sig->elto;
}

template <typename T>
T& Lista<T>::elemento(posicion p) {
    assert(p->sig != nullptr); // p no es fin()
    return p->sig->elto;
}

template <typename T>
inline void Lista<T>::insertar(const T& x, posicion p) {
    p->sig = new nodo(x, p->sig);
    ++n;
    // El nuevo nodo con x queda en la posición p
}

template <typename T>
inline void Lista<T>::eliminar(posicion p) {
    assert(p->sig != nullptr); // p no es fin()
    nodo* q = p->sig;
    p->sig = q->sig;
    delete q;
    --n;
    // El nodo siguiente queda en la posición p
}

template <typename T>
inline typename Lista<T>::posicion Lista<T>::siguiente(posicion p) const {
    assert(p->sig != nullptr); // p != fin()
    return p->sig;
}

template <typename T>
typename Lista<T>::posicion Lista<T>::anterior(posicion p) const {
    assert(p != primera());
    posicion q = primera();
    while (q->sig != p) q = q->sig;
    return q;
}

template <typename T>
inline typename Lista<T>::posicion Lista<T>::primera() const { 
    return L; 
}

template <typename T>
typename Lista<T>::posicion Lista<T>::fin() const {
    posicion p = primera();
    while (p->sig != nullptr) p = p->sig;
    return p;
}

template <typename T>
Lista<T>::Lista(const Lista& Lis) : L(new nodo), n(0) {
    posicion p = Lis.primera();
    posicion q = primera();
    while (p != Lis.fin()) {
        insertar(Lis.elemento(p), q);
        p = Lis.siguiente(p);
        q = siguiente(q);
    }
}

template <typename T>
Lista<T>& Lista<T>::operator=(const Lista& Lis) {
    if (this != &Lis) {
        this->~Lista();
        L = new nodo;
        n = 0;
        posicion p = Lis.primera();
        posicion q = primera();
        while (p != Lis.fin()) {
            insertar(Lis.elemento(p), q);
            p = Lis.siguiente(p);
            q = siguiente(q);
        }
    }
    return *this;
}

template <typename T>
Lista<T>::~Lista() {
    while (!vacia()) {
        posicion p = primera();
        eliminar(p);
    }
    delete L; // Eliminar cabecera
}

#endif