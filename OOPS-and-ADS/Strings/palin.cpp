#include<iostream>
#include<cstring>
using namespace std;
int main(){
string str;
cout<<"Enter the string:";
cin>>str;
string str1=str;

char temp;
int n=str.length()-1;
for(int i=0;i<int(n/2);i++){
temp=str[i];
str[i]=str[n-i];
str[n-i]=temp;
}
cout<<str1<<endl;
cout<<str<<endl;	
if(str1==str){
cout<<"The given string is palindrome";
}
else{
cout<<"The given string is not palindrome";
}
}