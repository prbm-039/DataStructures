#include<stdio.h>
#include<stdlib.h>
#define max 3
int quu[max];
int front = -1;
int rear = -1;
void enqueue(int ele);
void dequeue();
void display();
int main(){
    int num,elem;
    while(1){
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d",&num);
        switch(num){
            case 1: printf("Enter The Element\n");
                    scanf("%d",&elem);
                    enqueue(elem);
                    break;
            case 2: dequeue(); 
                break;
            case 3: display();
                break;
            case 4:exit(0);
        }
    }
    return 0;
}
void enqueue(int ele){
    if(front == -1 && rear == -1){
        front = 0;
        rear = 0;
        quu[rear] = ele;
        printf("Ele here Inserted");
    }
    else if(((rear)+1)%max == front){
        printf("Queue Overflow");
    }
    else{
        rear = ((rear)+1)%max;
        quu[rear] = ele;
        printf("Ele Inserted");
    }
}
void display() 
{
    int i = front;
    if(front == -1){
        printf("\nQueue is Empty");
    }
    else{
        printf("\n Elements in a Queue are :");
        while(i != rear){
            printf("%d",quu[i]);
            i = (i+1)%max;
        }
        printf("%d",quu[rear]);
    }
}
void dequeue(){
    if((front==-1)&(rear==-1))
    {
        printf("\n queue is underflow");
    }
    else if(front==rear)
    {
        printf("\n the dequeued element is %d",quu[rear]);
        front = rear = -1;
    }
    else{
        printf("\n the dequeued element is %d",quu[front]);
        front = ((front)+1)%max;
    }
}