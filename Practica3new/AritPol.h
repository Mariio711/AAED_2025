#ifndef ARITPOL_H_
#define ARITPOL_H_

#include "polinom.h"


polinomio operator+(const polinomio &a, const polinomio &b);
polinomio operator-(const polinomio &a, const polinomio &b);
polinomio operator*(const polinomio &a, const polinomio &b);
polinomio derivada(const polinomio &pol);


#endif