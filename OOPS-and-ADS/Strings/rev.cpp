#include<iostream>
using namespace std;
int main(){
string str="welcome";
char temp;
int n=str.length()-1;
cout<<"The original string is :"<<str;
for(int i=0;i<int(n/2);i++){
temp=str[i];
str[i]=str[n-i];
str[n-i]=temp;
}
cout<<"\nThe reversed string is:"<<str;
}