#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * Demonstrating OS virtualization for applications 
 * on using the OS's system rescources. 
**/

// Program Start
int main(int argc, char *argv[]) 
{
    // Display the initial process created for the program
    printf("Initial Process PID: (pid:%d)\n", (int) getpid());

    // To test virtualization for processes using resources we use
    // value to demonstrate how this works for each process using it.
    int value = 100;
    int process = fork(); // create a process

    if (process < 0) 
    { // Fork failed; print error; exit program
        fprintf(stderr, "fork failed\n");
        exit(1);
    } 
    else if (process == 0) 
    { // Run our child (new process)
        printf("-------------------------------\n\n");        
        printf("Hello, I am child (pid:%d)\n\n", (int) getpid());        
        printf("My initial value is: %d\n", value);
        value = 200;
        printf("My new value contains: %d\n\n", value);
        printf("-------------------------------\n\n");
    } 
    else 
    { // Parent goes down this path (main)
        int process_wait = wait(NULL);
        printf("-------------------------------\n\n");
        printf("Hello, I am parent of %d (process_wait:%d) (pid:%d)\n\n",
        process, process_wait, (int) getpid());        
        printf("My initial value is: %d\n", value);
        value = 300;
        printf("My new value contains: %d\n\n", value);
        printf("-------------------------------\n");
    }

    return 0;
} // End Program
