all: main

main: shell.o init.o signal_handlers.o split.o builtin_cmd.o ls_cmd.o sys_cmd.o pinfo_cmd.o reminder.o clk_cmd.o
	gcc *.o -o run

shell.o:
	gcc -c shell.c -o shell.o

init.o:
	gcc -c init.c -o init.o

signal_handlers.o:
	gcc -c signal_handlers.c -o signal_handlers.o

split.o:
	gcc -c split.c -o split.o

builtin_cmd.o:
	gcc -c builtin_cmd.c -o builtin_cmd.o

ls_cmd.o:
	gcc -c ls_cmd.c -o ls_cmd.o

sys_cmd.o:
	gcc -c sys_cmd.c -o sys_cmd.o

pinfo_cmd.o:
	gcc -c pinfo_cmd.c -o pinfo_cmd.o

reminder.o:
	gcc -c reminder.c -o reminder.o

clk_cmd.o:
	gcc -c clk_cmd.c -o clk_cmd.o

clean:
	rm -rf *.o
	rm -rf run


