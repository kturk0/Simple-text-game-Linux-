#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include "shooter.h"
#include "alien.h"
#include "score.h"

int main()
{
    int space[15][15];
    reset(space);
    int poz=7;
    char input;
    int score=0;
    int highscore;
    hscore_init(&highscore);
    double mdif1=50;
    double mdif2=20;
    int dif1=(int)mdif1;
    int dif2=(int)mdif2;
    int lifes=5;
    initscr();
    curs_set(0);
    noecho();
    nodelay(stdscr, TRUE);
    show(space,&score,&lifes,&highscore);
    do
    {
        if(dif1>=mdif1 && dif1>8)
        {
            a_spawn(space);
            dif1=0;
            mdif1*=0.995;
        }
        else
            dif1++;
        if (dif2>=mdif2 && dif2>8)
        {
            a_travel(space,&lifes);
            dif2=0;
            mdif2*=0.9986;
        }
        else
            dif2++;
        b_travel(space,&score);
        usleep(50000);
        p_control(space,&input,&poz);
        score_update(score,highscore);
        /*move(20,1);
        printw("%d  %f        %d  %f",dif1,mdif1,dif2,mdif2);*/
        refresh();
    }
    while(input!='t' && lifes>0);
    erase();
    move(10,32);
    printw("GAME OVER");
    refresh();
    hscore_new(score,highscore);
    sleep(5);
    endwin();
    return 0;
}

