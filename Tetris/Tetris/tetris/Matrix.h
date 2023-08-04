
#ifndef MATRIX_H
#define MATRIX_H

#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<string>
#include "Clean.h"
#define ssize 30

class MATRIX{
public:
    int X[10],Y[20];
    bool POS[20][10];
    MATRIX()
    {
        for(int x=0;x<10;x++)
            X[x]=20+x*ssize;
        for(int x=0;x<20;x++)
        {
           Y[x]=x*ssize;
            for(int y=0;y<10;y++)
            {
                POS[x][y]=false;
            }
        }
    }
    int getindexx(int a)
    {
        for(int x=0;x<10;x++)
            if(X[x]<=a && X[x]+ssize>a)
                return x;
        return -1;
    }
    int getindexy(int a)
    {
        for(int x=0;x<20;x++)
        {
            if(Y[x]<=a && Y[x]+ssize>a)
                return x;
        }
        return -1;
    }
};



#endif // MATRIX_H
