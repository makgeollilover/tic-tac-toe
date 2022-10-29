#include "stdio.h"

#include "gamefct.h"
//access columns in game
#define COL_1 1
#define COL_2 5
#define COL_3 9


//functions
//void Field(char line1[], char line2[], char line3[]);
//char line1[] = char *line1
//int isover(int *win, char *line1, char *line2, char *line3);
//1, 5, 9 are for the 3 columns
//char Movex(int *x, char *line1, char *line2, char *line3);
//char Moveo(int *o, char *line1, char *line2, char *line3);
//for each move


int main(void)
{
    int n = 0; //number of turns
    int win = 0; //0 = keep playing!
    char line1[] = "   |   |   ";
    char line2[] = "   |   |   ";
    char line3[] = "   |   |   ";


    while (win == 0)
    {
        Field(line1, line2, line3);
        int x;
        int o;

        Movex(&x, &n, line1, line2, line3);
        isover(&win, &n, line1, line2, line3);
        if (win == 1)
        {
            break;
        }
        Moveo(&o, &n, line1, line2, line3);
        isover(&win, &n, line1, line2, line3);
        printf("It's turn no. %d\n", n);
    }


    Field(line1, line2, line3);
    //line1[COL_3] = 'x'; //way to alter game
    //line2[COL_2] = 'x'; 
    //line3[COL_1] = 'x'; 
    //Field(line1, line2, line3);
    //printf("%d\n", isover(&win, line1, line2, line3));
    //printf("%d", win); //check if value is changed
}


