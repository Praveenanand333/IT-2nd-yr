#include<stdio.h>
#include<stdlib.h>
struct node1{
char coach_name[50];
int no_of_pass;
struct node1* next;
};

struct node1* head1=NULL;
struct node1* head2=NULL;


void Insertatlast1(){
struct node1* temp=malloc(sizeof(struct node1));
struct node1* temp1=head1;
char coach_name1[50];
int no_of_pass1;
printf("\nEnter the name of the coach:");
scanf("%s",temp->coach_name);
printf("\nEnter the no of passengers:");
scanf("%d",&temp->no_of_pass);
if(head1==NULL){
head1=temp;
return;
}
//temp->next=head1;
//head1=temp;
while(temp1->next!=NULL){
temp1=temp1->next;
}
temp1->next=temp;
temp->next=NULL;

}

void Insertatlast2(){
struct node1* temp=malloc(sizeof(struct node1));
struct node1* temp1=head2;
char coach_name1[50];
int no_of_pass1;
printf("\nEnter the name of the coach:");
scanf("%s",temp->coach_name);
printf("\nEnter the weight on coach:");
scanf("%d",&temp->no_of_pass);
if(head2==NULL){
head2=temp;
return;
}
//temp->next=head2;
//head2=temp;
while(temp1->next!=NULL){
temp1=temp1->next;
}
temp1->next=temp;
temp->next=NULL;
}


void Print(struct node1* temp){
while(temp!=NULL){
printf("|%s:",temp->coach_name);
printf("%d|->",temp->no_of_pass);
temp=temp->next;
}
printf("\n");
}

void Merge(){
struct node1* temp=head1;
while(temp->next!=NULL){
temp=temp->next;
}
temp->next=head2;
}

int Calculate1(struct node1* temp){
int sum=0;
while(temp!=NULL){
sum+=temp->no_of_pass*10;
temp=temp->next;
}
return sum;
}

int Calculate2(struct node1* temp){
int sum=0;
int price=50;
int count=0;
while(temp!=NULL){
if(count>10){price=2;}
sum+=temp->no_of_pass*price;
temp=temp->next;
count++;
}
return sum;
}


void main(){
int i;
int no_of_coach1;
int no_of_coach2;

printf("\nEnter the no of coaches in passenger train:");
scanf("%d",&no_of_coach1);
for(i=0;i<no_of_coach1;i++){
Insertatlast1();
}

printf("\nEnter the no of coaches in goods train:");
scanf("%d",&no_of_coach2);
for(i=0;i<no_of_coach2;i++){
Insertatlast2();
}

printf("\nPassenger train is\n");
Print(head1);
printf("\nGoods train is\n");
Print(head2);

int sum=Calculate1(head1);
sum+=Calculate2(head2);
Merge();

printf("\nAfter merging the trains\n");
Print(head1);
printf("\nThe revenue is :%d\n",sum);
}
