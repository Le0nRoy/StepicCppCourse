#include "String.h"
#include <iostream>

String::String(const char *input_str)
{
    size = strlen(input_str);
    str = new char[size + 1];
    strcpy(str, input_str);
}

String::String(size_t n, char c)
{
    this->size = n;
    str = new char[size + 1];
    memset(str, c, size);
    str[size] = '\0';
}

String &String::operator=(const String &other)
{
    if (this == &other)
    {
        return *this;
    }
    delete[] this->str;
    this->size = other.size;
    this->str = new char[this->size + 1];
    strcpy(this->str, other.str);
    return *this;
}

String::~String()
{
    delete[] this->str;
}

const char *String::getStr() 
{
    return this->str;
}

void String::increase_size(unsigned new_size)
{
    char *old_ar = this->str;
    this->str = new char[new_size];
    memcpy(this->str, old_ar, this->size);
    this->str[size] = '\0';
    this->size = new_size - 1;
    delete[] old_ar;
}

void String::append(String &other)
{
    int new_size = this->size + other.size + 1;
    String addStr(other.str);
    int old_size = this->size;
    this->increase_size(new_size);
    strcat(this->str, addStr.str);
}

char &String::at(size_t idx)
{
    return str[idx];
}

char String::at(size_t idx) const
{
    return str[idx];
}

void checkStringAppend()
{
    String s1("Hello,");
    String s2(" world!");

    // теперь s1 хранит "Hello, world!"
    s1.append(s2);
    std::cout << s1.getStr() << std::endl;

    String s("Hello");
    // теперь s хранит "HelloHello"
    s.append(s);
    std::cout << s.getStr() << std::endl;
}

void checkStringEqual()
{
    String str1(0, 'n');
    String str2("abvabsd");
    String str3 = str1;
    String str4 = str2;
    str4 = str4;
}

void checkStringAt()
{
    String greet("Hello");
    // Calls not const
    char ch1 = greet.at(0);

    String const const_greet("Hello, Const!");
    // Calls const
    char const &ch2 = const_greet.at(0);
}
