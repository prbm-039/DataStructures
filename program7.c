
#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *head;
void beginsert();
void display();
void main()
{
int choice =0;
    while(1)
    {
        printf("\n\n*********Main Menu*********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n==== ==\n"); printf("\n1.Insert in begining\n2.Show\n3.Exit\n"); 
        printf("\nEnter your choice?\n");
        scanf("\n%d", &choice);
    switch(choice){
        case 1:
        beginsert();
        break;
        case 2:
        display(); break;
        case 3: exit(0);
        }
    }
}
void beginsert(){
    struct node* ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    printf("Enter The data : ");
    scanf("%d",&ptr->data);
    if(head == NULL){
        head = ptr;
        ptr->next = NULL;
    }
    else{
        ptr->next = head;
        head = ptr;
    }
    printf("Node Inserted");
}
void display(){
    struct node* ptr;
    ptr = head;
    int len = 1;
    if(ptr==NULL){
        printf("Empty");
    }else{
        while(ptr->next != NULL){
            printf("%d\t",ptr->data);
            ptr = ptr->next;
            len += 1;
        }
        printf("%d\t",ptr->data);
        printf("\nNumber of nodes %d\n",len);
    }
}