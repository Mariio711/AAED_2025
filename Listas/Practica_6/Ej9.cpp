/*En una variante de un juego bastante conocido, n jugadores, identificados por su nombre,
se sitúan en círculo y se les asigna aleatoriamente un número del 1 al 6 (obviamente varios
jugadores pueden tener asignado el mismo número). Se elige al azar un jugador de comienzo
y, suponiendo que su número asignado es i, se elimina al jugador que está i posiciones hacia
la izquierda si i es impar, o hacia la derecha si i es par. Se toma como nuevo valor de i el
número que tuviera asignado el último jugador eliminado, el cuál, determina de la forma
descrita el siguiente jugador a eliminar. Este proceso se repite hasta que quede un único
jugador, el ganador del juego.
Implemente una función que determine y devuelva el jugador ganador, dado el conjunto
de n jugadores con sus números del 1 al 6 asignados y la posición del jugador de comienzo.*/

#include "listaenla.h"
#include <string>
#include <iostream>
#include <locale>
#include <windows.h>

// Función para configurar la consola para mostrar caracteres especiales y tildes
void configurarConsola() {
    // Configurar la página de códigos para entrada y salida
    SetConsoleCP(1252);         // Establece la página de códigos de entrada
    SetConsoleOutputCP(1252);   // Establece la página de códigos de salida
    
    // Configurar el locale para usar caracteres españoles
    std::setlocale(LC_ALL, "spanish");
}

struct jugador
{
    std::string nombre;
    int num;
    
    jugador(const std::string& n = "", int numero = 0) : nombre(n), num(numero) {}
};

jugador juego(Lista<jugador> jugadores, Lista<jugador>::posicion comienzo)
{
    Lista<jugador>::posicion p = comienzo;
    int numero = jugadores.elemento(comienzo).num, cont = 0;
    
    std::cout << "\nInicio del juego con " << jugadores.tama() << " jugadores." << std::endl;
    std::cout << "Jugador de comienzo: " << jugadores.elemento(comienzo).nombre 
              << " (número: " << jugadores.elemento(comienzo).num << ")" << std::endl;
    
    while (jugadores.tama() > 1)
    {
        std::cout << "\n--- Iteración " << cont + 1 << " ---" << std::endl;
        std::cout << "Posición actual: jugador " << jugadores.elemento(p).nombre 
                  << " (número: " << jugadores.elemento(p).num << ")" << std::endl;
        
        if (numero % 2 == 0)
        {
            if (cont != 0)
            {
                numero -= 1;
                std::cout << "Número ajustado (no primera iteración): " << numero << std::endl;
            }
            std::cout << "Número par: avanzando " << numero << " posiciones a la derecha" << std::endl;
            for (int i = 0; i < numero; i++)
            {
                p = jugadores.siguiente(p);
                if (p == jugadores.fin())
                    p = jugadores.primera();
            }
        }
        else
        {
            if (cont != 0)
            {
                numero -= 1;
                std::cout << "Número ajustado (no primera iteración): " << numero << std::endl;
            }
            std::cout << "Número impar: avanzando " << numero << " posiciones a la izquierda" << std::endl;
            for (int i = 0; i < numero; i++)
            {
                p = jugadores.anterior(p);
                if (p == jugadores.fin())
                    p = jugadores.anterior(jugadores.primera()); // Último elemento
            }
        }

        // actualizar numero de la siguiente iteracion menos uno
        // por que ya se pasa a la siguiente posicion mas adelante
        numero = jugadores.elemento(p).num;
        
        std::cout << "Jugador a eliminar: " << jugadores.elemento(p).nombre 
                  << " (número: " << jugadores.elemento(p).num << ")" << std::endl;

        // guardar el siguiente jugador antes de eliminarlo
        Lista<jugador>::posicion siguiente;

        if (numero % 2 == 0)
        {
            if (p == jugadores.fin())
            {
                siguiente = jugadores.primera();
            }
            else
            {
                siguiente = jugadores.siguiente(p);
                if (siguiente == jugadores.fin())
                {
                    siguiente = jugadores.primera();
                }
            }
            std::cout << "Siguiente jugador (derecha): " << jugadores.elemento(siguiente).nombre << std::endl;
        }
        else
        {
            if (p == jugadores.fin())
            {
                siguiente = jugadores.anterior(jugadores.primera());
            }
            else
            {
                siguiente = jugadores.anterior(p);
                if (siguiente == jugadores.fin())
                {
                    siguiente = jugadores.primera();
                }
            }
            std::cout << "Siguiente jugador (izquierda): " << jugadores.elemento(siguiente).nombre << std::endl;
        }

        // eliminar al jugador
        jugadores.eliminar(p);
        std::cout << "Jugadores restantes: " << jugadores.tama() << std::endl;

        // Actualizar p para la siguient iteracion
        p = siguiente;
        if (p == jugadores.fin())
            p = jugadores.primera();

        cont++;
    }

    std::cout << "\n¡Juego terminado!" << std::endl;
    std::cout << "El ganador es: " << jugadores.elemento(jugadores.primera()).nombre 
              << " (número: " << jugadores.elemento(jugadores.primera()).num << ")" << std::endl;

    return jugadores.elemento(jugadores.primera());
}

// Función para mostrar todos los jugadores en la lista
void mostrarJugadores(const Lista<jugador>& lista) {
    std::cout << "Lista de jugadores:" << std::endl;
    Lista<jugador>::posicion p = lista.primera();
    int i = 1;
    
    while (p != lista.fin()) {
        std::cout << i << ". " << lista.elemento(p).nombre 
                  << " (número: " << lista.elemento(p).num << ")" << std::endl;
        p = lista.siguiente(p);
        i++;
    }
    std::cout << std::endl;
}

int main() {
    // Configurar la consola para mostrar caracteres especiales
    configurarConsola();
    
    // Crear una lista de jugadores para probar
    Lista<jugador> listaJugadores;
    
    // Crear algunos jugadores con nombres y números aleatorios
    jugador j1("Martín", 3);
    jugador j2("José", 6);
    jugador j3("María", 1);
    jugador j4("Sofía", 4);
    jugador j5("Ramón", 2);
    jugador j6("Pilar", 5);
    
    // Insertar los jugadores en la lista circular
    Lista<jugador>::posicion p = listaJugadores.fin();
    listaJugadores.insertar(j1, p);
    p = listaJugadores.fin();
    listaJugadores.insertar(j2, p);
    p = listaJugadores.fin();
    listaJugadores.insertar(j3, p);
    p = listaJugadores.fin();
    listaJugadores.insertar(j4, p);
    p = listaJugadores.fin();
    listaJugadores.insertar(j5, p);
    p = listaJugadores.fin();
    listaJugadores.insertar(j6, p);
    
    // Mostrar la lista inicial de jugadores
    mostrarJugadores(listaJugadores);
    
    // Elegir el jugador de comienzo (por ejemplo, el primero)
    Lista<jugador>::posicion comienzo = listaJugadores.primera();
    
    // Ejecutar el juego
    jugador ganador = juego(listaJugadores, comienzo);
    
    // Mostrar el resultado final
    std::cout << "\nResultado final:" << std::endl;
    std::cout << "El ganador es: " << ganador.nombre << " (número: " << ganador.num << ")" << std::endl;
    
    system("pause");
    return 0;
}