#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
	int i;
	printf("In prog-2: my process ID is %d\n", getpid());
	/*char *argv[]={"./prog1", NULL};
	execvp("./prog1" , argv);
	wait(NULL); */  
	printf("Exit From prog-2\n");
}

