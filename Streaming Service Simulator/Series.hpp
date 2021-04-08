//
//  Series.hpp
//  ProyectoPOO
//
//  Copyright © 2020 Pablo Yamamoto Magaña. All rights reserved.





//

#ifndef Series_hpp
#define Series_hpp

#include <stdio.h>

#include "Video.hpp"
#include <vector>

class Capitulos;
class Series : public Video {
    
    private:
        vector<Capitulos*> ListaCap;
        static int numofSeries; 

    public:

        Series(int ID = 0, string nombre = "None", double duracion = 0.0, int calificacion = 0, string genero = "None", string director = "None", string actor ="None");
        ~Series();
        
        int getID();
        string getNombre();
        double getDuracion();
        int getCalificacion();
        string getGenero();
        string getDirector();
        string getActor();

        void AñadeCapis(Capitulos* Cap);
        static int SeriesActivas();
        vector<Capitulos*> getListCaps(); 

};



#endif /* Series_hpp */
