#ifndef PILA_BICOLA_H
#define PILA_BICOLA_H
#include <fstream>
#include <cstddef> //size_t
#include <cassert>
#include "bicola.h"

template <typename T>
class PilaBicola
{
public:
    // Constructor por defecto
    PilaBicola() {}

    // Constructor de copia
    PilaBicola(const PilaBicola<T>& otra) : B(otra.B) {}

    // Operador de asignación
    PilaBicola<T>& operator=(const PilaBicola<T>& otra) {
        if (this != &otra)
            B = otra.B;
        return *this;
    }

    // Destructor
    ~PilaBicola() = default;

    void push(const T &x)
    {
        B.push_final(x); // Insertar al final de la bicola
    }

    void pop()
    {
        assert(!B.vacia());
        B.pop_final(); // Eliminar el último elemento
    }

    const T &tope() const
    {
        assert(!B.vacia());
        return B.final(); // Consultar el último elemento
    }

    bool vacia() const
    {
        return B.vacia();
    }

    size_t tama() const
    {
        return B.tama();
    }

private:
    Bicola<T> B;
};

// Apila en P los valores numéricos de los dígitos extraídos del flujo de entrada fe
inline std::fstream &operator>>(std::fstream &fe, PilaBicola<int> &P)
{
    char cifra;
    while (fe.get(cifra) && cifra != '\n') // leer caracteres hasta fin de línea
        P.push(cifra - '0');               // convierte un dígito en su valor numérico
    return fe;
}

// Inserta en el flujo los elementos de la pila (del tope al fondo)
inline std::fstream &operator<<(std::fstream &fs, PilaBicola<int> &P)
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
