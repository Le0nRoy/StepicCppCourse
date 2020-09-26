#pragma once

#include <cstddef>
#include <cstring>

struct String {
public:
    String(const char *str = "");
    String(size_t n, char c);
    String(const String &other);
    String &operator=(const String &other);
    ~String();

    const char *getStr();
    void append(String &other);
    char &at(size_t idx);
    char at(size_t idx) const;

private:
    size_t size;
    char *str;

    void increase_size(unsigned new_size);

};
