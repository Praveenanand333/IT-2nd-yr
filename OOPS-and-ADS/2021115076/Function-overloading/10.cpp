#include <iostream>
using namespace std;
template<typename T>
void print(T arg) {
    cout << arg << endl;
}
template<>
void print<int>(int arg) {
    cout << "Integer: " << arg << endl;
}
int main() {
    print(3.14);
    print(42);
    return 0;
}
