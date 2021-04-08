//
//  AdministradorVideo.cpp
//  ProyectoPOO
//
//  Copyright © 2020 Pablo Yamamoto Magaña. All rights reserved.
//

#include "AdminVideo.hpp"

AdminVideo::AdminVideo(vector<Peliculas*> ListaPeliculas, vector<Series*> ListaSeries) : ListaPeliculas(ListaPeliculas), ListaSeries(ListaSeries){
    
}

void AdminVideo::AñadeSeries(Series *s){
    ListaSeries.push_back(s);
}

void AdminVideo::AñadePelicula(Peliculas *p){
    ListaPeliculas.push_back(p); 
}

void AdminVideo::ImprimeGenero(string genero){
    cout << endl;
    cout << "========================================================================" << endl;
    cout << endl;
    cout << "Películas con el género: " << genero << endl;
    cout << endl;
    int num = 1;
    int size = 0;
    for(vector<Peliculas*>::iterator it = ListaPeliculas.begin(); it != ListaPeliculas.end(); it++){
        if(genero != (*it)->getGenero()){
            size++;
            if(size == ListaPeliculas.size()){
                       cout << "Lo sentimos, no hay ninguna película disponible con ese género" << endl;
                       break;
                   }
        }
       
            
        else if(genero == (*it)->getGenero()){
            cout << num << " " << (*it)->getNombre() << endl;
            }
        else{
            continue;
        }
     
    }
    
    int num2 = 1;
    int size2 = 0;
    cout << endl;
    cout << "========================================================================" << endl;
    cout << endl;
    cout << "Series con el género: " << genero << endl;
    cout << endl;
    for(vector<Series*>::iterator it = ListaSeries.begin(); it != ListaSeries.end(); it++){
       if(genero != (*it)->getGenero()){
                  size2++;
                  if(size2 == ListaSeries.size()){
                      cout << "Lo sentimos, no hay ninguna Serie disponible con ese género" << endl;
                      break;
                  }
        }
             
                  
        else if(genero == (*it)->getGenero()){
            cout << num2 << " " << (*it)->getNombre() << endl;
        }
        else{
            continue;
        }
     
    }
    

    
    
}


void AdminVideo::ImprimeSeries(){
    cout << endl;
    cout << "========================================================================" << endl;
    cout << endl;
    cout << "Estas son las series disponibles:  "  << endl;
    cout << endl; 
    int num = 1;
    for(vector<Series*>::iterator it = ListaSeries.begin(); it != ListaSeries.end(); it++){
        cout << num << " " << (*it)->getNombre() << endl;
        num++;
    }
    cout << endl;
    cout << endl; 
    
    
    
    
    
}

vector<Series*> AdminVideo::getListaSeries(){
    return ListaSeries; 
}
vector<Peliculas*> AdminVideo::getListaPeliculas(){
    return ListaPeliculas; 
}



void AdminVideo::ImprimeCapitulosdeSerie(Series *Series_ptr){
    
    cout << endl;
    cout << "========================================================================" << endl;
    cout << "Los capitulos disponibles de ==== " << Series_ptr->getNombre() << " === son:  " << endl;
    cout << endl;
    int index = 1;
    for(Capitulos* Caps: Series_ptr->getListCaps()){
        if(Series_ptr->getListCaps().size() == 0){
            cout << "En estos momentos, esta serie no cuenta con capitulos disponibles" << endl;
            cout << "Te avisaremos cuando haya alguno disponible" << endl;
        }
        else{
            cout << index << " " << Caps->getNombre() << endl;
            index++;
        }
    }
    cout << endl;
    cout << endl;
}


void AdminVideo::ImprimeCalificación(int calificación){
    cout << endl;
    cout << "========================================================================" << endl;
    cout << "Las Películas con la calificación: " << calificación  << endl;
    cout << endl;
    int index = 1;
    int size = 0;
    for(vector<Peliculas*>::iterator it = ListaPeliculas.begin(); it != ListaPeliculas.end(); it++){
        if(calificación == (*it)->getCalificacion()){
            cout << index << " " << (*it)->getNombre() << endl;
            index++;
        }
        else if(calificación != (*it)->getCalificacion()){
            size++;
            if(size == ListaPeliculas.size()){
                cout << "No hay Películas con esa calificación actualmente" << endl;
                cout << endl;
            }
        }
        
    }
    
    
    int none = 0;
    for(auto Serie : ListaSeries){
        if(Serie->getCalificacion() != calificación){
            none++;
            if(none == ListaSeries.size()){
                cout << endl;
                cout << "========================================================================" << endl;
                cout << "Lo sentimos, no hay ninguna Serie disponible con esa calificación " << endl;
                cout << endl;
                break;
            }
        }
        else{
        
            cout << endl;
            cout << "========================================================================" << endl;
            cout << "La Serie: " << Serie->getNombre() << " cuenta con " << Serie->getCalificacion() << " de califcación " << endl;
            cout << endl;
            int none2 = 0;
            for(auto *Capitulo : Serie->getListCaps()){
                if(calificación != Capitulo->getCalificacion()){
                    none2++;
                    if(none2 == Serie->getListCaps().size()){
                        cout << endl;
                        cout << "Pero Lamentablemente, no cuenta con ningún capítulo con esa calificación "<< endl;
                        cout << endl;
                        break;

                    }
                    
                                   
               }
                else if (calificación == Capitulo->getCalificacion()){
                    cout << "El Capitulo " << Capitulo->getID()  << " === " << Capitulo->getNombre() << " cuenta con un " << Capitulo->getCalificacion() << " de calificación" << endl;
                }

            }
            cout << endl; 
    
    }
    
}
    cout << endl;
}
