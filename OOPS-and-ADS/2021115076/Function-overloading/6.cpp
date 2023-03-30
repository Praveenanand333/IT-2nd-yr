#include <iostream>
using namespace std;
void printNum(int num, int times = 1) {
    for (int i = 0; i < times; i++) {
        cout << num << " ";
    }
    cout << endl;
}
void printNum(double num, int times = 2) {
    for (int i = 0; i < times; i++) {
        cout << num << " ";
    }
    cout << endl;
}
int main() {
    printNum(5);
    printNum(3.14);
    printNum(7, 3);
    printNum(2.71, 4);
}
