#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() 
{
    FILE * inFile;
    char * token;
    char section[50];
    char sec1[50];
    char sec2[50];
    char sec3[50];
    char sec4[50];

    int count = 0;

    inFile = fopen("section.txt", "r");

    while(!feof(inFile))
    {

        fgets(section, 50, inFile);

        token = strtok(section, ",-");
        strcpy(sec1, token);
        //printf("First Set:(%s)\n", sec1);

        token = strtok(NULL, ",-\n");
        strcpy(sec2, token);

        token = strtok(NULL, ",-\n");
        strcpy(sec3, token);

        token = strtok(NULL, ",-\n");
        strcpy(sec4, token);

        printf("(%s) (%s)\n", sec1, sec2);
        printf("(%s) (%s)\n", sec3, sec4);

        if(atoi(sec3) >= atoi(sec1) && atoi(sec3) <= atoi(sec2))
        {
            count++;
        }
        else if (atoi(sec1) >= atoi(sec3) && atoi(sec1) <= atoi(sec4))
        {
            count++;
        } else if (atoi(sec2) >= atoi(sec3) && atoi(sec2) <= atoi(sec4))
        {
            count++;
        } else if (atoi(sec4) >= atoi(sec1) && atoi(sec4) <= atoi(sec2))
        {
            count++;
        }

        printf("Current Count: %d\n", count);
    }

    printf("Total Count: %d", count);


    return 0;
}