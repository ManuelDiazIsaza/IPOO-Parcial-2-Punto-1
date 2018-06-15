/*
  Archivo: transaccion.cpp
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
#include "Transaccion.h"

Transaccion::Transaccion()
{
    tipo = " ";
    numCuenta = 0;
    valor = 0;
    cliente = 0;
    sig = nullptr;
    ant = nullptr;
}

Transaccion::~Transaccion()
{
    //MC)todo destructor
}

void Transaccion::setTipo(string tipo){
    this -> tipo = tipo;
}
string Transaccion::getTipo(){
    return tipo;
}

void Transaccion::setNumCuenta(int numCuenta){
    this -> numCuenta = numCuenta;
}

int Transaccion::getNumCuenta(){
    return numCuenta;
}

void Transaccion::setValor(int valor){
    this -> valor = valor;
}

int Transaccion::getValor(){
    return valor;
}

void Transaccion::setCliente(int cliente){
    this -> cliente = cliente;
}

int Transaccion::getCliente(){
    return cliente;
}

void Transaccion::setSig(Transaccion *sig){
    this -> sig = sig;
}

Transaccion* Transaccion::getSig(){
    return this -> sig;
}

void Transaccion::setAnt(Transaccion *ant){
    this -> ant = ant;
}

Transaccion* Transaccion::getAnt(){
    return this -> ant;
}