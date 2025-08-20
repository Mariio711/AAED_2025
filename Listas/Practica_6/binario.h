/*El TAD número binario consta de un conjunto de elementos definidos como secuencias de
la forma bn bn−1 . . . b1 b0, donde cada b_i es un dígito binario cuyo valor es 0 ó 1 y n ≥ 0,

Las operaciones de este TAD son las siguientes:
    -Constructor:   Genera un número binario a partir de una cadena de caracteres con
                    ceros y unos.
    -verNumero:     Devuelve el número binario en forma de cadena de caracteres.
    -Operaciones lógicas de bits NOT, AND, OR inclusivo y OR exclusivo.
    -Desplazamiento a la izquierda n bits. Cada bit se desplaza n posiciones a la izquierda,
     introduciendo ceros por la derecha y desechando los n bits de la izquierda.
    -Desplazamiento a la derecha n bits. Se añaden n ceros por la izquierda y se desechan
     los n bits de la derecha.

a) Realice la especificación del TAD número binario con las operaciones anteriores.
b) Implemente el TAD número binario según la anterior especificación.

Nota 1: No conviene que estas operaciones sean miembros de la clase, sino amigas.
Nota 2: Las operaciones lógicas y los desplazamientos se pueden implementar mediante
funciones, pero si lo prefiere puede sobrecargar los operadores ~, &, |, ^, << y >>.*/

#ifndef BINARIO_H
#define BINARIO_H

#include "listaenla1.h"
#include <string>
#include <assert.h>

class Binario
{
public:
    Binario(std::string cadena = "0");
    std::string verNumero() const;

    // operaciones lógicas

    friend Binario operator&(const Binario &a, const Binario &b); // AND
    friend Binario operator|(const Binario &a, const Binario &b); // OR
    friend Binario operator^(const Binario &a, const Binario &b); // XOR
    Binario operator~() const;                                    // NOT
    friend Binario operator<<(const Binario &a, int n);           // Desplazamiento a la izquierda
    friend Binario operator>>(const Binario &a, int n);           // Desplazamiento a la derecha

    // Destructor - No necesita implementación especial
    ~Binario() = default;

private:
    Lista<int> Bin;
};

// constructor
Binario::Binario(std::string cadena = "0")
{
    for (char c : cadena)
    {
        int bit = c - '0';
        assert(bit == 0 || bit == 1);           // Verificar que el bit sea válido (0 o 1)
        Lista<int>::posicion p = Bin.primera(); // bit menos significativo al principio de la lista
        Bin.insertar(bit, p);
    }
}

std::string Binario::verNumero() const
{
    std::string cadena;
    Lista<int>::posicion p = Bin.primera();

    // Como insertamos los bits con el menos significativo primero,
    // necesitamos invertir el orden al mostrarlos
    while (p != Bin.fin())
    {
        // Añadimos cada bit al principio para invertir el orden
        cadena = std::to_string(Bin.elemento(p)) + cadena;
        p = Bin.siguiente(p);
    }

    return cadena.empty() ? "0" : cadena;
}

Binario operator&(const Binario &a, const Binario &b)
{
    Binario res;
    Lista<int>::posicion p = a.Bin.primera(), q = b.Bin.primera(), r = res.Bin.primera();
    while (p != a.Bin.fin() && q != b.Bin.fin())
    {
        res.Bin.insertar(a.Bin.elemento(p) & b.Bin.elemento(q), r);
        p = a.Bin.siguiente(p);
        q = b.Bin.siguiente(q);
        r = res.Bin.siguiente(r);
    }

    return res;
}

Binario operator|(const Binario &a, const Binario &b)
{
    Binario res, a_copia(a.verNumero()), b_copia(b.verNumero());
    Lista<int>::posicion p = a_copia.Bin.primera(), q = b_copia.Bin.primera(), r = res.Bin.primera();

    while (a_copia.Bin.tama() != b_copia.Bin.tama())
    {
        if (a_copia.Bin.tama() > b_copia.Bin.tama())
        {
            b_copia.Bin.insertar(0, b_copia.Bin.fin());
        }
        else
        {
            a_copia.Bin.insertar(0, a_copia.Bin.fin());
        }
    }
    while (p != a_copia.Bin.fin() && q != b_copia.Bin.fin())
    {
        res.Bin.insertar(a_copia.Bin.elemento(p) | b_copia.Bin.elemento(q), r);
        p = a_copia.Bin.siguiente(p);
        q = b_copia.Bin.siguiente(q);
        r = res.Bin.siguiente(r);
    }

    return res;
}

Binario operator^(const Binario &a, const Binario &b)
{
        Binario res, a_copia(a.verNumero()), b_copia(b.verNumero());
    Lista<int>::posicion p = a_copia.Bin.primera(), q = b_copia.Bin.primera(), r = res.Bin.primera();

    while (a_copia.Bin.tama() != b_copia.Bin.tama())
    {
        if (a_copia.Bin.tama() > b_copia.Bin.tama())
        {
            b_copia.Bin.insertar(0, b_copia.Bin.fin());
        }
        else
        {
            a_copia.Bin.insertar(0, a_copia.Bin.fin());
        }
    }
    while (p != a_copia.Bin.fin() && q != b_copia.Bin.fin())
    {
        res.Bin.insertar(a_copia.Bin.elemento(p) ^ b_copia.Bin.elemento(q), r);
        p = a_copia.Bin.siguiente(p);
        q = b_copia.Bin.siguiente(q);
        r = res.Bin.siguiente(r);
    }

    return res;
}

Binario Binario::operator~() const
{
    Binario res;
    Lista<int>::posicion p = this->Bin.primera(), q = res.Bin.primera();
    while (p != this->Bin.fin())
    {
        if(this->Bin.elemento(p) == 0)
        {
            res.Bin.insertar(1, q);
        }
        else
        {
            res.Bin.insertar(0, q);
        }
        p = this->Bin.siguiente(p);
        q = res.Bin.siguiente(q);
    }
}

Binario operator<<(const Binario &a, int n)
{
    Binario res;
    Lista<int>::posicion p = a.Bin.primera(), q = res.Bin.primera();

    while(p != a.Bin.fin())
    {
        res.Bin.insertar(a.Bin.elemento(p), q);
        p = a.Bin.siguiente(p);
        q = res.Bin.siguiente(q);
    }

    for (int i = 0; i < n; i++)
    {
        res.Bin.insertar(0, q);
        q = res.Bin.siguiente(q);
    }

    return res;
}

Binario operator>>(const Binario &a, int n)
{
    Binario res;
    Lista<int>::posicion p = a.Bin.primera(), q = res.Bin.primera();

    while(p != a.Bin.fin())
    {
        res.Bin.insertar(a.Bin.elemento(p), q);
        p = a.Bin.siguiente(p);
        q = res.Bin.siguiente(q);
    }

    for (int i = 0; i < n; i++)
    {
        res.Bin.insertar(0, q);
        q = res.Bin.siguiente(q);
    }

    return res;
}

#endif