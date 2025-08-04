/*Escriba una función que dada una cola y dos elementos a y b, invierta la secuencia delimitada por ambos dentro de ella.
Dado que la cola puede tener elementos repetidos, se invertirá la secuencia delimitada por
la primera ocurrencia de a y b.
*/
#include <iostream>
#include "colaenla.h"
#include "pilaenla.h"

void invertir_sec(Cola<int> &C, int a, int b)
{
    Cola<int> aux1;
    Pila<int> aux2;
    while (C.frente() != a)
    {
        aux1.push(C.frente());
        C.pop();
    }

    while (C.frente() != b)
    {
        aux2.push(C.frente());
        C.pop();
    }

    aux2.push(C.frente());
    C.pop();

    while (!aux2.vacia())
    {
        aux1.push(aux2.tope());
        aux2.pop();
    }

    while (!C.vacia())
    {
        aux1.push(C.frente());
        C.pop();
    }

    while (!aux1.vacia())
    {
        C.push(aux1.frente());
        aux1.pop();
    }
}


void imprimir_cola(Cola<int> C) {
    std::cout << "[";
    bool primero = true;
    while (!C.vacia()) {
        if (!primero) std::cout << ", ";
        std::cout << C.frente();
        C.pop();
        primero = false;
    }
    std::cout << "]" << std::endl;
}

int main() {
    Cola<int> C;
    // Cola: 1 2 3 4 5 6 7 8 9 10
    for (int i = 1; i <= 10; ++i)
        C.push(i);

    std::cout << "Cola original: ";
    imprimir_cola(C);

    // Invertimos la secuencia entre 3 y 8
    invertir_sec(C, 3, 8);

    std::cout << "Cola tras invertir entre 3 y 8: ";
    imprimir_cola(C);

    system ("pause");
    return 0;
}