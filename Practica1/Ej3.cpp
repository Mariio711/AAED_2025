#include <cstdlib>

double random_double_a_b(double a, double b)
{
    return a + (b - a) * (rand() / (double)RAND_MAX);
}