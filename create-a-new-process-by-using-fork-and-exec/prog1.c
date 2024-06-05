#include <stdio.h>
#include <unistd.h>
int main()
{
	int i;
	printf("In prog-1: my process ID is %d\n", getpid());
	printf("Output Generated from prog-1\n");
	for(i=1;i<=15;i++)
	{
		printf("%d\n", i);
		sleep(1);
	}
	printf("Exit From prog-1\n");
}

