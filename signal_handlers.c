#include "maindef.h"

void sigintHandler(int sig_num)
{
    signal(SIGINT, sigintHandler);
    fflush(stdout);
}

void sigchildHandler(int sig_num)
{
    pid_t cpid;
    int status;
    while ((cpid = waitpid(-1, &status, WNOHANG)) > 0)
    {
        if(!WIFEXITED(status))
        {
            ;
        }
        else if (WIFEXITED(status))
        {
            fprintf(stderr, "\n%s with pid %d exited normally\n", args[0], cpid);
        }
    }
    return;
}
