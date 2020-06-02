#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
class String
{
public:
    String();
    String(const char*);
    String(char);
    String(const String&);

    String& operator=(const String&);
    String& operator=(const char*);
    String& operator=(const char);

    friend std::ostream& operator<<(std::ostream&, const String&);
    friend std::istream& operator>>(std::istream&, String&);

    String operator+(const String&)const;
    String& operator+=(const String&);

    bool operator<(const String&)const;
    bool operator>(const String&)const;
    bool operator<=(const String&)const;
    bool operator>=(const String&)const;
    bool operator==(const String&)const;
    bool operator!=(const String&)const;

    char& operator[](size_t);
    const char& operator[](size_t)const;
    String& erase(int, int);

    size_t getCapacity() const { return capacity; };
    size_t getSize() const { return size; };

    ~String();

private:

    size_t capacity;//память, выделенная для строки
    size_t size;//фактичесоке количество символов в строке
    char* data;

    bool checkMem();

};