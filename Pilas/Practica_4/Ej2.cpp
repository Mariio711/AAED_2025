/*Escriba una función que determine y devuelva si una secuencia de caracteres de entrada
es de la forma A#B#C#D . . ., donde A, B, C, D,. . . son de la forma X&Y , que a su vez
están separados por el caráter ‘#’.*/
#include "pilaenla.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
bool formato(char *cadena);
bool inversa(char *cadena);

int main() {
    // Todos los bloques son de la forma X&Y, Y es la inversa de X -> Esperado: SI
    char caso1[] = "ab&ba#xy&yx#123&321";
    // El último bloque no es inversa (312 != 213) -> Esperado: NO
    char caso2[] = "ab&ba#xy&yx#123&312";
    // Los bloques no cumplen la forma X&Y (a&b, b&a) -> Esperado: NO
    char caso3[] = "a&b#b&a";
    // Segundo bloque vacío antes de & -> Esperado: NO
    char caso4[] = "ab&ba#&";
    // Último bloque vacío después de # -> Esperado: NO
    char caso5[] = "ab&ba#xy&yx#";
    // Solo un bloque correcto -> Esperado: SI
    char caso6[] = "ab&ba";
    // Primer bloque vacío antes de # -> Esperado: NO
    char caso7[] = "#ab&ba#xy&yx";

    std::cout << '"' << caso1 << '"' << " -> " << (formato(caso1) ? "SI" : "NO") << std::endl; // SI
    std::cout << '"' << caso2 << '"' << " -> " << (formato(caso2) ? "SI" : "NO") << std::endl; // NO
    std::cout << '"' << caso3 << '"' << " -> " << (formato(caso3) ? "SI" : "NO") << std::endl; // NO
    std::cout << '"' << caso4 << '"' << " -> " << (formato(caso4) ? "SI" : "NO") << std::endl; // NO
    std::cout << '"' << caso5 << '"' << " -> " << (formato(caso5) ? "SI" : "NO") << std::endl; // NO
    std::cout << '"' << caso6 << '"' << " -> " << (formato(caso6) ? "SI" : "NO") << std::endl; // SI
    std::cout << '"' << caso7 << '"' << " -> " << (formato(caso7) ? "SI" : "NO") << std::endl; // NO
    system("pause");
    return 0;
}


bool formato(char *cadena)
{
    int i = 0;
    while (cadena[i] != '\0') {
        // Buscar el inicio del bloque
        int inicio = i;
        // Avanzar hasta el siguiente '#' o fin de cadena
        while (cadena[i] != '\0' && cadena[i] != '#') {
            i++;
        }
        int len = i - inicio;
        if (len == 0) // Bloque vacío, no válido
            return false;
        // Copiar el bloque a un array temporal
        char* cad = new char[len + 1];
        for (int j = 0; j < len; j++) {
            cad[j] = cadena[inicio + j];
        }
        cad[len] = '\0';
        // Comprobar si el bloque es de la forma X&Y y X e Y no vacíos
        if (!inversa(cad)) {
            delete[] cad;
            return false;
        }
        // Extra: no aceptar bloques de la forma "&" (X o Y vacíos)
        char* amp = strchr(cad, '&');
        if (!amp || amp == cad || *(amp + 1) == '\0') {
            delete[] cad;
            return false;
        }
        delete[] cad;
        // Si hay un '#', saltarlo
        if (cadena[i] == '#')
            i++;
    }
    return true;
}

bool inversa(char *cadena)
{
    Pila<char> A;
    int i = 0;
    // Buscar el '&' y llenar la pila con X
    while (cadena[i] != '\0' && cadena[i] != '&') {
        A.push(cadena[i]);
        i++;
    }
    // Si no hay '&', no es válido
    if (cadena[i] != '&')
        return false;
    // No aceptar X vacío ni Y vacío
    if (i == 0 || cadena[i + 1] == '\0')
        return false;
    i++; // Saltar el '&'
    // Comparar Y con la inversa de X
    while (cadena[i] != '\0' && !A.vacia()) {
        if (cadena[i] != A.tope())
            return false;
        A.pop();
        i++;
    }
    // Si la pila no está vacía o quedan caracteres en Y, no es válido
    if (!A.vacia() || cadena[i] != '\0')
        return false;
    return true;
}