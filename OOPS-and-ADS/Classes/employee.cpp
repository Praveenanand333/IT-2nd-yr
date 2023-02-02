#include<iostream>
using namespace std;
class employee{\

public:
string fname;
string lname;
int mon_sal;


employee(string fname1,string lname1,int mon_sal1){
fname=fname1;
lname=lname1;
mon_sal=mon_sal1;
}

int get_fname(){
cout<<"\nThe fname of employee is :"<<fname;
}

int get_lname(){
cout<<"\n The lname of the employee is:"<<lname;
}

int get_sal(){
cout<<"\n The salary of the employee is :"<<mon_sal;
}

int set_fname(string name){
fname=name;
}

int set_lname(string name){
lname=name;
}

int set_sal(int sal){
mon_sal=sal;
}
};

int main(){
employee e1("anand","kumar",10000);
int choice=0,sal;
string name;
e1.get_fname();
e1.get_lname();
e1.get_sal();


cout<<"\n Do you want to change the fname? 1/0:";
cin>>choice;
if(choice==1){
cout<<"\nEnter the new fname of employee:";
cin>>name;
e1.set_fname(name);
e1.get_fname();
choice=0;
}


cout<<"\n Do you want to change the lname? 1/0:";
cin>>choice;
if(choice==1){
cout<<"\nEnter the new fname of employee:";
cin>>name;
e1.set_lname(name);
e1.get_lname();
choice=0;
}


cout<<"\n Do you want to change the monthly salary? 1/0";
cin>>choice;
if(choice==1){
cout<<"\nEnter the new salary of employee:";
cin>>sal;
e1.set_sal(sal);
e1.get_sal();
choice=0;
}

}
