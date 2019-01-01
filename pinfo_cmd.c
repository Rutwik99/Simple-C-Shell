#include "maindef.h"

char* int_to_string(int pid)
{
	char* buf = (char*)malloc(10);
	sprintf(buf, "%d", pid);
	return buf;
}

void pinfo_command()
{
    char s_file[2048];
    char ex_file[2048];
    char line[1024];
    char* s_param[100];
    char ex_path[2048];
    int ret;

    strcpy(s_file, "/proc/");
    
    if(!args[1])
    {
        strcat(s_file, int_to_string(getpid()));
    }
    else
    {
        strcat(s_file, args[1]);
    }
    
    strcpy(ex_file, s_file);
    strcat(s_file, "/stat");

    // Path of s_file is /proc/<PID>/stat
    FILE* fd = fopen(s_file, "r");
    if(fd == NULL)
    {
        printf("Process doesn't exist\n");
    }
    else
    {
        fgets(line, sizeof(line), fd);

        s_param[0] = strtok(line, " ");
        for(int i = 0; s_param[i] != NULL;)
        {
            s_param[i + 1] = strtok(NULL, " ");
            i++;
        }

        printf("pid -- %s\n", s_param[0]);
        printf("Process Status -- %s\n", s_param[2]);
        printf("Virtual Memory -- %s\n", s_param[22]);
    
        strcat(ex_file, "/exe");

        // Path of ex_file is /proc/<PID>/exe
		ret = readlink(ex_file, ex_path, sizeof(ex_path));
        if(ret < 0)
        {
			printf("Unable to find the executable path\n");
        }
		else
        {
            ex_path[ret] = '\0';
            if(ex_path[1] == 'h' && ex_path[2] == 'o' && ex_path[3] == 'm' && ex_path[4] == 'e')
            {
			    printf("Executable Path: ~%s\n", &ex_path[strlen(current_directory)]);	
            }
            else
            {
                printf("Executable Path: %s\n", ex_path);
            }
        }
    }
}