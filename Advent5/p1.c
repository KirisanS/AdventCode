#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void push()
{

}

int main()
{

    FILE * inFile;

    inFile = fopen("test.txt", "r");
    char buffer[100];
    int numOfStacks = 0;
    int check1 = 0;
    int currentPosition = 1;
    char crateArray[9][100];
    int top[9] = {0};
    while(!feof(inFile))
    {
        for(int i = 0; i < 9; i++)
        {
            fgets(crateArray[])
        }






        /*while(strcmp(fgets(buffer, 100, inFile), "\n") != 0)
        {
            currentPosition = 1;
            printf("Loop (%s)\n", buffer);
            //Run only once x
            if (check1 == 0)
            {
                numOfStacks = strlen(buffer) / 4;

                printf("NumOfStacks: %d\n", numOfStacks);
                check1 = 1;
            }

            for(int i = numOfStacks-1; i >=0; i--)
            {
                printf("Current Crate: %c \n", buffer[currentPosition]);
                if(buffer[currentPosition] != ' ')
                {
                    crateArray[i][top[i]] = buffer[currentPosition];
                    top[i] ++;
                }
                currentPosition += 4;
            }
            //printf("%d\n", strlen(buffer) / 4);
            sleep(1);

            for(int i = 0; i < numOfStacks; i++)
            {
                for(int j = 0; j < top[i]+1; j++)
                {
                    printf("%c ", crateArray[i][j]);
                }
                printf("          Top [%d]\n", top[i]);
            }



        }*/
    }

    return 0;
}