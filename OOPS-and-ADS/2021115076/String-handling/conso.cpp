#include<iostream>
#include<algorithm>
#include<ctype.h>
#include<bits/stdc++.h>
using namespace std;
int main(){
string str;
cout<<"Enter your string:";
getline(cin,str);
for(int i=0;i<str.length();i++){
if(str[i]=='a' || str[i]=='e' || str[i]=='i' ||
           str[i]=='o' || str[i]=='u' || str[i]=='A' ||
           str[i]=='E' || str[i]=='I' || str[i]=='O' ||
           str[i]=='U'){
	continue;
}
else if(!isspace(str[i]) && (((str[i]>=48 && str[i]<=57)||
        (str[i]>=65 && str[i]<=90)||
        (str[i]>=97 && str[i]<=122)))){
str.erase(str.begin()+i,str.begin()+i+1);
}
}
cout<<str;
}