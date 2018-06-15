/*
  Archivo: cliente.h
  Autor: Manuel Diaz COD 1741652 - Jeffrey Rios COD 1744831
  Email: manuel.isaza@correounivalle.edu.co - jeffrey.rios@correounivalle.edu.co
  Fecha creacion: 2018-06-14
  Fecha ultima modificacion: 2018-06-14
  Version: 0.1
  Licencia: GPL
*/

// Responsabilidad: elemento (cliente) de caja
// Colaboracion: ninguna



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