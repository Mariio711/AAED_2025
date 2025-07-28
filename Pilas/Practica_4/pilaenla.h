#ifndef PILA_ENLA_H
#define PILA_ENLA_H
#include <fstream>
#include <cstddef> //size_t
#include <cassert>

template <typename T>
class Pila
{
public:
    Pila();
    bool vacia() const;
    size_t tama() const;
    const T &tope() const;
    void pop();
    void push(const T &x);          // requiere T copiable
    Pila(const Pila &P);            // Ctro de copia, requiere T copiable
    Pila &operator=(const Pila &P); // Asig. entre pilas, requiere T copiable
    ~Pila();                        // Desctructor

private:
    struct nodo
    {
        T elto;
        nodo *sig;
        nodo(const T &e, nodo *p = nullptr) : elto(e), sig(p) {}
    };

    nodo *tope_;
    size_t n_eltos;
};

template <typename T>
inline Pila<T>::Pila() : tope_(nullptr),
                         n_eltos(0)
{
}

template <typename T>
inline bool Pila<T>::vacia() const
{
    return (n_eltos == 0); // alternativa: return tope_ == nullptr;
}

template <typename T>
inline size_t Pila<T>::tama() const
{
    return n_eltos;
}

template <typename T>
inline const T &Pila<T>::tope() const
{
    assert(!vacia());
    return tope_->elto;
}

template <typename T>
inline void Pila<T>::pop()
{
    assert(!vacia());
    nodo *p = tope_;
    tope_ = p->sig;
    delete p;
    --n_eltos;
}

template <typename T>
inline void Pila<T>::push(const T &x)
{
    tope_ = new nodo(x, tope_);
    ++n_eltos;
}

// constructor de copia
template <typename T>
Pila<T>::Pila(const Pila &P) : Pila()
{
    if (!P.vacia())
    {
        tope_ = new nodo(P.tope()); // copiar el primer elemento
        // Copiar el resto de elementos hasta el fondo de la pila
        nodo *p = tope_;        // p recorre la pila destino(*this)
        nodo *q = P.tope_->sig; // q recorre la pila origen (P) desde el segundo nodo
        while (q)
        {
            p->sig = new nodo(q->elto);
            p = p->sig;
            q = q->sig;
        }
        n_eltos = P.n_eltos;
    }
}

// asignación ente pilas
template <typename T>
inline Pila<T> &Pila<T>::operator=(const Pila &P)
{
    Pila Q(P); // Si falla, *this no cambia
    // intercambiar atributos con la pila Q
    nodo *t = tope_;
    tope_ = Q.tope_;
    Q.tope_ = t;
    size_t n = n_eltos;
    n_eltos = Q.n_eltos;
    Q.n_eltos = n;
    return *this;
} // destrucción de Q (contenido previo de la pila de destino)

// Destructor -> vacía la pila
template <typename T>
Pila<T>::~Pila()
{
    nodo *p;
    while (tope_)
    {
        p = tope_->sig;
        delete tope_;
        tope_ = p;
    }
    n_eltos = 0;
}

// Apila en P los valores numéricos de los dígitos extraídos del flujo de entrada fe
inline std::fstream &operator>>(std::fstream &fe, Pila<int> &P)
{
    char cifra;
    while (fe.get(cifra) && cifra != '\n') // leer caracteres hasta fin de línea
        P.push(cifra - '0');               // convierte un dígito en su valor numérico
    return fe;
}

// Inserta en el flujo los elementos de la pila (del tope al fondo)
inline std::fstream &operator<<(std::fstream &fs, Pila<int> &P)
{
    while (!P.vacia())
    {
        fs << P.tope();
        P.pop();
    }
    fs << std::endl;
    return fs;
}

#endif // PILA_ENLA_H
