#include "maindef.h"

// Function to execute the built-in commmands(cd, pwd, echo)
void builtin(char *s)
{
	int i = 1;
	int j;
	int c;
	int flag = 0;

	// checking if command is 'cd'
	if(strcmp(args[0], "cd") == 0)
	{
		if(args[1] == NULL)
		{
			chdir(current_directory);
			execFlag = 1;
		}
		else if(strcmp(args[1], "~") == 0)
        {
			chdir(current_directory);
			execFlag = 1;
		}
		else if(strcmp(args[1], "..") == 0)
		{
			chdir("..");
			execFlag = 1;
		}
		else if(strcmp(args[1], ".") == 0)
		{
			execFlag = 1;
		}
		else if(chdir(args[1]) < 0)
		{
			printf("bash: cd: %s: No such file or directory\n", args[1]);
			execFlag = 1;
		}
		else
		{
			if(args[1][strlen(args[1]) - 1] == '/')
			{
				args[1][strlen(args[1]) - 1] = '\0';
			}
			execFlag = 1;
		}
	}

	// Checking if command is pwd
	else if(strcmp(args[0], "pwd") == 0)
	{
		// printing the absolute path
		getcwd(temp, sizeof(temp));
		printf("%s\n", temp);
		execFlag = 1;
	}

	// Add functionalities
	// 1. add feature for use with single quotes('')
	else if(strcmp(args[0], "echo") == 0)
	{
		c = 0;
		for(i = 0; i < strlen(s); i++)
		{	
			// bonus "" and  ''
			if(s[i] == '\"')
			{
				if(s[strlen(s) - 1] == '\"')
				{
					for(j = i + 1; j < strlen(s) - 1; j++)
					{
						cmd_exec[c++] = s[j];
					}
					cmd_exec[c] = '\0';
					flag = 1;
					printf("%s\n", cmd_exec);
					execFlag = 1;
					break;
				}
				else
				{
					printf("Usage: echo \"<text to be printed>\"\n");
					flag = 1;
				}
			}
			else if(s[i] == '\'')
			{
				if(s[strlen(s) - 1] == '\'')
				{
					for(j = i + 1; j < strlen(s) - 1; j++)
					{
						cmd_exec[c++] = s[j];
					}
					cmd_exec[c] = '\0';
					flag = 1;
					printf("%s\n", cmd_exec);
					execFlag = 1;
					break;
				}
				else
				{
					printf("Usage: echo \"<text to be printed>\"\n");
					flag = 1;
				}
			}
		}

		if(flag == 0)
		{
			i = 1;
			while(args[i] != NULL)
			{
				printf("%s ", args[i]);
				i++;
			}
			printf("\n");
			execFlag = 1;
		}
	}
}