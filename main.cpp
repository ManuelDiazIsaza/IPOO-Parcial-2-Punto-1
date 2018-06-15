/*
  Archivo: main.cpp
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
#include "Caja.h"
using namespace std;

int main()
{
    Caja *caja = new Caja();

    caja->interfazPPal();

    return 0;
}