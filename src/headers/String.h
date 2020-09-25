#pragma once

#include <cstddef>
#include <cstring>

struct String {
public:
    String(const char *str = "");

    String(size_t n, char c);

    ~String();

    /* Реализуйте оператор присваивания */
    String &operator=(const String &other);

    const char *getStr();

    /* Реализуйте этот метод. */
    void append(String &other);

    char &at(size_t idx);

    char at(size_t idx) const;

private:
    size_t size;
    char *str;

    void increase_size(unsigned new_size);

};

void checkStringAppend();

void checkStringEqual();

void checkStringAt();
