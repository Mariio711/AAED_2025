#ifndef POLI_USER_H_
#define POLI_USER_H_
#include <cstdlib>

class polinomio
{
public:
    // Constructor
    explicit polinomio(unsigned gradoMax = 0);

    unsigned gradoMax() const { return GradoMax; };
    unsigned grado() const { return Grado; };

    double coeficiente(unsigned n) const { return (n > Grado) ? 0 : pol[n]; };
    void coeficiente(unsigned n, double c);

    polinomio& operator=(const polinomio &otro);
    ~polinomio();

private:
    double *pol;
    unsigned GradoMax, Grado;
};

#endif