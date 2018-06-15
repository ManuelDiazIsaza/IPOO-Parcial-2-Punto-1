/*
  Archivo: ListaEnlazadaDoble.h
  Autor: Luis Yovany Romo
  Email: luis.romo@correounivalle.edu.co
  Fecha creaciC3n: 2018-02-09
  Fecha Cltima modificaciC3n: 2018-02-09
  VersiC3n: 0.1
  Licencia: GPL
*/

// Clase: ListaDoble
// Responsabilidad: elemento (nodo) de una lista Enlazada Doble
// ColaboraciCB3n: ninguna


#ifndef CAJA_H
#define CAJA_H
#include "Cliente.h"
#include "Transaccion.h"


using namespace std;


class Caja
{
private:
    Transaccion *cabTrans; // Transacciones Hechas
    Cliente *cabClientes; // Clientes en cola
    Cliente *cabClientesA; // Clientes diferentes atendidos
public:
    Caja();
    ~Caja();

    //Metodos Transacciones
    void hacerTransaccion();
    int cantidadTransacciones();
    void imprimirTransacciones();
    void valorPorTransaccion();
    void interfazPPal();


    //Metodos Cola
    int cantidadEnCola(); // cantidad de clientes en cola
    int cantidadAtendidos(); // cantidad de clientes diferentes atendidos;
    void llegoCliente(int id); // agrega el cliente a la cola de esperar
    void atenderCliente(); // retira al cliente de la cola y lo agrega a clientes atendidos si es un cliente nuevo
    void imprimirClientesCola(); // clientes en cola
    void imprimirClientesAtendidos(); // Clientes diferentes atendidos
    void agregarAtendidos(); // agrega un cliente nuevo a la cola de atendidos

};

#endif