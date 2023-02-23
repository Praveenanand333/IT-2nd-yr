/*    8. Write a program that demonstrates function overloading by defining two functions with the same name and same template, but different template parameters.*/
#include <iostream>
using namespace std;

template <typename T1>
T1 add(T1 num1, T1 num2) {
    return (num1 + num2);
}
template <typename T1>
T1 add(T1 num1, T1 num2,T1 num3) {
    return (num1 + num2+num3);
}

int main() {
    double result1;
    double result2;
    result1 = add<int>(2, 3);
    cout << "2 + 3.3 = " << result1 << endl;
    result2 = add<double>(2.2, 3.3,1.1);
    cout << "2.2 + 3.3+1.1 = " << result2 << endl;		
    return 0;
}
