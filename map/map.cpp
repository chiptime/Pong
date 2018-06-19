//
// Created by bruno on 18/06/18.
//

#include "map.h"


//////////////// Dibujar marco
void dibujar_Marco(){//char matriz[fila][columna]){
    for(int f=0; f<fila;f++) {
        for(int c=0;c<columna;c++) {
            if(((f) == minf) || ((f) == maxf)){
                if( ((f==minf)&&(c==minc)) || ((f==minf)&&(c==maxc)) || ((f==maxf)&&(c==minc)) || ((f==maxf)&&(c==maxc)) )
                    printw("█");
                else printw("█");
            }
            else
            if( (c<(minc+1)) ||(c>(maxc-1)) )
                printw("█");
            else
                printw(" ");
        }
        printw("\n");
    }
    refresh();
}
