
#ifndef ALL_H
#define ALL_H
#include "psqr1.h"
#include "psqr2.h"
#include "psqr3.h"
#include "psqr4.h"
#include "psqr5.h"
#include "psqr6.h"
#include "psqr7.h"
#define ssize 30
class ALL{
    public:
    psqr1 *p1;
    psqr2 *p2;
    psqr3 *p3;
    psqr4 *p4;
    psqr5 *p5;
    psqr6 *p6;
    psqr7 *p7;
    int value,next=0,pos,nextpos;
    int refresh(){
        // Generate block
        if(next==0) {
            next=rand()%7+1; // first block
            switch(next){
                case 1 : p1=new psqr1; break;
                case 2 : p2=new psqr2; break;
                case 3 : p3=new psqr3; break;
                case 4 : p4=new psqr4; break;
                case 5 : p5=new psqr5; break;
                case 6 : p6=new psqr6; break;
                case 7 : p7=new psqr7; break;
            }
            nextpos=rand()%totpos(next)+1;
        }
        value=next;
        pos=nextpos;
        next=rand()%7+1; // next blocks
        switch(next){
            case 1 : p1=new psqr1; break;
            case 2 : p2=new psqr2; break;
            case 3 : p3=new psqr3; break;
            case 4 : p4=new psqr4; break;
            case 5 : p5=new psqr5; break;
            case 6 : p6=new psqr6; break;
            case 7 : p7=new psqr7; break;
        }
        nextpos= rand()%totpos(next)+1;
        int x=400,y=150;
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
        {
            clean(x+ssize*i,y+ssize*j);
        }
        switch(next){
            case 1 : y+=ssize; p1->print(x,y,nextpos); break;
            case 2 : p2->print(x,y,nextpos); break;
            case 3 : p3->print(x,y,nextpos); break;
            case 4 : p4->print(x,y,nextpos); break;
            case 5 : p5->print(x,y,nextpos); break;
            case 6 : p6->print(x,y,nextpos); break;
            case 7 : p7->print(x,y,nextpos); break;
        }
        return pos;
    }
    bool transform(int *x,int *y,int *r)
    {
        if(value==1)
            return p1->transform(*x,*y,*r);
        if(value==2)
            return p2->transform(*x,*y,*r);
        if(value==3)
            return p3->transform(*x,*y,*r);
        if(value==4)
            return p4->transform(*x,*y,*r);
        if(value==5)
            return p5->transform(*x,*y,*r);
        if(value==6)
            return false;
        if(value==7)
            return p7->transform(*x,*y,*r);
    }
    int totpos(int value){
        if(value==1)
            return p1->totpos;
        if(value==2)
            return p2->totpos;
        if(value==3)
            return p3->totpos;
        if(value==4)
            return p4->totpos;
        if(value==5)
            return p5->totpos;
        if(value==6)
            return p6->totpos;
        if(value==7)
            return p7->totpos;
    }
    int totpos(){
        if(value==1)
            return p1->totpos;
        if(value==2)
            return p2->totpos;
        if(value==3)
            return p3->totpos;
        if(value==4)
            return p4->totpos;
        if(value==5)
            return p5->totpos;
        if(value==6)
            return p6->totpos;
        if(value==7)
            return p7->totpos;
    }
    bool movablel(int x,int y,int r){
        if(value==1)
            return p1->movablel(x,y,r);
        if(value==2)
            return p2->movablel(x,y,r);
        if(value==3)
            return p3->movablel(x,y,r);
        if(value==4)
            return p4->movablel(x,y,r);
        if(value==5)
            return p5->movablel(x,y,r);
        if(value==6)
            return p6->movablel(x,y,r);
        if(value==7)
            return p7->movablel(x,y,r);
    }
    bool movabler(int x,int y,int r){
        if(value==1)
            return p1->movabler(x,y,r);
        if(value==2)
            return p2->movabler(x,y,r);
        if(value==3)
            return p3->movabler(x,y,r);
        if(value==4)
            return p4->movabler(x,y,r);
        if(value==5)
            return p5->movabler(x,y,r);
        if(value==6)
            return p6->movabler(x,y,r);
        if(value==7)
            return p7->movabler(x,y,r);
    }
    bool print(int *x,int *y, int *r ,bool flag,bool down=false){
        if(value==1)
            return p1->print(*x,*y,*r,flag,down);
        if(value==2)
            return p2->print(*x,*y,*r,flag,down);
        if(value==3)
            return p3->print(*x,*y,*r,flag,down);
        if(value==4)
            return p4->print(*x,*y,*r,flag,down);
        if(value==5)
            return p5->print(*x,*y,*r,flag,down);
        if(value==6)
            return p6->print(*x,*y,*r,flag,down);
        if(value==7)
            return p7->print(*x,*y,*r,flag,down);
    }
};





#endif // ALL_H
