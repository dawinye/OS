
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
	int ret = fork();
	

	if (ret < 0)
	{	
		fprintf(stderr, "fork failed\n");
		exit(1);
	}
	 else if (ret == 0) 
	{
		printf("Enter a number: ");
		int myInt;
		scanf("%d", &myInt);
		return myInt;
	}
	else 
	{	
		int status;
		int w = wait(&status);
 		printf("Child exited with status %d", WEXITSTATUS(status));
		return 0;
	}

}
