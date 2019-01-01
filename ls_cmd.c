#include "maindef.h"

// Function to perform ls
void ls_command()
{
	struct dirent **filelist;
	int n;
	int i;

	n = scandir(".", &filelist, NULL, alphasort);
	for(i = 0; i < n; i++)
	{
		if((filelist[i]->d_name)[0] != '.')
		{
			printf("%s\n", filelist[i]->d_name);
		}
		free(filelist[i]);
	}
	free(filelist);
}

// Function to perform ls -a
void lsa_command()
{
	struct dirent **filelist;
	int n;
	int i;

	n = scandir(".", &filelist, NULL, alphasort);
	for(i = 0; i < n; i++)
	{		
		printf("%s\n", filelist[i]->d_name);
		free(filelist[i]);
	}
	free(filelist);
}

// Function to perform ls -l
void lsl_command()
{
	DIR * dir; 
	struct dirent * file; 
	struct stat sbuf;
    char buf[128];
    struct passwd pwent, * pwentp;
    struct group grp, * grpt;
    char datestring[256];
    struct tm time;
	char perms[11];

	getcwd(path, sizeof(path));
    dir = opendir(path);
    while(file=readdir(dir)) 
	{
		if((file->d_name)[0] != '.')
		{
			stat(file->d_name, &sbuf);
			if(S_ISREG(sbuf.st_mode)) perms[0]='-';
			else if(sbuf.st_mode & S_ISDIR(sbuf.st_mode)) perms[0]='d';
			else if(sbuf.st_mode & S_ISFIFO(sbuf.st_mode)) perms[0]='|';
			else if(sbuf.st_mode & S_ISSOCK(sbuf.st_mode)) perms[0]='s';
			else if(sbuf.st_mode & S_ISCHR(sbuf.st_mode)) perms[0]='c';
			else if(sbuf.st_mode & S_ISBLK(sbuf.st_mode)) perms[0]='b';
			else perms[0]='l';  // S_ISLNK
			perms[1] = (sbuf.st_mode & S_IRUSR) ? 'r':'-';
			perms[2] = (sbuf.st_mode & S_IWUSR) ? 'w':'-';
			perms[3] = (sbuf.st_mode & S_IXUSR) ? 'x':'-';
			perms[4] = (sbuf.st_mode & S_IRGRP) ? 'r':'-';
			perms[5] = (sbuf.st_mode & S_IWGRP) ? 'w':'-';
			perms[6] = (sbuf.st_mode & S_IXGRP) ? 'x':'-';
			perms[7] = (sbuf.st_mode & S_IROTH) ? 'r':'-';
			perms[8] = (sbuf.st_mode & S_IWOTH) ? 'w':'-';
			perms[9] = (sbuf.st_mode & S_IXOTH) ? 'x':'-';
			perms[10] = '\0';
			printf("%s", perms);

			printf(" %d", (int)sbuf.st_nlink);
			if (!getpwuid_r(sbuf.st_uid, &pwent, buf, sizeof(buf), &pwentp))
				printf(" %s", pwent.pw_name);
			else
				printf(" %d", sbuf.st_uid);
	
			if (!getgrgid_r (sbuf.st_gid, &grp, buf, sizeof(buf), &grpt))
				printf(" %s", grp.gr_name);
			else
				printf(" %d", sbuf.st_gid);
			printf(" %5d", (int)sbuf.st_size);
			
			localtime_r(&sbuf.st_mtime, &time);
			/* Get localized date string. */
			strftime(datestring, sizeof(datestring), "%b %e %R", &time);
	
			printf(" %s %s\n", datestring, file->d_name);
		}
    }
}

// Function to perform ls -a -l
void lsal_command()
{
	DIR * dir; 
	struct dirent * file; 
	struct stat sbuf;
    char buf[128];
    struct passwd pwent, * pwentp;
    struct group grp, * grpt;
    char datestring[256];
    struct tm time;
	char perms[11];
	getcwd(path, sizeof(path));
    dir = opendir(path);
    while(file=readdir(dir)) 
	{
		stat(file->d_name, &sbuf);
		if(S_ISREG(sbuf.st_mode)) perms[0]='-';
		else if(sbuf.st_mode & S_ISDIR(sbuf.st_mode)) perms[0]='d';
		else if(sbuf.st_mode & S_ISFIFO(sbuf.st_mode)) perms[0]='|';
		else if(sbuf.st_mode & S_ISSOCK(sbuf.st_mode)) perms[0]='s';
		else if(sbuf.st_mode & S_ISCHR(sbuf.st_mode)) perms[0]='c';
		else if(sbuf.st_mode & S_ISBLK(sbuf.st_mode)) perms[0]='b';
		else perms[0]='l';  // S_ISLNK
		perms[1] = (sbuf.st_mode & S_IRUSR) ? 'r':'-';
		perms[2] = (sbuf.st_mode & S_IWUSR) ? 'w':'-';
		perms[3] = (sbuf.st_mode & S_IXUSR) ? 'x':'-';
		perms[4] = (sbuf.st_mode & S_IRGRP) ? 'r':'-';
		perms[5] = (sbuf.st_mode & S_IWGRP) ? 'w':'-';
		perms[6] = (sbuf.st_mode & S_IXGRP) ? 'x':'-';
		perms[7] = (sbuf.st_mode & S_IROTH) ? 'r':'-';
		perms[8] = (sbuf.st_mode & S_IWOTH) ? 'w':'-';
		perms[9] = (sbuf.st_mode & S_IXOTH) ? 'x':'-';
		perms[10] = '\0';
		printf("%s", perms);

		printf(" %d", (int)sbuf.st_nlink);

		if (!getpwuid_r(sbuf.st_uid, &pwent, buf, sizeof(buf), &pwentp))
			printf(" %s", pwent.pw_name);
		else
			printf(" %d", sbuf.st_uid);

		// Prints the name
		if (!getgrgid_r (sbuf.st_gid, &grp, buf, sizeof(buf), &grpt))
			printf(" %s", grp.gr_name);
		else
			printf(" %d", sbuf.st_gid);

		// Prints the size
		printf(" %5d", (int)sbuf.st_size);
		
		localtime_r(&sbuf.st_mtime, &time);
		/* Get localized date string. */
		strftime(datestring, sizeof(datestring), "%b %e %R", &time);

		// Prints the date and time
		printf(" %s %s\n", datestring, file->d_name);
    }
}

void check_ls()
{
	if(!args[1])
	{
		ls_command();
		execFlag = 1;
	}
	else if((strcmp(args[1], "-al") == 0 || strcmp(args[1], "-la") == 0) && !args[2])
	{
		lsal_command();
		execFlag = 1;
	}
	else if((strcmp(args[1], "-a") == 0) && !args[2])
	{
		lsal_command();
		execFlag = 1;
	}
	else if((strcmp(args[1], "-l") == 0) && !args[2])
	{
		lsal_command();
		execFlag = 1;
	}
	else if((strcmp(args[1], "-a") == 0 || strcmp(args[1], "-l") == 0) && (strcmp(args[2], "-a") == 0 || strcmp(args[2], "-l") == 0))
	{
		lsal_command();
		execFlag = 1;
	}
}