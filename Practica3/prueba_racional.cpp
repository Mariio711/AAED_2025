#include "racional.hpp"
#include <iostream>

using namespace std;

int main()
{
    cout << "=== Prueba del TAD racional ampliado ===" << endl;
    
    // Crear algunos números racionales
    racional r1(3, 4);  // 3/4
    racional r2(2, 3);  // 2/3
    racional r3(1, 2);  // 1/2
    
    cout << "r1 = " << r1.num() << "/" << r1.den() << endl;
    cout << "r2 = " << r2.num() << "/" << r2.den() << endl;
    cout << "r3 = " << r3.num() << "/" << r3.den() << endl;
    
    // Probar operadores aritméticos básicos
    cout << "\n=== Operadores aritméticos básicos ===" << endl;
    racional suma = r1 + r2;
    racional resta = r1 - r2;
    racional producto = r1 * r2;
    racional division = r1 / r2;
    
    cout << "r1 + r2 = " << suma.num() << "/" << suma.den() << endl;
    cout << "r1 - r2 = " << resta.num() << "/" << resta.den() << endl;
    cout << "r1 * r2 = " << producto.num() << "/" << producto.den() << endl;
    cout << "r1 / r2 = " << division.num() << "/" << division.den() << endl;
    
    // Probar operadores unarios
    cout << "\n=== Operadores unarios ===" << endl;
    racional pos = +r1;
    racional neg = -r1;
    cout << "+r1 = " << pos.num() << "/" << pos.den() << endl;
    cout << "-r1 = " << neg.num() << "/" << neg.den() << endl;
    
    // Probar operadores de asignación compuesta
    cout << "\n=== Operadores de asignación compuesta ===" << endl;
    racional temp = r1;
    cout << "temp inicial = " << temp.num() << "/" << temp.den() << endl;
    
    temp += r2;
    cout << "temp += r2 = " << temp.num() << "/" << temp.den() << endl;
    
    temp -= r3;
    cout << "temp -= r3 = " << temp.num() << "/" << temp.den() << endl;
    
    temp *= r2;
    cout << "temp *= r2 = " << temp.num() << "/" << temp.den() << endl;
    
    temp /= r3;
    cout << "temp /= r3 = " << temp.num() << "/" << temp.den() << endl;
    
    // Probar operadores de comparación
    cout << "\n=== Operadores de comparación ===" << endl;
    cout << "r1 == r2: " << (r1 == r2) << endl;
    cout << "r1 != r2: " << (r1 != r2) << endl;
    cout << "r1 < r2: " << (r1 < r2) << endl;
    cout << "r1 <= r2: " << (r1 <= r2) << endl;
    cout << "r1 > r2: " << (r1 > r2) << endl;
    cout << "r1 >= r2: " << (r1 >= r2) << endl;
    
    cout << "\n=== Pruebas completadas ===" << endl;
    
    return 0;
}
