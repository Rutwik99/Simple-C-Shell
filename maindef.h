#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/dir.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <wait.h>

char *cmds[512];
char *args[512];
int flag, len;
char his_var[2000];
char input_buffer[1024];
char cwd[1024];
char temp[1024];
char path[1024];
char current_directory[1000];
char *cmd_exec;
int execFlag;
int no_args;
int no_cmds;
int is_bg;


void split_cmds();

void split_args(char *s);

void builtin(char *s);

void ls_command();

void lsa_command();

void lsl_command();

void lsal_command();

void check_ls();

void remindme_command();

void clock_command(char *s);

void execCommand();

char* int_to_string(int pid);

void pinfo_command();

void sigintHandler(int sig_num);

void sigchildHandler(int sig_num);

void alarmHandler(int sig_num);

void clear_variables1();

void clear_variables2();

void cust_pwd();

void prompt();
