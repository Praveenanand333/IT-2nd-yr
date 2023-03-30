#include <iostream>
#include <string>
using namespace std;
int main()
{
    string statement;
    cout << "Enter a statement: ";
    getline(cin, statement);
    string largest_word = "";
    string current_word = "";
    for (int i = 0; i < statement.length(); i++) {
        if (statement[i] == ' ') {
            if (current_word.length() > largest_word.length()) {
                largest_word = current_word;
            }
            current_word = "";
        } else {
            current_word += statement[i];
        }
    }
    if (current_word.length() > largest_word.length()) {
        largest_word = current_word;
    }
    cout << "The largest word in the statement is: " << largest_word << endl;
}
