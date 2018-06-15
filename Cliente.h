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


#ifndef CLIENTE_H
#define CLIENTE_H


using namespace std;


class Cliente
{
protected:
    int id;
    int cantidadT;
    Cliente *sig;
    Cliente *ant;
public:
    Cliente();
    ~Cliente();
    void setId(int id);
    int getId();
    void setCantidadT(int id);
    int getCantidadT();
    Cliente *getSig();
    void setSig(Cliente *sig);
    Cliente *getAnt();
    void setAnt(Cliente *ant);
};

#endif