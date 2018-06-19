//
// Created by bruno on 19/06/18.
//

#ifndef BATTLECITY_GLOBAL_H
#define BATTLECITY_GLOBAL_H


#include <ncurses.h>

#define fila  30
#define columna 100

#define minf 0
#define minc 0
#define maxf (fila-1)   //fila de matriz
#define maxc (columna-1)//columna de matriz


#define LESSVEL 0.5


//////////////////// Movil
typedef struct{
    double x;
    double y;
}Movil;
//////////////////// Bola
typedef struct{
    Movil pos;
    Movil direccion;
    double vel;
}Bola;
//////////////////// Palas
typedef struct{
    Movil pos;
}Pala;




#endif //BATTLECITY_GLOBAL_H
