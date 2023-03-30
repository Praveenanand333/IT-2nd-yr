#include<iostream>
using namespace std;
class Account{
double bal;
public:
static double rate;
Account(int amt){
    bal=amt;
}
static void setrate(int rate1){
    rate=rate1;
}
void printrate(){
    cout<<rate;
}
};
double Account::rate=0;
int main(){
    Account a1(200);
    Account::setrate(4);
    a1.printrate();
    
}