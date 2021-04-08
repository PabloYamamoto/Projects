//
//  Aereopuerto.cpp
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

Aereopuerto::Aereopuerto(){
    cout << "Introduzca la fecha: " << endl;
    cin >> d_Date;
    setDate(d_Date);
    startOperations(d_Date);
    
    //Construir Los atributos que son listas de la clase Aereopuerto, Aereolinea y Vuelo
    
    
}

Aereopuerto::~Aereopuerto(){
    
    
}


string Aereopuerto::getId(){
    return d_Id;
}

string Aereopuerto::getDate(){
    return d_Date;
}

string Aereopuerto::getCity(){
    return d_City;
}

string Aereopuerto::getCountry(){
    return d_Country;
}


void Aereopuerto::setId(const string &Id){
    d_Id = Id;
}

void Aereopuerto::setDate(const string &Date){
    d_Date = Date;
}

void Aereopuerto::setCity(const string &City){
    d_City = City;
}


void Aereopuerto::setCountry(const string &Country){
    d_Country = Country;
}


void Aereopuerto::startOperations(string d_Date){
   
    
    cout << "Introduzca el ID del Aereopuerto: "; cin >> d_Id;
    cout << "" << endl;
   
   
    cout << "Introduzca la Ciudad de Operación: "; cin >> d_City;
    cout << "" << endl;
    
    cout << "Introduzca el País de Operación: "; cin >> d_Country;
    cout << "" << endl;
    
    setId(d_Id);
    setCity(d_City);
    setCountry(d_Country);

    for (int i=0;i<NUM_AIRLINES; i++){
        ListadeAerelonieas[i].setBoardingCity(d_City);
    
    
}
}

void Aereopuerto::printAllFlights(){
    cout << "Los vuelos programados para: " << getDate() << "son: " << endl;
    
    
}


void Aereopuerto::closeOperations(){
    cout << "El número total de Vuelos fueron: " << d_TotalTransactions << endl;
    cout << "El número total de Ingresos fueron: " << d_TotalDailyIncome << endl; 
}

