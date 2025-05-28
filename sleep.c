#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	printf("Program started\n");
	
	printf("sleeping for 3 seconds...\n");
	sleep(3);
	
	printf("Exiting the program.\n");
	exit(0);
}