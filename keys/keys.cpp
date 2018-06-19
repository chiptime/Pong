//
// Created by bruno on 19/06/18.
//

#include "keys.h"

int teclas(Pala *palaN, Pala *pala1N, int key){
    switch(getch()){
        case KEY_UP:
            if(pala1N->pos.y   >= minf+2)
                pala1N->pos.y -= 1;
            break;
        case KEY_DOWN:
            if(pala1N->pos.y+4 <= maxf-2)
                pala1N->pos.y += 1;
            break;
        case 'w':
            if(palaN->pos.y    >= minf+2)
                palaN->pos.y  -= 1;
            break;
        case 's':
            if(palaN->pos.y+4  <= maxf-2)
                palaN->pos.y  += 1;
            break;
        case 'p':
            getchar();
            break;
        default:
            break;
    }
    return key;
}