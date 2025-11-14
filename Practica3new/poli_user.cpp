#include "poli_user.h"
#include <algorithm>
#include <cassert>

polinomio::polinomio(unsigned gradoMax) : pol(new double[gradoMax + 1]), GradoMax(gradoMax), Grado(0)
{
    for (int i = 0; i <= GradoMax; i++)
    {
        pol[i] = 0.0;
    }
}

polinomio &polinomio::operator=(const polinomio &otro)
{
    if (this != &otro)
    {
        // Crear copia temporal
        double *nuevo_pol = new double[otro.GradoMax + 1];
        for (unsigned i = 0; i <= otro.GradoMax; ++i)
        {
            nuevo_pol[i] = otro.pol[i];
        }

        // Liberar memoria antigua e intercambiar
        delete[] pol;
        pol = nuevo_pol;
        GradoMax = otro.GradoMax;
        Grado = otro.Grado;
    }
    return *this;
}

void polinomio::coeficiente(unsigned n, double c)
{
    assert(n <= GradoMax); // Asegurar que n está en rango
    pol[n] = c;

    // Actualizar el grado del polinomio
    if (c != 0.0 && n > Grado)
    {
        // Si asignamos un coeficiente no nulo a un grado mayor
        Grado = n;
    }
    else if (c == 0.0 && n == Grado)
    {
        // Si ponemos a 0 el coeficiente del grado máximo actual,
        // recalcular el grado buscando desde atrás
        while (Grado > 0 && pol[Grado] == 0.0)
        {
            --Grado;
        }
    }
};

polinomio::~polinomio() { delete[] pol; }