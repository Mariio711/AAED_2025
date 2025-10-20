/*EJ6. Se quiere representar el TAD Conjunto de tal forma que los elementos estén almacenados
en una secuencia de celdas enlazadas.
Especifique e implemente el TAD Conjunto, representado mediante celdas enlazadas, con
las siguientes operaciones: crear conjunto vacío, comprobar si está vacío, cardinal,
comprobar la pertenencia de un elemento, devolver la lista de elementos, añadir un elemento,
eliminar un elemento, unión, intersección y diferencia de conjuntos.
*/

#ifndef CONJUNTO_H
#define CONJUNTO_H
#include <cstddef> // size_t
#include <utility> // swap
#include <cassert>

template <typename T>
class Conjunto
{
    struct nodo; // Declaración adelantada privada
public:
    typedef nodo *posicion; // Posición de un elemento
    Conjunto();             // Requiere ctor. T()
    bool vacia() const;
    size_t cardinal() const;
    void insertar(const T &x, posicion &p); // Requiere T copiable
    void eliminar(posicion &p);
    const T &elemento(posicion p) const; // Lec. elto. en Conjunto const
    T &elemento(posicion p);             // Lec/Esc elto. en Conjunto no-const
    posicion siguiente(posicion p) const;
    posicion anterior(posicion p) const;
    posicion primera() const;
    posicion fin() const;                     // Posición después del último
    Conjunto(const Conjunto &Lis);            // Ctor. de copia, req. T() y T copiable
    Conjunto &operator=(const Conjunto &Lis); // Asig., req. T() y T copiable

    // metodos especificos de conjuntos
    bool contiene(const T &x) const; // Comprobar pertenencia
    Conjunto operator+(const Conjunto &otro) const;
    Conjunto operator&(const Conjunto &otro) const;
    Conjunto operator-(const Conjunto &otro) const;

    ~Conjunto(); // Destructor
private:
    struct nodo
    {
        T elto;
        nodo *sig;
        nodo(const T &e = T(), nodo *p = nullptr) : elto(e), sig(p) {}
    };
    nodo *L;  // Conjunto enlazada simple con cabecera
    size_t n; // Longitud de la Conjunto
};
template <typename T>
inline Conjunto<T>::Conjunto() : L(nullptr), n(0) {}

template <typename T>
inline bool Conjunto<T>::vacia() const
{
    return n == 0;
}

template <typename T>
inline size_t Conjunto<T>::cardinal() const
{
    return n;
}

template <typename T>
const T &Conjunto<T>::elemento(posicion p) const
{
    assert(p != fin());
    return p->elto;
}

template <typename T>
T &Conjunto<T>::elemento(posicion p)
{
    assert(p != fin());
    return p->elto;
}

template <typename T>
inline typename Conjunto<T>::posicion Conjunto<T>::siguiente(posicion p) const
{
    assert(p != fin());
    return p->sig;
}

template <typename T>
typename Conjunto<T>::posicion Conjunto<T>::anterior(posicion p) const
{
    assert(p != primera());
    posicion q = primera();
    while (q->sig != p)
        q = q->sig;
    return q;
}

template <typename T>
inline typename Conjunto<T>::posicion Conjunto<T>::primera() const
{
    return L;
}

template <typename T>
inline typename Conjunto<T>::posicion Conjunto<T>::fin() const
{
    return nullptr;
}

template <typename T>
void Conjunto<T>::insertar(const T &x, posicion &p)
{
    if (p == primera())
        p = L = new nodo(x, p);
    else
    { // Inserción en cualquier otra posición, incluso fin()
        posicion q = anterior(p);
        p = q->sig = new nodo(x, p);
    }
    ++n;
    // El nuevo nodo con x queda en la posición p
}

template <typename T>
void Conjunto<T>::eliminar(posicion &p)
{
    assert(p != fin());
    if (p == primera())
    {
        L = p->sig;
        delete p;
        p = primera();
    }
    else
    {
        posicion q = anterior(p);
        q->sig = p->sig;
        delete p;
        p = q->sig;
    }
    --n;
    // El nodo siguiente queda en la posición p
}

template <typename T>
Conjunto<T>::Conjunto(const Conjunto &Lis) : L(nullptr), n(0)
{
    posicion p = Lis.primera();
    while (p != Lis.fin())
    {
        posicion q = fin();
        insertar(Lis.elemento(p), q);
        p = Lis.siguiente(p);
    }
}

template <typename T>
Conjunto<T> &Conjunto<T>::operator=(const Conjunto &Lis)
{
    if (this != &Lis)
    {
        this->~Conjunto();
        L = nullptr;
        n = 0;
        posicion p = Lis.primera();
        while (p != Lis.fin())
        {
            posicion q = fin();
            insertar(Lis.elemento(p), q);
            p = Lis.siguiente(p);
        }
    }
    return *this;
}

// metodos especificos de conjuntos
template <typename T>
bool Conjunto<T>::contiene(const T &x) const
{
    posicion p = primera();
    while (p != fin())
    {
        if (elemento(p) == x)
            return true;
        p = siguiente(p);
    }
    return false;
}

template <typename T>
Conjunto<T> Conjunto<T>::operator&(const Conjunto &otro) const
{
    Conjunto<T> inter;

    // Para cada elemento de this
    posicion p = this->primera();
    while (p != this->fin())
    {
        // Comprobar si está en el otro conjunto
        if (otro.contiene(this->elemento(p)))
        {
            // Si no está ya en el resultado
            if (!inter.contiene(this->elemento(p)))
            {
                posicion q = inter.fin();
                inter.insertar(this->elemento(p), q);
            }
        }
        p = this->siguiente(p);
    }

    return inter;
}

template <typename T>
Conjunto<T> Conjunto<T>::operator+(const Conjunto &otro) const
{
    Conjunto<T> uni;

    // Para cada elemento de this insertar en uni
    posicion p = this->primera();
    while (p != this->fin())
    {
        if (!uni.contiene(this->elemento(p)))
        {
            posicion q = uni.fin();
            uni.insertar(this->elemento(p), q);
        }

        p = this->siguiente(p);
    }

    posicion j = otro.primera();
    while (j != otro.fin())
    {
        // Si no está ya en el resultado
        if (!uni.contiene(otro.elemento(j)))
        {
            posicion q = uni.fin();
            uni.insertar(otro.elemento(j), q);
        }
        j = otro.siguiente(j);
    }

    return uni;
}

template <typename T>
Conjunto<T> Conjunto<T>::operator-(const Conjunto &otro) const
{
    Conjunto<T> dif;
    posicion p = this->primera();
    while(p != this->fin())
    {
        if(!otro.contiene(this->elemento(p)))
        {
            posicion q = dif.fin();
            dif.insertar(this->elemento(p), q);
        }
        p = this->siguiente(p);
    }
    return dif;

}

template <typename T>
Conjunto<T>::~Conjunto()
{
    while (!vacia())
    {
        posicion p = primera();
        eliminar(p);
    }
}
#endif