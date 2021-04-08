//
//  AdministradorVideo.hpp
//  ProyectoPOO
//
//  Copyright © 2020 Pablo Yamamoto Magaña. All rights reserved.
//

#ifndef AdminVideo_hpp
#define AdminVideo_hpp

#include <stdio.h>

#include <iostream>
#include <vector>
#include "Peliculas.hpp"
#include "Series.hpp"
#include "Capitulos.hpp"
using namespace std;


class AdminVideo{
    private:
        vector<Peliculas*> ListaPeliculas;
        vector<Series*> ListaSeries;
    public:
        AdminVideo() = default;
        AdminVideo(vector<Peliculas*> ListaPeliculas, vector<Series*> ListaSeries);
       
        vector<Peliculas*> getListaPeliculas();
        vector<Series*> getListaSeries();

        void AñadePelicula(Peliculas *p);
        void AñadeSeries(Series *s);
    
        void ImprimeGenero(string genero);
        void ImprimeSeries();
    
        void ImprimeCapitulosdeSerie(Series* Series_ptr);
        void ImprimeCalificación(int calificación); 


};

#endif /* AdminVideo_hpp */
