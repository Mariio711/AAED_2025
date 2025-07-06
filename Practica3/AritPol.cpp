#include "AritPol.h"

polinomio operator+(const polinomio &a, const polinomio &b)
{
    int GradoA = a.grado(), GradoB = b.grado(), n = 0;

    polinomio c = polinomio(0);
    if (GradoA >= GradoB)
    {
        c = polinomio(GradoA);
        n = GradoA;
    }
    else
    {
        c = polinomio(GradoB);
        n = GradoB;
    }

    for (int i = 0; i <= n; i++)
    {
        c.coeficiente(i, (a.coeficiente(i) + b.coeficiente(i)));
    }

    return c;
}

polinomio operator-(const polinomio &a, const polinomio &b)
{
    int GradoA = a.grado(), GradoB = b.grado(), n = 0;

    polinomio c = polinomio(0);
    if (GradoA >= GradoB)
    {
        c = polinomio(GradoA);
        n = GradoA;
    }
    else
    {
        c = polinomio(GradoB);
        n = GradoB;
    }

    for (int i = 0; i <= n; i++)
    {
        c.coeficiente(i, (a.coeficiente(i) - b.coeficiente(i)));
    }

    return c;
}

polinomio operator*(const polinomio &a, const polinomio &b)
{
    polinomio c = polinomio(a.grado() + b.grado());

    for (int i = 0; i <= a.grado(); i++)
    {
        for (int j = 0; j <= b.grado(); j++)
        {
            double valor = c.coeficiente(i + j) + a.coeficiente(i) * b.coeficiente(j);
            c.coeficiente(i + j, valor);
        }
    }

    return c;
}

polinomio derivada(const polinomio &a)
{
    polinomio b = polinomio(a.grado() - 1);

    for (int i = 0; i < a.grado(); i++)
    {
        b.coeficiente(i, (a.coeficiente(i + 1) * (i + 1)));
    }
    return b;
}