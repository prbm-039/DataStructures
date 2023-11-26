// 4. Design, Develop and Implement a Program in C for the following Stack Applications
//    • Evaluation of Suffix expression with single digit operands and operators: +, -, \*, /, %, ^ b
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#define MAX 100
struct stack
{
int top;
double a[MAX];
};
void push(char,struct stack *);
double pop(struct stack *);
double compute(double,double,char);
int main()
{
    struct stack s;
    s.top = -1;
    int i;
    double op1,op2,res;
    char postfix[100],symb;
    printf("Enter postfix expression");
    scanf("%s",postfix);
    for(i=0;postfix[i]!='\0';i++)
    {
        symb =postfix[i];
        if(isdigit(symb))
            push(symb,&s);
        else
        {
            op2=pop(&s);
            op1=pop(&s);
            res = compute(op1,op2,symb);
            s.a[++s.top]=res;
        }
    }
    res=pop(&s);
    printf("Result after evaluation =%f",res);
    return 0;
}
void push(char symb,struct stack *s)
{
    if(s->top == MAX-1)
        printf("Stack Overflow");
    else
        s->a[++s->top]=symb-'0';
}
double pop(struct stack *s)
{
    if(s->top ==-1)
        printf("Stack is Empty\n");
    else
        return(s->a[s->top--]);
    }
    double compute(double op1,double op2,char symb)
{
    switch(symb)
    {
        case '+' : return(op1+op2);
        case '-' : return(op1-op2);
        case '*' : return(op1*op2);
        case '/' : return(op1/op2);
        case '$' :
        case '^' : return(pow(op1,op2));
    }
}