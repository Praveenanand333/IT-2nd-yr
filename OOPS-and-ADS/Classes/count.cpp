#include<iostream>
#include<ctype.h>
using namespace std;
int main(){
string str;
int ct=0;
cout<<"Enter the string:";
cin>>str;
for(int i=0;i<str.length();i++){
if(isalpha(str[i])){
ct++;
}
}
cout<<"The number of words in the string is:"<<ct;
}
