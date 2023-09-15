#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
    FILE * inFile;
    char buf[400];
    int bufNum = 0;
    int maxCal1 = 0;
    int maxCal2 = 0;
    int maxCal3 = 0;

    int lineCount = 0;

    inFile = fopen("test.txt", "r");

    while (!feof(inFile))
    {
        lineCount++;
        fgets(buf, 400, inFile);
        //printf("%s", buf);

        bufNum += atoi(buf);

        if(strcmp(buf, "\n") == 0) 
        {
            //printf("Cals: %d\n", bufNum);

            if (bufNum > maxCal3)
            {
                if(bufNum > maxCal2)
                {
                    if(bufNum > maxCal1)
                    {
                        maxCal2 = maxCal1;
                        maxCal1 = bufNum;
                    } else {
                        maxCal3 = maxCal2;
                        maxCal2 = bufNum;
                    }
                } else {
                    maxCal3 = bufNum;
                }
            }
            bufNum = 0;
        }

    } 

    fclose(inFile);

    printf("1. %d  2. %d  3. %d\n", maxCal1, maxCal2, maxCal3);
    printf("MaxCals: %d\n", maxCal1 + maxCal2 + maxCal3);
    printf("Line Count: %d\n", lineCount);

    return 0;
}