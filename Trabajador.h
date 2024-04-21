#ifndef TRABAJADOR_H_INCLUDED
#define TRABAJADOR_H_INCLUDED
#include "Persona.h"

class Trabajador : public Persona
{
protected:
    float sueldoMensual;
    float descuentoIsr;
    float totalPagar;
public:
    Trabajador(int c, string n, string a) : Persona (c, n, a)
    {
        this->sueldoMensual = 0;
        this->descuentoIsr = 0;
        this->totalPagar = 0;
    }
    float getSueldoMensual()
    {
        return this->sueldoMensual;
    }
    float getDescuentoIsr()
    {
        return this->descuentoIsr;
    }
    float getTotalPagar()
    {
        return this->totalPagar;
    }
    virtual int getTipoTrabajador() = 0;
};
#endif // TRABAJADOR_H_INCLUDED
