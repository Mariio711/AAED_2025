#ifndef LINEA_TEXTO_H
#define LINEA_TEXTO_H

#include "pilaenla.h"

class LineaTexto
{
public:
    LineaTexto(char *Cad = "");
    void avanzar_cursor();
    void retrasar_cursor();
    void final_linea();
    void principio_linea();
    void borrar_carac_pos();
    void borrar_carac_ant();
    void insertar_carac(const char);
    void sobreescribir_carac(const char);
    ~LineaTexto();
private:
    Pila<char> Izq, Der;
};

#endif // LINEA_TEXTO_H