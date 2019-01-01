#include "maindef.h"

void clock_command(char *s)
{
    char rtc_file[2048];
    char line1[2048];    
    char line2[2048];    
    char* rtc_param1[100];
    char* rtc_param2[100];

    strcpy(rtc_file, "/proc/driver/rtc");

    while(1)
    {
        FILE* inpFile = fopen(rtc_file, "r");
        if(inpFile == NULL)
        {
            printf("Command Has Failed\n");
        }
        else
        {
            fgets(line1, sizeof(line1), inpFile);
            fgets(line2, sizeof(line2), inpFile);
        }

        rtc_param1[0] = strtok(line1, ":\n");
        for(int i = 0; rtc_param1[i] != NULL; i++)
        {
            rtc_param1[i + 1] = strtok(NULL, ":\n");
        }

        rtc_param2[0] = strtok(line2, ":-\n");
        for(int i = 0; rtc_param2[i] != NULL; i++)
        {
            rtc_param2[i + 1] = strtok(NULL, ":-\n");
        }

        if(atoi(rtc_param2[2]) == 1)
        {
            printf("%s Jan%s,%s:%s:%s\n", rtc_param2[3], rtc_param2[1], rtc_param1[1], rtc_param1[2], rtc_param1[3]);
        }
        else if(atoi(rtc_param2[2]) == 2)
        {
            printf("%s Feb%s,%s:%s:%s\n", rtc_param2[3], rtc_param2[1], rtc_param1[1], rtc_param1[2], rtc_param1[3]);
        }
        else if(atoi(rtc_param2[2]) == 3)
        {
            printf("%s Mar%s,%s:%s:%s\n", rtc_param2[3], rtc_param2[1], rtc_param1[1], rtc_param1[2], rtc_param1[3]);
        }
        else if(atoi(rtc_param2[2]) == 4)
        {
            printf("%s Apr%s,%s:%s:%s\n", rtc_param2[3], rtc_param2[1], rtc_param1[1], rtc_param1[2], rtc_param1[3]);
        }
        else if(atoi(rtc_param2[2]) == 5)
        {
            printf("%s May%s,%s:%s:%s\n", rtc_param2[3], rtc_param2[1], rtc_param1[1], rtc_param1[2], rtc_param1[3]);    
        }
        else if(atoi(rtc_param2[2]) == 6)
        {
            printf("%s Jun%s,%s:%s:%s\n", rtc_param2[3], rtc_param2[1], rtc_param1[1], rtc_param1[2], rtc_param1[3]);
        }
        else if(atoi(rtc_param2[2]) == 7)
        {
            printf("%s Jul%s,%s:%s:%s\n", rtc_param2[3], rtc_param2[1], rtc_param1[1], rtc_param1[2], rtc_param1[3]);
        }
        else if(atoi(rtc_param2[2]) == 8)
        {
            printf("%s Aug%s,%s:%s:%s\n", rtc_param2[3], rtc_param2[1], rtc_param1[1], rtc_param1[2], rtc_param1[3]);
        }
        else if(atoi(rtc_param2[2]) == 9)
        {
            printf("%s Sep%s,%s:%s:%s\n", rtc_param2[3], rtc_param2[1], rtc_param1[1], rtc_param1[2], rtc_param1[3]);
        }
        else if(atoi(rtc_param2[2]) == 10)
        {
            printf("%s Oct%s,%s:%s:%s\n", rtc_param2[3], rtc_param2[1], rtc_param1[1], rtc_param1[2], rtc_param1[3]);
        }
        else if(atoi(rtc_param2[2]) == 11)
        {
            printf("%s Nov%s,%s:%s:%s\n", rtc_param2[3], rtc_param2[1], rtc_param1[1], rtc_param1[2], rtc_param1[3]);
        }
        else if(atoi(rtc_param2[2]) == 12)
        {
            printf("%s Dec%s,%s:%s:%s\n", rtc_param2[3], rtc_param2[1], rtc_param1[1], rtc_param1[2], rtc_param1[3]);
        }
        sleep(atoi(args[2]));
    }
}