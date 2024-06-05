#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
int main()
{
char message[3024],buffer[3024];
int fd[2],pid=0;
if(pipe(fd)==-1){
    perror("Pipe creation failed\n");
    exit(0);
}
pid=fork();
if(pid>0)
{
    close(fd[0]);
    while(1){
        memset(message,0,sizeof(message));
        printf("Enter data for child\n");
        gets(message);
        write(fd[1],message,1024);
        sleep(1);
        if (strcmp(message,"exit")==0)
        break;
    }
}
else{
    close(fd[1]);
    while (1)
    {
        memset(buffer,0,sizeof(buffer));
        read(fd[0],buffer,1024);
        printf("Received data from parent: %s\n",buffer);
        sleep(1);
        if(strcmp(buffer, "exit")==0)
        break;
    }
}
}

