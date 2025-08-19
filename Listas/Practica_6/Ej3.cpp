/*Suponiendo una lista simplemente enlazada de enteros,
implemente una función para invertir el orden de los elementos
a partir de una posición p incluida.
*/

#include "listaenla0.h"
#include <iostream>

void invertir(Lista<int> &lista, Lista<int>::posicion p)
{
    // 1. Contar elementos (esto está bien)
    int cont = 0;
    Lista<int>::posicion actual = p;
    while (actual != lista.fin()) {
        cont++;
        actual = lista.siguiente(actual);
    }
    
    // 2. Casos especiales
    if (cont <= 1) return;
    
    // 3. Para cada elemento excepto el primero
    for (int i = 1; i < cont; i++) {  // ✅ < cont, no <= cont
        // 4. Encontrar el último elemento de la sublista
        Lista<int>::posicion ultimo = p;  // ✅ Inicializar con p
        while (lista.siguiente(ultimo) != lista.fin()) {
            ultimo = lista.siguiente(ultimo);
        }
        
        // 5. Extraer valor y eliminar
        int valor = lista.elemento(ultimo);
        lista.eliminar(ultimo);
        
        // 6. Insertar desde p
        lista.insertar(valor, p);
        
        // 7. Avanzar p
        p = lista.siguiente(p);
    }
}

// Función auxiliar para imprimir la lista
void imprimir_lista(const Lista<int>& lista) {
    std::cout << "[";
    for (Lista<int>::posicion p = lista.primera(); p != lista.fin(); p = lista.siguiente(p)) {
        std::cout << lista.elemento(p);
        if (lista.siguiente(p) != lista.fin()) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

// Función auxiliar para encontrar posición de un elemento por índice
Lista<int>::posicion obtener_posicion(const Lista<int>& lista, int indice) {
    Lista<int>::posicion p = lista.primera();
    for (int i = 0; i < indice && p != lista.fin(); i++) {
        p = lista.siguiente(p);
    }
    return p;
}

int main() {
    std::cout << "=== CASOS DE PRUEBA PARA FUNCIÓN INVERTIR ===" << std::endl;
    
    // CASO 1: Invertir desde el medio
    std::cout << "\n--- CASO 1: Invertir desde posición 2 ---" << std::endl;
    Lista<int> lista1;
    Lista<int>::posicion pos;
    
    // Crear lista [1, 2, 3, 4, 5]
    pos = lista1.fin();
    lista1.insertar(1, pos);
    pos = lista1.fin();
    lista1.insertar(2, pos);
    pos = lista1.fin();
    lista1.insertar(3, pos);
    pos = lista1.fin();
    lista1.insertar(4, pos);
    pos = lista1.fin();
    lista1.insertar(5, pos);
    
    std::cout << "Lista original: ";
    imprimir_lista(lista1);
    
    // Invertir desde posición 2 (elemento 3)
    Lista<int>::posicion p_invertir = obtener_posicion(lista1, 2);
    invertir(lista1, p_invertir);
    
    std::cout << "Después de invertir desde posición 2: ";
    imprimir_lista(lista1);
    std::cout << "Resultado esperado: [1, 2, 5, 4, 3]" << std::endl;
    
    // CASO 2: Invertir desde el inicio
    std::cout << "\n--- CASO 2: Invertir desde el inicio ---" << std::endl;
    Lista<int> lista2;
    
    // Crear lista [10, 20, 30, 40]
    pos = lista2.fin();
    lista2.insertar(10, pos);
    pos = lista2.fin();
    lista2.insertar(20, pos);
    pos = lista2.fin();
    lista2.insertar(30, pos);
    pos = lista2.fin();
    lista2.insertar(40, pos);
    
    std::cout << "Lista original: ";
    imprimir_lista(lista2);
    
    // Invertir desde el inicio
    invertir(lista2, lista2.primera());
    
    std::cout << "Después de invertir desde el inicio: ";
    imprimir_lista(lista2);
    std::cout << "Resultado esperado: [40, 30, 20, 10]" << std::endl;
    
    // CASO 3: Invertir último elemento (no debería cambiar)
    std::cout << "\n--- CASO 3: Invertir desde el último elemento ---" << std::endl;
    Lista<int> lista3;
    
    // Crear lista [1, 2, 3]
    pos = lista3.fin();
    lista3.insertar(1, pos);
    pos = lista3.fin();
    lista3.insertar(2, pos);
    pos = lista3.fin();
    lista3.insertar(3, pos);
    
    std::cout << "Lista original: ";
    imprimir_lista(lista3);
    
    // Invertir desde el último elemento
    Lista<int>::posicion ultimo = obtener_posicion(lista3, 2);
    invertir(lista3, ultimo);
    
    std::cout << "Después de invertir desde el último elemento: ";
    imprimir_lista(lista3);
    std::cout << "Resultado esperado: [1, 2, 3] (sin cambios)" << std::endl;
    
    // CASO 4: Lista de dos elementos
    std::cout << "\n--- CASO 4: Lista pequeña [7, 8] desde inicio ---" << std::endl;
    Lista<int> lista4;
    
    pos = lista4.fin();
    lista4.insertar(7, pos);
    pos = lista4.fin();
    lista4.insertar(8, pos);
    
    std::cout << "Lista original: ";
    imprimir_lista(lista4);
    
    invertir(lista4, lista4.primera());
    
    std::cout << "Después de invertir: ";
    imprimir_lista(lista4);
    std::cout << "Resultado esperado: [8, 7]" << std::endl;
    
    system ("pause");
    return 0;
}