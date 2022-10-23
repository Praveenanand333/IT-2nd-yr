#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int acc_no,pin;
int acc,balance;
FILE *bal;
void Transaction(){
int tamount,tacc;
int taccflag=0;
printf("\nEnter the amount to be transfered:");
scanf("%d",&tamount);
taccentry:
printf("\nEnter the account number to be transfered:");
scanf("%d",&tacc);
bal=fopen("balance.txt","r");
while(fscanf(bal,"%d\t%d",&acc,&balance)!=EOF){
printf("%d-%d",acc,balance);
if(acc==acc_no && balance<tamount){
printf("\nInsufficient balance");
goto texit;
}
if(acc==tacc){
taccflag=1;
}


}
if(taccflag==0){
printf("\nNo account number found please re-enter the account number");
goto taccentry;
}
if(taccflag==1){
FILE *w;
FILE *r;
r=fopen("balance.txt","r");
w=fopen("newdata.txt","w");
while(fscanf(r,"%d\t%d",&acc,&balance)!=EOF){
if(acc==acc_no){
fprintf(w,"%d\t%d\n",acc,balance-tamount);
}
else if(acc==tacc){
fprintf(w,"%d\t%d\n",acc,balance+tamount);
}
else{
fprintf(w,"%d\t%d\n",acc,balance);
}
}
fclose(w);
}

fclose(bal);
remove("balance.txt");
rename("newdata.txt","balance.txt");
printf("\n Transaction done successfully!!!\n");
texit:
}

void Balance(){
bal=fopen("balance.txt","r");
while(fscanf(bal,"%d\t%d",&acc,&balance)!=EOF){
if(acc_no==acc){
printf("\nYour balance is:%d",balance);
}
}
}


void main(){
system("figlet Welcome to Anand bank");
rename("temp.txt","temp1.txt");
FILE *acc;
int acc_no1,pin1;
int login_flag=1;
acc=fopen("accno_pin.txt","r");
login:
printf("\nEnter your 10 digit bank  acccount number:");
scanf("%d",&acc_no);
printf("\nEnter your 4 digit pin:");
scanf("%d",&pin);
while(fscanf(acc,"%d\t%d",&acc_no1,&pin1)!=EOF){
if(acc_no==acc_no1 && pin==pin1){
login_flag=1;
}
}
if(login_flag==1){
int choice;
menu:
printf("\n***********************\n");
printf("1-Withdrawl\n2-Transaction\n3-Balance enquiry\n");
printf("\n***********************\n");
printf("\nEnter your choice:\n");
scanf("%d",&choice);
switch(choice){
case 1:
//Withdrawl();
break;
case 2:
Transaction();
break;
case 3:
Balance();
break;
default:
printf("\nInvalid choice");
goto menu;
break;
}
}
else{
printf("\nInvalid pin/account number");
goto login;
}
}
