#include <iostream>
#include <cstring>
using namespace std;
class String {
public:
    String(const char* s = "") {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
    bool operator==(const String s) const {
        return (strcmp(str, s.str) == 0);
    }
    
private:
    char* str;
};
int main() {
    String s1("Hello");
    String s2("Hello");
    if (s1 == s2) {
        cout << "s1 and s2 are equal" <<endl;
    }
    else {
        cout << "s1 and s2 are not equal" <<endl;
    }
}
