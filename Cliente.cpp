/*
  Archivo: Nodo.cpp
  Autor: Luis Yovany Romo Portilla
  Email: luis.romo@correounivalle.edu.co
  Fecha creaciC3n: 2017-08-31
  Fecha C:ltima modificaciC3n: 2017-08-31
  VersiC3n: 0.1
  Licencia: GPL
*/

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