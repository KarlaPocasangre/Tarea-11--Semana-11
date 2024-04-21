#ifndef TRABAJADORTIEMPOCOMPLETO_H_INCLUDED
#define TRABAJADORTIEMPOCOMPLETO_H_INCLUDED
#include "Trabajador.h"

class TrabajadorTiempoCompleto : public Trabajador
{
private:
    float descuentoIsss;
    float descuentoAfp;
    void calcular()
    {
        this->descuentoIsss =  (this->sueldoMensual <=1000) ? this->sueldoMensual*0.03 : 30;
        this->descuentoAfp = (this->sueldoMensual <=7500) ? this->sueldoMensual*0.0725 :543.75;
        float ri= this->sueldoMensual - this->descuentoIsss - this->descuentoAfp;
        if (ri > 0 && ri <= 472){
            this->descuentoIsr = 0;
        }
        else{
            if (ri >472 && ri <= 895.24){
                this->descuentoIsr = (ri - 472)*0.1 + 17.67;
            }
            else{
                if (ri > 895.24 && ri <=2038.01){
                    this->descuentoIsr = (ri -895.24)*0.2 + 60;
                }
                else{
                    this->descuentoIsr = (ri -2038.01)*0.3 + 288.57;
                }
            }
        }
        this->totalPagar = this->sueldoMensual - descuentoIsss - this->descuentoAfp - this-> descuentoIsr;
    }
public:
    TrabajadorTiempoCompleto(int c, string n, string a, float sm) : Trabajador(c, n, a)
    {
        this->sueldoMensual = sm;
        this->calcular();
    }
    float getDescuentoIsss()
    {
        return this->descuentoIsss;
    }
    float getDescuentoAfp()
    {
        return this->descuentoAfp;
    }
    int getTipoTrabajador()
    {
        return 1;
    }
};
#endif // TRABAJADORTIEMPOCOMPLETO_H_INCLUDED
