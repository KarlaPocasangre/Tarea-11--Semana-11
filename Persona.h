#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include <string.h>
using namespace std;

class Persona
{
protected:
    int codigo;
    string nombre;
    string apellido;
public:
    Persona(int c, string n, string a)
    {
        this->codigo = c;
        this->nombre = n;
        this->apellido = a;
    }
    int getCodigo()
    {
        return this->codigo;
    }
    string getNombre()
    {
        return this->nombre;
    }
    string getApellido()
    {
        return this->apellido;
    }
};
#endif // PERSONA_H_INCLUDED
