#include<iostream>
using namespace std;
void func(int a,int b){
cout<<"This is from function accepting integer parameters"<<endl;
cout<<"The sum is:"<<a+b<<endl;
}
void func(double a,double b){
cout<<"This is from function accepting double parameters"<<endl;
cout<<"The sum is:"<<a+b<<endl;
}
int main(){
func(2,5);
func(3.14,5.1);
}
