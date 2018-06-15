/*
  Archivo: Nodo.h
  Autor: Luis Yovany Romo
  Email: luis.romo@correounivalle.edu.co
  Fecha creaciC3n: 2018-02-09
  Fecha Cltima modificaciC3n: 2018-02-09
  VersiC3n: 0.1
  Licencia: GPL
*/

// Clase: Nodo
// Responsabilidad: elemento (nodo) de una lista
// ColaboraciCB3n: ninguna


#ifndef TRANSACCION_H
#define TRANSACCION_H
#include "iostream"

using namespace std;


class Transaccion
{
protected:
    string tipo;
    int numCuenta;
    int valor;
    int cliente;
    Transaccion *sig;
    Transaccion *ant;
public:
    Transaccion();
    ~Transaccion();
    void setTipo(string tipo);
    string getTipo();
    void setNumCuenta(int numCuenta);
    int getNumCuenta();
    void setValor(int Valor);
    int getValor();
    void setCliente(int Cliente);
    int getCliente();
    Transaccion *getSig();
    void setSig(Transaccion *sig);
    Transaccion *getAnt();
    void setAnt(Transaccion *ant);
};

#endif