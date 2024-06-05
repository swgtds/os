#include <stdio.h>
#include <unistd.h>
int main()
{
int pid=0;
pid=fork();
if(pid>0)
{
printf("I am parent: My ID is %d and my child id is %d\n", getpid(), pid);
sleep(1);
}
else
{
printf("I am child: My ID is %d and my Parent id is %d\n", getpid(), getppid());
sleep(1);
}
}
