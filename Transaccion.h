/*
  Archivo: transaccion.h
  Autor: Manuel Diaz COD 1741652 - Jeffrey Rios COD 1744831
  Email: manuel.isaza@correounivalle.edu.co - jeffrey.rios@correounivalle.edu.co
  Fecha creacion: 2018-06-14
  Fecha ultima modificacion: 2018-06-14
  Version: 0.1
  Licencia: GPL
*/

// Responsabilidad: elemento(Transaccion) de caja
// Colaboracion: ninguna



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