#include <stdio.h>
#include <stdlib.h>

void print_args(int, char**);
int main(int argc, char **argv)
{
	print_args(argc, argv);
	return 0;
}

void print_args(int number, char **argv) {
	int i;
	for (i = 0; i < number; i++) {
		printf("argv[%d] ='%s'\n", i, argv[i]);
	}
} 

