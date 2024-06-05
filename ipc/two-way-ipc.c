#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
int main()
{
char message[3024],buffer[3024];
int fd1[2],fd2[2],pid=0;
if(pipe(fd1)==-1){
    perror("Pipe 1  creation failed\n");
    exit(0);
}
if(pipe(fd2)==-1){
    perror("Pipe 2 creation failed\n");
    exit(0);
}
pid=fork();
if(pid>0)
{
    close(fd1[0]);
    close(fd2[1]);
    while(1){
        memset(message,0,sizeof(message));
        printf("Enter data for child in Pipe 1\n");
        gets(message);
        write(fd1[1],message,1024);
        read(fd2[0],buffer,1024);
        printf("Received data from parent in Pipe 2: %s\n",buffer);
        sleep(1);
        if (strcmp(message,"exit")==0)
        break;
    }
}
else{
    close(fd1[1]);
    close(fd2[0]);
    while (1)
    {
        memset(buffer,0,sizeof(buffer));
        read(fd1[0],buffer,1024);
        printf("Received data from parent in Pipe 1: %s\n",buffer);
        printf("Enter data for child in Pipe 2\n");
        gets(message);
        write(fd2[1],message,1024);
        sleep(1);
        if(strcmp(buffer, "exit")==0)
        break;
    }
}
}

