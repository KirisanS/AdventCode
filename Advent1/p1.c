#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
    FILE * inFile;
    char buf[100];
    int bufNum = 0;
    int maxCal = 0;

    inFile = fopen("test.txt", "r");

    while (!feof(inFile))
    {
        fgets(buf, 200, inFile);
        //printf("%s", buf);

        bufNum += atoi(buf);

        if(strcmp(buf, "\n") == 0) 
        {
            //printf("Cals: %d\n", bufNum);

            if (bufNum > maxCal)
            {
                maxCal = bufNum;
            }
            bufNum = 0;
        }

    } 

    fclose(inFile);


    printf("MaxCals: %d", maxCal);

    return 0;
}