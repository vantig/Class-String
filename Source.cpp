#include"String.h"

//String(char);


//String& operator=(const char*);
//String& operator=(const char);

//String operator+=(const String&);
//bool operator<(const String&)const;
//bool operator>(const String&)const;
//bool operator<=(const String&)const;
//bool operator>=(const String&)const;
//bool operator==(const String&)const;
//bool operator!=(const String&)const;




String::String() : capacity(1), size(0), data(new char[1])
{
    data[0] = '\0';
}
String::String(const char* str) : capacity(strlen(str) + 1), size(strlen(str)), data(new char[size + 1])
{
    strcpy(data, str);
}
String::String(char ch) : capacity(2), size(1), data(new char[size + 1])
{
    this->data[0] = ch;
    this->data[1] = '\0';
}


String::~String()
{
    delete[]data;
}

String& String::operator=(const String& s)
{
    if (this != &s)
    {
        delete[]this->data;
        this->size = s.size;
        this->capacity = s.capacity;
        this->data = new char[this->capacity];
        strcpy(this->data, s.data);

    }
    return *this;
}
String& String::operator+=(const String& s)
{
    this->size += s.size;

    if (checkMem())
    {
        this->capacity = this->size * 2;
        char* temp = new char[this->capacity];
        strcpy(temp, this->data);
        strcat(temp, s.data);

        delete[]this->data;

        this->data = temp;
    }
    else
    {
        strcat(this->data, s.data);
    }

    return *this;
}


std::ostream& operator<<(std::ostream& out, const String& s)
{
    out << s.data;
    return out;
}
std::istream& operator>>(std::istream& in, String& s)
{
    delete[]s.data;
    s.data = new char[1];
    s.data[0] = '\0';
    s.size = 0;
    s.capacity = 1;

    char a;
    while (a = in.get())
    {
        String temp(a);
        if (a == '\n')
        {
            break;
        }
        s += temp;
    }
    s.data[s.size + 1] = '\0';
    return in;
}

bool String::checkMem()
{
    if (getSize() + 1 < getCapacity())
        return false;

    return true;
}

char& String::operator[](size_t index)
{
    char temp = '\0';
    if (index > size)
    {
        std::cout << "Error index";
        return temp;

    }
    return data[index];


}

const char& String::operator[](size_t index)const
{
    char temp = '\0';
    if (index > size)
    {
        std::cout << "Error index";
        return temp;

    }
    return data[index];


}
String& String::erase(int pos, int count)
{
    if (pos > this->size)
    {
        std::cout << "Error position\n";
        return *this;
    }
    if (pos + count - (int)size >= 0)
    {
        this->data[pos] = '\0';
        this->size = pos;
        return *this;
    }
    memcpy(this->data + pos, this->data + pos + count, this->size - count - pos + 1);
    this->size -= count;
    return *this;
}
String::String(const String& s)
{
    this->capacity = s.capacity;
    this->size = s.size;
    this->data = new char[capacity];
    strcpy(this->data, s.data);
}

