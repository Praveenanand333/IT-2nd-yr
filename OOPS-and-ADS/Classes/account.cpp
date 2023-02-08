#include<iostream>
using namespace std;

class account{
public:
int acc_bal;

account(int amount){
if(amount>0){
acc_bal=amount;}
else{
cout<<"\n Cant have balance as negative value";
acc_bal=0;
}
}


int credit(int amount){
acc_bal+=amount;
return acc_bal;
}


int debit(int amount){
if(acc_bal-amount>1000){
acc_bal-=amount;}
else{
cout<<"\nCant debit must have minimum balance of 1000";
}
return acc_bal;
}

int getbal(){
return acc_bal;
}


};

int main(){
int am,bal;
account a1(20000);
int choice;
cout<<"\nEnter the choice 1-get balance\n 2-Credit amount \n3-Debit amount \n4-Exit\n";
cin>>choice;
while(choice!=4){
    if(choice==1){
bal=a1.getbal();
cout<<"Balance is "<<bal;
    }
    if(choice==2){
cout<<"\n Enter the amount you want to credit:";
cin>>am;
bal=a1.credit(am);
cout<<"\n The updated balance is:"<<bal;
    }
    if(choice==3){
cout<<"\nEnter the amount you want to debit:";
cin>>am;
bal=a1.debit(am);
cout<<"\nThe updated balance is:"<<bal;
    }
    if(choice==4)break;
    cout<<"\nEnter the choice 1-get balance\n 2-Credit amount \n3-Debit amount \n4-Exit\n";
cin>>choice;
}



}
