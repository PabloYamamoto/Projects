//
//  Vuelo.cpp
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

Vuelo::Vuelo(){
    
}

Vuelo::~Vuelo(){
    
}


int Vuelo::getDate(){
    return d_date;
}

int Vuelo::getHour(){
    return d_hour;
}

float Vuelo::getPrice(){
    return d_price;
}

string Vuelo::getAirplaneModel(){
    return d_AirplaneModel;
}

string Vuelo::getFromTo(){
    return d_FromTo;
}

float Vuelo::getDistance(){
    return d_distance;
}

int Vuelo::getCrew(){
    return d_crew;
}

float Vuelo::getFuel(){
    return d_fuel;
}


void Vuelo::setDaate(const int &Date){
    d_date = Date;
}

void Vuelo::setHour(const int &Hour){
    d_hour = Hour;
}

void Vuelo::setPrice(const float &Price){
    d_price = Price;
}

void Vuelo::setAirplaneModel(const string &AirplaneModel){
    d_AirplaneModel = AirplaneModel;
}

void Vuelo::setFromTo(const string &FromTo){
    d_FromTo = FromTo;
}

void Vuelo::setDistance(const float &Distance){
    d_distance = Distance;
}

void Vuelo::setCrew(const int &Crew){
    d_crew = Crew;
}

void Vuelo::setFuel(const float &Fuel){
    d_fuel = Fuel;
}


void Vuelo::CalculateFuel(){
    
    cout << "Introduce el Destino: " << endl;
    cin >> d_FromTo;
    setFromTo(d_FromTo);
    cout << "Introduce la Distancia del Destino: " << endl;
    cin >> d_distance;
    setDistance(d_distance);
    
    d_fuel = (d_distance*1200) / 100;
    
    setFuel(d_fuel);
    
    
    cout << "El combustible requerido para viajar a: " << getFromTo() << " es de: " << getFuel() << " galones." << endl;
    

}
