//
//  Aereolinea.cpp
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

Aereolinea::Aereolinea(){
    
}

Aereolinea::~Aereolinea(){
    
}

string Aereolinea::getBoardingCity(){
    return d_BoardingCity;
}

string Aereolinea::getShortName(){
    return d_ShortName;
}

int Aereolinea::getIncome(){
    return d_Income; 
}

string Aereolinea::getFullName(){
    return d_FullName;
}

void Aereolinea::setBoardingCity(const string &BoardingCity){
    d_BoardingCity = BoardingCity;
}

void Aereolinea::setShortName(const string &ShortName){
    d_ShortName = ShortName;
}

void Aereolinea::setIncome(const int &Income){
    d_Income = Income;
}

void Aereolinea::setFullName(const string &FullName){
    d_FullName = FullName;
}

void Aereolinea::UpdateAirlines(){
    
for (int i = 0; i < NUM_AIRLINES;i++){
    cout << "Dame la clave de la Aereolinea";
    cin >> d_ShortName;
    setShortName(d_ShortName);
    
    
    cout << "Dame el nombre de la Aereolinea";
    cin >> d_FullName;
    setFullName(d_FullName);
        
    }
    
}

void Aereolinea::ScheduleFlight(){
    
    
}
