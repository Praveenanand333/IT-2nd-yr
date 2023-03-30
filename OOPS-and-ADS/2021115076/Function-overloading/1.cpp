#include<iostream>
using namespace std;
void func(int a,int b,int c){
cout<<"This is from function accepting 3 parameters:"<<endl;
cout<<"The sum of three numbers is:"<<a+b+c<<endl;
}
void func(int a,int b){
cout<<"This is from function accepting 2 parameters"<<endl;
cout<<"The sum of two numbers is:"<<a+b<<endl;
}
int main(){
func(1,2);
func(1,2,3);
}
