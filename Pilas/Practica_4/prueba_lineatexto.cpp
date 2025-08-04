#include "lineatexto.h"
#include <iostream>
#include <cstring>

void mostrar_linea(const LineaTexto& lt) {
    // Esta función es solo un placeholder, debes implementarla según tu TAD
    std::cout << "[Función mostrar_linea no implementada]" << std::endl;
}

int main() {
    char texto[] = "hola mundo";
    LineaTexto lt(texto);
    std::cout << "Estado inicial: ";
    mostrar_linea(lt);

    lt.insertar_carac('X');
    std::cout << "Tras insertar 'X': ";
    mostrar_linea(lt);

    lt.avanzar_cursor();
    std::cout << "Tras avanzar cursor: ";
    mostrar_linea(lt);

    lt.retrasar_cursor();
    std::cout << "Tras retrasar cursor: ";
    mostrar_linea(lt);

    lt.borrar_carac_pos();
    std::cout << "Tras borrar caracter a la izquierda del cursor: ";
    mostrar_linea(lt);

    lt.borrar_carac_ant();
    std::cout << "Tras borrar caracter a la derecha del cursor: ";
    mostrar_linea(lt);

    lt.sobreescribir_carac('Z');
    std::cout << "Tras sobreescribir con 'Z': ";
    mostrar_linea(lt);

    lt.final_linea();
    std::cout << "Tras mover cursor al final: ";
    mostrar_linea(lt);

    lt.principio_linea();
    std::cout << "Tras mover cursor al principio: ";
    mostrar_linea(lt);

    return 0;
}
