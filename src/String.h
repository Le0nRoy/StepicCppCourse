#pragma once
#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {
public:
    String(const char *str = "");
    String(size_t n, char c);
    ~String();

    /* ���������� �������� ������������ */
    String &operator=(const String &other);

    const char *getStr();
    void increase_size(unsigned new_size);
    /* ���������� ���� �����. */
    void append(String &other);

    char &at(size_t idx);
    char   at(size_t idx) const;

    size_t size;
    char *str;
};

void checkStringAppend();
void checkStringEqual();
void checkStringAt();
