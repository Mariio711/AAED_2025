#include "Ej3.cpp"
#include <iostream>
#include <cmath>

void media_valores_rand(int n)
{
    double aux = 0;
    for (int i = 0; i < n; i++)
    {
        int num = 4 * sqrt(1 - pow(random_double_a_b(0, 1), 2));
        aux += num;
    }

    std::cout << "media de " << n << " resultados = " << aux/n << std::endl;
}

int main(){
    media_valores_rand(10000000);
    return 0;
}