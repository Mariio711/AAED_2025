#ifndef _AritPol_
#define _AritPol_

#include "polinom.h"

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
    int Grado = 0, n = 0;

    Grado = a.grado() * b.grado();
    polinomio c = polinomio(Grado);

    for (int i = 0; i <= a.grado(); i++)
    {
        for (int j = 0; j <= b.grado(); j++)
        {
            
        }
    }

    return c;
}
#endif