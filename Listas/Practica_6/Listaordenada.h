/*Ej5. Una lista ordenada es una lista cuyos elementos están ordenados de forma ascendente
según la relación de orden definida entre ellos por el operador <. Especifique e implemente
el TAD Lista ordenada. Repita el ejercicio 2. y explique el beneficio de usar este TAD.*/

#ifndef LISTA_ORDE_H
#define LISTA_ORDE_H
#include <cstddef> // size_t
#include <utility> // swap
#include <cassert>

template <typename T>
class Lista
{
    struct nodo; // Declaración adelantada privada
public:
    typedef nodo *posicion; // Posición de un elemento
    Lista();                // Requiere ctor. T()
    bool vacia() const;
    size_t tama() const;
    void insertar(const T &x); // Inserta manteniendo orden - Requiere T copiable y operator<
    void eliminar(posicion p);
    const T &elemento(posicion p) const; // Solo lectura - mantiene invariante de orden
    // NOTA: NO hay elemento() modificable para preservar el orden
    posicion siguiente(posicion p) const;
    posicion anterior(posicion p) const;
    posicion primera() const;           // Devuelve la cabecera (posición antes del 1º elemento)
    posicion fin() const;               // Cabecera (sentinela). siguiente(fin()) == primer nodo o fin si vacía
    
    // Métodos específicos de lista ordenada
    posicion buscar(const T& x) const;  // Búsqueda eficiente
    bool contiene(const T& x) const;    // Verificar existencia
    bool insertar_unico(const T& x);    // Insertar solo si no existe
    
    Lista(const Lista &Lis);            // Ctor. de copia
    Lista &operator=(const Lista &Lis); // Asignación
    ~Lista();                           // Destructor
    
    // INVARIANTE: Los elementos están ordenados ascendentemente según operator<
    // REQUISITO: T debe tener operator< y operator== definidos
private:
    struct nodo
    {
        T elto;
        nodo *sig;
        nodo(const T &e = T(), nodo *p = nullptr) : elto(e), sig(p) {}
    };
    nodo *L;  // Cabecera (sentinela) fija: L->sig apunta al primer nodo o a L si vacía
    size_t n; // Longitud de la lista
};

template <typename T>
inline Lista<T>::Lista() : L(new nodo), // Crear cabecera
                           n(0)
{
    L->sig = L; // Estructura circular
}

template <typename T>
inline bool Lista<T>::vacia() const
{
    return n == 0; // Alternativa: return primera() == fin();
}

template <typename T>
inline size_t Lista<T>::tama() const { return n; }

template <typename T>
inline void Lista<T>::eliminar(posicion p)
{
    // p es la posición previa al nodo a eliminar
    assert(p != nullptr && p->sig != L); // hay nodo a eliminar
    nodo* q = p->sig;
    p->sig = q->sig;
    delete q;
    --n;
}

template <typename T>
inline const T &Lista<T>::elemento(posicion p) const
{
    // p es la posición ANTERIOR al nodo cuyo elemento se quiere leer
    assert(p != nullptr && p->sig != nullptr && p->sig != fin());
    return p->sig->elto;
}

template <typename T>
inline typename Lista<T>::posicion Lista<T>::siguiente(posicion p) const
{
    // siguiente(fin()) es el primer nodo de datos (o fin() si vacía)
    assert(p != nullptr);
    return p->sig;
}

template <typename T>
typename Lista<T>::posicion Lista<T>::anterior(posicion p) const
{
    assert(p != primera());
    posicion q = primera();
    while (q->sig != p)
        q = q->sig;
    return q;
}

template <typename T>
inline typename Lista<T>::posicion Lista<T>::primera() const { return L; }

template <typename T>
inline typename Lista<T>::posicion Lista<T>::fin() const { return L; }

// Constructor de copia
template <typename T>
Lista<T>::Lista(const Lista &Lis) : Lista()
{
    // Copia lineal preservando orden
    nodo* tail = L; // previo al primer nodo copiado
    for (nodo *p = Lis.L->sig; p != Lis.L; p = p->sig)
    {
        tail->sig = new nodo(p->elto, L); // siguiente apunta a cabecera por defecto
        tail = tail->sig;
        ++n;
    }
    // Cerrar el último hacia L ya se hizo al construir cada nodo
}

// Asignación de listas
template <typename T>
inline Lista<T> &Lista<T>::operator=(const Lista &Lis)
{
    Lista L1(Lis);
    std::swap(L, L1.L);
    std::swap(n, L1.n);
    return *this;
}

// Destructor: vacía la lista y destruye el nodo cabecera
template <typename T>
Lista<T>::~Lista()
{
    nodo *p;
    while (L != L->sig)
    {
        p = L->sig;
        L->sig = p->sig;
        delete p;
    }
    delete L;
}

template <typename T>
void Lista<T>::insertar(const T &x)
{
    posicion p = L; // previo
    while (p->sig != L && p->sig->elto < x)
        p = p->sig;
    p->sig = new nodo(x, p->sig);
    ++n;
}

// Búsqueda eficiente en lista ordenada
template <typename T>
typename Lista<T>::posicion Lista<T>::buscar(const T& x) const {
    // Devuelve la posición previa al nodo cuyo elto==x, o fin() si no está
    posicion p = L; // cabecera
    while (p->sig != L && p->sig->elto < x)
        p = p->sig;
    if (p->sig != L && p->sig->elto == x)
        return p; // previo al encontrado
    return L; // fin()
}

// Verificar si contiene un elemento
template <typename T>
bool Lista<T>::contiene(const T& x) const {
    return buscar(x) != L; // fin()
}

// Insertar solo si no existe
template <typename T>
bool Lista<T>::insertar_unico(const T& x) {
    if (!contiene(x)) { insertar(x); return true; }
    return false;
}
#endif // LISTA_ENLA_H