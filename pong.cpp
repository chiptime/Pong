#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//for getch

#include <unistd.h>
#include <locale.h>
#include <ncurses.h>

#define fila  30
#define columna 100

#define minf 0
#define minc 0
#define maxf (fila-1)
#define maxc (columna-1)

#define LESSVEL 0.5

char matriz[fila][columna];
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


void dibujar_Marco(char matriz[fila][columna]);


void movimiento_Bola(Bola bola, Bola *bola_nuevo, Pala pala, Pala pala1){

    mvprintw((int)bola.pos.y,(int)bola.pos.x,"(_)");
    mvprintw(10,10, "pos y = %i, posx = %i ",(int)bola.pos.y,(int)bola.pos.x);

    bola_nuevo->pos.x = bola.pos.x + bola.direccion.x*LESSVEL  ;
    bola_nuevo->pos.y = bola.pos.y + bola.direccion.y*LESSVEL  ;


    if ( ((bola.pos.x == pala.pos.x)||(bola.pos.x+1 == pala.pos.x)||(bola.pos.x+2 == pala.pos.x)) && ((bola.pos.y == pala.pos.y)||(bola.pos.y == pala.pos.y+1)||(bola.pos.y == pala.pos.y+2)||(bola.pos.y == pala.pos.y+3)||(bola.pos.y == pala.pos.y+4)) ){
        bola_nuevo->direccion.x *= -1;
        bola_nuevo->direccion.y *= -1;
    }
    if ( ((bola.pos.x == pala1.pos.x)||(bola.pos.x+1 == pala1.pos.x)||(bola.pos.x+2 == pala1.pos.x)) && ((bola.pos.y == pala1.pos.y)||(bola.pos.y == pala1.pos.y+1)||(bola.pos.y == pala1.pos.y+2)||(bola.pos.y == pala1.pos.y+3)||(bola.pos.y == pala1.pos.y+4)) ){
        bola_nuevo->direccion.x *= -1;
        bola_nuevo->direccion.y *= -1;
    }

    if((bola.pos.x <= minc) || (bola.pos.x >= maxc))
        bola_nuevo->direccion.x *= -1;
    if((bola.pos.y <= minf) || (bola.pos.y >= maxf))
        bola_nuevo->direccion.y *= -1;
    refresh();
}
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
int teclas(Pala pala,Pala pala1, Pala *palaN, Pala *pala1N, int key){
    switch(getch()){
        case KEY_UP:
            if(pala1.pos.y   >= minf+2)
                pala1N->pos.y -= 1;
            break;
        case KEY_DOWN:
            if(pala1.pos.y+4 <= maxf-2)
                pala1N->pos.y += 1;
            break;
        case 'w':
            if(pala.pos.y    >= minf+2)
                palaN->pos.y  -= 1;
            break;
        case 's':
            if(pala.pos.y+4  <= maxf-2)
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

int main() {
    /*TODO pasar todo a double y comprobar que funcione bien*/
    int arrow = 0;
    Bola bola = {.pos = {.x = 8, .y = 8}, .direccion = {.x = 1 , .y = 1} };
    Pala pala = {20, 10};
    Pala pala1 = {80, 10};

    setlocale(LC_ALL,"");
    iniciar_Curses();
    char matriz[fila][columna];
    for(int i=0;i<fila;i++) {
        for(int j=0;j<columna;j++) {
            matriz[i][j] = 'x';
        }
    }
    while(teclas(pala, pala1, &pala, &pala1, arrow) != KEY_BREAK){
        clear();
        dibujar_Marco(matriz);
        palaA(pala);
        palaB(pala1);
        movimiento_Bola(bola,&bola,pala,pala1);
        usleep(20000*1.2);
    }
    finalizar_Curses();
    return 0;
}


//////////////// Dibujar marco
void dibujar_Marco(char matriz[fila][columna]){
    for(int f=0; f<fila;f++) {
        for(int c=0;c<columna;c++) {
            if(((f) == minf) || ((f) == maxf)){
                if( ((f==minf)&&(c==minc)) || ((f==minf)&&(c==maxc)) || ((f==maxf)&&(c==minc)) || ((f==maxf)&&(c==maxc)) )
                    printw("%cx", matriz[f][c] );
                else printw("x");
            }
            else
                if( (c<(minc+1)) ||(c>(maxc-1)) )
                    printw("l%c",matriz[f][c]);
                else
                    printw(" ");
        }
        printw("\n");
    }
    refresh();
}


