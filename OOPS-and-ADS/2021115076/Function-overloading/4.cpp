#include <iostream>
using namespace std;
int sum(int a, int b) {
  return a + b;
}
double sum(double a, double b) {
  return a + b;
}
int main() {
  int a = 5, b = 7;
  double c = 3.5, d = 2.8;
cout << "sum(" << a << ", " << b << ") = " << sum(a, b) << endl;
cout << "sum(" << c << ", " << d << ") = " << sum(c, d) << endl;
  return 0;
}
