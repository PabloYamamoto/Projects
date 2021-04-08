//
//  main.cpp
//  ProyectoPOO
//
//  Copyright © 2020 Pablo Yamamoto Magaña. All rights reserved.
//

#include <iostream>
#include "Peliculas.hpp"
#include "Series.hpp"
#include "AdminVideo.hpp"

using namespace std;

/* FUNCIÓN ESPECIAL !!!!!!

   ESTA FUNCIÓN NOS PERMITE VER CUANTOS OBJETOS DE CADA TIPO TENEMOS ACTIVOS
   CADA VEZ QUE SE CREA UN OBJETO DE CUALQUIER TIPO, SE INCREMENTA UN CONTADOR ESTÁTICO
   CADA VEZ QUE SE DESTRUYE UN OBJETO DE CUALQUIER TIPO, SE DECEMENTA EL CONTADOR
   ESTO LO LOGRAMOS GRACIAS A LOS CONSTRUCTORES Y DESTRUCTORES
   PODRIAMOS LLAMAR A LA FUNCIÓN EN CUALQUIER PARTE DEL MAIN Y VER CUANTOS OBJETOS TENEMOS
   YO DECIDÍ PONERLA ANTES DE QUE SE LIBERE TODA LA MEMORIA, ANTES DE TERMINAR LA EJECUCIÓN DEL PROGRAMA Y DESPUÉS DE QUE ESTA SE LIBERA

    AL FINAL DEL PROGRAMA APARECEN LOS CONTADORES EN 0´S LO QUE INDICA QUE LA MEMORIA SE LIBERO CORRECTAMENTE
 
 */

//===========================================================================

void muestra_SP_Activas(){
    cout << "========================================================================" << endl;
    cout << "Series Activas: " << Series::SeriesActivas() << endl;
    cout << "Películas Activas: " << Peliculas::PelisActivas()  << endl;
    cout << "Capítulos Activos: " << Capitulos::CapsActivos()   << endl;
    cout << "========================================================================" << endl;
    cout << endl;
}
//===========================================================================



int main() {
    
    //===========================================================================
    //APARTADO PARA CREAR LAS INSTANCIAS DE PELÍCULAS, SERIES Y CAPITULOS
    Peliculas P1(1, "Batman", 2.35, 5, "Acción", "Nol", "Patrick");
    Peliculas P2(2, "Batman 2", 2.65, 7, "Acción", "Nol", "Patrick");
    Peliculas P3(3, "Batman 3", 2.55, 2, "Acción", "Nol", "Patrick");
    Peliculas P4(4, "Amor", 2.39, 1, "Amor", "Nol", "Patrick");
    Peliculas P5(60, "Spiderman", 2.90, 10, "Aventura");
    
    Series S1(1, "13ReasonsWhy", 23.5, 10, "Drama");
    Series S2(2, "Dark");
    Series S3(3, "The Society");
    Series S4(4, "WhatsUpDanger?");
    Series S5(5, "The Office", 10.30, 10);
    
    Capitulos C1(1, "Piloto", 20.90, 10);
    Capitulos C2(2, "Smile", 9.00, 5);
    Capitulos C3(3, "Hello", 20.22, 10);
    
    Capitulos C1_TO(1, "Piloto", 2.90, 10, "Acción");
    Capitulos C2_TO(2, "Mellow", 202.02, 10, "Drama");
    Capitulos C3_TO(3, "Brad", 292.00, 10, "Drama");
    Capitulos C4_TO(4, "Miller and Brad", 292.02, 0, "Acción");
    //===========================================================================

    
    //===========================================================================
    //APARTADO PARA CREAR LOS APUNTADORES
    Peliculas *P1_ptr = new Peliculas(P1);
    Peliculas *P2_ptr = new Peliculas(P2);
    Peliculas *P3_ptr = new Peliculas(P3);
    Peliculas *P4_ptr = new Peliculas(P4);
    Peliculas *P5_ptr = new Peliculas(P5);
    
    Series *S1_ptr = new Series(S1);
    Series *S2_ptr = new Series(S2);
    Series *S3_ptr = new Series(S3);
    Series *S4_ptr = new Series(S4);
    Series *S5_ptr = new Series(S5);
    
    Capitulos *C1_ptr = new Capitulos(C1);
    Capitulos *C2_ptr = new Capitulos(C2);
    Capitulos *C3_ptr = new Capitulos(C3);
    
    Capitulos *C1_TO_ptr = new Capitulos(C1_TO);
    Capitulos *C2_TO_ptr = new Capitulos(C2_TO);
    Capitulos *C3_TO_ptr = new Capitulos(C3_TO);
    Capitulos *C4_TO_ptr = new Capitulos(C4_TO);

    //===========================================================================

    //===========================================================================
    //APARTADO PARA AÑADIR LAS PELÍCULAS, SERIES Y CAPITULOS A SUS RESPECTIVOS VECTORES
    AdminVideo AV;
    
    AV.AñadePelicula(P1_ptr);
    AV.AñadePelicula(P2_ptr);
    AV.AñadePelicula(P3_ptr);
    AV.AñadePelicula(P4_ptr);
    AV.AñadePelicula(P5_ptr);
    
    AV.AñadeSeries(S1_ptr);
    AV.AñadeSeries(S2_ptr);
    AV.AñadeSeries(S3_ptr);
    AV.AñadeSeries(S4_ptr);
    AV.AñadeSeries(S5_ptr);

    
    S1_ptr->AñadeCapis(C1_ptr);
    S1_ptr->AñadeCapis(C2_ptr);
    S1_ptr->AñadeCapis(C3_ptr);
    
    
    S5_ptr->AñadeCapis(C1_TO_ptr);
    S5_ptr->AñadeCapis(C2_TO_ptr);
    S5_ptr->AñadeCapis(C3_TO_ptr);
    S5_ptr->AñadeCapis(C4_TO_ptr);

    //===========================================================================
    
    
    
    
    //===========================================================================
    //APARTADO PARA LAS DIFERENTES FUNCIONES QUE REALIZA EL PROGRAMA
    
    AV.ImprimeGenero("Drama"); //IMPRIME SERIES Y PELICULAS CON EL GÉNERO QUE SE INTRODUZCA COMO PARÁMETRO
    
    AV.ImprimeSeries(); //IMPRIME LAS SERIES DISPONIBLES
    
    
    AV.ImprimeCapitulosdeSerie(S1_ptr); //IMPRIME LOS CAPITULOS DE UNA SERIE EN PARTICULAR, TOMA UN APUNTADOR DE TIPO SERIE COMO PARÁMETRO
    
    AV.ImprimeCalificación(10); 
    
    //===========================================================================

    
    
    //===========================================================================
    muestra_SP_Activas(); //FUNCIÓN ESPECIAL!!!!!
    //===========================================================================
    
    
    
    //===========================================================================
    //APARTADO PARA LIBERAR LA MEMORIA DINÁMICA, HAY QUE SER UN PROGRAMADOR RESPONSABLE
    for(auto *Pelis : AV.getListaPeliculas()){
        delete Pelis;
    }
    
    for(auto *Series : AV.getListaSeries()){
        for(auto *Caps : Series->getListCaps()){
            delete Caps;
        }
        delete Series;
      }
    //===========================================================================

    
    
    //===========================================================================
    muestra_SP_Activas();//FUNCIÓN ESPECIAL !!!!!
    //===========================================================================


    return 100; //  AL TERMINAR LA FUNCIÓN MAIN SE REGRESA UN 100 PORQUE ESA ES LA CALIFICACIÓN QUE ESPERO SACAR CON ESTE PROYECTO ;)

}


