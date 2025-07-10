#include <cassert>
#include "polinomio.h"

/*
    Cabecera:       polinomio(unsigned GradoMax).
    Precondición:   GradoMax > 0.
    Postondición:   Crea el polinomio nulo. El objetivo de este método es crear un objeto
                    polinomio, reservando el espacio necesario e inicializando con el valor nulo.
*/
polinomio::polinomio(unsigned GradoMax) : pol(new double[GradoMax]), gradoM(GradoMax)
{
    for (int i = 0; i <= GradoMax; i++)
    {
        pol[i] = 0;
    }
}

/*
    Cabecera:       unsigned grado() const.
    Postondición:   Devuelve el grado de un polinomio.
*/
unsigned polinomio::grado() const
{
    return gradoM;
}

/*
    Cabecera:       double coeficiente(unsigned n) const
    Precondición:   0 <= n
    Postondición:   devuelve el coeficiente correspondiente al monomio de grado n de un polinomio. Si n > GradoMax, devuelve 0.
*/
double polinomio::coeficiente(unsigned n) const
{
    if (n > gradoM)
    {
        return 0;
    }
    else
    {
        return pol[n];
    }
}

/*
    Cabecera:       void coeficiente(unsigned n, double c)
    Precondición:   n <= GradoMax
    Postondición:   asigna al monomio de grado n el coeficiente c.
*/
void polinomio::coeficiente(unsigned n, double c)
{
    assert(n <= gradoM);
    pol[n] = c;
}

/*
    Cabecera:       polinomio (const polinomio& otro)
    Postondición:   crea un polinomio identico al que le pasamos
*/
polinomio::polinomio(const polinomio &otro) : pol(new double[otro.gradoM]), gradoM(otro.gradoM)
{
    for (int i = 0; i <= gradoM; i++)
    {
        pol[i] = otro.pol[i];
    }
}

/*
    Cabecera:       polinomio &operator=(const polinomio &otro)
    Precondición:
    Postondición:
*/
polinomio &polinomio::operator=(const polinomio &otro)
{
    if (this != &otro)
    {
        delete[] pol;
        gradoM = otro.gradoM;
        pol = new double[gradoM + 1];

        for (int i = 0; i <= gradoM; i++)
        {
            pol[i] = otro.pol[i];
        }
    }
    return *this;
}

/*
    Cabecera:       ~polinomio()
    Precondición:   existe el objeto polinomio.
    Postondición:   vacia la estructura para limpiar la memoria.
*/
polinomio::~polinomio()
{
    delete[] pol;
}