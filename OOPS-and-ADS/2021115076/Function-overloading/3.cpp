#include<iostream>
using namespace std;
void fun(char *a)
{
cout << "non-const fun() " << a<<endl;}
void fun(const char *a)
{
cout << "const fun() " << a<<endl;}
int main()
{
const char *ptr = "Hello";
fun(ptr);
char *ptr1="welcome";
fun(ptr1);
}

