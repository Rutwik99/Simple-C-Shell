#include "maindef.h"

// Function to reset variables
void clear_variables1()
{
	input_buffer[0] = '\0';
	no_cmds = 0;
	cwd[0] = '\0';
}

// Function to reset variables
void clear_variables2()
{
	no_args = 0;
	execFlag = 0;
	is_bg = 0;
}

// Function to generate relative path
void cust_pwd()
{
	char *token1[512];
	char *token2[512];
	char temp[1024];
	char pth[1024];
	int cnt;
	int no_toks1 = 0;
	int no_toks2 = 0;
	int i;

	cnt = 1;
	strcpy(temp, current_directory);
	token1[0] = strtok(temp, "/");
	no_toks1++;
	while((token1[cnt] = strtok(NULL, "/")) != NULL)
	{
		cnt++;
		no_toks1++;
	}
	token1[cnt] = NULL;


	cnt = 1;
	getcwd(pth, sizeof(pth));
	strcpy(temp, pth);
	token2[0] = strtok(temp, "/");
	no_toks2++;
	while((token2[cnt] = strtok(NULL, "/")) != NULL)
	{
		cnt++;
		no_toks2++;
	}
	token2[cnt] = NULL;

	if(no_toks1 == no_toks2)
	{
		strcpy(cwd, "~");
	}
	else
	{
		strcat(cwd, "~");
		for(i = no_toks1; i < no_toks2; i++)
		{
			strcat(cwd, "/");
			strcat(cwd, token2[i]);
		}
	}
}

void prompt()
{
	char shell[1000];
	char *buff;
	char hostname[1000];

	buff = (char *) malloc(10 * sizeof(char));
	buff = getlogin();

	gethostname(hostname, 1000);

	// Printing the relative path of the file
	cust_pwd();

	// Printing the prompt
	strcpy(shell, "<");
	strcat(shell, buff);
	strcat(shell, "@");
	strcat(shell, hostname);
	strcat(shell, ":");
	strcat(shell, cwd);
	strcat(shell, ">");

	printf("%s", shell);
}