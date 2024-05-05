#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class MyString {
    private:
        char *strochka;
    public:
        MyString(const char * str); //конструктор с одним параметром
        MyString(MyString& s); //конструктор копирования
        MyString(MyString&& s); //конструктор переноса
        MyString();
        ~MyString(); //деструктор
        int length(); //количество символов(длина строки)
        char *get(); //возвращение указателя на данные
        bool operator== (MyString& s); //сравнение на равенство
        bool operator!= (MyString& s); //сравнение на неравенство
        friend bool operator< (const MyString& rhs, const MyString& lhs); //лексографическое сравнение
        friend bool operator> (const MyString& rhs, const MyString& lhs); //лексографическое сравнение
        friend bool operator<= (const MyString& rhs, const MyString& lhs); //лексографическое сравнение
        friend bool operator>= (const MyString& rhs, const MyString& lhs); //лексографическое сравнение
        friend MyString operator+ (const MyString& lhs, const MyString& rhs); //склеивание двух строк
        friend MyString operator-(const MyString& lhs, const MyString& rhs); //вычитание
        MyString& operator= (MyString& s); //присвоение строк
        MyString& operator= (MyString&& s); //присвоение строк
        friend istream& operator>>(istream& is, MyString& s); //запись в поток
        friend ostream& operator<<(ostream& os, const MyString& s);//чтение из потока
        char& operator[] (int value); //доступ к символу по индексу
};