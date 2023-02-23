/*    9. Write a program that demonstrates function overloading by defining two functions with the same name and same template parameters, but different template parameter lists.*/
#include<iostream>
using namespace std;
	
template <typename T>
T add(T num1, T num2) {
cout<<"This is from function having two template parameter list\n";
    return (num1 + num2);
}

template <typename T>
T add(T num1, T num2,T num3) {
cout<<"This is from function having three template parameter list\n";
    return (num1 + num2+num3);
}

int main(){
int a=add<int>(1,2);
int b=add<int>(1,2,3);
}
