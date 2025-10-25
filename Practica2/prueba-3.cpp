/*Realice pruebas de caja negra sobre los algoritmos del ejercicio anterior con las técnicas
explicadas en la práctica 1. Utilice como batería de pruebas vectores de nenteros: varíe n
desde 1 hasta 9 y pruebe todas las permutaciones de cada vector.*/
#include "./Ejercicio1/ordenacion.h"
#include "cronometro.h"
#include <algorithm>
#include <fstream>

int main()
{
    const unsigned N = 20000;
    int v[N];
    cronometro c;
    std::ofstream salida("prueba-3.tmp");
    
    for (int i = 1000; i <= N; i += 1000)
    {
        for(int j = 0; j < i; j++)
        {
            v[j] = j + 1;
        }
        std::random_shuffle(v, v + i);
        c.activar();
        ordenacion_insercion(v, v + i);
        c.parar();
        
        salida << i << " " << c.tiempo() << std::endl;
    }
    
    salida.close();
    return 0;
}