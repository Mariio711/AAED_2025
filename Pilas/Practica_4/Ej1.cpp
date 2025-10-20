/*. Escriba una función que determine y devuelva si una secuencia de caracteres de entrada
es de la forma X&Y , donde X es una cadena de caracteres e Y es la cadena inversa,
separadas por el carácter ‘&’.*/

#include "pilaenla.h"
#include <cstdio>
#include <cstdlib>


bool inversa(char *cadena);

int main()
{
    char prueba1[] = "abc&cba";
    char prueba2[] = "hola&aloh";
    char prueba3[] = "test&tsetextra";
    char prueba4[] = "aa&aa";
    char prueba5[] = "abc&abc";
    char prueba6[] = "abc&cbaextra";
    char prueba7[] = "abcabc";
    char prueba8[] = "&";

    printf("\"%s\" -> %s\n", prueba1, inversa(prueba1) ? "SI" : "NO");
    printf("\"%s\" -> %s\n", prueba2, inversa(prueba2) ? "SI" : "NO");
    printf("\"%s\" -> %s\n", prueba3, inversa(prueba3) ? "SI" : "NO");
    printf("\"%s\" -> %s\n", prueba4, inversa(prueba4) ? "SI" : "NO");
    printf("\"%s\" -> %s\n", prueba5, inversa(prueba5) ? "SI" : "NO");
    printf("\"%s\" -> %s\n", prueba6, inversa(prueba6) ? "SI" : "NO");
    printf("\"%s\" -> %s\n", prueba7, inversa(prueba7) ? "SI" : "NO");
    printf("\"%s\" -> %s\n", prueba8, inversa(prueba8) ? "SI" : "NO");

    system("pause");
    return 0;
}

bool inversa(char *cadena)
{
    Pila<char> A;
    int i = 0;

    // Buscar el '&' y llenar la pila con X
    while (cadena[i] != '\0' && cadena[i] != '&')
    {
        A.push(cadena[i]);
        i++;
    }

    // Si no hay '&', no es válido
    if (cadena[i] != '&')
        return false;

    i++; // Saltar el '&'

    // Comparar Y con la inversa de X
    while (cadena[i] != '\0' && !A.vacia())
    {
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