
#ifndef PSQR4_H
#define PSQR4_H

#include "Coloring.h"
#define ssize 30

class psqr4{ // Stair shape
    int xold,yold,pold;
    void old(int x,int y,int r){
        xold=x;
        yold=y;
        pold=r;
    }
public:
    int const totpos=2;
    bool movablel(int x,int y,int r)
    {
        if(r==1)
        {
            if(mat->getindexx(x)==0)
                return false;
            for(int i=0;i<3;i++)
            if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)-1])
                return false;
            for(int i=0;i<2;i++)
            if(mat->POS[mat->getindexy(y)+i+2][mat->getindexx(x)])
                return false;
            return true;
        }
        if(r==2)
        {
            if(mat->getindexx(x)==0)
                return false;
            for(int i=1;i<=2;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)-1])
                    return false;
            for(int i=0;i<2;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)])
                    return false;
            return true;
        }
    }
    bool movabler(int x,int y,int r)
    {
        if(r==1)
        {
            if(mat->getindexx(x)==8)
                return false;
            for(int i=1;i<=3;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)+2])
                return false;
            for(int i=0;i<=1;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)+1])
                return false;
            return true;
        }
        if(r==2)
        {
            if(mat->getindexx(x)==7)
                return false;
            for(int i=0;i<2;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)+3])
                return false;
            for(int i=1;i<=2;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)+2])
                return false;
            return true;
        }
    }
    bool transform(int &x, int &y,int &r){
        if(r==1){
            if(mat->getindexx(x)==8 || mat->POS[mat->getindexy(y)][mat->getindexx(x)+2] || mat->POS[mat->getindexy(y)+1][mat->getindexx(x)+2]){
                if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)-1] || mat->POS[mat->getindexy(y)+1][mat->getindexx(x)-1])
                    return false;
                else if(mat->getindexx(x)==0)
                    return false;
                else x-=ssize;
            }
        }
        else if(r==2){
            if(mat->POS[mat->getindexy(y)+3][mat->getindexx(x)+1])
                return false;
            else if(mat->POS[mat->getindexy(y)][mat->getindexx(x)])
                return false;
        }
        return true;
    }
    bool print(int &x,int &y,int r=1, bool dflag=false, bool down=false)
    {
        if(dflag)
        {
            if(pold==1)
            {
                clean(xold,yold);
                clean(xold,yold+ssize);
                clean(xold+ssize,yold+ssize);
                clean(xold+ssize,yold+ssize*2);
            }
            else if(pold==2)
            {
                clean(xold,yold+ssize);
                clean(xold+ssize,yold+ssize);
                clean(xold+ssize,yold);
                clean(xold+ssize*2,yold);
            }
        }
        if(r==1)
        {
            bool flag=false;
            if(mat->getindexy(y)>16)
                flag= true;
            else if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)])
                flag= true;
            else if(mat->POS[mat->getindexy(y)+3][mat->getindexx(x)+1])
                flag= true;
            else if(down){
                bool loop=false;
                while(!loop){
                    y+=ssize;
                    if(mat->getindexy(y)>16)
                        loop= true;
                    else if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)])
                        loop= true;
                    else if(mat->POS[mat->getindexy(y)+3][mat->getindexx(x)+1])
                        loop= true;
                }
                flag=true;
                sqr(x,mat->Y[mat->getindexy(y)], 4);
                sqr(x,mat->Y[mat->getindexy(y)+1], 4);
                sqr(x+ssize,mat->Y[mat->getindexy(y)+1], 4);
                sqr(x+ssize,mat->Y[mat->getindexy(y)+2], 4);
            }
            if(flag){
                mat->POS[mat->getindexy(y)][mat->getindexx(x)]=true;
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x)]=true;
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x+ssize)]=true;
                mat->POS[mat->getindexy(y+ssize*2)][mat->getindexx(x+ssize)]=true;
            }
            if(!down){
                sqr(x,y, 4);
                sqr(x,y+ssize, 4);
                sqr(x+ssize,y+ssize, 4);
                sqr(x+ssize,y+ssize*2, 4);
            }
            old(x,y,r);
            return flag;
        }
        else if(r==2)
        {
            bool flag=false;
            if(down){
                bool loop=false;
                while(!loop){
                    y+=ssize;
                    if(mat->getindexy(y)>17)
                        loop= true;
                    else
                    for(int i=0;i<2;i++)
                    if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+i])
                        loop= true;
                    else if((mat->POS[mat->getindexy(y)+1][mat->getindexx(x)+2]))
                        loop= true;
                }
                flag=true;
                sqr(x+ssize,mat->Y[mat->getindexy(y)], 4);
                sqr(x,mat->Y[mat->getindexy(y)+1], 4);
                sqr(x+ssize,mat->Y[mat->getindexy(y)+1], 4);
                sqr(x+ssize*2,mat->Y[mat->getindexy(y)], 4);
            }
            else if(mat->getindexy(y)>17)
                flag= true;
            else
            for(int i=0;i<2;i++)
            if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+i])
                flag= true;
            else if((mat->POS[mat->getindexy(y)+1][mat->getindexx(x)+2]))
                flag= true;
            if(flag){
                mat->POS[mat->getindexy(y)][mat->getindexx(x+ssize)]=true;
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x)]=true;
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x+ssize)]=true;
                mat->POS[mat->getindexy(y)][mat->getindexx(x+ssize*2)]=true;
            }
            if(!down){
                sqr(x+ssize,y, 4);
                sqr(x,y+ssize, 4);
                sqr(x+ssize,y+ssize, 4);
                sqr(x+ssize*2,y, 4);
            }
            old(x,y,r);
            return flag;
        }
    }
};



#endif // PSQR4_H
