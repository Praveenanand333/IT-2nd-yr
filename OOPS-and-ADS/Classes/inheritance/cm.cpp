#include <iostream>
#include <string>
using namespace std;


class CommunityMember {
protected:
    string name;
    int age;
public:
    CommunityMember(string name, int age) : name(name), age(age) {}
    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Employee : public CommunityMember {
protected:
    int employeeID;
public:
    Employee(string name, int age, int employeeID) : CommunityMember(name, age), employeeID(employeeID) {}
    void display() {
        CommunityMember::display();
        cout << "Employee ID: " << employeeID << endl;
    }
};

class Faculty : public Employee {
protected:
    string department;
public:
    Faculty(string name, int age, int employeeID, string department) : Employee(name, age, employeeID), department(department) {}
    void display() {
        Employee::display();
        cout << "Department: " << department << endl;
    }
};

class Staff : public Employee {
protected:
    string office;
public:
    Staff(string name, int age, int employeeID, string office) : Employee(name, age, employeeID), office(office) {}
    void display() {
        Employee::display();
        cout << "Office: " << office << endl;
    }
};

class Administrator : public Faculty {
protected:
    string title;
public:
    Administrator(string name, int age, int employeeID, string department, string title) : Faculty(name, age, employeeID, department), title(title) {}
    void display() {
        Faculty::display();
        cout << "Title: " << title << endl;
    }
};

class Teacher : public Faculty {
protected:
    string course;
public:
    Teacher(string name, int age, int employeeID, string department, string course) : Faculty(name, age, employeeID, department), course(course) {}
    void display() {
        Faculty::display();
        cout << "Course: " << course << endl;
    }
};

class AdministratorTeacher : public Administrator, public Teacher {
public:
    AdministratorTeacher(string name, int age, int employeeID, string department, string title, string course) : Administrator(name, age, employeeID, department, title), Teacher(name, age, employeeID, department, course) {}
    void display() {
        Administrator::display();
        cout << "Course: " << course << endl;
    }
};

class Student:public CommunityMember{
protected:
int marks;
char grade;
public:
Student(string name,int age,int marks,char grade):CommunityMember(name, age),marks(marks),grade(grade){}
void display(){
	CommunityMember::display();
	cout<<"Marks:"<<marks<<endl;
	cout<<"Grade:"<<grade<<endl;
}
};

class Alumnus:public CommunityMember{
protected:
int graduationyear;
public:
Alumnus(string name,int age,int year):CommunityMember(name, age),graduationyear(year){}
void display(){
	CommunityMember::display();
	cout<<"Graduated year:"<<graduationyear;
}
};

int main() {
    CommunityMember member("John Doe", 30);
    member.display();
    cout << endl;

    Employee employee("Jane Smith", 25, 123);
    employee.display();
    cout << endl;

    Faculty faculty("Tom Jones", 40, 456, "Mathematics");
    faculty.display();
    cout << endl;

    Staff staff("Sarah Lee", 35, 789, "Admissions");
    staff.display();
    cout << endl;

    Administrator administrator("Mary Johnson", 50, 111, "Business", "Dean");
    administrator.display();
    cout << endl;
    
    Teacher teacher("anand",30,344,"IT","OOPS");
    teacher.display();
    cout<<endl;
    
    AdministratorTeacher administratorteacher("ram",33,355,"IT","HOD","DAA");
    administratorteacher.display();
    cout<<endl;
    
    Student student("bala",21,99,'A');
    student.display();
    cout<<endl;
    
    Alumnus alumnus("Seetha",40,2003);
    alumnus.display();
    cout<<endl;
    
    
    
}
