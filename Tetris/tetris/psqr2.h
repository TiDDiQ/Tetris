
#ifndef PSQR2_H
#define PSQR2_H

#include "Coloring.h"
#define ssize 30

class psqr2{ // Reverse L shape
    int xold,yold,pold;
    void old(int x,int y,int r){
        xold=x;
        yold=y;
        pold=r;
    }
public:
    int const totpos=4;
    bool movabler(int x,int y,int r)
    {
        if(r==1)
        {
            if(mat->getindexx(x)==7)
                return false;
            for(int i=1;i<=2;i++)
            if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)+3])
                return false;
            if(mat->POS[mat->getindexy(y)][mat->getindexx(x)+1])
                return false;
            return true;
        }
        if(r==2)
        {
            if(mat->getindexx(x)==7)
                return false;
            for(int i=1;i<4;i++)
            if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)+2])
                return false;
            for(int i=0;i<2;i++)
            if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)+3])
                return false;
            return true;
        }
        if(r==3)
        {
            if(mat->getindexx(x)==7)
                return false;
            for(int i=1;i<4;i++)
            if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)+3])
                return false;
            return true;
        }
        if(r==4)
        {
            if(mat->getindexx(x)==8)
                return false;
            for(int i=0;i<4;i++)
            if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)+2])
                return false;
            return true;
        }
    }
    bool movablel(int x,int y,int r)
    {
        if(r==1)
        {
            if (0==mat->getindexx(x))
                return false;
            for(int i=0;i<3;i++)
            if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)-1])
                return false;
            return true;
        }
        if(r==2)
        {
            if (-1==mat->getindexx(x))
                return false;
            for(int i=0;i<4;i++)
            if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)])
                return false;
            return true;
        }
        if(r==3)
        {
            if (0==mat->getindexx(x))
                return false;
            for(int i=1;i<=2;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)-1])
                    return false;
            for(int i=2;i<=3;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)+1])
                    return false;
            return true;
        }
        if(r==4)
        {
            if (0==mat->getindexx(x))
                return false;
            for(int i=2;i<=3;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)-1])
                    return false;
            for(int i=0;i<=2;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)])
                    return false;
            return true;
        }
    }
    bool transform(int &x,int &y, int &r){
        if(r==1){
            if(mat->getindexy(y)==17 || mat->POS[mat->getindexy(y)+3][mat->getindexx(x)+1] || mat->POS[mat->getindexy(y)][mat->getindexx(x)+2])
            {
                return false;
            }
        }
        else if(r==2){
            if(mat->getindexx(x)==-1 || mat->POS[mat->getindexy(y)+2][mat->getindexx(x)] || mat->POS[mat->getindexy(y)+1][mat->getindexx(x)]){
                if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+3] || mat->POS[mat->getindexy(y)+1][mat->getindexx(x)+3] || mat->POS[mat->getindexy(y)+3][mat->getindexx(x)+3])
                    return false;
                else if(mat->getindexx(x)==7)
                    return false;
                else
                    x+=ssize;
            }
            else if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+2] || mat->POS[mat->getindexy(y)+3][mat->getindexx(x)+2])
                return false;

        }
        else if(r==3){
            if(mat->POS[mat->getindexy(y)+3][mat->getindexx(x)] || mat->POS[mat->getindexy(y)+3][mat->getindexx(x)+1])
                return false;
        }
        else if(r==4){
            if(mat->getindexx(x)==8 || mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+2] || mat->POS[mat->getindexy(y)+1][mat->getindexx(x)+2]){
                if(mat->POS[mat->getindexy(y)][mat->getindexx(x)-1] || mat->POS[mat->getindexy(y)+1][mat->getindexx(x)-1] || mat->POS[mat->getindexy(y)+2][mat->getindexx(x)-1])
                    return false;
                else if(mat->getindexx(x)==0)
                    return false;
                else
                    x-=ssize;
            }
            else if(mat->POS[mat->getindexy(y)][mat->getindexx(x)] || mat->POS[mat->getindexy(y)+1][mat->getindexx(x)] || mat->POS[mat->getindexy(y)+2][mat->getindexx(x)])
                return false;

        }
        return true;
    }
    bool print(int &x,int &y,int &r,bool dflag=false, bool down=false)
    {
        if(dflag)
        {
            if(pold==1)
            {
                clean(xold,yold);
                clean(xold,yold+ssize);
                clean(xold+ssize,yold+ssize);
                clean(xold+ssize*2,yold+ssize);
            }
            else if(pold==2)
            {
                clean(xold+ssize,yold);
                clean(xold+ssize*2,yold);
                clean(xold+ssize,yold+ssize);
                clean(xold+ssize,yold+ssize*2);
            }
            else if(pold==3)
            {
                clean(xold,yold+ssize);
                clean(xold+ssize*2,yold+ssize);
                clean(xold+ssize,yold+ssize);
                clean(xold+ssize*2,yold+ssize*2);
            }
            else if(pold==4)
            {
                clean(xold+ssize,yold);
                clean(xold+ssize,yold+ssize*2);
                clean(xold+ssize,yold+ssize);
                clean(xold,yold+ssize*2);
            }
        }
        if(r==1)
        {
            bool flag=false;
            for(int i=0;i<3;i++)
            if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+i])
                flag= true;
            if(mat->getindexy(y)==18)
                flag=true;
            else if(down){
                bool loop =false;
                while(!loop)
                {
                    y+=ssize;
                    for(int i=0;i<3;i++)
                    if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+i])
                        loop= true;
                    if(mat->getindexy(y)==18)
                        loop=true;
                }
                sqr(x,mat->Y[mat->getindexy(y)], 2);
                sqr(x,mat->Y[mat->getindexy(y)+1], 2);
                sqr(x+ssize,mat->Y[mat->getindexy(y)+1], 2);
                sqr(x+ssize*2,mat->Y[mat->getindexy(y)+1], 2);
                flag=true;
            }
            if(flag){
                mat->POS[mat->getindexy(y)][mat->getindexx(x)]=true;
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x)]=true;
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x+ssize)]=true;
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x+ssize*2)]=true;
            }
            if(!down){
                sqr(x,y, 2);
                sqr(x,y+ssize, 2);
                sqr(x+ssize,y+ssize, 2);
                sqr(x+ssize*2,y+ssize, 2);
            }
            old(x,y,r);
            return flag;
        }
        else if(r==2)
        {

            bool flag=false;
            if(mat->getindexy(y)==17)
                flag= true;
            else if(mat->POS[mat->getindexy(y)+3][mat->getindexx(x)+1])
                flag= true;
            else if(mat->POS[mat->getindexy(y)+1][mat->getindexy(x)+2])
                flag= true;
            else if(down){
                bool loop=false;
                while(!loop){
                    y+=ssize;
                    if(mat->getindexy(y)==17)
                        loop= true;
                    else if(mat->POS[mat->getindexy(y)+3][mat->getindexx(x)+1])
                        loop= true;
                    else if(mat->POS[mat->getindexy(y)+1][mat->getindexy(x)+2])
                        loop= true;
                }
                sqr(x+ssize,mat->Y[mat->getindexy(y)], 2);
                sqr(x+ssize*2,mat->Y[mat->getindexy(y)], 2);
                sqr(x+ssize,mat->Y[mat->getindexy(y)+1], 2);
                sqr(x+ssize,mat->Y[mat->getindexy(y)+2], 2);
                flag=true;
            }
            if(flag){
                mat->POS[mat->getindexy(y)][mat->getindexx(x+ssize)]=true;
                mat->POS[mat->getindexy(y)][mat->getindexx(x+ssize*2)]=true;
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x+ssize)]=true;
                mat->POS[mat->getindexy(y+ssize*2)][mat->getindexx(x+ssize)]=true;
            }
            if(!down){
                sqr(x+ssize,y, 2);
                sqr(x+ssize*2,y, 2);
                sqr(x+ssize,y+ssize, 2);
                sqr(x+ssize,y+ssize*2, 2);
            }
            old(x,y,r);
            return flag;

        }
        else if(r==3)
        {
            bool flag=false;
            if(mat->getindexy(y)==17)
                flag= true;
            else if(mat->POS[mat->getindexy(y)+3][mat->getindexx(x)+2])
                flag= true;
            else for(int i=0;i<2;i++)
                if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+i])
                flag=true;
            if(down){
                bool loop=false;
                while(!loop){
                    y+=ssize;
                    if(mat->getindexy(y)==17)
                        loop= true;
                    else if(mat->POS[mat->getindexy(y)+3][mat->getindexx(x)+2])
                        loop= true;
                    else for(int i=0;i<2;i++)
                        if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+i])
                        loop=true;
                }
                sqr(x,mat->Y[mat->getindexy(y)+1], 2);
                sqr(x+ssize*2,mat->Y[mat->getindexy(y)+1], 2);
                sqr(x+ssize,mat->Y[mat->getindexy(y)+1], 2);
                sqr(x+ssize*2,mat->Y[mat->getindexy(y)+2], 2);
                flag=true;
            }
            if(flag){
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x)]=true;
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x+ssize*2)]=true;
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x+ssize)]=true;
                mat->POS[mat->getindexy(y+ssize*2)][mat->getindexx(x+ssize*2)]=true;
            }
            if(!down){
                sqr(x,y+ssize, 2);
                sqr(x+ssize*2,y+ssize, 2);
                sqr(x+ssize,y+ssize, 2);
                sqr(x+ssize*2,y+ssize*2, 2);
            }
            old(x,y,r);
            return flag;
        }
        else if(r==4)
        {

            bool flag=false;
            if(down){
                bool loop=false;
                while(!loop){
                    y+=ssize;
                    if(mat->getindexy(y)==17)
                        loop= true;
                    else
                    for(int i=0;i<2;i++)
                        if(mat->POS[mat->getindexy(y)+3][mat->getindexx(x)+i])
                            loop= true;
                }
                sqr(x+ssize,mat->Y[mat->getindexy(y)], 2);
                sqr(x+ssize,mat->Y[mat->getindexy(y)+2], 2);
                sqr(x+ssize,mat->Y[mat->getindexy(y)+1], 2);
                sqr(x,mat->Y[mat->getindexy(y)+2], 2);
                flag=true;
            }
            else if(mat->getindexy(y)==17)
                flag= true;
            else
            for(int i=0;i<2;i++)
                if(mat->POS[mat->getindexy(y)+3][mat->getindexx(x)+i])
                    flag= true;
            if(flag){
                mat->POS[mat->getindexy(y)][mat->getindexx(x+ssize)]=true;
                mat->POS[mat->getindexy(y+ssize*2)][mat->getindexx(x+ssize)]=true;
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x+ssize)]=true;
                mat->POS[mat->getindexy(y+ssize*2)][mat->getindexx(x)]=true;
            }
            if(!down){
                sqr(x+ssize,y, 2);
                sqr(x+ssize,y+ssize*2, 2);
                sqr(x+ssize,y+ssize, 2);
                sqr(x,y+ssize*2, 2);
            }
            old(x,y,r);
            return flag;
        }
    }
};



#endif // PSQR2_H

