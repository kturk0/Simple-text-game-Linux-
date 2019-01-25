#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

void hscore_init(int *highscore)
{
    FILE *hr=fopen("hscore.txt","r");
    if(hr==NULL)
        *highscore=0;
    else
    {
        fscanf(hr,"%d",highscore);
        fclose(hr);
    }
}

void score_update(int score,int highscore)
{
    move(16,9);
    printw("%d",score);
    if(score>highscore)
    {
        move(3,30);
        printw("%d",score);
        move(4,19);
        printw("NEW HIGHSCORE");
    }
}

void hscore_new(int score,int highscore)
{
    FILE *hw=fopen("hscore.txt","w");
    if(score>highscore)
        fprintf(hw,"%d",score);
    else
        fprintf(hw,"%d",highscore);
    fclose(hw);
}
