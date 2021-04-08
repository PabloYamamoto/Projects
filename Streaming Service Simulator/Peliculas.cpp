//
//  Peliculas.cpp
//  ProyectoPOO
//
//  Copyright © 2020 Pablo Yamamoto Magaña. All rights reserved.
//

#include "Peliculas.hpp"

int Peliculas::NumPelis = 0;

Peliculas::Peliculas(int ID, string nombre, double duracion, int calificacion, string genero, string director, string actor) : Video(ID, nombre, duracion,calificacion, genero, director, actor){
   
    NumPelis++;
}

Peliculas::~Peliculas(){
 
    NumPelis--; 
}


int Peliculas::getID(){
    return ID;
}

string Peliculas::getNombre(){
    return nombre;
}

double Peliculas::getDuracion(){
    return duracion;
}

int Peliculas::getCalificacion(){
    return calificacion;
}

string Peliculas::getGenero(){
    return genero;
}

string Peliculas::getDirector(){
    return director;
}

string Peliculas::getActor(){
    return actor;
}

int Peliculas::PelisActivas(){
    return NumPelis; 
}
