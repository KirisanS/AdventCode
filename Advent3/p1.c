#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{

    FILE * inFile;
    char ramSack[200];
    int totalSum = 0;

    inFile = fopen("ramsack.txt", "r");

    while(!feof(inFile))
    {
        
        fgets(ramSack, 200, inFile);
        if(strcmp(ramSack, "\n") == 1)
        {
            
            printf("%d\n", strlen(ramSack) - 1);
            printf("From 0 -> %d to %d -> %d\n", ((strlen(ramSack)-1)/2), (strlen(ramSack)-1)/2, strlen(ramSack)-1);
            for(int i = 0; i < ((strlen(ramSack)-1)/2); i++)
            {
                for(int j = (strlen(ramSack)-1)/2; j < strlen(ramSack)-1; j++)
                {
                    if(ramSack[i] == ramSack[j])
                    {
                        if(islower(ramSack[i]))
                        {
                            //printf("Priority: %c: %d\n",ramSack[i], ramSack[i] - 96);
                            totalSum += ramSack[i] - 96;
                            j = 300;
                            i = 300;
                        } else {
                            totalSum += ramSack[i] - 38;
                            j = 300;
                            i = 300;
                        }
                    }
                }
            } 
        }

    }

    printf("Total Sum: %d\n", totalSum);


    return 0;
}