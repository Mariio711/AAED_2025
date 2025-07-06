#ifndef _POLINOMIO_
#define _POLINOMIO_

class polinomio
{
public:
    //constructor
    explicit polinomio(unsigned GradoMax); 

    //metodos observadores
    unsigned grado() const;
    double coeficiente(unsigned n) const;

    //metodos modificadores
    void coeficiente(unsigned n, double c);

private:
    double *pol;
    unsigned grado;
    unsigned a;
};

#endif