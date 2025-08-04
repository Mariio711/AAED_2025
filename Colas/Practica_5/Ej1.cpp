/*Se dice que una pila es isomórfica a una cola cuando los elementos situados en posiciones
pares de la pila coinciden con los situados en posiciones impares de la cola.

Usando los TAD Pila y Cola, implemente una función que determine y devuelva si una
pila y una cola dadas son isomórficas o no.*/

#include <iostream>
#include "pilaenla.h"
#include "colaenla.h"


//entendemos que la primera posicion es 1 y no 0
template <typename T>
bool isomorfica(Cola<T> C, Pila<T> P)
{
    int contP = 1, contC = 1;
    while (!P.vacia() && !C.vacia())
    {
        P.pop();
        ++contP;
        if ((P.tope() != C.frente()) && contC % 2 == 1 && contP % 2 == 0)
        {
            return false;
        }
        if (!P.vacia())
        {
            P.pop();
            ++contP;
        }
        C.pop();
        ++contC;
        if(!C.vacia())
        {
            C.pop();
            ++contC;
        }

    }
    return true;
}

int main() {
    Pila<int> P;
    Cola<int> C;

    // Ejemplo: Pila [4, 4, 2, 7] (tope=4), Cola [9, 4, 8, 2, 7] (frente=9)
    // Posiciones pares de P: 0->4, 2->2
    // Posiciones impares de C: 1->4, 3->2
    // Coinciden 4 con 4 y 2 con 2

    P.push(7);
    P.push(2);
    P.push(5);
    P.push(6);
    P.push(4);
    P.push(4);

    C.push(4);
    C.push(4);
    C.push(5);
    C.push(2);
    C.push(7);

    if (isomorfica(C, P))
        std::cout << "La pila y la cola son isomorficas." << std::endl;
    else
        std::cout << "La pila y la cola NO son isomorficas." << std::endl;

    system("pause");
    return 0;

}