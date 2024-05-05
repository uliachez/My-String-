#include "MyString.h"
#include <ostream>

int main() {
    MyString s1("Hello,");
    MyString s2("world!");
    MyString s3;
    MyString s4("world!");
    MyString s5;
    cin >> s5;
    cout << s5 << endl; 
    s3 = s1 + s2;
    cout << "s1 + s2: " << s3 << endl;
    cout << "s1 < s2 = " << (s1 < s2) << endl;
    cout << "s1 > s2 = " << (s1 > s2) << endl;
    cout << "s1 <= s2 = " << (s1 <= s2) << endl;
    cout << "s1 >= s2 = " << (s1 >= s2) << endl;
    cout << "s1 != s2 = " << (s1 != s2) << endl;
    cout << "s2 == s4 = " << (s2 == s4) << endl;
    cout << s1.length() << endl;
    cout << s1[2] << endl;
    cout << s1.get() << endl;
    MyString s6("World");
    MyString s7("oldw");
    MyString s8;
    s8 = s6 - s7;
    cout << "s6 - s8 = " << s8 << endl;
}