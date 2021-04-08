//
//  Capitulos.hpp
//  ProyectoPOO
//
//  Copyright © 2020 Pablo Yamamoto Magaña. All rights reserved.
//

#ifndef Capitulos_hpp
#define Capitulos_hpp

#include <stdio.h>

#include"Video.hpp"
class Series;

class Capitulos : public Video {
    private:
    static int numCapsActivos;


    public:
        Capitulos(int ID = 0, string nombre = "None", double duracion = 0.0, int calificacion = 0, string genero = "None", string director = "None", string actor ="None");
        ~Capitulos();
        int getID();
        string getNombre();
        double getDuracion();
        int getCalificacion();
        string getGenero();
        string getDirector();
        string getActor();
        static int CapsActivos(); 


};



#endif /* Capitulos_hpp */
