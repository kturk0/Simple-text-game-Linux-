#include <stdio.h>
#include <ncurses.h>


void reset(int t[][15])
{
    for (int i=0;i<13;i++)
        for (int j=1;j<14;j++)
            t[i][j]=0;
    for (int i=0;i<15;i++)
    {
        t[i][0]=1;
        t[i][14]=1;
    }
    for (int i=1;i<14;i++)
    {
        t[14][i]=1;
        t[13][i]=2;
    }
    t[13][7]=3;
}

void show(int t[][15],int *score,int *lifes,int *hscore)
{
    for (int i=0;i<15;i++)
    {
        for (int j=0;j<15;j++)
            {
                if(t[i][j]==1)
                    printw("O");
                else if(t[i][j]==3)
                    printw("X");
                else if(t[i][j]==4)
                    printw("A");
                else if(t[i][j]==5)
                    printw("*");
                else
                    printw(" ");
            }
        printw("\n");
    }
    printw("\n Score = %d", *score);
    printw("\n Lifes = %d", *lifes);
    move(3,18);
    printw("Highscore = %d", *hscore);
    move(8,24);
    printw("CONTROLS");
    move(9,22);
    printw("move - A , D");
    move(10,22);
    printw("shoot - W");
    move(11,22);
    printw("surrender - T");
}

void p_control(int t[][15],char *input,int *poz)
{
    *input=getch();
    if(*input=='a' && *poz>1)
        {
            t[13][*poz]=2;
            (*poz)--;
            t[13][*poz]=3;
            move(13,*poz);
            printw("X ");
        }
        if(*input=='d' && *poz<13)
        {
            t[13][*poz]=2;
            (*poz)++;
            t[13][*poz]=3;
            move(13,*poz-1);
            printw(" X");
        }
        if(*input=='w')
        {
            t[12][*poz]=5;
            move(12,*poz);
            printw("*");
        }
}

void b_travel(int t[][15],int *score)
{
    for (int i=0;i<13;i++)
        for (int j=1;j<14;j++)
        {
            if(t[i][j]==5 && i==0)
            {
                t[i][j]=0;
                move(i,j);
                printw(" ");
            }
            else if (t[i][j]==5)
            {
                t[i][j]=0;
                move(i,j);
                printw(" ");
                move(i-1,j);
                if(t[i-1][j]==4)
                {
                    *score+=10;
                    t[i-1][j]=0;
                    printw(" ");
                }
                else
                {
                    t[i-1][j]=5;
                    printw("*");
                }
            }
        }
}
