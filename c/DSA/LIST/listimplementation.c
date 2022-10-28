#include<stdio.h>
#include<stdlib.h>
int arr1[100];
int i,length=0,pos;


void createlist(){
    int size,count=0;
    printf("\nEnter the size of the array:");
    scanf("%d",&size);
    for(i=0;i<size;i++){
        printf("\nEnter the element of array[%d]:",i);
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



void Deleteatlast(){
length--;
printf("\nDeleted successfully\n");
}


void Deleteatfirst(){
for(i=1;i<length;i++){
arr1[i-1]=arr1[i];
}
length--;
printf("\nDeleted successfully\n");
}


void Deleteatpos(int pos){
for(i=pos;i<length-1;i++){
arr1[i]=arr1[i+1];
}
length--;
printf("\nDeleted successfully\n");
}



void Search(int n){
int flag=0;
for(i=0;i<length;i++){
if(arr1[i]==n){flag=1;}
}
if(flag==1){
printf("\nElement present\n");}
else{
printf("\nElement not found\n");
}
}

void Replace(int n,int pos){
arr1[pos]=n;
printf("\nReplaced successfully\n");

}
void Display(){
printf("[");
for(i=0;i<length;i++){
if(i!=length-1){
printf("%d,",arr1[i]);}
else{
printf("%d",arr1[i]);
}
}
 printf("]\n");
}


void main(){
    int  n;
    int choice;
       system("figlet MENU");
    while (1)
    {
    printf("\n************************\n");
    printf("1-Create a list\t\t|\n2-Insert at beginning\t|\n3-Insert at end\t\t|\n4-Insert at position\t|\n5-Display\t\t|\n6-Delete last element\t|\n7-Delete first element\t|\n8-Delete element at pos\t|\n9-Search\t\t|\n10-Replace\t\t|");
      printf("\n************************\n");
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
    break;
    case 6:
    Deleteatlast();
    break;
    case 7:
    Deleteatfirst();
    break;
    case 8:
    printf("\nEnter the position of the element to be deleted\n");
    scanf("%d",&pos);
    Deleteatpos(pos);
    break;
    case 9:
    printf("\nEnter the element to be searched:\n");
    scanf("%d",&n);
    Search(n);
    break;
    case 10:
    printf("\nEnter the position of the number to be replaced:\n");
    scanf("%d",&pos);
    printf("\nEnter the number to replace with:\n");
    scanf("%d",&n);
    Replace(n,pos);
    break;
    default:
        break;
    } }
}
