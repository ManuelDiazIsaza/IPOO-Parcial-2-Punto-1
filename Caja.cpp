/*
  Archivo: caja.cpp
  Autor: Manuel Diaz COD 1741652 - Jeffrey Rios COD 1744831
  Email: manuel.isaza@correounivalle.edu.co - jeffrey.rios@correounivalle.edu.co
  Fecha creacion: 2018-06-14
  Fecha ultima modificacion: 2018-06-14
  Version: 0.1
  Licencia: GPL
*/

// Responsabilidad:
// Colaboracion: ninguna

#include "Caja.h"
#include <time.h>
#include <stdio.h>
#include <iostream>

Caja::Caja()
{
    cabTrans = nullptr;
    cabClientes = nullptr;
    cabClientesA = nullptr;
}

Caja::~Caja()
{
    Cliente *desplaza = cabClientes;
    Cliente *borrar;
    while (desplaza != nullptr)
    {
        borrar = desplaza;
        desplaza = desplaza->getSig();
        delete borrar;
        borrar = nullptr;
    }

    Transaccion *desplaza2 = cabTrans;
    Transaccion *borrar2;
    while (desplaza2 != nullptr)
    {
        borrar2 = desplaza2;
        desplaza2 = desplaza2->getSig();
        delete borrar2;
        borrar = nullptr;
    }
}

void Caja::interfazPPal()
{
    int opcion = 0;

    do
    {
        cout << ":::::::::::::::: MENU PRINCIPAL ::::::::::::::::" << endl;
        cout << "-------------- Caja Gran Colombia --------------" << endl;
        cout << "1: Nueva transaccion." << endl;
        cout << "2: Ingresar cliente a la cola." << endl;
        cout << "3: Mostrar Transacciones." << endl;
        cout << "4: Mostrar Clientes en Cola." << endl;
        cout << "5: Mostrar Clientes atendidos." << endl;
        cout << "6: Total de dinero por transaccion." << endl;
        cout << "7: Salir." << endl;

        cout << "Su opcion: " << endl;
        cin >> opcion;
        switch (opcion) {
            case 1:
                hacerTransaccion();
                break;
            case 2:
            {
                int id;
                cout << "Ingrese el id del cliente que llego al banco: ";
                cin >> id;
                llegoCliente(id);
                cout << endl;
                break;
            }
            case 3:
                imprimirTransacciones();
                break;
            case 4:
                imprimirClientesCola();
                break;
            case 5:
                imprimirClientesAtendidos();
                break;
            case 6:
                valorPorTransaccion();
                break;
            default:
                if (opcion != 7)
                    cout << endl << "=== Opcion no valida ===" << endl;
        }

    } while (opcion != 7);
}

//Metodos Caja

void Caja::hacerTransaccion()
{
    if(cantidadEnCola()>=1)
    {
    string tipo;
    int valor, numCuenta;
    bool valido = false;
    while(!valido)
    {
    cout << "Digite el tipo de transaccion que va a realizar (consignacion o retiro):";
    cin >> tipo;
    if(tipo == "consignacion" || tipo == "retiro")
    {
        valido = true;
    }
    }
    cout << "Digite el numero de cuenta:";
    cin >> numCuenta;
    cout << "Digite el valor:";
    cin >> valor;

    Transaccion *transAgregar = new Transaccion();
    transAgregar->setTipo(tipo);
    transAgregar->setNumCuenta(numCuenta);
    transAgregar->setValor(valor);
    transAgregar->setCliente(cabClientes->getId());

    Transaccion *desplaza = cabTrans;
    if(desplaza==nullptr)
    {
        cabTrans = transAgregar;
    }
    else
    {
        while(desplaza!= nullptr)
        {
            if(desplaza->getSig()== nullptr)
            {
                desplaza->setSig(transAgregar);
                transAgregar->setAnt(desplaza);
                desplaza= nullptr;
            }
            else
            {
                desplaza=desplaza->getSig();
            }
        }
    }
    atenderCliente();
    }
    else
    {
        cout << "No hay clientes en cola" << endl << endl;
    }
    cout << endl;
}

int Caja::cantidadTransacciones()
{
    Transaccion *desplaza = cabTrans;
    int cant = 0;
    while (desplaza != nullptr)
    {
        cant++;
        desplaza = desplaza->getSig();
    }
    return cant;
}

void Caja::imprimirTransacciones()
{
    if(cantidadTransacciones()==0)
    {
        cout << "No se han realizado transacciones." << endl << endl;
    }
    else
    {
    Transaccion *desplaza = cabTrans;
    cout << "Listado completo de Transacciones" << endl;
    cout << "Numero de Cuenta - Tipo - Valor" << endl;
    while (desplaza != nullptr)
    {
        cout << desplaza->getNumCuenta() << " - " << desplaza->getTipo() << " - " << desplaza->getValor() << endl;
        desplaza = desplaza->getSig();
    }
    cout << endl;
    cout << "Se han hecho " << cantidadTransacciones() << " transacciones." << endl << endl;
    }
}

void Caja::valorPorTransaccion()
{
    if(cantidadTransacciones()==0)
    {
        cout << "No se han realizado transacciones." << endl << endl;
    }
    else
    {
        int consignacion = 0;
        int retiro = 0;
        Transaccion *desplaza = cabTrans;
        cout << "Total de dinero por tipo de transaccion:" << endl;
        while (desplaza != nullptr)
        {
            if(desplaza->getTipo()=="consignacion")
            {
                consignacion += desplaza->getValor();
                desplaza = desplaza->getSig();
            }
            else
            {
                retiro += desplaza->getValor();
                desplaza = desplaza->getSig();
            }
        }
        cout << "Consignacion: " << consignacion << " pesos. " << endl;
        cout << "Retiro: " << retiro << " pesos. " << endl << endl;
    }
}


// Metodos Cola de clientes
int Caja::cantidadEnCola()
{
    Cliente *desplaza = cabClientes;
    int cant = 0;
    while (desplaza != nullptr)
    {
        cant++;
        desplaza = desplaza->getSig();
    }
    return cant;
}

int Caja::cantidadAtendidos()
{
    Cliente *desplaza = cabClientesA;
    int cant = 0;
    while (desplaza != nullptr)
    {
        cant++;
        desplaza = desplaza->getSig();
    }
    return cant;
}

void Caja::imprimirClientesCola()
{
    if(cantidadEnCola()==0)
    {
        cout << "No hay clientes en cola." << endl << endl;
    }
    else
    {
    Cliente *desplaza = cabClientes;
    cout << "Listado completo de clientes en cola" << endl;
    while (desplaza != nullptr)
    {
        cout << desplaza->getId() << " - ";
        desplaza = desplaza->getSig();
    }
    cout << endl;
    cout << "Hay " << cantidadEnCola() << " personas en cola." << endl << endl;
    }
}

void Caja::imprimirClientesAtendidos()
{
    if(cantidadAtendidos()==0)
    {
        cout << "No se han atendido clientes." << endl << endl;
    }
    else
    {
    Cliente *desplaza = cabClientesA;
    cout << "Listado completo de clientes diferentes atendidos" << endl;
    while (desplaza != nullptr)
    {
        cout << "El cliente con ID: " << desplaza->getId() << " hizo " << desplaza->getCantidadT() << " transacciones." << endl;
        desplaza = desplaza->getSig();
    }
    cout << endl;
    cout << "Se han atendido " << cantidadAtendidos() << " clientes diferentes." << endl << endl;
    }
}

void Caja::atenderCliente()
{
    if(cantidadEnCola()>=1)
    {
        agregarAtendidos();
    }

    Cliente *borrar = cabClientes;
    if(cabClientes == nullptr)
    {
        cout << "No hay clientes en cola." << endl << endl;
    }
    else if(cantidadEnCola()==1)
    {
        delete borrar;
        cabClientes = nullptr;
    }
    else
    {
        cabClientes->getSig()->setAnt(nullptr);
        cabClientes = cabClientes->getSig();
        delete borrar;
    }

}

void Caja::llegoCliente(int id)
{
    bool agregar = true;

    Cliente *nuevo = new Cliente();
    nuevo->setId(id);

    Cliente *desplaza = cabClientes;

    while(desplaza!=nullptr)
    {
        if(id == desplaza->getId())
        {
            agregar = false;
            desplaza = desplaza->getSig();
        }
        else
        {
            desplaza = desplaza->getSig();
        }
    }

    desplaza = cabClientes;

    if(agregar)
    {
    if(desplaza==nullptr)
    {
        cabClientes = nuevo;
    }
    else
    {
        while(desplaza!= nullptr)
        {
            if(desplaza->getSig()== nullptr)
            {
                desplaza->setSig(nuevo);
                nuevo->setAnt(desplaza);
                desplaza= nullptr;
            }
            else
            {
                desplaza=desplaza->getSig();
            }
        }
    }
    }
    else
    {
        cout << "Este cliente ya esta en la cola." << endl;
    }
}

void Caja::agregarAtendidos()
{
    bool agregar = true;
    Cliente *desplaza = cabClientesA;

    while(desplaza!= nullptr)
    {
        if(desplaza->getId() == cabClientes->getId())
        {
            agregar = false;
            desplaza->setCantidadT(desplaza->getCantidadT()+1);
            desplaza = nullptr;
        }
        else
        {
            desplaza=desplaza->getSig();
        }
    }
    if(agregar)
    {
        Cliente *nuevo = new Cliente();
        nuevo->setId(cabClientes->getId());

        Cliente *desplaza = cabClientesA;
        if(desplaza==nullptr)
        {
            cabClientesA = nuevo;
        }
        else
        {
            while(desplaza!= nullptr)
            {
                if(desplaza->getSig()== nullptr)
                {
                    desplaza->setSig(nuevo);
                    nuevo->setAnt(desplaza);
                    desplaza= nullptr;
                }
                else
                {
                    desplaza=desplaza->getSig();
                }
            }
        }
    }
}
