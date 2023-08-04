
#ifndef COLORING_H
#define COLORING_H
#include "Matrix.h"

MATRIX *mat;
void sqr(int x,int y, int type){
        register int ss=30,shado=4,poly[12];
        setcolor(BLACK);
        line(x,y,x+ss,y);

        //TOP OUTLINE COLOUR
        poly[0]=x+1;
        poly[1]=y+1;

        poly[2]=x+ss-2;
        poly[3]=y+1;

        poly[4]=x+ss-2;
        poly[5]=y+ss-2;

        poly[6]=x+ss-shado;
        poly[7]=y+ss-shado;

        poly[8]=x+ss-shado;
        poly[9]=y+shado;

        poly[10]=x+shado;
        poly[11]=y+shado;


        setcolor(COLOR(109,207,246));
        setfillstyle(1,COLOR(109,207,246));
        fillpoly(6,poly);

        //BOTTOM OUTLINE
        poly[0]=x+1;
        poly[1]=y+1;

        poly[2]=x+1;
        poly[3]=y+ss-2;

        poly[4]=x+ss-2;
        poly[5]=y+ss-2;

        poly[6]=x+ss-shado;
        poly[7]=y+ss-shado;

        poly[8]=x+shado;
        poly[9]=y+ss-shado;

        poly[10]=x+shado;
        poly[11]=y+shado;

        setcolor(COLOR(82,142,163));
        setfillstyle(1,COLOR(82,142,163));
        fillpoly(6,poly);

        // BLOCK COLOUR
        switch(type){
            case 1:
                setfillstyle(1,RED);
                break;
            case 2:
                setfillstyle(1,LIGHTGREEN);
                break;
            case 3:
                setfillstyle(1,YELLOW);
                break;
            case 4:
                setfillstyle(1,BLUE);
                break;
            case 5:
                setfillstyle(1,LIGHTBLUE);
                break;
            case 6:
                setfillstyle(1,WHITE);
                break;
            case 7:
                setfillstyle(1,GREEN);
                break;
        }

        bar(x+1+shado,y+1+shado,x+ss-shado,y+ss-shado);
}



#endif // COLORING_H
