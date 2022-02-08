#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int main(int argc, char **argv)
{
	char buffer[MAX];

	while (1)
	{
		printf("$ ");
		fgets(buffer, MAX, stdin);
		int length = strlen(buffer);
		buffer[length-1] = '\0';
		printf("%s",buffer);
		printf("\n");
		
	}
        //unreachable, must ctrl c to quit
	return 0;
}
