#include <cassert>
#include "polinomio.h"

polinomio::polinomio(unsigned GradoMax): pol(new double [GradoMax]), grado(GradoMax), 