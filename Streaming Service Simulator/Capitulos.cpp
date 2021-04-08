//
//  Capitulos.cpp
//  ProyectoPOO
//
//  Copyright © 2020 Pablo Yamamoto Magaña. All rights reserved.
//

#include "Capitulos.hpp"

int Capitulos::numCapsActivos = 0;

Capitulos::Capitulos(int ID, string nombre, double duracion, int calificacion, string genero, string director, string actor) : Video(ID, nombre, duracion,calificacion, genero, director, actor){
    numCapsActivos++;
}


Capitulos::~Capitulos(){
    numCapsActivos--;
}

int Capitulos::getID(){
    return ID;
}

string Capitulos::getNombre(){
    return nombre;
}

double Capitulos::getDuracion(){
    return duracion;
}

int Capitulos::getCalificacion(){
    return calificacion;
}

string Capitulos::getGenero(){
    return genero;
}

string Capitulos::getDirector(){
    return director;
}

string Capitulos::getActor(){
    return actor;
}

int Capitulos::CapsActivos(){
    return numCapsActivos;
}
