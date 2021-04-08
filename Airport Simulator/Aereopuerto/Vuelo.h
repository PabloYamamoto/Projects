//
//  Vuelo.h
//  Aereopuerto
//
//  Created by Pablo on 24/11/19.
//  Copyright © 2019 Pablo Yamamoto Magaña. All rights reserved.
//

#ifndef Vuelo_h
#define Vuelo_h
#include <iostream>
#include <string>
#include <sstream>
#include "Aereolinea.h"
#include "Aereopuerto.h"
#include "Pasajero.h"
const int COLUMNAS = 4;
const int FILAS = 30;
using namespace std;

class Vuelo {
private:
    int d_date;
    int d_hour;
    float d_price;
    string d_AirplaneModel;
    string d_FromTo;
    float d_distance;
    int d_crew;
    float d_fuel;
    Pasajero Asientos[FILAS][COLUMNAS];
    
    
    
    
public:
    Vuelo();
    ~Vuelo();
    
    int getDate();
    int getHour();
    float getPrice();
    string getAirplaneModel();
    string getFromTo();
    float getDistance();
    int getCrew();
    float getFuel();
    
    
    void setDaate(int const &Date);
    void setHour(int const &Hour);
    void setPrice(float const &Price);
    void setAirplaneModel(string const &AirplaneModel);
    void setFromTo(string const &FromTo);
    void setDistance(float const &Distance);
    void setCrew(int const &Crew);
    void setFuel(float const &Fuel);
    
    void CalculateFuel();
    
    
    
    
    
};

#endif /* Vuelo_h */
