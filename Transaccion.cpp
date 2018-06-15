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