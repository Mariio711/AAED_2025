#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

void permuta_vec(int v[], int n)
{
    random_shuffle(v, v + n);
}

bool prueba_ordena(int v[], unsigned n)
{
    int s[] = {1, 2, 3, 4, 5, 6};

    permuta_vec(v, n);                           // «Ordena» el vector.
    return (memcmp(v, s, n * sizeof(int)) == 0); // Devuelve la comprobación del resultado.
}

int main()
{

    int v[] = {1, 2, 3, 4, 5, 6};
    int n = 6;
    int cont = 0;

    for (int j = 0; j < 10000000; j++)
    {
        if (prueba_ordena(v, n))
        {
            cont++;
        }
    }

    cout << "El numero de veces que se ordena es: " << cont << endl;
    return 0;
}