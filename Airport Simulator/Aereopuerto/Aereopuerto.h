//
//  Aereopuerto.h
//  Aereopuerto
//
//  Created by Pablo on 24/11/19.
//  Copyright © 2019 Pablo Yamamoto Magaña. All rights reserved.
//

#ifndef Aereopuerto_h
#define Aereopuerto_h
#include <iostream>
#include <string>
#include <sstream>
#include "Aereolinea.h"
#include "Vuelo.h"
#include "Pasajero.h"
const int NUM_AIRLINES = 3;
using namespace std;

class Aereopuerto{
private :
    string d_Id;
    string d_Date;
    string d_City;
    string d_Country;
    int d_TotalTransactions;
    int d_TotalDailyIncome;
    Aereolinea ListadeAerelonieas[NUM_AIRLINES];
    

public :
    Aereopuerto();
    ~Aereopuerto();
    
    string getId();
    string getDate();
    string getCity();
    string getCountry();
    
    void setId(string const &Id);
    void setDate(string const &Date);
    void setCity(string const &City);
    void setCountry(string const &Country);
    
    
    void startOperations(string d_Date);
    void printAllFlights();
    void closeOperations();
    
    
};


#endif /* Aereopuerto_h */
