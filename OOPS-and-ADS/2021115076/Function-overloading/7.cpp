/*   7. Write a program that demonstrates function overloading by defining two functions with the same name but different templates.*/
#include <iostream>
using namespace std;
template <typename T>	
T add(T num1, T num2) {
    return (num1 + num2);
}
template <typename T1,typename T2>	
T2 add(T1 num1, T2 num2) {
    return (num1 + num2);
}
int main() {
    int result1;
    double result2;
    result1 = add<int>(2, 3);
    cout << "2 + 3 = " << result1 << endl;
    result2 = add<int,double>(2, 3.3);
    cout << "2 + 3.3 = " << result2 << endl;
}
