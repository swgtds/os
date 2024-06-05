#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int mutex=1;
int full=0,empty=10,x=0;
void producer()
{
    --mutex;
    ++full;
    --empty;
    x++;
    printf("\nProducer produces item %d", x);
    ++mutex;
}
void consumer(){
    --mutex;
    --full;
    ++empty;
    printf("\n Consumer consumes item %d", x);
    x--;
    ++mutex;
}
int main()
{
    int n,i;
    printf("\nPress 1 for Producer\nPress 2 for Consumer\nPress 3 for exit");
    for (i = 1; i>0; i++)       
    {
        printf("\nEnter the Choice: ");
        scanf("%d",&n);
        switch(n){
            case 1:
            if((mutex==1)&&(empty!=0))
            {
                producer();
            }
            else
            {
                printf("Buffer is Full");
            }
            break;
            case 2:
            if((mutex==1)&&(full!=0))
            {
                consumer();
            }
            else
            {
                printf("Buffer is Empty");
            }
            break;
            case 3:
            exit(0);
            break;
        }
    }
    return 0;
    
}