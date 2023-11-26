#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head;
void beginsert();
void right_insert();
void right_delete();
void last_insert();
void last_delete();
void display();
int get_length();
int get_length(){
    struct node *temp;
    temp = head;
    int size = 1;
    if(temp == NULL){
        return -1;
    }
    while(temp->next != head){
        temp = temp->next;
        size++;
    }
    return size;
}
void main(){
    int cho;
    while(1){
        printf("\n\n\t\t\tMain Menu");
        printf("\n1.Insert From Front\n2.Insert Right of The Given Node\n3.Delete Right Of The Given Node\n4.Insert At The End\n5.Delete At The End\n6.Display\n7.Exit");
        printf("\nEnter Your Choice ");
        scanf("%d",&cho);
        switch (cho)
        {
        case 1: beginsert(); break;
        case 2: right_insert(); break;
        case 3: right_delete(); break;
        case 4: last_insert(); break;
        case 5: last_delete(); break;
        case 6: display(); break;
        case 7: exit(0);
        }
    }
}
void beginsert(){
    struct node *ptr,*temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter The Value = ");
    scanf("%d", &ptr->data);
    if(head == NULL){
        head = ptr;
        ptr->next = head;
        printf("\nNode Inserted!\n");
    }
    else{
        temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        ptr->next = head;
        temp->next = ptr;
        head = ptr;
        printf("\nNode Inserted!\n");
    }
}
void last_insert(){
    struct node *ptr,*temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter The Value = "); 
    scanf("%d",&ptr->data);
    if(head == NULL){
        head = ptr;
        ptr->next = head;
        printf("\nNode Inserted!\n");
    }else{
        temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        ptr->next = temp->next;
        temp->next = ptr;
        printf("\nNode Inserted!\n");
    }
}
void last_delete(){
    struct node *ptr,*prev;
    ptr = head;
    if(head == NULL){
        printf("List Empty!\n");
    }
    while(ptr->next != head){
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = ptr->next;
    free(ptr);
    printf("\nNode Deleted!\n");
}
void right_insert(){
    struct node *ptr,*temp;
    int pos,i=1,len;
    printf("Enter The Position : ");
    scanf("%d",&pos);
    len = get_length();
    if(pos<0||pos>len){
        printf("Invalid position");
    }else if(pos==0){
        beginsert();
    }else if(pos==len){
        last_insert();
    }else{
        ptr = (struct node *)malloc(sizeof(struct node));
        printf("Enter The Value = ");
        scanf("%d",&ptr->data);
        temp = head;
        while(i<pos){
            temp = temp->next;
            i++;
        }
        ptr->next = temp->next;
        temp->next = ptr;
    }
}
void right_delete(){
    struct node *ptr,*prev;
    int pos,i=1,len;
    printf("Enter The Position : ");
    scanf("%d",&pos);
    len = get_length();
    if(pos<0||pos>len){
        printf("Invalid Position");
    }else if(pos==len){
        last_delete();
    }else{
        ptr = head;
        if(head == NULL){
        printf("List Empty!\n");
        }
        while(i<=pos){
            prev = ptr;
            ptr = ptr->next;
            i++;
        }
        prev->next = ptr->next;
        free(ptr);
        printf("\nNode Deleted\n");
    }
}
void display(){
    struct node *ptr;
    ptr = head;
    while(ptr->next != head){
        printf("%d",ptr->data);
        ptr = ptr->next;
        printf("--->");
    }
    printf("%d\t",ptr->data);
    int len=get_length();
    printf("\nNumber Of Nodes: %d\n",len);
}