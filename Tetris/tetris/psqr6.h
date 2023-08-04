
#ifndef PSQR6_H
#define PSQR6_H

#include "Coloring.h"
#define ssize 30

class psqr6{ // Big square
    int xold,yold,pold;
    void old(int x,int y,int r){
        xold=x;
        yold=y;
        pold=r;
    }
public:
    int const totpos=1;
    bool movablel(int x,int y,int r)
    {
        if(mat->getindexx(x)==0)
            return false;
        for(int i=0;i<3;i++)
            if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)-1])
            return false;
        return true;
    }
    bool movabler(int x,int y,int r)
    {
        if(mat->getindexx(x)==8)
            return false;
        for(int i=0;i<3;i++)
            if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)+2])
            return false;
        return true;
    }
    bool print(int x,int y, int r=1,bool dflag=false,bool down=false)
    {
        if(dflag)
        {
            clean(xold,yold);
            clean(xold+ssize,yold);
            clean(xold+ssize,yold+ssize);
            clean(xold,yold+ssize);
        }
        bool flag=false;
        if(down){
            bool loop =false;
            while(!loop){
                y+=ssize;
                if(mat->getindexy(y)==18)
                    loop= true;
                else for(int i=0;i<2;i++)
                    if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+i])
                    loop= true;
            }
            flag=true;
            sqr(x,mat->Y[mat->getindexy(y)], 6);
            sqr(x+ssize,mat->Y[mat->getindexy(y)], 6);
            sqr(x+ssize,mat->Y[mat->getindexy(y)+1], 6);
            sqr(x,mat->Y[mat->getindexy(y)+1], 6);
        }
        else if(mat->getindexy(y)==18)
            flag= true;
        else for(int i=0;i<2;i++)
            if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+i])
            flag= true;
        if(flag){
            mat->POS[mat->getindexy(y)][mat->getindexx(x)]=true;
            mat->POS[mat->getindexy(y)][mat->getindexx(x+ssize)]=true;
            mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x+ssize)]=true;
            mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x)]=true;
        }
        if(!down){
            sqr(x,y, 6);
            sqr(x+ssize,y, 6);
            sqr(x+ssize,y+ssize, 6);
            sqr(x,y+ssize, 6);
        }
        old(x,y,r);
        return flag;
    }
};



#endif // PSQR6_H
