#include <iostream>
#include "polinom.h"
#include "AritPol.h"

using namespace std;

void mostrar(const polinomio& p) {
    cout << "Polinomio: ";
    for (unsigned i = 0; i <= p.grado(); ++i) {
        cout << p.coeficiente(i);
        if (i > 0) cout << "x^" << i;
        if (i < p.grado()) cout << " + ";
    }
    cout << endl;
}

int main() {
    int opcion;
    unsigned grado1, grado2;
    double coef;
    polinomio p1(0), p2(0), res(0);

    do {
        cout << "\n--- MENU ARITHPOL ---\n";
        cout << "1. Crear polinomio 1\n";
        cout << "2. Crear polinomio 2\n";
        cout << "3. Sumar p1 + p2\n";
        cout << "4. Restar p1 - p2\n";
        cout << "5. Multiplicar p1 * p2\n";
        cout << "6. Derivar p1\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Grado de p1: ";
                cin >> grado1;
                p1 = polinomio(grado1);
                for (unsigned i = 0; i <= grado1; ++i) {
                    cout << "Coeficiente x^" << i << ": ";
                    cin >> coef;
                    p1.coeficiente(i, coef);
                }
                mostrar(p1);
                break;
            case 2:
                cout << "Grado de p2: ";
                cin >> grado2;
                p2 = polinomio(grado2);
                for (unsigned i = 0; i <= grado2; ++i) {
                    cout << "Coeficiente x^" << i << ": ";
                    cin >> coef;
                    p2.coeficiente(i, coef);
                }
                mostrar(p2);
                break;
            case 3:
                res = p1 + p2;
                cout << "Resultado de p1 + p2:\n";
                mostrar(res);
                break;
            case 4:
                res = p1 - p2;
                cout << "Resultado de p1 - p2:\n";
                mostrar(res);
                break;
            case 5:
                res = p1 * p2;
                cout << "Resultado de p1 * p2:\n";
                mostrar(res);
                break;
            case 6:
                res = derivada(p1);
                cout << "Derivada de p1:\n";
                mostrar(res);
                break;
            case 0:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion no valida.\n";
        }
    } while (opcion != 0);

    return 0;
}