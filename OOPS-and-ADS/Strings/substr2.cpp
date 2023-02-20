#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string substr1(string str,int pos,int length){
string res="";
for(int i=pos;i<pos+length;i++){
    res+=str[i];
}
return res;
}

int main(){
    string str="welcome to c++";
    string str1=substr1(str,2,5);
    cout<<str1;
}