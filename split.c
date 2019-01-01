#include "maindef.h"

// Function to split the input into commands into cmds[]
void split_cmds()
{
	int cnt1;
	
	cnt1 = 1;
	cmd_exec = strdup(input_buffer);

	cmds[0] = strtok(cmd_exec, ";");
	no_cmds++;
	while((cmds[cnt1] = strtok(NULL, ";")) != NULL)
	{
		cnt1++;
		no_cmds++;
	}
	cmds[cnt1] = NULL;
}

// Function to split the arguments of the command into args[]
void split_args(char *s)
{
	int cnt2;

	cnt2 = 1;
	cmd_exec = strdup(s);

	args[0] = strtok(cmd_exec, "\t ");
	no_args++;
	while((args[cnt2] = strtok(NULL, "\t ")) != NULL)
	{
		cnt2++;
		no_args++;
	}
	args[cnt2] = NULL;
}