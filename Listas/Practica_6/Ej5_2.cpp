/* Ej5: Programa de prueba reescrito para el Modelo B (posición = nodo previo).
   Se validan: inserciones, duplicados, copia, asignación, eliminación, concat, invariantes. */

#include "Listaordenada.h"
#include <iostream>
#include <initializer_list>
#include <string>

// Recorre usando posición previa (cabecera incluida). Para cada p, elemento(p) es p->sig->elto.
void imprimir(const Lista<int>& L, const std::string& nombre) {
    std::cout << nombre << ": [";
    bool primero = true;
    for (auto p = L.primera(); L.siguiente(p) != L.fin(); p = L.siguiente(p)) {
        if (!primero) std::cout << ", ";
        std::cout << L.elemento(p);
        primero = false;
    }
    std::cout << "]\n";
}

Lista<int> construir(std::initializer_list<int> vals) {
    Lista<int> L;
    for (int v : vals) L.insertar(v);
    return L;
}

// Concatena copiando elementos (cada inserción mantiene orden)
Lista<int> concat(const Lista<int>& A, const Lista<int>& B) {
    Lista<int> R;
    for (auto p = A.primera(); A.siguiente(p) != A.fin(); p = A.siguiente(p)) R.insertar(A.elemento(p));
    for (auto p = B.primera(); B.siguiente(p) != B.fin(); p = B.siguiente(p)) R.insertar(B.elemento(p));
    return R;
}

// Verificación de invariantes básicos
bool verificar_invariantes(const Lista<int>& L, const std::string& ctx) {
    // Contar nodos y comprobar orden ascendente
    size_t cuenta = 0;
    bool orden = true;
    bool primero = true;
    int prev = 0;
    for (auto p = L.primera(); L.siguiente(p) != L.fin(); p = L.siguiente(p)) {
        int x = L.elemento(p);
        if (primero) { prev = x; primero = false; }
        else if (x < prev) { orden = false; break; }
        else prev = x;
        ++cuenta;
    }
    bool tamaOk = (cuenta == L.tama());
    if (!tamaOk || !orden) {
        std::cout << "[FALLO] Invariantes en " << ctx << ": tamaOk=" << tamaOk << ", orden=" << orden << '\n';
        return false;
    }
    return true;
}

// Elimina el k-ésimo (0-based) elemento de datos usando posiciones previas
void eliminar_k(Lista<int>& L, size_t k) {
    auto prev = L.primera(); // cabecera previa al primero (k=0)
    for (size_t i = 0; i < k; ++i) {
        // Avanzar prev hasta que sea la posición previa al k-ésimo
        if (L.siguiente(prev) == L.fin()) return; // fuera de rango
        prev = L.siguiente(prev);
    }
    if (L.siguiente(prev) != L.fin()) L.eliminar(prev);
}

int main() {
    int fallos = 0;
    std::cout << "=== PRUEBAS LISTA ORDENADA (Modelo B) ===\n";

    // 1. Inserciones desordenadas -> orden
    auto L1 = construir({5,1,8,3,2});
    imprimir(L1, "L1 (ordenada)");
    if (!verificar_invariantes(L1, "L1")) ++fallos;

    // 2. Duplicados
    auto L2 = construir({5,5,5,2,2,9});
    imprimir(L2, "L2 (duplicados)");
    if (!verificar_invariantes(L2, "L2")) ++fallos;

    // 3. Concat
    auto C = concat(L1, L2);
    imprimir(C, "Concat(L1,L2)");
    if (!verificar_invariantes(C, "Concat")) ++fallos;

    // 4. Constructor copia
    Lista<int> Copia = C; // usa ctor copia
    imprimir(Copia, "Copia");
    if (!verificar_invariantes(Copia, "Copia")) ++fallos;

    // 5. Asignación
    Lista<int> Asig;
    Asig = L1;
    imprimir(Asig, "Asig=L1");
    if (!verificar_invariantes(Asig, "Asig")) ++fallos;

    // 6. Eliminar posiciones (primero, medio, último)
    auto L3 = construir({1,2,3,4,5});
    eliminar_k(L3, 0);   // borra 1
    eliminar_k(L3, 2);   // después de borrar: lista = [2,3,4,5], k=2 -> borra 4
    eliminar_k(L3, 10);  // fuera de rango (ignora)
    imprimir(L3, "L3 tras eliminaciones");
    if (!verificar_invariantes(L3, "L3")) ++fallos;

    // 7. insertar_unico / contiene
    Lista<int> L4;
    L4.insertar(4); L4.insertar(1); L4.insertar(3);
    bool insA = L4.insertar_unico(3); // ya existe
    bool insB = L4.insertar_unico(2); // nuevo
    imprimir(L4, "L4 tras insertar_unico");
    std::cout << "insertar_unico(3) -> " << (insA?"true":"false") << ", insertar_unico(2) -> " << (insB?"true":"false") << '\n';
    if (!verificar_invariantes(L4, "L4")) ++fallos;

    // 8. Búsqueda
    auto posPrev3 = L4.buscar(3);
    bool found3 = (posPrev3 != L4.fin());
    auto posPrev9 = L4.buscar(9);
    bool found9 = (posPrev9 != L4.fin());
    std::cout << "buscar(3) -> " << (found3?"ENCONTRADO":"NO") << ", buscar(9) -> " << (found9?"ENCONTRADO":"NO") << '\n';

    // Resultado final
    std::cout << '\n' << (fallos==0?"TODAS LAS PRUEBAS OK":"FALLOS: "+std::to_string(fallos)) << '\n';
    
    system("pause");
    return fallos==0 ? 0 : 1;
}