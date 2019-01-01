#include "maindef.h"

// Function to execute system commands
void execCommand()
{
	int status;
	pid_t pid, wpid;

	if(strcmp(args[no_args - 1], "&") == 0)
	{
		is_bg = 1;
		args[no_args - 1] = NULL;
	}
	
	pid = fork();
	if(pid == -1)
	{
		printf("Fork Command has Failed\n");
	}
	else if(pid == 0)
	{
		if(execvp(args[0], args) < 0)
		{
			printf("Command could not be executed\n");
			return;
		}
		exit(0);
	}

	// Foreground process
	if(is_bg == 0)
	{
		wpid = waitpid(pid, &status, WUNTRACED);
		while(!WIFEXITED(status) && !WIFSIGNALED(status) && !WIFSTOPPED(status))
		{
			wpid = waitpid(pid, &status, WUNTRACED);
		}
		return;
	}
	
	// Background process
	else
	{
		signal(SIGCHLD, sigchildHandler);
		printf("%d\n", pid);
	}
}