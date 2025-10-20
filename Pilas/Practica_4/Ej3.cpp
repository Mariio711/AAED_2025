/*Escriba una función que dados dos elementos a y b y una pila, invierta la secuencia delimitada por ambos dentro de ella.
Dado que la pila puede tener elementos repetidos, se invertirá la secuencia delimitada por
la primera ocurrencia de a y de b.*/

#include "pilaenla.h"
#include <iostream>

void imprimir_pila(Pila<int> P) {
    std::cout << "[";
    bool primero = true;
    while (!P.vacia()) {
        if (!primero) std::cout << ", ";
        std::cout << P.tope();
        P.pop();
        primero = false;
    }
    std::cout << "]" << std::endl;
}


void invertir_sec(Pila<int> &P, int a, int b)
{
    Pila<int> aux1, aux2;
    
    //pasar a aux los elementos hasta a
    while (P.tope() != a)
    {
        aux1.push(P.tope());
        P.pop();
    }
    
    while (P.tope() != b)
    {
        aux2.push(P.tope());
        P.pop();
    }
    aux2.push(P.tope());
    P.pop();
    
    while(!aux2.vacia())
    {
        aux1.push(aux2.tope());
        aux2.pop();
    }
    
    while (!aux1.vacia())
    {
        P.push(aux1.tope());
        aux1.pop();
    }
    
}

int main() {
    Pila<int> P;
    // Insertar elementos: 1,2,3,4,5,6 (6 en el tope)
    for (int i = 1; i <= 6; ++i) P.push(i);
    std::cout << "Pila original: ";
    imprimir_pila(P);

    invertir_sec(P, 4, 2); // Invierte desde el primer 4 hasta el primer 2
    std::cout << "Pila tras invertir entre 4 y 2: ";
    imprimir_pila(P);
    system("pause");
    return 0;
}