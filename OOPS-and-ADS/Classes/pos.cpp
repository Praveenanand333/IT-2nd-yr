#include<iostream>
#include<cstring>
#include <bits/stdc++.h>
using namespace std;
int main(){
string str1="Hello";
string str2="Welcome to all,Hello Take Your Seat";

int flag=str2.find(str1);
if(flag!=-1){
cout<<"Found";
}
else{
cout<<"Not found";
}
}


