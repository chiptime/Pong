//
// Created by bruno on 19/06/18.
//

#include "bola.h"



void movimiento_Bola(Bola *bola, Pala pala, Pala pala1){

    mvprintw((int)bola->pos.y,(int)bola->pos.x,"(_)");

    bola->pos.x = bola->pos.x + bola->direccion.x*LESSVEL ;
    bola->pos.y = bola->pos.y + bola->direccion.y*LESSVEL ;

    if ( ((bola->pos.x == pala.pos.x)||(bola->pos.x+1 == pala.pos.x)||(bola->pos.x+2 == pala.pos.x)) && ((bola->pos.y == pala.pos.y)||(bola->pos.y == pala.pos.y+1)||(bola->pos.y == pala.pos.y+2)||(bola->pos.y == pala.pos.y+3)||(bola->pos.y == pala.pos.y+4)) ){
        bola->direccion.x *= -1;
        bola->direccion.y *= -1;
    }
    if ( ((bola->pos.x == pala1.pos.x)||(bola->pos.x+1 == pala1.pos.x)||(bola->pos.x+2 == pala1.pos.x)) && ((bola->pos.y == pala1.pos.y)||(bola->pos.y == pala1.pos.y+1)||(bola->pos.y == pala1.pos.y+2)||(bola->pos.y == pala1.pos.y+3)||(bola->pos.y == pala1.pos.y+4)) ){
        bola->direccion.x *= -1;
        bola->direccion.y *= -1;
    }
    if(bola->pos.x <= minc+1 || bola->pos.x >= maxc-3)
        bola->direccion.x *= -1;
    if(bola->pos.y <= minf+1 || bola->pos.y >= maxf-1)
        bola->direccion.y *= -1;
    refresh();
}