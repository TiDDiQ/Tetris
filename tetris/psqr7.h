
#ifndef PSQR7_H
#define PSQR7_H

#include "Coloring.h"
#define ssize 30

class psqr7{ // Big line
    int xold,yold,pold;
    void old(int x,int y,int r){
        xold=x;
        yold=y;
        pold=r;
    }
public:
    int const totpos=2;
    bool movabler(int x,int y,int p)
    {
        if(p==1)
        {
            if(mat->getindexx(x)==6) return false;
            bool tflag=true;
            for(int i=1;i<=2;i++)
            if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)+4])
                tflag= false;
            return tflag;
        }
        else if(p==2)
        {
            if(mat->getindexx(x)==8) return false;
            bool tflag=true;
            for(int z=0;z<3;z++)
            for(int i=0;i<=2;i++)
            if(mat->POS[mat->getindexy(y+ssize*z)+i][mat->getindexx(x)+2])
                tflag= false;
            return tflag;
        }
    }
    bool movablel(int x,int y,int p)
    {
        if(p==1)
        {
            if(mat->getindexx(x)==0) return false;
            bool tflag=true;
            for(int i=1;i<=2;i++)
            if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)-1])
                tflag= false;
            return tflag;
        }
        else if(p==2)
        {
            if(mat->getindexx(x+ssize)==0) return false;
            bool tflag=true;
            for(int z=0;z<3;z++)
            for(int i=0;i<=2;i++)
            if(mat->POS[mat->getindexy(y+ssize*z)+i][mat->getindexx(x)])
                tflag= false;
            return tflag;
        }
    }
    bool transform(int &x,int &y, int &r){
        if(r==1){
            if(mat->getindexy(y)>=16 || mat->POS[mat->getindexy(y)+4][mat->getindexx(x)+1] || mat->POS[mat->getindexy(y)+3][mat->getindexx(x)+1] || mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+1])
                return false;
        }
        else if(r==2){
            if(mat->getindexx(x)==-1 || mat->POS[mat->getindexy(y)+1][mat->getindexx(x)] || mat->POS[mat->getindexy(y)+2][mat->getindexx(x)]){
                for(int i=1;i<=4;i++){
                    if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+i] || mat->POS[mat->getindexy(y)+1][mat->getindexx(x)+i])
                        return false;
                    else if(mat->getindexx(x)+i-2==8)
                        return false;
                }
                x+=ssize;
            }
            else if(mat->getindexx(x)==8 || mat->POS[mat->getindexy(y)+1][mat->getindexx(x)+2] || mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+2]){
                for(int i=0;i<3;i++){
                    if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)-i] || mat->POS[mat->getindexy(y)+1][mat->getindexx(x)-i])
                        return false;
                    else if(mat->getindexx(x)-i+1==0)
                        return false;
                }
                x-=ssize*2;
            }
            else if(mat->getindexx(x)==7 || mat->POS[mat->getindexy(y)+1][mat->getindexx(x)+3] || mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+3]){
                for(int i=1;i<=2;i++){
                    if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)-1] || mat->POS[mat->getindexy(y)+1][mat->getindexx(x)-1])
                        return false;
                    else if(mat->getindexx(x)-i+2==0)
                        return false;
                }
                x-=ssize;
            }
        }
        return true;
    }
    bool print(int &x,int &y,int r=1,bool dflag=false,bool down=false)
    {
        if(dflag)
        {
            if(pold==1)
            {
                clean(xold+ssize,yold+ssize);
                clean(xold,yold+ssize);
                clean(xold+ssize*2,yold+ssize);
                clean(xold+ssize*3,yold+ssize);
            }
            else if(pold==2)
            {
                clean(xold+ssize,yold+ssize);
                clean(xold+ssize,yold);
                clean(xold+ssize,yold+ssize*2);
                clean(xold+ssize,yold+ssize*3);
            }
        }
        if(r==1)
        {
            bool flag=false;
            if(down){
                bool loop=false;
                while(!loop){
                    y+=ssize;
                    if(mat->getindexy(y)==18)
                        loop=true;
                    else for(int i=0;i<4;i++)
                        if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+i]){
                            loop=true;
                            break;
                        }
                }
                flag=true;
                sqr(x,mat->Y[mat->getindexy(y)+1], 7);
                sqr(x+ssize*2,mat->Y[mat->getindexy(y)+1], 7);
                sqr(x+ssize*3,mat->Y[mat->getindexy(y)+1], 7);
                sqr(x+ssize,mat->Y[mat->getindexy(y)+1], 7);
            }
            else if(mat->getindexy(y)==18)
                flag=true;
            else for(int i=0;i<4;i++)
                if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+i]){
                    flag=true;
                    break;
                }
            if(flag){
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x)]=true;
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x+ssize*2)]=true;
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x+ssize*3)]=true;
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x+ssize)]=true;
            }
            if(!down){
                sqr(x,y+ssize, 7);
                sqr(x+ssize*2,y+ssize, 7);
                sqr(x+ssize*3,y+ssize, 7);
                sqr(x+ssize,y+ssize, 7);
            }
            old(x,y,r);
            return flag;
        }
        else if(r==2)
        {
            bool flag=false;
            if(mat->getindexy(y)==16)
                flag=true;
            else if(mat->POS[mat->getindexy(y)+4][mat->getindexx(x)+1])
                flag=true;
            else if(down){
                bool loop=false;
                while(!loop){
                    y+=ssize;
                    if(mat->getindexy(y)==16)
                        loop=true;
                    else if(mat->POS[mat->getindexy(y)+4][mat->getindexx(x)+1])
                        loop=true;
                }
                flag=true;
                sqr(x+ssize,mat->Y[mat->getindexy(y)], 7);
                sqr(x+ssize,mat->Y[mat->getindexy(y)+2], 7);
                sqr(x+ssize,mat->Y[mat->getindexy(y)+3], 7);
                sqr(x+ssize,mat->Y[mat->getindexy(y)+1], 7);
            }
            if(flag){
                mat->POS[mat->getindexy(y)][mat->getindexx(x+ssize)]=true;
                mat->POS[mat->getindexy(y+ssize*2)][mat->getindexx(x+ssize)]=true;
                mat->POS[mat->getindexy(y+ssize*3)][mat->getindexx(x+ssize)]=true;
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x+ssize)]=true;
            }
            if(!down){
                sqr(x+ssize,y, 7);
                sqr(x+ssize,y+ssize*2, 7);
                sqr(x+ssize,y+ssize*3, 7);
                sqr(x+ssize,y+ssize, 7);
            }
            old(x,y,r);
            return flag;
        }
    }
};



#endif // PSQR7_H
