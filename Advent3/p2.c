#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{

    FILE * inFile;
    char ramSack1[200];
    char ramSack2[200];
    char ramSack3[200];
    int totalSum = 0;

    inFile = fopen("ramsack.txt", "r");

    while(!feof(inFile))
    {
        
        fgets(ramSack1, 200, inFile);
        fgets(ramSack2, 200, inFile);
        fgets(ramSack3, 200, inFile);

        //printf("Sack1: %s  Sack2: %s  Sack3: %s \n", ramSack1, ramSack2, ramSack3);

        for(int i = 0; i < strlen(ramSack1)-1; i++)
        {
            for(int j = 0; j < strlen(ramSack2)-1; j++)
            {
                if(ramSack1[i] == ramSack2[j])
                {
                    for(int k = 0; k < strlen(ramSack3)-1; k++)
                    {
                        if(ramSack1[i] == ramSack3[k])
                        {
                            if(islower(ramSack1[i]))
                            {
                                //printf("Priority: %c: %d\n",ramSack1[i], ramSack1[i] - 96);
                                totalSum += ramSack1[i] - 96;
                                j = 300;
                                i = 300;
                                k = 300;
                            } else {
                                //printf("Priority: %c: %d\n",ramSack1[i], ramSack1[i] - 38);
                                totalSum += ramSack1[i] - 38;
                                j = 300;
                                i = 300;
                                k = 300;
                            }
                        }
                    }
                }
            }
        } 

    }

    printf("Total Sum: %d\n", totalSum);


    return 0;
}