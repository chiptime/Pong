//
// Created by bruno on 19/06/18.
//

#include "ncurses.h"
#include "../../global.h"


void iniciar_Curses(){
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);
    halfdelay(1);
    noecho();
    cbreak();
    nodelay(stdscr,true);
}
void finalizar_Curses(){
    curs_set(1);
    endwin();
}