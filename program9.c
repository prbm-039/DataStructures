#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head;
void beginsert();
void begin_delete();
void last_insert();
void last_delete();
void display();
void main(){
    int cho = 0;
    while(1){
        printf("\n\n\t\t\tMain Menu");
        printf("\n1.Insert From Front\n2.Delete From Front\n3.Insert At The End\n4.Delete At The End\n5.Display\n6.Exit");
        printf("\nEnter Your Choice ");
        scanf("%d",&cho);
        switch (cho)
        {
        case 1: beginsert(); break;
        case 2: begin_delete();break;
        case 3: last_insert(); break;
        case 4: last_delete(); break;
        case 5: display(); break;
        case 6: exit(0);
        }
    }
}
void beginsert(){
    struct node *ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    printf("Enter The Value = ");
    scanf("%d",&ptr->data);
    if(head == NULL){
        ptr->prev = NULL;
        ptr->next = NULL;
        head = ptr;
        printf("\nNode Inserted\n");
    }else{
        ptr->prev = NULL;
        ptr->next = head;
        head->prev = ptr;
        head = ptr;
        printf("\nNode Inserted\n");
    }
}
void begin_delete(){
    struct node *ptr;
    if (head == NULL){
        printf("Nothing to Delete\n");
    }else if(head->next == NULL){
        head = NULL;
        free(head);
    }else{
        ptr = head;
        head = head->next;
        head->prev = NULL;
        free(ptr);
        printf("\nNode Deleted\n");
    }
}
void last_insert(){
    struct node *ptr,*temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter The Value = \n");
    scanf("%d", &ptr->data);
    if(head == NULL){
        ptr->next = NULL;
        ptr->prev = NULL;
        head = ptr;
        printf("\nNode Inserted\n");
    }else{
        temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->prev = temp;
        ptr->next = NULL;
        printf("\nNode Inserted\n");
    }
}
void last_delete(){
    struct node *temp;
    temp = head;
    if(head == NULL){
        printf("\nNothing to Delete\n");
    }else if(head->next == NULL){
        head = NULL;
        free(temp);
        printf("\nNode Deleted\n");
    }else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
        printf("\nNode Deleted\n");
    }
}
void display(){
    struct node *ptr;
    ptr = head;
    int len = 0;
    if(head == NULL){
        printf("\nNothing To Print\n");
    }else{
        while(ptr!= NULL){// if we use ptr->next != NULL, we will have to print last node out of the while loop(Both Works)
            printf("%d",ptr->data);
            ptr = ptr->next;
            if(ptr!= NULL){
                printf("--->");
            }
            len++;
        }
        printf("\nNumber Of Nodes = %d",len);
    }
}