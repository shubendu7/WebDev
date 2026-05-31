#include <iostream>
#include <string>
using namespace std;

class StringManager {
private:
    string str; // Private data member[cite: 2]

public:
    // Overloading >> operator for input[cite: 1, 2]
    friend istream& operator>>(istream& input, StringManager& s) {
        input >> s.str;
        return input;
    }

    // Overloading == operator for comparison[cite: 2]
    bool operator==(const StringManager& other) {
        return this->str == other.str;
    }

    void display() {
        cout << str << endl;
    }
};

int main() {
    StringManager s1, s2;

    cout << "Enter first & Second string: ";
    cin >>s1>>s2; 

    if (s1 == s2) {
        cout << "Strings are equal." << endl;
    } else {
        cout << "Strings are not equal." << endl;
    }

    return 0;
}