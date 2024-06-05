#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
void *thread_fn(void *);
int count=0;
pthread_mutex_t lock;
int main(){
	int i=0;
	pthread_t th[4];
	pthread_mutex_init(&lock,NULL);
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
	pthread_mutex_destroy(&lock);
	printf("Main thread Exit\n");
	}
void *thread_fn(void *args){
	pthread_mutex_lock(&lock);
	count++;
	printf("Thread- %d started\n",count);
	sleep(2);
	printf("Thread- %d finished\n",count);
	pthread_mutex_unlock(&lock);
}
