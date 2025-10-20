#include <cstdlib>

using namespace std;

int num_aleat_a_b(int a, int b)
{
    int n = 0;
        n = a + rand() % (b - a + 1);
    return n;
}