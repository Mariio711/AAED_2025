/*El estacionamiento de las avionetas en un aeródromo es en línea, con capacidad para 12
avionetas. Las avionetas llegan por el extremo izquierdo y salen por el derecho. Cuando
llega un piloto a recoger su avioneta, si ésta no está justamente en el extremo de salida
(derecho), todas las avionetas a su derecha han de ser retiradas, sacar la suya y las retiradas
colocadas de nuevo en el mismo orden relativo en que estaban. La salida de una avioneta
supone que las demás se mueven hacia adelante, de tal forma que los espacios libres del
estacionamiento estén en la parte izquierda (entrada).
Implemente un subprograma que emule el estacionamiento. Este subprograma, además del
aeródromo, recibirá un código de acción sobre una avioneta, y la matrícula de la misma.
La acción puede ser entrada (E) o salida (S) de avioneta. En la llegada puede ocurrir que
el estacionamiento esté lleno; si es así, la avioneta espera hasta que se quede una plaza
libre o hasta que se le dé la orden de retirada (salida).
*/
#include "colaenla.h"
#include <string>
#include <iostream>
struct avioneta
{
    std::string matricula;
};

Cola<avioneta> cola_espera; // Variable global o pasada como parámetro
const int CAPACIDAD_MAX = 12;

bool matricula_existe(Cola<avioneta>& estac, Cola<avioneta>& espera, std::string matricula)
{
    // Buscar en estacionamiento
    Cola<avioneta> aux_estac = estac; // Copia para no modificar original
    while (!aux_estac.vacia())
    {
        if (aux_estac.frente().matricula == matricula)
            return true;
        aux_estac.pop();
    }
    
    // Buscar en cola de espera
    Cola<avioneta> aux_espera = espera; // Copia para no modificar original
    while (!aux_espera.vacia())
    {
        if (aux_espera.frente().matricula == matricula)
            return true;
        aux_espera.pop();
    }
    
    return false;
}

void procesar_espera(Cola<avioneta>& estac, Cola<avioneta>& espera)
{
    while (!espera.vacia() && estac.tama() < CAPACIDAD_MAX)
    {
        estac.push(espera.frente());
        std::cout << "Avioneta " << espera.frente().matricula << " ,en espera, pasa a estacionamiento." << std::endl;
        espera.pop();
    }
}

void estacionamiento_aerodromo(Cola<avioneta>& estac, std::string matricula, char accion)
{
    if(accion == 'S')
    {   
        Cola<avioneta> retiradas;
        bool encontrada = false;
        
        // Retirar avionetas hasta encontrar la buscada
        while (!estac.vacia() && !encontrada)
        {
            if(estac.frente().matricula == matricula)
            {
                estac.pop(); // Sacar la avioneta buscada
                encontrada = true;
                std::cout << "Avioneta " << matricula << " retirada." << std::endl;
            }
            else
            {
                retiradas.push(estac.frente()); // Retirar temporalmente
                estac.pop();
            }
        }
        
        // Reponer las avionetas retiradas en el mismo orden
        while (!retiradas.vacia())
        {
            estac.push(retiradas.frente());
            retiradas.pop();
        }
        
        if (!encontrada)
        {
            std::cout << "La avioneta " << matricula << " no se encuentra en el estacionamiento." << std::endl;
        }
        
        procesar_espera(estac, cola_espera);
    }

    if (accion == 'E')
    {
        if (matricula_existe(estac, cola_espera, matricula))
        {
            std::cout << "Error: Ya existe una avioneta con matrícula " << matricula << std::endl;
            return;
        }
        
        avioneta avion;
        avion.matricula = matricula;
        if(estac.tama() < CAPACIDAD_MAX)
        {
            estac.push(avion);
            std::cout << "Avioneta " << matricula << " estacionada." << std::endl;
        }
        else
        {
            cola_espera.push(avion);
            std::cout << "Avioneta " << matricula << " en cola de espera." << std::endl;
        }
    }
}