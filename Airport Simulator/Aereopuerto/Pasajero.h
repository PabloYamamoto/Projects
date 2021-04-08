//
//  Pasajero.h
//  Aereopuerto
//
//  Created by Pablo on 24/11/19.
//  Copyright © 2019 Pablo Yamamoto Magaña. All rights reserved.
//

#ifndef Pasajero_h
#define Pasajero_h
#include <iostream>
#include <string>
#include <sstream>
#include "Aereopuerto.h"
#include "Aereolinea.h"
#include "Vuelo.h"

using namespace std;

class Pasajero{
private:
    string d_Nombre;
    int d_Telefono;
    
public:
    Pasajero();
    ~Pasajero();
    
    string getNombre();
    int getTelefono();
    
    void setNombre(string const &Nombre);
    void setTelefono(int const &Telefono); 
    

};




#endif /* Pasajero_h */
