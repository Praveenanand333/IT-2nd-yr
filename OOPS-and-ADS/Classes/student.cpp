#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Student{
string name;
int age;
int marks;

public:
void set_age(int age1){
age=age1;
}

void set_name(string name1){
name=name1;
}

void set_marks(int marks1){
marks=marks1;
}

string get_name(){
return name;
}

int get_marks(){
return marks;
}
};

int main(){
Student s[5];
string name[5]={"anand","bala","kumar","abi","Ravi"};
int age[5]={19,21,23,22,19};
int marks[5]={99,94,96,100,91};
for(int i=0;i<5;i++){
s[i].set_name(name[i]);
s[i].set_age(age[i]);
s[i].set_marks(marks[i]);

}
sort(marks,marks+5);
cout<<"The students who got the top 3 marks are"<<endl;
for(int i=4;i>1;i--){
for(int j=0;j<5;j++){
if(marks[i]==s[j].get_marks()){
cout<<s[j].get_name()<<endl;
}
}
}
}
