/*    8. Write a program that demonstrates function overloading by defining two functions with the same name and same template, but different template parameters.*/
#include <iostream>
using namespace std;

template <typename T1,typename T2>
T2 add(T1 num1, T2 num2) {
    return (num1 + num2);
}
template <typename T3>
T3 add(T3 num1, T3 num2) {
    return (num1 + num2);
}

int main() {
    double result1;
    double result2;
    result1 = add<int,double>(2, 3.3);
    cout << "2 + 3.3 = " << result1 << endl;
    result2 = add<double>(2.2, 3.3);
    cout << "2.2 + 3.3 = " << result2 << endl;
    return 0;
}
