#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
void *thread_fn(void *);
int main(){
	char message[]="Hello World";
	int res;
	void *thread_result;
	pthread_t th;
	res=pthread_create(&th,NULL,thread_fn,(void *)message);
	if(res!=0){
		perror("Thread creation failed\n");
		exit(0);
	}
	printf("Wait for thread joining\n");
	res=pthread_join(th,&thread_result);
	if(res!=0){
		perror("Thread joining failed\n");
		exit(0);
	}
	printf("Thread joined:%s\n",(char *)thread_result);
	printf("Exit from main thread\n");
}
void *thread_fn(void *args){
	printf("In child thread:%s\n",(char *)args);
	sleep(2);
	pthread_exit("Thank you");
}
