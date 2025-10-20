/*Implemente una función que concatene una lista de listas (TAD Lista cuyo 
tipo de elementos es a su vez una lista de elementos de cierto tipo T), de forma que a partir de la
lista de listas se obtenga una nueva lista de todos los elementos de tipo T.
*/

#include "listaenla.h"
#include <iostream>

template <typename T>
Lista<T> concat_listas(const Lista<Lista<T>> &lista_de_listas)
{
    Lista<T> lista_concat;
    typename Lista<T>::posicion p_concat = lista_concat.fin();
    typename Lista<Lista<T>>::posicion p = lista_de_listas.primera();

    while (p != lista_de_listas.fin())
    {
        Lista<T> aux = lista_de_listas.elemento(p);
        typename Lista<T>::posicion p_aux = aux.primera();
        while (p_aux != aux.fin())
        {
            lista_concat.insertar(aux.elemento(p_aux), p_concat);
            p_concat = lista_concat.fin();
            p_aux = aux.siguiente(p_aux);
        }
        p = lista_de_listas.siguiente(p);
    }
    
    return lista_concat;
}

// Función auxiliar para imprimir una lista
template<typename T>
void imprimir_lista(const Lista<T>& lista, const std::string& nombre) {
    std::cout << nombre << ": [";
    bool primero = true;
    for (typename Lista<T>::posicion p = lista.primera(); p != lista.fin(); p = lista.siguiente(p)) {
        if (!primero) std::cout << ", ";
        std::cout << lista.elemento(p);
        primero = false;
    }
    std::cout << "]" << std::endl;
}

// Función auxiliar para crear una lista con elementos
template<typename T>
Lista<T> crear_lista(std::initializer_list<T> elementos) {
    Lista<T> lista;
    for (const T& elem : elementos) {
        typename Lista<T>::posicion pos = lista.fin();
        lista.insertar(elem, pos);
    }
    return lista;
}

int main() {
    std::cout << "=== CASOS DE PRUEBA PARA CONCAT_LISTAS ===" << std::endl;
    
    // CASO 1: Concatenar varias listas con elementos
    std::cout << "\n--- CASO 1: Listas normales ---" << std::endl;
    Lista<Lista<int>> lista_de_listas1;
    
    // Crear sublistas
    Lista<int> sublista1 = crear_lista<int>({1, 2, 3});
    Lista<int> sublista2 = crear_lista<int>({4, 5});
    Lista<int> sublista3 = crear_lista<int>({6, 7, 8, 9});
    
    // Agregar sublistas a la lista principal
    typename Lista<Lista<int>>::posicion pos = lista_de_listas1.fin();
    lista_de_listas1.insertar(sublista1, pos);
    pos = lista_de_listas1.fin();
    lista_de_listas1.insertar(sublista2, pos);
    pos = lista_de_listas1.fin();
    lista_de_listas1.insertar(sublista3, pos);
    
    // Mostrar sublistas
    std::cout << "Sublista 1: ";
    imprimir_lista(sublista1, "");
    std::cout << "Sublista 2: ";
    imprimir_lista(sublista2, "");
    std::cout << "Sublista 3: ";
    imprimir_lista(sublista3, "");
    
    // Concatenar
    Lista<int> resultado1 = concat_listas(lista_de_listas1);
    imprimir_lista(resultado1, "Resultado");
    std::cout << "Esperado: [1, 2, 3, 4, 5, 6, 7, 8, 9]" << std::endl;
    
    // CASO 2: Lista con una sublista vacía
    std::cout << "\n--- CASO 2: Con lista vacía en el medio ---" << std::endl;
    Lista<Lista<int>> lista_de_listas2;
    
    Lista<int> sub1 = crear_lista<int>({10, 20});
    Lista<int> sub2; // Lista vacía
    Lista<int> sub3 = crear_lista<int>({30, 40});
    
    pos = lista_de_listas2.fin();
    lista_de_listas2.insertar(sub1, pos);
    pos = lista_de_listas2.fin();
    lista_de_listas2.insertar(sub2, pos);
    pos = lista_de_listas2.fin();
    lista_de_listas2.insertar(sub3, pos);
    
    Lista<int> resultado2 = concat_listas(lista_de_listas2);
    imprimir_lista(resultado2, "Resultado");
    std::cout << "Esperado: [10, 20, 30, 40]" << std::endl;
    
    // CASO 3: Lista vacía de listas
    std::cout << "\n--- CASO 3: Lista vacía de listas ---" << std::endl;
    Lista<Lista<int>> lista_vacia;
    Lista<int> resultado3 = concat_listas(lista_vacia);
    imprimir_lista(resultado3, "Resultado");
    std::cout << "Esperado: []" << std::endl;
    
    // CASO 4: Una sola sublista
    std::cout << "\n--- CASO 4: Una sola sublista ---" << std::endl;
    Lista<Lista<int>> lista_de_listas4;
    Lista<int> unica = crear_lista<int>({100, 200, 300});
    
    pos = lista_de_listas4.fin();
    lista_de_listas4.insertar(unica, pos);
    
    Lista<int> resultado4 = concat_listas(lista_de_listas4);
    imprimir_lista(resultado4, "Resultado");
    std::cout << "Esperado: [100, 200, 300]" << std::endl;
    
    // CASO 5: Test con strings
    std::cout << "\n--- CASO 5: Test con strings ---" << std::endl;
    Lista<Lista<std::string>> lista_strings;
    
    Lista<std::string> palabras1 = crear_lista<std::string>({"Hola", "Mundo"});
    Lista<std::string> palabras2 = crear_lista<std::string>({"Esto", "Es", "Una", "Prueba"});
    
    typename Lista<Lista<std::string>>::posicion pos_str = lista_strings.fin();
    lista_strings.insertar(palabras1, pos_str);
    pos_str = lista_strings.fin();
    lista_strings.insertar(palabras2, pos_str);
    
    Lista<std::string> resultado_str = concat_listas(lista_strings);
    imprimir_lista(resultado_str, "Resultado strings");
    std::cout << "Esperado: [Hola, Mundo, Esto, Es, Una, Prueba]" << std::endl;
    
    system("pause");
    return 0;
}
