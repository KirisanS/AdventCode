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
    inFile = fopen("crates.txt", "r");
    char buffer[100];
    int numOfStacks = 0;

    int count = 0;
    int currentPosition = 1;
    char baseCrateArray[9][300];
    char crateArray[9][300];
    char deadBuffer[50];
    char moveBuffer[100];
    int top[9] = {0};

    int amount = 0;
    int from = 0;
    int to = 0;

    for(int i = 0; i < 8; i++)
    {
        fgets(baseCrateArray[i], 300, inFile);
    }

    for(int i = 8; i >= 0; i--)
    {
        //printf("Current: %s", baseCrateArray[i]);
        count = 0;
        currentPosition = 1;
        
        while(currentPosition < strlen(baseCrateArray[i]))
        {
            //printf("%c\n", baseCrateArray[i][currentPosition]);
            if(baseCrateArray[i][currentPosition] != ' ')
            {
                crateArray[count][top[count]] = baseCrateArray[i][currentPosition];
                top[count]++;
            }
            count++;
            currentPosition += 4;
        } 

    }

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < top[i]; j++)
        {
            printf("[%c] ", crateArray[i][j]);
        }
        printf("          Top [%d]\n", top[i]);
    }

    printf("\n\n\n");


    //Skip two lines 
    for(int i = 0; i < 2; i++)
    {
        fgets(deadBuffer, 100, inFile);
    }

    while(!feof(inFile))
    {
        fgets(moveBuffer, 100, inFile);

        amount = (moveBuffer[5]) - '0';
        from = (moveBuffer[12]) - '0'-1;
        to = (moveBuffer[17]) - '0'-1;

        printf("Amount: (%d)\nFrom: (%d)\nTo: (%d)\n", amount, from, to);

        for(int i = 0 ; i < amount; i++)
        {
            if(top[from] >= 0)
            {   
                crateArray[to][top[to]] = crateArray[from][top[from] - 1];
                crateArray[from][top[from] - 1] = ' ';

                top[from]--;
                top[to]++;
            }
        }  

        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < top[i]; j++)
            {
                printf("[%c] ", crateArray[i][j]);
            }
            printf("          Top [%d]\n", top[i]);
        } 
        printf("\n");
    }

    printf("\n\n\n---------\n");
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < top[i]; j++)
        {
            printf("[%c] ", crateArray[i][j]);
        }
        printf("          Top [%d]\n", top[i]);
    }
    

    for(int i = 0; i < 9; i++)
    {
        printf("[%c] ", crateArray[i][top[i]-1]);
    }
    printf("\n");
    return 0;
}