#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int findChoice(char enemyChoice, int result)
{
    //You need too win
    if(result == 2)
    {
        if(enemyChoice == 'A')
        {
            return 2;
        } else if (enemyChoice == 'B')
        {
            return 3;
        } else if (enemyChoice == 'C')
        {
            return 1;
        }
    //Tie
    } else if (result == 1)
    {
        if(enemyChoice == 'A')
        {
            return 1;
        } else if (enemyChoice == 'B')
        {
            return 2;
        } else if (enemyChoice == 'C')
        {
            return 3;
        }

    } else if(result == 0)
    {
        if(enemyChoice == 'A')
        {
            return 3;
        } else if (enemyChoice == 'B')
        {
            return 1;
        } else if (enemyChoice == 'C')
        {
            return 2;
        }
    }
}

int main()
{
    FILE * inFile;

    char choices[5];
    int points = 0;


     inFile = fopen("rpc.txt", "r");

     while (!feof(inFile))
     {
        fgets(choices, 5, inFile);

        //printf("%s", choices);

        //Base Points for Each Point
        //points += choices[2] - 87;
        //printf("Points: %d - %d = %d\n", choices[2], 87, (choices[2] - 87));

        if (choices[2] == 'X')
        {
            points += 0 + findChoice(choices[0], 0);
        } else if (choices[2] == 'Y')
        {
            points += 3 + findChoice(choices[0], 1);
        } else if (choices[2] == 'Z')
        {
            points += 6 + findChoice(choices[0], 2);
        }
        //printf("Current Points: %d\n", points);
     }

     printf("Total Points: %d", points);



    return 0;
}