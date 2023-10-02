#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    FILE * inFile;
    char packet[5000];
    int check = 13;
    int flag = 0;

    inFile = fopen("packet.txt", "r");

    while(!feof(inFile))
    {
        fgets(packet, 5000, inFile);
        //printf("Packet: (%s)\n", packet);

        while(check != strlen(packet))
        {
            for(int i = check; i > check-13; i--)
            {
                for(int j = i-1; j >= check-13; j--)
                {
                    if(flag == 0)
                    {
                        //printf("%c %c\n", packet[i], packet[j]);
                        if(packet[i] == packet[j])
                        {
                            //printf("Match Found\n");
                            flag = 1;
                        }
                    }
                }
            }
            if(flag == 0)
            {
                printf("Check: %d\n", check+1);
                check = strlen(packet)-1;
            } 
            flag = 0;
            check++;
        }
    }
}