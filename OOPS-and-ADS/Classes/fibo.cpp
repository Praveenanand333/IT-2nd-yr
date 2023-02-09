#include<iostream>
using namespace std;

class Fib{
int a1=0;
int a2=1;
int a3;

public:
void display(int n){
cout<<a1<<"\n";
cout<<a2<<"\n";
for(int i=0;i<n;i++){
a3=a1+a2;
cout<<a3<<"\n";
a1=a2;
a2=a3;
}
}


};

int main(){
Fib f1;
f1.display(10);
}
