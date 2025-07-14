#include <iostream>
#include <algorithm> //random_shuffle
#include <ctime>
#include "carta.h"
#include "pilaenla.h"

bool solitario(tCarta *baraja, tfig *base)
{

    // elementos del juego
    Pila<tCarta> Mazo, Monton;

    // preparar el mazo...
    for (int i = 0; i < 40; i++)
    {
        Mazo.push(baraja[i]);
    }

    // y las bases vacias
    base[OROS] = VACIA;
    base[COPAS] = VACIA;
    base[ESPADAS] = VACIA;
    base[BASTOS] = VACIA;

    // JUGAR
    int colocadas;
    do
    {
        colocadas = 0;
        while (!Mazo.vacia())
        {
            // Pasar dos cartas (si hay) del mazo al montón de descartes.
            if (Mazo.tama() > 1)
            {
                Monton.push(Mazo.tope());
                Mazo.pop();
                Monton.push(Mazo.tope());
                Mazo.pop();
            }

            // Pasar cartas del montón de descartes a sus bases mientras sea posible
            while (!Monton.vacia() && Monton.tope().fig() == base[Monton.tope().palo()] + 1)
            {
                base[Monton.tope().palo()] = Monton.tope().fig();
                Monton.pop();
                colocadas++;
            }
        } // Mazo vacío.

        // Reponer el mazo con las cartas del montón de descartes.
        while (!Monton.vacia())
        {
            Mazo.push(Monton.tope());
            Monton.pop();
        }

        // Parar si no quedan cartas en el mazo o bien en el último
        // ciclo no se ha colocado ninguna en su base.
    } while (!Mazo.vacia() && colocadas > 0);

    return (Mazo.vacia());
    // TRUE (éxito) si el mazo está vacío, o lo
    // que es lo mismo, todas las cartas están
    // en sus bases.
}

int main()
{
    using namespace std;

    tCarta baraja[40];
    tfig base[4];

    // generar las 40 cartas de la baraja española
    for (int i = 0, p = OROS; p <= BASTOS; p++)
    {
        for (int f = AS; f <= REY; f++, i++)
        {
            baraja[i] = tCarta(tpalo(p), tfig(f));
        }
    }

    srand(time(0));
    bool victoria = false;
    int partidas = 0;

    do
    {
        random_shuffle(baraja, baraja + 40); // barajar cartas
        victoria = solitario(baraja, base);  // jugar

        // Mostrar resultado
        cout << "Partidas jugadas = " << ++partidas << endl;
        cout << "Últimas cartas colocadas:\n"
             << "\t" << tCarta(OROS, base[OROS]) << endl
             << "\t" << tCarta(COPAS, base[COPAS]) << endl
             << "\t" << tCarta(ESPADAS, base[ESPADAS]) << endl
             << "\t" << tCarta(BASTOS, base[BASTOS]) << endl
             << endl;
    } while (!victoria); // Parar al ganar una partida.
    cout << "½Conseguido! Bien hecho.\n"
         << endl;

    return 0;
}