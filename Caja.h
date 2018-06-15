/*
  Archivo: caja.h
  Autor: Manuel Diaz COD 1741652 - Jeffrey Rios COD 1744831
  Email: manuel.isaza@correounivalle.edu.co - jeffrey.rios@correounivalle.edu.co
  Fecha creacion: 2018-06-14
  Fecha ultima modificacion: 2018-06-14
  Version: 0.1
  Licencia: GPL
*/

// Responsabilidad:
// Colaboracion: ninguna


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
    void hacerTransaccion(); // realiza una transaccion
    int cantidadTransacciones(); // devuelve la cantidad de transacciones realizadas
    void imprimirTransacciones(); // imprime todas las transacciones realizadas con su respectiva cantidad
    void valorPorTransaccion(); // // imprime el total por tipo de transaccion (retiro o consignacion)
    void interfazPPal(); // maneja la interfaz principal


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