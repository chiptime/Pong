#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <locale.h>
////////////////////local
#include "global.h"
#include "map/map.h"
#include "interface/ncurses/ncurses.h"
#include "movil/pala/pala.h"
#include "movil/bola/bola.h"
#include "keys/keys.h"


int main() {
    int arrow = 0;
    Bola bola = {.pos = {.x = 30, .y = 8}, .direccion = {.x = 1 , .y = 1} };
    Pala pala = {20, 10};
    Pala pala1 = {80, 10};

    setlocale(LC_ALL,"");
    iniciar_Curses();

    while(teclas(&pala, &pala1, arrow) != KEY_BREAK){
        clear();
        dibujar_Marco();
        palaA(pala);
        palaB(pala1);
        movimiento_Bola(&bola,pala,pala1);
        usleep(20000*1.2);
    }
    finalizar_Curses();
    return 0;
}




