#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
void *thread_fn(void *);
int count=0;
sem_t s;
int main(){
	int i=0;
	pthread_t th[4];
	sem_init(&s,0,1);
	while(i<4){
	pthread_create(&th[i],NULL,thread_fn,NULL);
	i++;
	}
	printf("Wait for child thread join\n");
	i=0;
	while(i<4){
	pthread_join(th[i],NULL);
	i++;
	}
	sem_destroy(&s);
	printf("Main thread exit\n");
	}
void *thread_fn(void *args){
	sem_wait(&s);
	count++;
	printf("Thread-%d started\n",count);
	sleep(2);
	printf("Thread-%d finished\n",count);
	sem_post(&s);
}
