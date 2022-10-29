#include "stdio.h"

//access columns in game
#define COL_1 1
#define COL_2 5
#define COL_3 9


//functions
void Field(char line1[], char line2[], char line3[]);
//char line1[] = char *line1
int isover(int *win, char *line1, char *line2, char *line3);
 //1, 5, 9 are for the 3 columns
char Movex(int *x, char *line1, char *line2, char *line3);
char Moveo(int *o, char *line1, char *line2, char *line3);
//for each move


int main(void)
{
    int win = 0; //0 = keep playing!
    char line1[] = "   |   |   ";
    char line2[] = "   |   |   ";
    char line3[] = "   |   |   ";


    while (win == 0)
    {
        Field(line1, line2, line3);
        int x;
        int o;
        
        Movex(&x, line1, line2, line3);
        isover(&win, line1, line2, line3);
        if (win == 1)
        {
            break;
        }
        Moveo(&o, line1, line2, line3);
        isover(&win, line1, line2, line3);
    }


    Field(line1, line2, line3);
    //line1[COL_3] = 'x'; //way to alter game
    //line2[COL_2] = 'x'; 
    //line3[COL_1] = 'x'; 
    //Field(line1, line2, line3);
    //printf("%d\n", isover(&win, line1, line2, line3));
    //printf("%d", win); //check if value is changed
}


//create a game field
void Field(char* line1, char line2[], char line3[])
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
    if (line1[COL_1] == 'x' && line1[COL_2] == 'x' && line1[COL_3] == 'x')
    {
        *win = 1;
        printf("Player 1 wins\n");
    }
    else if(line2[COL_1] == 'x' && line2[COL_2] == 'x' && line2[COL_3] == 'x')
    {
        *win = 1;
        printf("Player 1 wins\n");
    }
        else if(line3[COL_1] == 'x' && line3[COL_2] == 'x' && line3[COL_3] == 'x')
    {
        *win = 1;
        printf("Player 1 wins\n");
    }
    else if(line1[COL_1] == 'x' && line2[COL_2] == 'x' && line3[COL_3] == 'x')
    {
        *win = 1;
        printf("Player 1 wins\n");
    }
    else if(line1[COL_3] == 'x' && line2[COL_2] == 'x' && line3[COL_1] == 'x')
    {
        *win = 1;
        printf("Player 1 wins\n");
    }

    else if (line1[COL_1] == 'o' && line1[COL_2] == 'o' && line1[COL_3] == 'o')
    {
        *win = 1;
        printf("Player 2 wins\n");
    }
    else if(line2[COL_1] == 'o' && line2[COL_2] == 'o' && line2[COL_3] == 'o')
    {
        *win = 1;
        printf("Player 2 wins\n");
    }
        else if(line3[COL_1] == 'o' && line3[COL_2] == 'o' && line3[COL_3] == 'o')
    {
        *win = 1;
        printf("Player 2 wins\n");
    }
    else if(line1[COL_1] == 'o' && line2[COL_2] == 'o' && line3[COL_3] == 'o')
    {
        *win = 1;
        printf("Player 2 wins\n");
    }
    else if(line1[COL_3] == 'o' && line2[COL_2] == 'o' && line3[COL_1] == 'o')
    {
        *win = 1;
        printf("Player 2 wins\n");
    }
    return *win;
}
//make isfull function or so to check if game can't be finished
//make it impossible to alter already changed field
/*
Generate function for player move (1) to (9)
print "invalid move" if different input
*/

char Movex(int *x, char *line1, char *line2, char *line3)
{
    int valid = 0;
    while (valid == 0)
    {
    printf("Player x, it's your turn! enter field (1) to (9)");
    scanf("%i", x);
    if (*x == 1 && line1[COL_1] == ' ')
    {
        line1[COL_1] = 'x';
        valid = 1;
        return *line1;
    }
    else if (*x == 2 && line1[COL_2] == ' ')
    {
        line1[COL_2] = 'x';
        valid = 1;
        return *line1;
    }
    else if (*x == 3 && line1[COL_3] == ' ')
    {
        line1[COL_3] = 'x';
        valid = 1;
        return *line1;
    }
    else if (*x == 4 && line2[COL_1] == ' ')
    {
        line2[COL_1] = 'x';
        valid = 1;
        return *line2;
    }
    else if (*x == 5 && line2[COL_2] == ' ')
    {
        line2[COL_2] = 'x';
        valid = 1;
        return *line2;
    }
    else if (*x == 6 && line2[COL_3] == ' ')
    {
        line2[COL_3] = 'x';
        valid = 1;
        return *line2;
    }
    else if (*x == 7 && line3[COL_1] == ' ')
    {
        line3[COL_1] = 'x';
        valid = 1;
        return *line3;
    }
    else if (*x == 8 && line3[COL_2] == ' ')
    {
        line3[COL_2] = 'x';
        valid = 1;
        return *line3;
    }
    else if (*x == 9 && line3[COL_3] == ' ')
    {
        line3[COL_3] = 'x';
        valid = 1;
        return *line3;
    }
    else
    {
        printf("Invalid input\n");
    }
    }
    return *line1;
}


char Moveo(int *o, char *line1, char *line2, char *line3)
{
    int valid = 0;
    //solve with switch case
    while (valid == 0)
    {
    printf("Player o, it's your turn! enter field (1) to (9)");
    scanf("%i", o);
    if (*o == 1 && line1[COL_1] == ' ')
    {
        line1[COL_1] = 'o';
        valid = 1;
        return *line1;
    }
    else if (*o == 2 && line1[COL_2] == ' ')
    {
        line1[COL_2] = 'o';
        valid = 1;
        return *line1;
    }
    else if (*o == 3 && line1[COL_3] == ' ')
    {
        line1[COL_3] = 'o';
        valid = 1;
        return *line1;
    }
    else if (*o == 4 && line2[COL_1] == ' ')
    {
        line2[COL_1] = 'o';
        valid = 1;
        return *line2;
    }
    else if (*o == 5 && line2[COL_2] == ' ')
    {
        line2[COL_2] = 'o';
        valid = 1;
        return *line2;
    }
    else if (*o == 6 && line2[COL_3] == ' ')
    {
        line2[COL_3] = 'o';
        valid = 1;
        return *line2;
    }
    else if (*o == 7 && line3[COL_1] == ' ')
    {
        line3[COL_1] = 'o';
        valid = 1;
        return *line3;
    }
    else if (*o == 8 && line3[COL_2] == ' ')
    {
        line3[COL_2] = 'o';
        valid = 1;
        return *line3;
    }
    else if (*o == 9 && line3[COL_3] == ' ')
    {
        line3[COL_3] = 'o';
        valid = 1;
        return *line3;
    }
    else
    {
        printf("Invalid input\n");
    }
    }
    return *line1;
}