#ifndef TEMPLATE_H
#define TEMPLATE_H

#include "allblocks.h"


void draw(int x, int y, int color){
    mat->POS[y][x]=1;
    sqr(mat->X[x], mat->Y[y], color);
}

void hi(){
    for(int i=11; i<16; i++)
        draw(1, i, 3);

    draw(2, 13, 3);
    draw(3, 13, 3);

    for(int i=11; i<16; i++)
        draw(4, i, 3);


    draw(6, 11, 3);
    draw(7, 11, 3);
    draw(8, 11, 3);
    draw(7, 12, 3);
    draw(7, 13, 3);
    draw(7, 14, 3);
    draw(6, 15, 3);
    draw(7, 15, 3);
    draw(8, 15, 3);
}

void siu(){
    for(int i=0; i<4; i++)
        draw(i, 11, 1);
    draw(0, 12, 1);
    for(int i=0; i<4; i++)
        draw(i, 13, 1);
    draw(3, 14, 1);
    for(int i=0; i<4; i++)
        draw(i, 15, 1);

    for(int i=11; i<16; i++)
        draw(5, i, 1);

    for(int i=11; i<16; i++)
        draw(7, i, 1);
    draw(8, 15, 1);
    for(int i=11; i<16; i++)
        draw(9, i, 1);
}

void cpp(){
    for(int i=0; i<3; i++)
        draw(i, 11, 4);
    for(int i=12; i<16; i++)
        draw(0, i, 4);
    for(int i=0; i<3; i++)
        draw(i, 15, 4);

    draw(4, 12, 4);
    draw(3, 13, 4);
    draw(4, 13, 4);
    draw(5, 13, 4);
    draw(4, 14, 4);

    draw(8, 12, 4);
    draw(7, 13, 4);
    draw(8, 13, 4);
    draw(9, 13, 4);
    draw(8, 14, 4);
}


#endif // TEMPLATE_H
