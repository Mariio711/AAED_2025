#include "polinom.h"
#include "AritPol.h"

// Suma de polinomios
polinomio operator+(const polinomio &a, const polinomio &b)
{
    int GradoA = a.grado(), GradoB = b.grado();
    int n = (GradoA >= GradoB) ? GradoA : GradoB;
    
    polinomio c(n);  // Crear con el grado máximo necesario

    for (int i = 0; i <= n; i++)
    {
        c.coeficiente(i, a.coeficiente(i) + b.coeficiente(i));
    }

    return c;
}

// Resta de polinomios
polinomio operator-(const polinomio &a, const polinomio &b)
{
    int GradoA = a.grado(), GradoB = b.grado();
    int n = (GradoA >= GradoB) ? GradoA : GradoB;
    
    polinomio c(n);  // Crear con el grado máximo necesario

    for (int i = 0; i <= n; i++)
    {
        c.coeficiente(i, a.coeficiente(i) - b.coeficiente(i));
    }

    return c;
}

// Producto de polinomios
polinomio operator*(const polinomio &a, const polinomio &b)
{
    polinomio c(a.grado() + b.grado());  // El grado del producto es la suma de grados

    for (unsigned i = 0; i <= a.grado(); i++)
    {
        for (unsigned j = 0; j <= b.grado(); j++)
        {
            double valor = c.coeficiente(i + j) + a.coeficiente(i) * b.coeficiente(j);
            c.coeficiente(i + j, valor);
        }
    }

    return c;
}

// derivada de un polinomio
polinomio derivada(const polinomio &a)
{
    if (a.grado() == 0) {
        // La derivada de una constante es 0
        polinomio b(0);
        b.coeficiente(0, 0);
        return b;
    }
    
    polinomio b(a.grado() - 1);  // El grado disminuye en 1

    for (unsigned i = 0; i < a.grado(); i++)
    {
        b.coeficiente(i, a.coeficiente(i + 1) * (i + 1));
    }
    
    return b;
}
