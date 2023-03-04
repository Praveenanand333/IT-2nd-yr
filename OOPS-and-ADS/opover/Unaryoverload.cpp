#include <iostream>
using namespace std;
class Time {
public:
    Time(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s) {}
    Time operator++() {
        ++second;
        if (second >= 60) {
            second = 0;
            ++minute;
            if (minute >= 60) {
                minute = 0;
                ++hour;
                if (hour >= 24) {
                    hour = 0;
                }
            }
        }
        return *this;
    }
    Time operator--() {
        --second;
        if (second < 0) {
            second = 59;
            --minute;
            if (minute < 0) {
                minute = 59;
                --hour;
                if (hour < 0) {
                    hour = 23;
                }
            }
        }
        return *this;
    }
    void print() {
       cout << hour << ":" << minute << ":" << second <<endl;
    }
private:
    int hour, minute, second;
};
int main() {
    Time t(12, 0, 0);
    ++t;
    t.print();
    --t;
    t.print();
}
