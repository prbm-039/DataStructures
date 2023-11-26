// 3. Queue of Integers (Array with structure Implementation of Queue with size MAX)
//    • Insert an Element in to Queue.
//    • Delete an Element from Queue.
//    • Demonstrate Overflow and Underflow situations on Queue.
//    • Display the status of Queue .
//    • Exit
//    Support the program with appropriate functions for each of the above operations
#include<stdio.h>
#include<stdlib.h>
#define max 5
struct queue{   
    int quee[max];
    int front;
    int rear;
};
void enqueue(struct queue * quu, int ele);
void dequeue(struct queue * quu);
void display(struct queue * quu);
int main(){
    struct queue qu;
    int num,elem;
    qu.front = -1;
    qu.rear = -1;
    while(1){
        printf("\n1. Enqueue\t2. Dequeue\t3. Display\t4. Exit\n");
        scanf("%d",&num);
        switch(num){
            case 1: printf("Enter The Element\n");
                    scanf("%d",&elem);
                    enqueue(&qu,elem);
                    break;
            case 2: dequeue(&qu); 
                break;
            case 3: display(&qu);
                break;
            case 4:exit(0);
        }
    }
    return 0;
}
void enqueue(struct queue * quu, int ele){
    if(quu->rear == (max-1)){
        printf("Queue is Overflow\n");
    }
    else {
        if(quu->front == -1){
        quu->front = 0;
        }
        quu->rear++;
        quu->quee[quu->rear] = ele;
    }
}

void display(struct queue *quu) 
{
    int i = quu->front;
    printf("%d\n", i);
    if(quu->front == -1){
        printf("\nQueue is Empty");
    }
    else{
        printf("\n Elements in a Queue are :");
        while(i != quu->rear){
            printf("%d",quu->quee[i]);
            i = (i+1)%max;
        }
        printf("%d",quu->quee[quu->rear]);
    }
}
void dequeue(struct queue *quu){
    if((quu->front==-1)&(quu->rear==-1))
    {
        printf("\n queue is underflow");
    }
    else if(quu->front==quu->rear)
    {
        printf("\n the dequeued element is %d",quu->quee[quu->rear]);
        quu->front = -1;
        quu->rear = -1;
    }
    else{
        printf("\n the dequeued element is %d",quu->quee[quu->front]);
        quu->front++;
    }
}