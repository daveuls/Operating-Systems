//         Course: CS3450-01 Operating Systems
//           Name: Ulikowski, David
//     Assignment: Programming 4
//  Date assigned: 10/11/18
//	 Date due: 10/23/18
// Date handed in: 10/23/18
//         Remark: Program that makes use of UNIX fork(), exec(), and wait() functions
//		   to pass an argument to child process which executes another program

#include <errno.h>
#include <iostream>
#include <stdio.h>
#include <sys/wait.h>
using namespace std;

int main(int argc, char *argv[])
{
	pid_t childPID = fork();	
	if (childPID < 0)	// if there is a fork error
	{
		perror("fork() error, child process was not created");
		exit(-1);
	}

	else if(childPID != 0)
	{
		printf("Parent PID is %d and Child PID is %d\n", getpid(), childPID);
		wait(NULL);
	}
	else
	{
		// child process will now run
		printf("Child process running with PID %d and Parent PID %d\n", getpid(), getppid());

		// child runs UNIX cp utility to copy file
		//system("cp source.txt cpSource.txt");

		// child runs copy program that was previously written
		// and saves a copy to file called "newest"
		execv("copy newest", &argv[0]);


	}

	return 0;
		
}






