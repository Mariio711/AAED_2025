#ifndef _AritPol_
#define _AritPol_

#include "polinom.h"

polinomio operator+(const polinomio &a, const polinomio &b);
polinomio operator-(const polinomio &a, const polinomio &b);
polinomio operator*(const polinomio &a, const polinomio &b);
polinomio derivada(const polinomio &a);
#endif