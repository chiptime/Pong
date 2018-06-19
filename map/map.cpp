//
// Created by bruno on 18/06/18.
//

#include "map.h"

//////////////// Dibujar marco
void dibujar_Marco(){
    for(int f=0; f<fila;f++) {
        for(int c=0;c<columna;c++)
            if((f) == minf || (f) == maxf)
                printw("█");
            else
            if((c) <minc+1 || (c) >  maxc-1)
                printw("█");
            else
                printw(" ");
        printw("\n");
    }
    refresh();
}
