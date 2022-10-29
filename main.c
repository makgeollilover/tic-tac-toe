#include "stdio.h"

//access columns in game
#define COL_1 1
#define COL_2 5
#define COL_3 9


//functions
void Field(char line1[], char line2[], char line3[]);
//char line1[] = char *line1
int isover(int *win, char line1[], char line2[], char line3[]);
 //1, 5, 9 are for the 3 columns

int main(void)
{
    int win = 0; //0 = keep playing!
    char line1[] = "   |   |   ";
    char line2[] = "   |   |   ";
    char line3[] = "   |   |   ";



    Field(line1, line2, line3);
    line1[COL_3] = 'x'; //way to alter game
    line2[COL_2] = 'x'; 
    line3[COL_1] = 'x'; 
    Field(line1, line2, line3);
    printf("%d\n", isover(&win, line1, line2, line3));
}


//create a game field
void Field(char line1[], char line2[], char line3[])
{
    printf("%s\n", line1);
    printf("___________\n");
    printf("%s\n", line2);
    printf("___________\n");
    printf("%s\n", line3);
}

/*
As winning condition, check line1[COL_1] != ' ' etc...
define new functions that returns something like 0 for keep playing
or 1 for game over
*/

int isover(int *win, char line1[], char line2[], char line3[])
{
    //first conditional works so far
    if (line1[COL_1] != ' ' && line1[COL_2] != ' ' && line1[COL_3] != ' ')
    {
        *win = 1;
    }
    else if(line2[COL_1] != ' ' && line2[COL_2] != ' ' && line2[COL_3] != ' ')
    {
        *win = 1;
    }
        else if(line3[COL_1] != ' ' && line3[COL_2] != ' ' && line3[COL_3] != ' ')
    {
        *win = 1;
    }
    else if(line1[COL_1] != ' ' && line2[COL_2] != ' ' && line3[COL_3] != ' ')
    {
        *win = 1;
    }
    else if(line1[COL_3] != ' ' && line2[COL_2] != ' ' && line3[COL_1] != ' ')
    {
        *win = 1;
    }
    return *win;
}