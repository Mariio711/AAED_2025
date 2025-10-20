/*Implemente una función que reciba una lista y un elemento x, de forma que la modifique
eliminando de ella todas las ocurrencias de x.*/

#include "listavec.h"

template<typename T>
void elimina_x(Lista<T> &lista, const T &x)
{
    for(size_t i = 0; i < lista.tama(); )
    {
        if (lista.elemento(i) == x)
        {
            lista.eliminar(i);
        }
        else
        {
            i++;
        }
    }
    
} 