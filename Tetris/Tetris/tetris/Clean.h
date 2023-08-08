
#ifndef CLEAN_H
#define CLEAN_H
#define ssize 30

#include<graphics.h>
#include<iostream>


void clean(int x,int y){
    setfillstyle(1,BLACK);
    bar(x,y,x+ssize,y+ssize);
}

#endif // CLEAN_H
