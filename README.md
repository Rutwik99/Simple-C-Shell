**Shell Implementation in C**
**By Rutwik Reddy**


*Introduction*

This is a basic shell implemented using syscalls and C language.


*How to Run*

- Install make (if not installed) by running the command
    sudo apt-get install make

- Type the command 
    make run

- Run the shell
    ./run


*Features of this Shell*

1. cd command 
    - cd <dir>
    - cd ~
    - cd .
    - cd ..
    - cd 

2. pwd command
    - pwd

3. echo command
    - echo "<text>" (Bonus Marks)
    - echo '<text>' (Bonus Marks)
    - echo <text>

4. ls command
    - ls
    - ls -l
    - ls -a
    - ls -al and its variations

5. System commands
    - All commands work for foreground and background processes
    - PID is returned when we kill the background process

6. pinfo command(Prints information related to the process)
    - pinfo
    - pinfo <PID>     

Bonus:-

7. remindme command(Prints a message in the shell after a specifed duration)
    - remindme <duration> "<message>"

8. clock command(Prints the time of the machine every <duration> seconds)
    - clock -t <duration>