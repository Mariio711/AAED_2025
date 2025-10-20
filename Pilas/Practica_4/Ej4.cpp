
/*Implemente una función que dado un fichero de texto, que almacena dos enteros de longitud
arbitraria en las dos primeras líneas del fichero, lo modifique añadiendo una tercera línea
que contenga la suma de ambos números.*/

#include "pilaenla.h"
#include <fstream>
#include <string>
#include <iostream>

void suma_pilas(Pila<int> P, Pila<int> Q, Pila<int> &R)
{
    int acarreo = 0;
    while (!P.vacia() || !Q.vacia() || acarreo)
    {
        int suma = acarreo;
        if (!P.vacia())
        {
            suma += P.tope();
            P.pop();
        }
        if (!Q.vacia())
        {
            suma += Q.tope();
            Q.pop();
        }
        R.push(suma % 10);
        acarreo = suma / 10;
    }
}

void suma_pila_ficheros(Pila<int> &P, Pila<int> &Q, Pila<int> &R)
{
    std::string nombre_f;
    std::cout << "Introduce el nombre del fichero: ";
    std::cin >> nombre_f;

    std::fstream f(nombre_f, std::ios::in | std::ios::out);
    if (!f.is_open()) {
        std::cerr << "No se pudo abrir el fichero." << std::endl;
        return;
    }
    f >> P >> Q; // Extraer de f los números (pilas) P y Q
    suma_pilas(P, Q, R);
    f.clear();
    f.seekp(0, std::ios::end); // Ir al final para añadir la suma
    f << std::endl; // Nueva línea antes de la suma
    f << R;    // Insertar en f el número (pila) R
    f.close(); // Cerrar el fichero asociado a f
}


int main() {
    Pila<int> P, Q, R;
    suma_pila_ficheros(P, Q, R);
    return 0;
}