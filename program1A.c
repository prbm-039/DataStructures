#include<stdio.h>
#include<stdlib.h>
int n;
void read(int a[]);
void display(int a[]);
void insert(int a[],int pos);
void delete(int a[],int pos);
int main(){
    int pos,cho;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    int arr[10000];
    read(arr);
    while(1){
        printf("\n*********** MAIN MENU ***********\n");
        printf("1.Display\t2.Insert at given position\t3.Delete at given position\t4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&cho);
        switch(cho){
            case 1: display(arr);
            break;
            case 2: printf("Enter The Position to Insert: ");
            scanf("%d",&pos);
            n=n+1;
            insert(arr,pos);
            break;
            case 3: printf("Enter The Position to Delete: ");
            scanf("%d",&pos);
            delete(arr,pos);
            n=n-1;
            break;
            case 4: exit(0);
            break;
        }
    }
}
void read(int a[]){
    printf("1.Enter The Array\n" );
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
}
void display(int a[]){
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
        }
    printf("\n");
}
void insert(int a[],int pos){
    int num;
    if(pos<0 || pos>n){
        printf("Invalid Position\n");
    }
    else{
        //n=n+1;
        for(int i=n;i>=pos;i--){
            a[i]=a[i-1];
        }
        printf("Enter the element to be inserted: ");
        scanf("%d",&num);
        a[pos-1]=num;
    }
}
void delete(int a[],int pos){
    if(pos<0 || pos>n){
        printf("Invalid Position\n");
    }
    else{
        int temp;
        for(int i=pos-1;i<n-1;i++){
            a[i]=a[i+1];
        }
    }
}