/*
  Archivo: cliente.cpp
  Autor: Manuel Diaz COD 1741652 - Jeffrey Rios COD 1744831
  Email: manuel.isaza@correounivalle.edu.co - jeffrey.rios@correounivalle.edu.co
  Fecha creacion: 2018-06-14
  Fecha ultima modificacion: 2018-06-14
  Version: 0.1
  Licencia: GPL
*/

// Responsabilidad:
// Colaboracion: ninguna

#include <stdio.h>
#include <iostream>
#include "Cliente.h"

Cliente::Cliente()
{
    id = 0;
    cantidadT = 1;
    sig = nullptr;
    ant = nullptr;
}

Cliente::~Cliente()
{
    //MC)todo destructor
}

void Cliente::setId(int id){
    this -> id = id;
}
int Cliente::getId(){
    return id;
}

void Cliente::setCantidadT(int cantidadT){
    this -> cantidadT = cantidadT;
}

int Cliente::getCantidadT(){
    return cantidadT;
}

void Cliente::setSig(Cliente *sig){
    this -> sig = sig;
}

Cliente* Cliente::getSig(){
    return this -> sig;
}

void Cliente::setAnt(Cliente *ant){
    this -> ant = ant;
}

Cliente* Cliente::getAnt(){
    return this -> ant;
}