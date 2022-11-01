//Libraries required
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

//Collatz function
int collatz(int num)
{   
    printf("\nChild Process running......\n\n");
    printf("The conjucture is:\n: ");
    printf("%d ",num);
    while(num!=1)
    {
        if (num%2 == 0)
        {
            num =num/2;
        }
        else if (num%2 == 1)
        {
            num = 3 * num + 1;
        }
        printf("%d ",num);
    }
return 0;
}

//Main function
void main(int argc, char *argv[])
{
    //Declaring required variables.
    int num, k = 0;
    pid_t pid;

    printf("\n\n------The Collatz conjecture-------\n");

    if (argc == 1)
    {   printf("\n-> Error: Starting number not entered\n");
        printf("\n-> Please enter the starting number through the command line\n\n");
        exit(1);    //Report the abnormal termination of the program
    } 
    else if (argc == 2)
    {
        if(atoi(argv[1]) <=  0)
        {
            printf("\n-> Error: Please enter a number greater than zero\n\n");
            exit(1);
        }
        num = atoi(argv[1]);
        printf("\nThe entered starting number is: %d\n",num);
    }


    //Process ID of parent
    printf("\nI am parent with pid: %d\n", (int) getpid());


    //fork a child process
    pid = fork();

    // A child process will be created
    printf("\n>> fork returned: %d\n", (int) pid);

    if (pid == -1)//error occured
    {
        printf("\nChild Process not created.");
    }
    else if (pid == 0) // child process
    {   printf("I am the child with pid %d\n", (int) getpid());
        printf("\nChild Process created.\n");
        collatz(num);
        printf("\n\nChild process is done.\n");
    }
    else if (pid > 0) // parent process
    {
        printf("Parent is waiting for child process to finish\n");
        wait(&k);
        // When the child is ended, then the parent will continue to execute its code
        printf("\nParent process is done.\n");
    }

}
