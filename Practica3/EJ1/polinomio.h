#ifndef _POLINOMIO_
#define _POLINOMIO_

class polinomio
{
public:
    //constructor
    explicit polinomio(unsigned GradoMax);
    polinomio (const polinomio& otro); 

    //destructor
    ~polinomio();

    //operador de asignación
    polinomio &operator=(const polinomio &otro);

    //metodos observadores
    unsigned grado() const;
    double coeficiente(unsigned n) const;

    //metodos modificadores
    void coeficiente(unsigned n, double c);

private:
    double *pol;
    unsigned gradoM;
};

#endif