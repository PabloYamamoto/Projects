//
//  Video.cpp
//  ProyectoPOO
//
//  Copyright © 2020 Pablo Yamamoto Magaña. All rights reserved.
//

#include "Video.hpp"





Video::Video(int ID, string nombre, double duracion, int calificacion, string genero, string director, string actor) : ID(ID), nombre(nombre), duracion(duracion), calificacion(calificacion), genero(genero), director(director), actor(actor) {

}

Video::~Video(){}

void Video::setId(int ID){
    this->ID = ID;
}

void Video::setNombre(string nombre){
    this->nombre = nombre;
}

void Video::setDuracion(double duracion){
    this->duracion=duracion;
}

void Video::setCalificacion(int calificacion){
    this->calificacion = calificacion;
}

void Video::setGenero(string genero){
    this->genero = genero;
}

void Video::setDirector(string director){
    this->director = director;
}

void Video::setActor(string actor){
    this->actor = actor;
}
