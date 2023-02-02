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
cout<<"Cant debit must have minimum balance of 1000";
}
return acc_bal;
}

int getbal(){
return acc_bal;
}


};

int main(){
int am;
account a1(20000);
int bal=a1.getbal();
cout<<"initial sbalance is "<<bal;
cout<<"\n Enter the amount you want to credit:";
cin>>am;
bal=a1.credit(am);
cout<<"\n The updated balance is:"<<bal;
cout<<"\nEnter the amount you want to debit:";
cin>>am;
bal=a1.debit(am);
cout<<"\nThe updated balance is:"<<bal;
}
