//
//  Video.hpp
//  ProyectoPOO
//
//  Copyright © 2020 Pablo Yamamoto Magaña. All rights reserved.
//

#ifndef Video_hpp
#define Video_hpp
#include<string>
#include<vector>
using namespace std;
#include <stdio.h>

class Video{
    protected:
        int ID;
        string nombre;
        double duracion;
        int calificacion;
        string genero;
        string director;
        string actor;

    public:

        Video() = default;
    Video(int ID = 0, string nombre = "None", double duracion = 0.0, int calificacion = 0, string genero = "None", string director = "None", string actor ="None");
        ~Video();

        virtual int getID() = 0;  // MÉTODOS VIRTUALES PUROS
        virtual string getNombre() = 0;
        virtual double getDuracion() = 0;
        virtual int getCalificacion() = 0;
        virtual string getGenero() = 0;
        virtual string getDirector() = 0;
        virtual string getActor() = 0;

        void setId(int ID);
        void setNombre(string nombre);
        void setDuracion(double duracion);
        void setCalificacion(int calificacion);
        void setGenero(string genero);
        void setDirector(string director);
        void setActor(string actor);

};


#endif /* Video_hpp */
