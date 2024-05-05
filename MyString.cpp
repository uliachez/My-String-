#include "MyString.h"

MyString::MyString(const char * str):strochka(new char[strlen(str) + 1]) {
    strcpy(this->strochka, str);
}
MyString::MyString(MyString &s):strochka(new char[strlen(s.strochka) + 1]) {
    strcpy(this->strochka, s.strochka);
}
MyString::MyString(MyString &&s) {
    delete[] this->strochka;
    this->strochka = s.strochka;
    s.strochka = NULL;
}
MyString::MyString() : strochka(NULL) {
}
MyString::~MyString() {
    delete [] this->strochka;
}
int MyString::length() {
    return strlen(strochka);
}
char* MyString::get() {
    return strochka;
}
bool MyString::operator== (MyString& s) {
    if (strcmp(this->strochka, s.strochka) == 0) {
        return true;
    }
    else {
        return false;
    }
}
bool MyString::operator!= (MyString& s) {
    if (strcmp(this->strochka, s.strochka) != 0) {
        return true;
    }
    else {
        return false;
    }
}
bool operator< (const MyString& lhs, const MyString& rhs) {
    if (strcmp(lhs.strochka, rhs.strochka) < 0) {
        return true;
    }
    else {
        return false;
    }
}
bool operator> (const MyString& lhs, const MyString& rhs) {
    if (strcmp(lhs.strochka, rhs.strochka) > 0) {
        return true;
    }
    else {
        return false;
    }
}
bool operator<= (const MyString& lhs, const MyString& rhs) {
    if (strcmp(lhs.strochka, rhs.strochka) <= 0) {
        return true;
    }
    else {
        return false;
    }
}
bool operator>= (const MyString& lhs, const MyString& rhs) {
    if (strcmp(lhs.strochka, rhs.strochka) >= 0) {
        return true;
    }
    else {
        return false;
    }
}
MyString operator+ (const MyString& lhs, const MyString& rhs) {
    char *glue = new char[strlen(lhs.strochka) + strlen(rhs.strochka) + 1];
    strcpy(glue, lhs.strochka);
    strcat(glue, rhs.strochka);
    MyString tmp(glue);
    return tmp;
}
MyString operator- (const MyString& lhs, const MyString& rhs) { 
    char* glue = new char[strlen(lhs.strochka) + 1]; 
    strcpy(glue, lhs.strochka); 
    for (int i = 0; i < strlen(rhs.strochka); i++) { 
        char* pos = strchr(glue, rhs.strochka[i]); 
        while (pos != nullptr) { 
            memmove(pos, pos + 1, strlen(pos)); 
            pos = strchr(glue, rhs.strochka[i]); 
        }
    }
    MyString tmp(glue);
    return tmp;
}
MyString& MyString::operator= (MyString& s) {
    delete[] this->strochka;
    this->strochka = new char[strlen(s.strochka) + 1];
    strcpy(this->strochka, s.strochka);
    return *this;
}
MyString& MyString::operator= (MyString&& s) {
    delete[] this->strochka;
    this->strochka = s.strochka;
    s.strochka = NULL;
    return *this;
}
istream& operator>>(istream& is, MyString& s) {
    char* glue = new char[1000];
    memset(&glue[0], 0, sizeof(glue));
    is >> glue;
    s = MyString{ glue };
    delete[] glue;
    return is;
}
ostream& operator<<(ostream& os, const MyString& s) {
    os << s.strochka;
    return os;
}
char& MyString::operator[](int value) {
    return this->strochka[value];
}