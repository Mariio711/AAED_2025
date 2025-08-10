/*Se desea simular el juego de los reyes. Se trata de un solitario que se desarrolla de la
siguiente forma:
Se reparten las cartas de la baraja española en diez montones de cuatro cartas cada uno.
Cada montón se corresponde con una de las diez figuras de la baraja. Se escoge uno de los
montones al azar y se extrae la carta de dicho montón que esté en la cima. Esta carta se
coloca al final del montón correspondiente a la figura que represente, extrayéndose ahora
la primera carta de este montón. Este ciclo se repite hasta llegar a un montón en el que
las cuatro cartas de la figura correspondiente han sido colocadas.
El juego se considera acabado con éxito si los cuatro reyes están en su montón*/

#include <iostream>
#include <algorithm> // random_shuffle o shuffle
#include <random>
#include <ctime>
#include "carta.h"
#include "colaenla.h"

// Tipo para representar un montón (cola de cartas)
typedef Cola<tCarta> tMonton;

bool completo(tMonton monton_reyes)
{
    tMonton temp = monton_reyes;
    //comprobamos que no hay 5 cartas lo cual indicaria que el juego sigue su curso y hay que extraerla a la mano
    if(temp.tama() > 4)
    {
        return false;
    }

    while(!temp.vacia())
    {
        if(temp.frente().fig() != REY)  //si hay alguna carta en el monton que no es un rey hay que seguir jugando
        {
            return false;
        }
        temp.pop();
    }

    //si llegamos aqui es que los 4 reyes estan en su monton y habremos acabado el juego con exito
    return true;
}

bool juego_reyes(tCarta *baraja, tMonton *montones, tfig comienzo)
{
    //rellenar montones
    int cont = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            montones[i].push(baraja[cont]);
            cont++; 
        }
    }

    tCarta mano;

    while(!completo(montones[REY]))
    {
        // Verificar que el montón no esté vacío
        if (montones[comienzo].vacia()) {
            return false; // No se puede continuar
        }
        
        //cogemos la carta del monton de comienzo
        mano = montones[comienzo].frente();
        montones[comienzo].pop();

        //ponemos la carta en mano al monton de su figura
        montones[mano.fig()].push(mano);

        //actualizamos "comienzo" con el monton en el que acabamos de poner la carta
        comienzo = mano.fig();
    }


    // Si llegamos aquí, los 4 reyes están en su montón
    return true;

}

int main()
{
    using namespace std;

    tCarta baraja[40];
    tMonton montones[10];

    // generar las 40 cartas de la baraja española
    for (int i = 0, p = OROS; p <= BASTOS; p++)
    {
        for (int f = AS; f <= REY; f++, i++)
        {
            baraja[i] = tCarta(tpalo(p), tfig(f));
        }
    }

    std::random_device rd;
    std::mt19937 g(rd());
    bool victoria = false;


    std::shuffle(baraja, baraja + 40, g); // barajar cartas
    victoria = juego_reyes(baraja, montones, AS);  // jugar

    // Mostrar resultado
    if (victoria) {
        cout << "¡Conseguido! Bien hecho.\n" << endl;
        cout << "Cartas monton de reyes:\n" << endl;
        for(int i = 0; i < 4; i++)
        {
            cout << "Posicion "<< i <<": " << montones[REY].frente() << endl;
            montones[REY].pop();
        }
    } else {
        cout << "No se pudo completar el juego. ¡Inténtalo de nuevo!" << endl;
    }

    system("pause");
    return 0;
}
