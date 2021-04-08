//
//  Aereolinea.h
//  Aereopuerto
//
//  Created by Pablo on 24/11/19.
//  Copyright © 2019 Pablo Yamamoto Magaña. All rights reserved.
//

#ifndef Aereolinea_h
#define Aereolinea_h
#include <iostream>
#include <string>
#include <sstream>
#include "Aereopuerto.h"
#include "Vuelo.h"
#include "Pasajero.h"
const int NUM_FLIGHTS = 5;
using namespace std;

class Aereolinea{
private:
    string d_BoardingCity;
    string d_ShortName;
    string d_FullName;
    int d_Income;
    vector<Vuelo> ListadeVuelos(NUM_FLIGHTS);
    

public:
    Aereolinea();
    ~Aereolinea();
    
    string getBoardingCity();
    string getShortName();
    string getFullName();
    int getIncome();
    
    void setBoardingCity(string const &BoardingCity);
    void setShortName(string const &ShortName);
    void setIncome(int const &Income);
    void setFullName(string const &FullName); 
    
    void UpdateAirlines();
    void ScheduleFlight();
    int CurrentIncome();
    int CloseOperations();
    
    int RegresaVuelo();
    
    
    
};


#endif /* Aereolinea_h */
