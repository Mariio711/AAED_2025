/*Implemente una función que dado un fichero de texto, que almacena dos enteros de longitud
arbitraria en las dos primeras líneas del fichero, lo modifique añadiendo una tercera línea
que contenga la suma de ambos números.*/

#include "pilaenla.h"
#include <fstream>
#include <string>

void suma_pilas(Pila<int> P, Pila<int> Q, Pila<int> &R)
{
    int aux = 0;
    while (!P.vacia() || !Q.vacia())
    {
        if(!P.vacia())
        {
            aux += P.tope();
            P.pop();
        }

        if(!Q.vacia())
        {
            aux += Q.tope();
            Q.pop();
        }

        //FALTA RERSULTADO
    }
}

Pila<int> suma_pila_ficheros(Pila<int> P, Pila<int> Q, Pila<int> &R)
{
    std::string nombre_f;
    std::fstream f(nombre_f);   // Abrir el fichero en modo lectura/escritura y
                                // asociarlo al flujo f .

    Pila<int> P, Q, R;

    f >> P >> Q; // Extraer de f los números (pilas) P y Q
    // Calcular el resultado en la pila R
    // ...
    f << R;    // Insertar en f el número (pila) R
    f.close(); // Cerrar el fichero asociado a f
}