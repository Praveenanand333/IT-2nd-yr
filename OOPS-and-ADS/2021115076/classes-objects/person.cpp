#include<iostream>
using namespace std;

class Person{
string name;
int age;
int id;
int salary;

public:
void set_name(string name1){name=name1;}
void set_age(int age1){age=age1;}
void set_id(int id1){id=id1;}
void set_salary(int salary1){salary=salary1;}

string get_name(){return name;}
int get_age(){return age;}
int get_id(){return id;}
int get_salary(){return salary;}
};

int main(){
Person p[5];
string name[5]={"anand","bala","kumar","abi","Ravi"};
int id[5]={1,2,3,4,5};
int age[5]={31,21,33,41,22};
int salary[5]={10000,20000,25000,30000,40000};
for(int i=0;i<5;i++){
p[i].set_name(name[i]);
p[i].set_id(id[i]);
p[i].set_age(age[i]);
p[i].set_salary(salary[i]);
}
Person h;
int maxi=p[0].get_salary();
for(int i=1;i<5;i++){
if(p[i].get_salary()>maxi){
maxi=p[i].get_salary();
h=p[i];
}
}
cout<<"The name of the person getting highest salary is: "<<h.get_name();
}

