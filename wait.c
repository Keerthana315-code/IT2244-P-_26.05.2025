#include<stdio.h>
#include<stdlib.h>//for exit
#include<unistd.h>// for fork, for sleep
#include<sys/wait.h>// for wait

int main()
{
	pid_t pid;
	
	printf("parent processs started. PID: %d\n",getpid());
	
	pid = fork();//create a new child processs
	
	if(pid<0)
	{
		perror("fork failed");
		exit(1);
	}
	if(pid == 0)
	{
		// child processs
		printf("child process. PID: %d, sleeping for 2 seconds..\n",getpid());
		sleep(2);
		printf("child process exiting.\n");
		exit(0);
	}
	else
	{
		//parent process
		int status;
		printf("parent waiting for child to finish...\n");
		wait(&status);
		if(WIFEXITED(status))
		{
			printf("child exited with status: %d \n",WIFEXITED(status));
		}
		else
		{
			printf("child did not exit normally.\n");
		}
		printf("parent process ending.\n");
	}
	return 0;
}