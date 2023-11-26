#include<stdio.h>
#include<stdlib.h>
#define Max 5
struct stackk
{
    int top;
    int stk[Max];
}sta;
void push(int, struct stackk *);
void popp(struct stackk *);
void display(struct stackk *);
int main(){
    sta.top = -1;
    int cho, item;
    while(1){
    printf("\n*********** MAIN MENU ***********\n");
    printf("Enter your choice\n");
    printf("1 Push\n2 Pop\n3 Display\n4 Exit\n");
    scanf("%d",&cho);
    switch(cho){
        case 1: printf("Enter the item :");
            scanf("%d",&item);
            push(item,&sta);
            break;
        case 2: popp(&sta); 
            break;
        case 3: display(&sta);
            break;
        case 4: exit(0);
    }  
    }
    return 0;
}
void push(int item, struct stackk *s){
    if(s->top == Max-1)
        printf("The stack is full\n");
    else
    {
        (s->top)++;
        s->stk[s->top]=item;
    }
}
void popp(struct stackk *s)
{
    int item;
    if(s->top==-1)
        printf("The stack is empty\n");
    else
    {
        item=s->stk[s->top];
        (s->top)--;
        printf("%d deleted\n",item);
    }
}
void display(struct stackk *s)
{
    int t=s->top;
    if(s->top==-1)
        printf("The stack is empty\n");
    else
    {
        printf("Elements in the stack are\n");
    while(t>-1)
        {
        printf("%d ",s->stk[t--]);
        }
    printf("\n");
    }
}