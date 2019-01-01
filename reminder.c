#include "maindef.h"

int var1 = 1;
int var2 = 1;

void alarmHandler(int sig_num)
{
    if(var1 == 0)
        var1++;
    if(var2 == 0)
        var2++;
    pause(); /* Pause the process until the other process sends it's alarm signal. */
    signal(SIGALRM, alarmHandler);
    fflush(stdin);
}

void remindme_command(char *s)
{
    int i;
    int j;
    int c;
    pid_t pid, wpid;

    // String the message argument
    c = 0;
    for(i = 0; i < strlen(s); i++)
    {
        if(s[i] == '\"')
        {
            for(j = i + 1; j < strlen(s) - 1; j++)
            {
                cmd_exec[c++] = s[j];
            }
            cmd_exec[c] = '\0';
            break;
        }
    }

    // Printing the message after fixed time
    if(fork() != 0)
    {
        while(1)
        {
            signal(SIGALRM, alarmHandler);
            if(var1 == 1)
            {
                alarm(atoi(args[1]));
                var1--;
            }
	        break;
        }
    }
    else
    {
        sleep(atoi(args[1])); /* Allow the parent to get ready. */
        while(1)
        {
            signal(SIGALRM, alarmHandler);
            if(var2 == 1)
            {
                alarm(atoi(args[1]));
                var2--;
            }
            printf("\nReminder: %s\n", cmd_exec);
            fflush(stdout);
	        break;
        }
    }

    alarm(0);
    return;
}
