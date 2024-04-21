#ifndef TRABAJADORPORHORA_H_INCLUDED
#define TRABAJADORPORHORA_H_INCLUDED
#include "Trabajador.h"

class TrabajadorPorHora : public Trabajador
{
private:
    float sueldoPorHora;
    int numHorasTrab;
    void calcular()
    {
        this->sueldoMensual = this->sueldoPorHora*this->numHorasTrab;
        this->descuentoIsr = this->sueldoMensual*0.1;
        this->totalPagar = this->sueldoMensual - this->descuentoIsr;
    }
public:
    TrabajadorPorHora(int c, string n, string a, float sh, int nht) : Trabajador (c, n, a)
    {
        this->sueldoPorHora = sh;
        this->numHorasTrab = nht;
        this->calcular();
    }
    float getSueldoMensual()
    {
        return this->sueldoPorHora;
    }
    int getNumHorasTrab()
    {
        return this->numHorasTrab;
    }
    int getTipoTrabajador()
    {
        return 2;
    }
};


#endif // TRABAJADORPORHORA_H_INCLUDED
