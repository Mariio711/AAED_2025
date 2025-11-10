#include "poli_user.h"
#include "AritPol.h"
#include <iostream>

using namespace std;

void mostrar(const polinomio& p) {
    cout << "Polinomio (grado " << p.grado() << "): ";
    bool primero = true;
    for (unsigned i = 0; i <= p.grado(); ++i) {
        double coef = p.coeficiente(i);
        if (coef != 0.0) {
            if (!primero && coef > 0) cout << " + ";
            if (coef < 0) cout << " - ";
            
            double absCoef = (coef < 0) ? -coef : coef;
            
            if (i == 0) {
                cout << absCoef;
            } else {
                if (absCoef != 1.0) cout << absCoef;
                cout << "x";
                if (i > 1) cout << "^" << i;
            }
            primero = false;
        }
    }
    if (primero) cout << "0";
    cout << endl;
}

int main() {
    cout << "=== PRUEBAS DEL MÓDULO ARITPOL ===" << endl;
    
    // CASO 1: Suma de polinomios
    cout << "\n--- CASO 1: Suma de polinomios ---" << endl;
    polinomio p1(2);  // 3x^2 + 2x + 1
    p1.coeficiente(0, 1);
    p1.coeficiente(1, 2);
    p1.coeficiente(2, 3);
    
    polinomio p2(2);  // 2x^2 + 4x + 3
    p2.coeficiente(0, 3);
    p2.coeficiente(1, 4);
    p2.coeficiente(2, 2);
    
    cout << "p1 = ";
    mostrar(p1);
    cout << "p2 = ";
    mostrar(p2);
    
    polinomio suma = p1 + p2;
    cout << "p1 + p2 = ";
    mostrar(suma);
    cout << "Esperado: 5x^2 + 6x + 4" << endl;
    
    // CASO 2: Resta de polinomios
    cout << "\n--- CASO 2: Resta de polinomios ---" << endl;
    polinomio resta = p1 - p2;
    cout << "p1 - p2 = ";
    mostrar(resta);
    cout << "Esperado: x^2 - 2x - 2" << endl;
    
    // CASO 3: Multiplicación de polinomios
    cout << "\n--- CASO 3: Multiplicación de polinomios ---" << endl;
    polinomio p3(1);  // 2x + 1
    p3.coeficiente(0, 1);
    p3.coeficiente(1, 2);
    
    polinomio p4(1);  // 3x + 2
    p4.coeficiente(0, 2);
    p4.coeficiente(1, 3);
    
    cout << "p3 = ";
    mostrar(p3);
    cout << "p4 = ";
    mostrar(p4);
    
    polinomio producto = p3 * p4;
    cout << "p3 * p4 = ";
    mostrar(producto);
    cout << "Esperado: 6x^2 + 7x + 2" << endl;
    
    // CASO 4: Derivada de un polinomio
    cout << "\n--- CASO 4: Derivada ---" << endl;
    polinomio p5(3);  // 2x^3 + 3x^2 + 4x + 5
    p5.coeficiente(0, 5);
    p5.coeficiente(1, 4);
    p5.coeficiente(2, 3);
    p5.coeficiente(3, 2);
    
    cout << "p5 = ";
    mostrar(p5);
    
    polinomio deriv = derivada(p5);
    cout << "derivada(p5) = ";
    mostrar(deriv);
    cout << "Esperado: 6x^2 + 6x + 4" << endl;
    
    // CASO 5: Polinomios de diferente grado
    cout << "\n--- CASO 5: Suma con diferentes grados ---" << endl;
    polinomio p6(1);  // x + 2
    p6.coeficiente(0, 2);
    p6.coeficiente(1, 1);
    
    polinomio p7(3);  // x^3 + 2x^2 + 3
    p7.coeficiente(0, 3);
    p7.coeficiente(2, 2);
    p7.coeficiente(3, 1);
    
    cout << "p6 = ";
    mostrar(p6);
    cout << "p7 = ";
    mostrar(p7);
    
    polinomio suma2 = p6 + p7;
    cout << "p6 + p7 = ";
    mostrar(suma2);
    cout << "Esperado: x^3 + 2x^2 + x + 5" << endl;
    
    // CASO 6: Derivada de polinomio de grado 1
    cout << "\n--- CASO 6: Derivada de polinomio lineal ---" << endl;
    polinomio p8(1);  // 5x + 3
    p8.coeficiente(0, 3);
    p8.coeficiente(1, 5);
    
    cout << "p8 = ";
    mostrar(p8);
    
    polinomio deriv2 = derivada(p8);
    cout << "derivada(p8) = ";
    mostrar(deriv2);
    cout << "Esperado: 5" << endl;
    
    // CASO 7: Producto por el polinomio nulo
    cout << "\n--- CASO 7: Producto con polinomio nulo ---" << endl;
    polinomio p9(2);  // Polinomio nulo (todos los coeficientes a 0)
    
    cout << "p1 = ";
    mostrar(p1);
    cout << "p9 (nulo) = ";
    mostrar(p9);
    
    polinomio producto2 = p1 * p9;
    cout << "p1 * p9 = ";
    mostrar(producto2);
    cout << "Esperado: 0" << endl;
    
    // CASO 8: Operaciones encadenadas
    cout << "\n--- CASO 8: Operaciones encadenadas ---" << endl;
    polinomio resultado = (p1 + p2) * p3;
    cout << "(p1 + p2) * p3 = ";
    mostrar(resultado);
    
    cout << "\n=== FIN DE LAS PRUEBAS ===" << endl;
    
    return 0;
}

