#include "lineatexto.h"
#include <cstring>

// constructor
LineaTexto::LineaTexto(char *cad)
{
    for (int i = 0; i < std::strlen(cad); i++)
    {
        Izq.push(cad[i]);
    }
}

// avanzar el cursor una posición
void LineaTexto::avanzar_cursor()
{
    if (!Der.vacia())
    {
        Izq.push(Der.tope());
        Der.pop();
    }
    // Si Der está vacía, no se hace nada
}

// retrasar el cursor una posicion
void LineaTexto::retrasar_cursor()
{
    if (!Izq.vacia())
    {
        Der.push(Izq.tope());
        Izq.pop();
    }
    // Si Izq está vacía, no se hace nada
}

// llevar el cursor al final de la linea
void LineaTexto::final_linea()
{
    while (!Der.vacia())
    {
        Izq.push(Der.tope());
        Der.pop();
    }
    // Si Der está vacía, no se hace nada
}

// llevar el cursor al principio de la linea
void LineaTexto::principio_linea()
{
    while (!Izq.vacia())
    {
        Der.push(Izq.tope());
        Izq.pop();
    }
    // Si Izq está vacía, no se hace nada
}

// borrar caracter de la posicion del cursor
void LineaTexto::borrar_carac_pos()
{
    if (!Izq.vacia())
    {
        Izq.pop();
    }
    // si no hay caracteres a la izquierda del cursor no se hace nada
}

// borrar caracter anterior al cursor (suprimir)
void LineaTexto::borrar_carac_ant()
{
    if (!Der.vacia())
    {
        Der.pop();
    }
    // si no hay caracteres a la derecha del cursor no se hace nada
}

// añadir caracter a la izq del cursor
void LineaTexto::insertar_carac(const char a)
{
    Izq.push(a);
}

void LineaTexto::sobreescribir_carac(const char a)
{
    if (!Der.vacia())
    {
        Der.pop();
    }
    Izq.push(a);
}