#include<iostream>
using namespace std;
class employee{

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
cout<<"\nThe lname of the employee is:"<<lname;
}

int get_sal(){
cout<<"\nThe salary of the employee is :"<<mon_sal;
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
int hike(){
    mon_sal*=1.1;
}
};

int main(){
employee e1("anand","kumar",10000);
int choice,sal;
string name;
cout<<"\nEnter the choice \n1-Get fname \n2-Get lname \n3-Get salary \n4-Set fname \n5-Set lname\n6-Set salary\n7-Make hike in salary\n 8-Exit\n";
cin>>choice;
while(choice!=8){
    switch (choice)
    {
    case 1:
    e1.get_fname();
    break;
    case 2:
    e1.get_lname();
    break;
    case 3:
    e1.get_sal();
    break;
    case 4:
    cout<<"\nEnter the new fname of employee:";
    cin>>name;
    e1.set_fname(name);
    e1.get_fname();
    break;
    case 5:
    cout<<"\nEnter the new fname of employee:";
    cin>>name;
    e1.set_lname(name);
    e1.get_lname();
    break;
    case 6:
    cout<<"\nEnter the new salary of employee:";
    cin>>sal;
    e1.set_sal(sal);
    e1.get_sal();
    case 7:
    e1.hike();
    e1.get_sal();
    default:
        break;
    }
    cout<<"\nEnter the choice \n1-Get fname \n2-Get lname \n3-Get salary \n4-Set fname \n5-Set lname\n6-Set salary\n7-Make hike in salary\n8-Exit\n";
    cin>>choice;
}

}
