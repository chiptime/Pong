//
// Created by bruno on 19/06/18.
//

#include "pala.h"

void printPala(Pala pala) {
    for (int i = 0; i < 5; ++i) {
        mvprintw((int)pala.pos.y+i,   (int)pala.pos.x,"█");
    }
    refresh();
}
