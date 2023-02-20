#include<iostream>
#include <bits/stdc++.h>
#include<cstring>
using namespace std;
int main(){
string name;
string name1;
int scount=0;
cout<<"Enter the name:";
getline(cin,name);
int n=name.length();
name1+=name[0];
name1+=".";
for(int i=0;i<n;i++){
if(isspace(name[i])!=0){
if(scount==0){
name1+=name[i+1];}
scount++;
}
if(scount==2){
name1+=name[i];
}
}
cout<<name1;
}