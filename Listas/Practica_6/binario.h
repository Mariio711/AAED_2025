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

#include "listaenla0.h"
#include <string>
#include <assert.h>

class Binario
{
public:
    Binario(std::string cadena);
    std::string verNumero() const;

    //operaciones lógicas
    
    friend Binario operator&(const Binario &a, const Binario &b); //AND
    friend Binario operator|(const Binario &a, const Binario &b); //OR
    friend Binario operator^(const Binario &a, const Binario &b); //XOR
    Binario operator~() const; //NOT
    friend Binario operator<<(const Binario &a, int n); //Desplazamiento a la izquierda
    friend Binario operator>>(const Binario &a, int n); //Desplazamiento a la derecha
    
    // Destructor - No necesita implementación especial
    ~Binario() = default;



private:
    Lista<int> Bin;
};

//constructor
Binario::Binario(std::string cadena)
{
    for(char c : cadena)
    {
        int bit = c - '0';
        assert(bit == 0 || bit == 1); // Verificar que el bit sea válido (0 o 1)
        Lista<int>::posicion p = Bin.primera(); //bit menos significativo al principio de la lista
        Bin.insertar(bit, p);
    }
}


#endif