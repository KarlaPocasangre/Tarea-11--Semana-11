#include <iostream>
#include <stdlib.h>
#define TAM 5
#include "TrabajadorTiempoCompleto.h"
#include "TrabajadorPorHora.h"

using namespace std;

int menu()
{
    int op;
    cout << "Menu de opciones\n";
    cout << "1. Agregar trabajador\n";
    cout << "2. Mostrar planilla\n";
    cout << "3. Ver detalles del trabajador\n";
    cout << "4. Salir\n";
    cout << "Digite una opcion: ";
    cin >> op;
    return op;
}
Trabajador *agregarTrabajador()
{
    int tipo, cod, nht;
    string nom, ape;
    float s;
    Trabajador *tb;
    cout << "Digite el codigo del trabajador: ";
    cin >> cod;
    cout << "Digite el nombre del trabajador: ";
    cin >> nom;
    cout << "Digite el apellido del trabajador: ";
    cin >> ape;
    cout << "Digite el tipo del trabajador (TTC=1, TH=2): ";
    cin >> tipo;
    if (tipo == 1)
    {
        cout << "Digite el sueldo mensual: ";
        cin >> s;
        tb = new TrabajadorTiempoCompleto(cod, nom, ape, s);
    }
    else
    {
        cout << "Digite el sueldo por hora: ";
        cin >> s;
        cout << "Digite el numero de horas trabajadas: ";
        cin >> nht;
        tb = new TrabajadorPorHora(cod, nom, ape, s, nht);
    }
    return tb;
}
void mostrarPlanilla(Trabajador *lst[], int cont)
{
    if (cont ==0)
    {
        cout << "La planilla esta vacia\n";
    }
    else
    {
        cout << "\nCod\tNombre\tApellido\tTipo\tSueldo\tTotal Pagar\n";
        for (int i=0; i<cont; i++)
        {
            cout << lst[i]->getCodigo() << "\t";
            cout << lst[i]->getNombre() << "\t";
            cout << lst[i]->getApellido() << "\t";
            (lst[i]->getTipoTrabajador()==1) ? cout << "TC\t" : cout << "TH\t";
            cout << lst[i]->getSueldoMensual() << "\t";
            cout << lst[i]->getTotalPagar() << "\n";
        }
    }
}
Trabajador *buscarTrabajador(Trabajador *lst[], int cont, int cod)
{
    bool encontrado = false;
    int c=0;
    Trabajador *tb=NULL;
    while (c < cont && !encontrado)
    {
        if (lst[c]->getCodigo() == cod)
        {
            encontrado = true;
            tb = lst[c];
        }
        else
        {
            c = c + 1;
        }
    }
    return tb;
}
void verDetalles(Trabajador *tb)
{
    if (tb->getTipoTrabajador()==1)
    {
        cout << "Trabajador Tiempo completo\n";
        TrabajadorTiempoCompleto *tc = (TrabajadorTiempoCompleto*) tb;
        cout << "Codigo: " << tb->getCodigo() << endl;
        cout << "Nombre: " << tb->getNombre() << endl;
        cout << "Apellido: " << tb->getApellido() << endl;
        cout << "Sueldo Mensual: " << tb->getSueldoMensual() << endl;
        cout << "Descuento Isss: " << tc->getDescuentoIsss() << endl;
        cout << "Descuento Afp: " << tc->getDescuentoAfp() << endl;
        cout << "Descuento Isr: " << tc->getDescuentoIsr() << endl;
        cout << "Total a pagar " << tc->getTotalPagar() << endl;
    }
    else
    {
        cout << "Trabajador por hora\n";
        TrabajadorPorHora *th = (TrabajadorPorHora*) tb;
        cout << "Codigo: " << tb->getCodigo() << endl;
        cout << "Nombre: " << tb->getNombre() << endl;
        cout << "Apellido: " << tb->getApellido() << endl;
        cout << "Sueldo Mensual: " << tb->getSueldoMensual() << endl;
        cout << "Descuento Isr: " << th->getDescuentoIsr() << endl;
        cout << "Total a pagar " << th->getTotalPagar() << endl;
    }
}
int main()
{
    Trabajador *planilla[TAM];
    int cont = 0, opc, id;
    do
    {
        system("cls");
//               system("pause");
        opc= menu();
        switch (opc)
        {
        case 1:
            //Agregar trabajador
            if (cont < TAM)
            {
                planilla[cont] = agregarTrabajador();
//                cout << planilla [cont]->getSueldoMensual() << endl;
//                cout << planilla [cont]->getTotalPagar() << endl;
                cont++;
                cout << "Trabajador agregado con exito\n";
            }
            else
            {
                cout << "La planilla esta llena\n";
            }
            break;
        case 2:
            //Mostrar planilla
            mostrarPlanilla(planilla, cont);
            break;
        case 3:
        {
            //Ver detalles del trabajador
            cout << "Digite el id del trabajador: ";
            cin >> id;
            Trabajador *tb = buscarTrabajador(planilla, cont, id);
            if (tb)
            {
                verDetalles(tb);
            }
            else
            {
                cout << "El trabajador no se encontro\n";
            }
        }
        break;
        case 4:
            //Salir
            cout <<  "Saliendo del programa\n";
            break;
        default:
            cout <<  "Error, opcion no definida\n";
            break;
        }
        system("pause");
    }
    while (opc!=4);
    return 0;
}
