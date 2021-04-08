//
//  Series.cpp
//  ProyectoPOO
//
//  Copyright © 2020 Pablo Yamamoto Magaña. All rights reserved.
//

#include "Series.hpp"

int Series::numofSeries = 0;


Series::Series(int ID, string nombre, double duracion, int calificacion, string genero, string director, string actor) : Video(ID, nombre, duracion,calificacion, genero, director, actor) {
    numofSeries++;
    
}

Series::~Series(){
    numofSeries--; 
}

int Series::getID(){
    return ID;
}

string Series::getNombre(){
    return nombre;
}

double Series::getDuracion(){
    return duracion;
}

int Series::getCalificacion(){
    return calificacion;
}

string Series::getGenero(){
    return genero;
}

string Series::getDirector(){
    return director;
}

string Series::getActor(){
    return actor;
}



void Series::AñadeCapis(Capitulos* Cap){
    ListaCap.push_back(Cap);
}


int Series::SeriesActivas(){
    return numofSeries;
}

vector<Capitulos*> Series::getListCaps(){
    return ListaCap; 
}
