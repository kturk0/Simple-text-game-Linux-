#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>

void a_spawn(int t[][15])
{
    srand(time(NULL));
    int n=rand()%13+1;
    t[0][n]=4;
    move(0,n);
    printw("A");
}

void a_travel(int t[][15],int *lifes)
{
    for (int i=13;i>=0;i--)
        for (int j=1;j<14;j++)
        {
            if(t[i][j]==4 && (t[i+1][j]==1 || t[i+1][j]==3))
            {
                t[i][j]=0;
                move(i,j);
                printw(" ");
                (*lifes)--;
                move(17,9);
                printw("%d",*lifes);
            }
            else if(t[i][j]==4 && t[i+1][j]==5)
            {
                t[i][j]=0;
                t[i+1][j]=0;
                move(i,j);
                printw(" ");
                move(i+1,j);
                printw(" ");
            }
            else if (t[i][j]==4)
            {
                t[i][j]=0;
                t[i+1][j]=4;
                move(i,j);
                printw(" ");
                move(i+1,j);
                printw("A");
            }
        }
}

