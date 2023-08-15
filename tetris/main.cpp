
#include <fstream>
#include "allblocks.h"
#include "Template.h"
#define ssize 30

using namespace std;


void combo(int COMBO); // Show combo
void sqr1(int x,int y,int clr=CYAN);
void getup();
void PointForEachBlock(int block, int& SCORE);
void RocketBonus(int& RPG, int LEVEL, int& LEVELtmp);
void Deathline(int& deathlineRow, int& tmpTime, int& currentClock, bool& resetClock);

int main(){
    string filepath = "HIGHESTSCORE.txt";
    ifstream fin(filepath);
    initwindow(600,620,"Tetris Game",300,10,false,true);
    getup();
	mat=new MATRIX();
    int y=0-ssize*3,r,x=mat->X[3];
    static int SCORE,LEVEL=1, COMBO=1, countingNotFull, HIGHESTSCORE;
    int RPG=2;
    int LEVELtmp=0;
    fin>>HIGHESTSCORE;
    bool resetOrNot = false;
    char ch;
    bool flag=false,down_flag=false;
    bool deleteClock = true;
    bool resetClock = true;
    bool fastFalling = false;
    int tmpTime=0;
    int currentClock=11; // 1 second screen init time average
    int deathlineRow=2;

    srand(time(NULL));
    ALL *all;
    all=new ALL();
    r=all->refresh();

    while(true) //MAIN LOOP
    {

        while(!kbhit())
        {
            for(int i=0; i<10; i++){
                if(mat->POS[deathlineRow-1][i]==1){
                    fastFalling=true;
                    break;
                }
                else{
                    fastFalling=false;
                }
            }
            if(deathlineRow<=15){
                Deathline(deathlineRow, tmpTime, currentClock, resetClock);
            }
            else{
                if(deleteClock==true){
                    setbkcolor(LIGHTCYAN);
                    settextstyle(3, HORIZ_DIR, 6);
                    outtextxy(360, 510, "        ");
                    setcolor(RED);
                    setbkcolor(BLACK);
                    line(mat->X[0], mat->Y[deathlineRow], mat->X[9] + 30, mat->Y[deathlineRow]);
                    setcolor(BLACK);
                    setbkcolor(LIGHTCYAN);
                    settextstyle(3, HORIZ_DIR, 2);
                    outtextxy(360, 510, "Line stopped");
                    deleteClock = false;
                }
            }
            //if(all.print(&x,&y,&r,flag))
            if(all->print(&x,&y,&r,flag,down_flag))
            {
                int coun; //count
                countingNotFull=0;
                for(int y=0;y<20;y++){  // delete a row
                    coun=0;
                    for(int x=0;x<10;x++){
                        if(mat->POS[y][x])
                            coun++;
                        else
                            break;
                    }
                    if(coun==10){
                        for(int i=y;i>0;i--)
                            for(int x=0;x<10;x++)
                                mat->POS[i][x]=mat->POS[i-1][x];
                        for(int i=0;i<20;i++)
                            for(int x=0;x<10;x++)
                                clean(mat->X[x],mat->Y[i]);
                        for(int i=0;i<20;i++)
                            for(int x=0;x<10;x++)
                                if(mat->POS[i][x])
                                    sqr(mat->X[x],mat->Y[i], all->value);

                        setcolor(BLACK);
                        setbkcolor(LIGHTCYAN);
                        settextstyle(4, HORIZ_DIR, 2);
                        SCORE= SCORE + 100*COMBO;
                        combo(COMBO);
                        if(COMBO<10){
                            COMBO++;
                        }

                        if(COMBO>=2){
                            if(deathlineRow>2){
                                deathlineRow--;
                                deleteClock=true;
                                resetClock=true;
                            }
                        }

                        if(SCORE/1000)
                            LEVEL=SCORE/1000 + 1;
                        RocketBonus(RPG, LEVEL, LEVELtmp);
                        if(!fastFalling){
                            if(RPG<15)
                                RPG++;
                        }
                        char tmpc[10];
                        itoa(SCORE,tmpc,10);
                        strcat(tmpc,"    ");
                        outtextxy(463, 350, tmpc);
                        itoa(LEVEL,tmpc,10);
                        strcat(tmpc,"    ");
                        outtextxy(460, 300, tmpc);
                        currentClock = 10;
                    }
                    else{
                        countingNotFull++;
                    }
                }
                if(countingNotFull==20){
                     COMBO=1;
                }
                for(int x=0;x<10;x++){ // game over
                    if(mat->POS[0][x]){
                        char tmpc[10];
                        if(SCORE > HIGHESTSCORE){
                            setcolor(BLACK);
                            settextstyle(4, HORIZ_DIR, 2);
                            outtextxy(360, 430, "                   ");
                            itoa(SCORE,tmpc,10);
                            strcat(tmpc,"    ");
                            outtextxy(360, 430, tmpc);
                            ofstream OutFile(filepath);
                            OutFile << SCORE;
                        }
                        setcolor(BLACK);
                        setbkcolor(LIGHTCYAN);
                        settextstyle(3, HORIZ_DIR, 6);
                        outtextxy(360, 510, "  ");
                        settextstyle(4, HORIZ_DIR, 2);
                        outtextxy(360, 470, "Game Over  ");
                        outtextxy(360, 580, "                                 ");
                        outtextxy(360, 510, "Press '1' to        ");
                        outtextxy(360, 540, "restart                    ");
                        //while(getch()!='0');
                        do{
                            char tc;
                            while(!kbhit()){
                                Sleep(500);
                                outtextxy(360, 470, "Game Over  ");
                                Sleep(500);
                                outtextxy(360, 470, "                    ");
                            }
                            ch=getch();
                            if(ch=='x')
                                return 0;
                        }while(ch!='1');
                        outtextxy(360, 510, "                                 ");
                        outtextxy(360, 540, "                                 ");
                        outtextxy(360, 470, "Playing...    ");
                        settextstyle(3, HORIZ_DIR, 2);

                        outtextxy(360, 580, "Rocket : ");
                        RPG=2;
                        deleteClock = true;
                        resetClock=true;
                        fastFalling = false;
                        currentClock=11;
                        deathlineRow=2;
                        outtextxy(440, 580, "2");
                        settextstyle(4, HORIZ_DIR, 2);
                        SCORE=0;
                        LEVEL=1;
                        outtextxy(463, 350, "            ");
                        outtextxy(463, 300, "            ");
                        outtextxy(463, 350, "0");
                        outtextxy(460, 300, "1");
                        setfillstyle(1,BLACK);
                        bar(mat->X[0],0,mat->X[9]+ssize,600);
                        // cout<<endl<<mat->Y[19]+ssize;
                        mat=new MATRIX();
                    }
                }
                r=all->refresh();
                x=mat->X[3];
                y=0-ssize*3;



                PointForEachBlock(all->value, SCORE);
                if(SCORE/1000)
                    LEVEL=SCORE/1000 + 1;
                RocketBonus(RPG, LEVEL, LEVELtmp);
                setcolor(BLACK);
                setbkcolor(LIGHTCYAN);
                settextstyle(4, HORIZ_DIR, 2);
                char tmpc[10];
                itoa(SCORE,tmpc,10);
                strcat(tmpc,"    ");
                outtextxy(463, 350, tmpc);
                itoa(LEVEL,tmpc,10);
                strcat(tmpc,"    ");
                outtextxy(460, 300, tmpc);
            }

            if(LEVEL<11 && fastFalling==false){
                Sleep(10-(LEVEL-1));
            }
            else{
                Sleep(0.5);
            }
            flag=false;
            down_flag=false;
            y++;
        }

        ch=getch();
        switch(ch) // INPUT FROM KEYBOARD
        {
            case 'x' : return 0;
            case 'r' :
                deleteClock = true;
                resetClock=true;
                fastFalling = false;
                currentClock=10;
                deathlineRow=2;
                RPG=2;
                SCORE=0;
                LEVEL=1;
                settextstyle(3, HORIZ_DIR, 2);
                setcolor(BLACK);
                outtextxy(440, 580, "            ");
                outtextxy(440, 580, "2");
                settextstyle(4, HORIZ_DIR, 2);
                outtextxy(463, 350, "            ");
                outtextxy(463, 300, "            ");
                outtextxy(463, 350, "0");
                outtextxy(460, 300, "1");
                setfillstyle(1,BLACK);
                bar(mat->X[0],0,mat->X[9]+ssize,600);
                mat=new MATRIX();
                r=all->refresh();
                x=mat->X[3];
                y=0-ssize*3;
                flag=false;
                down_flag=false;
                y++;
                break;
            case 'c' :
                deleteClock = true;
                resetClock=true;
                fastFalling = false;
                currentClock=10;
                deathlineRow=2;
                RPG=2;
                SCORE=0;
                LEVEL=1;
                settextstyle(3, HORIZ_DIR, 2);
                setcolor(BLACK);
                outtextxy(440, 580, "            ");
                outtextxy(440, 580, "2");
                settextstyle(4, HORIZ_DIR, 2);
                outtextxy(463, 350, "            ");
                outtextxy(463, 300, "            ");
                outtextxy(463, 350, "0");
                outtextxy(460, 300, "1");
                setfillstyle(1,BLACK);
                bar(mat->X[0],0,mat->X[9]+ssize,600);
                mat=new MATRIX();
                r=all->refresh();
                x=mat->X[3];
                y=0-ssize*3;
                flag=false;
                down_flag=false;
                y++;
                cpp();
                break;
            case 's' :
                deleteClock = true;
                resetClock=true;
                fastFalling = false;
                currentClock=10;
                deathlineRow=2;
                RPG=2;
                SCORE=0;
                LEVEL=1;
                settextstyle(3, HORIZ_DIR, 2);
                setcolor(BLACK);
                outtextxy(440, 580, "            ");
                outtextxy(440, 580, "2");
                settextstyle(4, HORIZ_DIR, 2);
                outtextxy(463, 350, "            ");
                outtextxy(463, 300, "            ");
                outtextxy(463, 350, "0");
                outtextxy(460, 300, "1");
                setfillstyle(1,BLACK);
                bar(mat->X[0],0,mat->X[9]+ssize,600);
                mat=new MATRIX();
                r=all->refresh();
                x=mat->X[3];
                y=0-ssize*3;
                flag=false;
                down_flag=false;
                y++;
                siu();
                break;
            case 'h' :
                deleteClock = true;
                resetClock=true;
                fastFalling = false;
                currentClock=10;
                deathlineRow=2;
                RPG=2;
                SCORE=0;
                LEVEL=1;
                settextstyle(3, HORIZ_DIR, 2);
                setcolor(BLACK);
                outtextxy(440, 580, "            ");
                outtextxy(440, 580, "2");
                settextstyle(4, HORIZ_DIR, 2);
                outtextxy(463, 350, "            ");
                outtextxy(463, 300, "            ");
                outtextxy(463, 350, "0");
                outtextxy(460, 300, "1");
                setfillstyle(1,BLACK);
                bar(mat->X[0],0,mat->X[9]+ssize,600);
                mat=new MATRIX();
                r=all->refresh();
                x=mat->X[3];
                y=0-ssize*3;
                flag=false;
                down_flag=false;
                y++;
                hi();
                break;
            case '0' :
                setcolor(BLACK);
                setbkcolor(LIGHTCYAN);
                settextstyle(4, HORIZ_DIR, 2);
                outtextxy(360, 470, "Paused   ");
                //while(getch()!='0');
                do{
                    char tc;
                    while(!kbhit()){
                        Sleep(500);
                        outtextxy(360, 470, "Paused  ");
                        Sleep(500);
                        outtextxy(360, 470, "             ");
                    }
                    ch=getch();
                }while(ch!='0');
                outtextxy(360, 470, "Playing...");
                break;
            case ' ' : if(!all->transform(&x,&y,&r))
                        break;
                if(r==all->totpos())
                    r=1;
                else
                    r++;
                flag=true;
                break;
            case 'q' :
                if(RPG>0){
                    RPG--;
                    bool hit = false;
                    for(int i=0; i<10; i++)
                        if(mat->POS[19][i]==1)
                            hit = true;

                    if(hit){
                        for(int y=16; y<20; y++) // 4 rows
                            for(int i=0; i<10; i++)
                                mat->POS[y][i]=1;
                        for(int y=16; y<20; y++)
                            for(int i=y;i>0;i--)
                                for(int x=0;x<10;x++)
                                    mat->POS[i][x]=mat->POS[i-1][x];
                            for(int i=0;i<20;i++)
                                for(int x=0;x<10;x++)
                                    clean(mat->X[x],mat->Y[i]);
                            for(int i=0;i<20;i++)
                                for(int x=0;x<10;x++)
                                    if(mat->POS[i][x])
                                        sqr(mat->X[x],mat->Y[i], all->value);
                    }
                    setcolor(BLACK);
                    setbkcolor(LIGHTCYAN);
                    settextstyle(3, HORIZ_DIR, 2);
                    char tmpc[10];
                    itoa(RPG,tmpc,10);
                    outtextxy(440, 580, tmpc);
                }
                break;
            case 0 :
                char temp=getch();
                if(temp==80)
                    down_flag=true;
                else if(temp==75 && all->movablel(x,y,r))
                    x=x-ssize;
                else if(temp==77 && all->movabler(x,y,r))
                    x=x+ssize;
                flag=true;
                break;
        }
    }
    getch();
    return 0;
}

void combo(int COMBO){
    setcolor(LIGHTCYAN);
    setbkcolor(BLACK);
    settextstyle(4, HORIZ_DIR, 2);
    int x = 52;
    int y = 100;
    switch(COMBO){
        case 1:
            outtextxy(x, y, "SINGLE  : +100  ");
            break;
        case 2:
            outtextxy(x, y, "2X COMBO! : +200");
            break;
        case 3:
            outtextxy(x, y, "3X COMBO! : +300");
            break;
        case 4:
            outtextxy(x, y, "4X COMBO! : +400");
            break;
        case 5:
            outtextxy(x, y, "5X COMBO! : +500");
            break;
        case 6:
            outtextxy(x, y, "6X COMBO! : +600");
            break;
        case 7:
            outtextxy(x, y, "7X COMBO! : +700");
            break;
        case 8:
            outtextxy(x, y, "8X COMBO! : +800");
            break;
        case 9:
            outtextxy(x, y, "9X COMBO! : +900");
            break;
        default:
            outtextxy(x, y, "INSANE! : +1000 ");
    }
    Sleep(500);
    outtextxy(x, y, "                                 ");
    setcolor(BLACK);
    setbkcolor(LIGHTCYAN);
}
void sqr1(int x,int y,int clr){
    setcolor(BLACK);
    line(x,y,x+ssize,y);
    setcolor(COLOR(109,207,246));
    setfillstyle(1,clr);
    bar3d(x+1,y+1,x+ssize-1,y+ssize-1,0,0);
}
void getup(){
    int HIGHESTSCORE;
    string filepath = "HIGHESTSCORE.txt";
    ifstream fin(filepath);
    fin>>HIGHESTSCORE;
    setfillstyle(1,LIGHTCYAN);
    setcolor(LIGHTCYAN);
    bar(0,0,19,620);
    bar(0,601,400,620);
    bar(321,0,600,620);

    setcolor(BLACK);
    setbkcolor(LIGHTCYAN);
    settextstyle(4, HORIZ_DIR, 3);
    outtextxy(360, 40, "Tetris Game");
    settextstyle(4, HORIZ_DIR, 2);
    outtextxy(385, 100, "Next Piece");
    outtextxy(360, 300, "Level : ");
    outtextxy(360, 350, "Score : ");
    outtextxy(463, 350, "0");
    outtextxy(460, 300, "1");
    outtextxy(360, 400, "Highest score : ");
    char tmpc[10];
    itoa(HIGHESTSCORE,tmpc,10);
    strcat(tmpc,"    ");
    outtextxy(360, 430, tmpc);
    outtextxy(360, 470, "Playing...");
    settextstyle(3, HORIZ_DIR, 2);
    outtextxy(360, 580, "Rocket : ");
    outtextxy(440, 580, "2");
    setcolor(RED);
    settextstyle(3, HORIZ_DIR, 1);
    int x=400,y=150,s=5;
    setfillstyle(1,BLACK);
    bar(x-s,y-s,x+ssize*4+s,y+ssize*4+s);
    if(false){
        sqr(x,y, 0);
        sqr(x+ssize,y, 0);
        sqr(x+ssize*2,y, 0);
        sqr(x+ssize*3,y, 0);

        sqr(x,y+ssize, 0);
        sqr(x+ssize,y+ssize, 0);
        sqr(x+ssize*2,y+ssize, 0);
        sqr(x+ssize*3,y+ssize, 0);

        sqr(x,y+ssize*2, 0);
        sqr(x+ssize,y+ssize*2, 0);
        sqr(x+ssize*2,y+ssize*2, 0);
        sqr(x+ssize*3,y+ssize*2, 0);

        sqr(x,y+ssize*3, 0);
        sqr(x+ssize,y+ssize*3, 0);
        sqr(x+ssize*2,y+ssize*3, 0);
        sqr(x+ssize*3,y+ssize*3, 0);
    }
}
void PointForEachBlock(int block, int& SCORE){
    switch(block)
    {
        case 1:
            SCORE = SCORE + 5;
            break;
        case 2:
            SCORE = SCORE + 15;
            break;
        case 3:
            SCORE = SCORE + 15;
            break;
        case 4:
            SCORE = SCORE + 25;
            break;
        case 5:
            SCORE = SCORE + 25;
            break;
        case 6:
            SCORE = SCORE + 20;
            break;
        case 7:
            SCORE = SCORE + 10;
            break;
    }
}
void RocketBonus(int& RPG, int LEVEL, int& LEVELtmp){
    if(LEVEL%2 == 0 && LEVEL != LEVELtmp) // Given 1 rpg after 2 rounds
        if(RPG<15){
           RPG++;
        }
        LEVELtmp = LEVEL;
        setcolor(BLACK);
        setbkcolor(LIGHTCYAN);
        settextstyle(3, HORIZ_DIR, 2);
        char tmpc[10];
        itoa(RPG,tmpc,10);
        outtextxy(440, 580, tmpc);
}
void Deathline(int& deathlineRow,int& tmpTime, int& currentClock, bool& resetClock){
    setcolor(RED);
    setbkcolor(BLACK);
    line(mat->X[0], mat->Y[deathlineRow], mat->X[9] + 30, mat->Y[deathlineRow]);
    setcolor(BLACK);
    setbkcolor(LIGHTCYAN);
    time_t currentTime = time(nullptr); // unit: second

    if(currentTime>tmpTime) {
        tmpTime=currentTime;
        if(currentClock>1){
            currentClock--;
        }
        else{
            currentClock=10;
            setcolor(BLACK);
            setbkcolor(BLACK);
            line(mat->X[0], mat->Y[deathlineRow], mat->X[9] + 30, mat->Y[deathlineRow]);
            deathlineRow++;
        }
    }

    char tmpc[2];
    itoa(currentClock,tmpc,10);
    strcat(tmpc,"    ");
    settextstyle(3, HORIZ_DIR, 6);
    setbkcolor(LIGHTCYAN);
    if(currentClock>3){
        setcolor(BLACK);
    }
    else{
        setcolor(RED);
    }
    if(resetClock){
        outtextxy(360, 510, "          ");
        resetClock=false;
    }
    outtextxy(360, 510, tmpc);
}
