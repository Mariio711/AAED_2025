/*Dadas dos listas de enteros en orden creciente, implemente una función que devuelva una
tercera lista ordenada con la mezcla de las otras dos.*/

#include "listavec.h"

Lista<int> concat(const Lista<int> &lista1, const Lista<int> &lista2)
{
    Lista<int> listaconcat(lista1.tama() + lista2.tama());
    size_t i = 0, j = 0, k = 0;
    while (i < lista1.tama() && j < lista2.tama())
    {
        if (lista1.elemento(i) < lista2.elemento(j))
        {
            listaconcat.insertar(lista1.elemento(i), k);
            k++;
            i++;
        }
        else
        {
            listaconcat.insertar(lista2.elemento(j), k);
            k++;
            j++;
        }
    }
    // Agregar elementos restantes de lista1
    while (i < lista1.tama())
    {
        listaconcat.insertar(lista1.elemento(i), k);
        k++;
        i++;
    }

    // Agregar elementos restantes de lista2
    while (j < lista2.tama())
    {
        listaconcat.insertar(lista2.elemento(j), k);
        k++;
        j++;
    }

    return listaconcat;
}