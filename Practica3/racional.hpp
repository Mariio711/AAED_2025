#ifndef _RACIONAL_
#define _RACIONAL_
#include <cassert>

class racional
{
public:
    typedef long long entero;
    racional(entero nu = 0, entero de = 1);
    entero num() const { return n; }
    entero den() const { return d; }

    // operadores de asignación compuesta (métodos miembro)
    racional& operator+=(const racional &r);
    racional& operator-=(const racional &r);
    racional& operator*=(const racional &r);
    racional& operator/=(const racional &r);

    // declaracion de operadores aritméticos no miembros
    friend racional operator+(const racional &r, const racional &s);
    friend racional operator-(const racional &r, const racional &s); // binario
    friend racional operator*(const racional &r, const racional &s);
    friend racional operator/(const racional &r, const racional &s);
    friend racional operator-(const racional &r); // unario
    friend racional operator+(const racional &r); // unario
    friend racional inv(const racional &r);

    // declaracion de operadores de comparación no miembros
    friend bool operator==(const racional &r, const racional &s);
    friend bool operator!=(const racional &r, const racional &s);
    friend bool operator<(const racional &r, const racional &s);
    friend bool operator<=(const racional &r, const racional &s);
    friend bool operator>(const racional &r, const racional &s);
    friend bool operator>=(const racional &r, const racional &s);

private:
    entero n, d;
    static entero mcd(entero, entero);
    static entero mcm(entero, entero);
};

// Implementaciones de operaciones en linea
// operadores aritméticos no miembros
inline racional operator-(const racional &r)
{
    return racional(-r.n, r.d);
}

inline racional operator+(const racional &r)
{
    return r; // operador unario positivo
}

inline racional operator-(const racional &r, const racional &s)
{
    return r + (-s); // usando suma y negación unaria
}

inline racional operator/(const racional &r, const racional &s)
{
    return r * inv(s); // usando multiplicación e inversión
}

inline racional inv(const racional &r)
{
    assert(r.n != 0); // No se puede invertir un número racional con numerador 0
    return racional(r.d, r.n);
}

// operadores de comparación
inline bool operator==(const racional &r, const racional &s)
{
    return (r.num() == s.num()) && (r.den() == s.den());
}

inline bool operator!=(const racional &r, const racional &s)
{
    return !(r == s);
}

inline bool operator<(const racional &r, const racional &s)
{
    return (r + -s).num() < 0;
}

inline bool operator<=(const racional &r, const racional &s)
{
    return (r < s) || (r == s);
}

inline bool operator>(const racional &r, const racional &s)
{
    return !(r <= s);
}

inline bool operator>=(const racional &r, const racional &s)
{
    return !(r < s);
}

//Método privado
inline racional::entero racional::mcm(entero x, entero y)
// devuelve m.c.m.(|x|,|y|). Devuelve 0 si x o y valen 0.
{
    return (x && y) ? (x < 0 ? -x : x) / mcd(x,y) * (y < 0 ? -y : y) : 0;
}

#endif