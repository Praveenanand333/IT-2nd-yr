#include<stdio.h>
int arr1[100];
int i,length=0,pos;
void createlist(){
    int size,count=0;
    printf("\nEnter the size of the array:");
    scanf("%d",&size);
    for(i=0;i<size;i++){
        printf("\nEnter the element of array[%d]:");
        scanf("%d",&arr1[count]);
        count++;
    }
        for(length=0;arr1[length]!='\0';length++);
printf("\n List  created");

}
void Insertatlast(int n){
    arr1[length]=n;
    length++;
    }

void Insertatfirst(int n){
    printf("%d",length);
    for(i=0;i<length;i++){
        arr1[length-i]=arr1[length-i-1];
    }
    arr1[0]=n;
    length++;
}

void Insertatpos(int n,int pos){
    for(i=0;length-i>pos;i++){
        arr1[length-i]=arr1[length-i-1];
    }
    arr1[pos]=n;
    length++;
}
void Display(){
printf("[");
for(i=0;i<length;i++){
printf("%d,",arr1[i]);
}
 printf("]\n");
}
void main(){
    
    int *a;
    int  n;
    int choice;
    while (1)
    {
    printf("1-Create a list\n2-Insert at beginning\n3-Insert at end\n4-Insert at position\n5-Display\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
    createlist();
        break;
    case 2:
    printf("\nEnter the number to be inserted:");
    scanf("%d",&n);
    Insertatfirst(n);
    break;
    case 3:
     printf("\nEnter the number to be inserted:");
    scanf("%d",&n);
    Insertatlast(n);
    break;
       case 4:
     printf("\nEnter the number to be inserted:");
    scanf("%d",&n);
    printf("\n Enter the position:");
    scanf("%d",&pos);
    Insertatpos(n,pos);
    break;
    case 5:
    Display();
    default:
        break;
    } }
}