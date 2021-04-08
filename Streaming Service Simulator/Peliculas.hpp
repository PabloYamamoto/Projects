//
//  Peliculas.hpp
//  ProyectoPOO
//
//  Copyright © 2020 Pablo Yamamoto Magaña. All rights reserved.
//

#ifndef Peliculas_hpp
#define Peliculas_hpp
#include "Video.hpp"
#include <stdio.h>

class Peliculas : public Video{
    private:
    static int NumPelis;
     
    

    public:
        Peliculas(int ID = 0, string nombre = "None", double duracion = 0.0, int calificacion = 0, string genero = "None", string director = "None", string actor ="None");
        int getID();
        ~Peliculas();
        string getNombre();
        double getDuracion();
        int getCalificacion();
        string getGenero();
        string getDirector();
        string getActor();
        

        static int PelisActivas(); 
         
};


#endif /* Peliculas_hpp */
