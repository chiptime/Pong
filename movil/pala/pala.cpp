//
// Created by bruno on 19/06/18.
//

#include "pala.h"


void palaA(Pala pala) {
    mvprintw((int)pala.pos.y,   (int)pala.pos.x,"█");
    mvprintw((int)pala.pos.y+1, (int)pala.pos.x,"█");
    mvprintw((int)pala.pos.y+2, (int)pala.pos.x,"█");
    mvprintw((int)pala.pos.y+3, (int)pala.pos.x,"█");
    mvprintw((int)pala.pos.y+4, (int)pala.pos.x,"█");
    refresh();
}
void palaB(Pala pala) {
    mvprintw((int)pala.pos.y,   (int)pala.pos.x,"█");
    mvprintw((int)pala.pos.y+1, (int)pala.pos.x,"█");
    mvprintw((int)pala.pos.y+2, (int)pala.pos.x,"█");
    mvprintw((int)pala.pos.y+3, (int)pala.pos.x,"█");
    mvprintw((int)pala.pos.y+4, (int)pala.pos.x,"█");
    refresh();
}