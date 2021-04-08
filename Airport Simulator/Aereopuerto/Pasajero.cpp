//
//  Pasajero.cpp
//  Aereopuerto
//
//  Created by Pablo on 24/11/19.
//  Copyright © 2019 Pablo Yamamoto Magaña. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include "Aereopuerto.h"
#include "Aereolinea.h"
#include "Vuelo.h"
#include "Pasajero.h"

using namespace std;

Pasajero::Pasajero(){
    
}

Pasajero::~Pasajero(){
    
}

string Pasajero::getNombre(){
    return d_Nombre;
}

int Pasajero::getTelefono(){
    return d_Telefono;
}

void Pasajero::setNombre(const string &Nombre){
    d_Nombre = Nombre;
}

void Pasajero::setTelefono(const int &Telefono){
    d_Telefono = Telefono;
}
