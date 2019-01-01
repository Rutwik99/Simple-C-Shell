#include "maindef.h"

int main()
{
	char ch[2] = {"\n"};
	int i;

	getcwd(current_directory, sizeof(current_directory));
	signal(SIGINT, sigintHandler);

	while(1)
	{
		// Prompt
		clear_variables1();
		prompt();
		fgets(input_buffer, 1024, stdin);

		
		// If no input is given then nothing is done
		if(strcmp(input_buffer, ch) == 0)
    	{
            continue;
		}

		// Finding the length of the input
		len = strlen(input_buffer);
		input_buffer[len - 1] = '\0';

		// printf("%s\n", input_buffer);

		// Command to stop execution of shell
		if(strcmp(input_buffer, "exit\n") == 0)
		{
			exit(0);
		}

		// Splits into separate commands
		split_cmds();

		for(i = 0; i < no_cmds - 1; i++)
		{
			strcat(cmds[i], "\0");
		}
		cmds[i][strlen(cmds[i])] = '\0';

		for(i = 0; i < no_cmds; i++)
		{
			clear_variables2();
			
			// Splits the input into individual words
			split_args(cmds[i]);
			
			// if 'exit' command is typed then the shell will stop
			if(strcmp(args[0], "exit") == 0) 
			{
				exit(0);
			}

			// Executes the built-in commands(cd, pwd, echo)
			builtin(cmds[i]);
			
			// Executes the 'ls' command with its flags
			if(strcmp(args[0], "ls") == 0)
			{
				check_ls();
				continue;
			}

			// Executes the 'pinfo' command
			if(strcmp(args[0], "pinfo") == 0)
			{
				pinfo_command();
				execFlag = 1;
				continue;
			}

			// Personal Reminder using 'remindme' command
			if(strcmp(args[0], "remindme") == 0)
			{
				remindme_command(cmds[i]);
				execFlag = 1;
				continue;
			}

			// Executes the 'clock' command
			if((strcmp(args[0], "clock") == 0) && (strcmp(args[1], "-t") == 0))
			{
				clock_command(cmds[i]);
				execFlag = 1;
				continue;
			}

			// Executes System Commands
			if(execFlag == 0)
			{
				execCommand();
			}
		}
	}

	return 0;
}