/*Suponiendo una lista simplemente enlazada de enteros, 
implemente una función para invertir el orden de los elementos 
a partir de una posición p incluida.
*/

#include "listaenla0.h"

void invertir (Lista<int> &lista, Lista<int>::posicion p){
    int cont = 0;
    Lista<int>::posicion actual = p;

    while(actual != lista.fin())
    {
        cont++;
        actual = lista.siguiente(actual);
    }

    for(int i = 0; i <= cont; i ++)
    {
        lista.insertar(lista.elemento(lista.fin()), p);
    }
}
//esta mal hay que seguir