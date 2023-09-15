#include <stdio.h>
#include <string.h>
#include <stdlib.h>


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
        points += choices[2] - 87;
        printf("Points: %d - %d = %d\n", choices[2], 87, (choices[2] - 87));

        //Player Rock
        if (choices[2] == 'X')
        {
            if(choices[0] == 'A')
            {
                points += 3;

            } else if (choices[0] == 'B')
            {
                points += 0;
            } else if (choices[0] == 'C') {
                points += 6;
            }
        } else if (choices[2] == 'Y')
        {
            if(choices[0] == 'A')
            {
                points += 6;
            } else if (choices[0] == 'B')
            {
                points += 3;
            } else if (choices[0] == 'C')
            {
                points += 0;
            }
        } else if (choices[2] == 'Z')
        {
            if(choices[0] == 'A')
            {
                points += 0;
            } else if (choices[0] == 'B')
            {
                points += 6;
            } else if (choices[0] == 'C')
            {
                points += 3;
            }
        }

        printf("Updated Points: %d\n", points);

     }

    printf("Points: %d", points);

    return 0;
}