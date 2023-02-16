#include<bits/stdc++.h>
#include<iostream>
#include<ctype.h>
using namespace std;
int main(){
string str;
cout<<"Enter the string:";
getline(cin,str);
for(int i=0;i<str.length();i++){
if(isalpha(str[i])){
str[i]=str[i]+1;
}
}
cout<<str;
}

