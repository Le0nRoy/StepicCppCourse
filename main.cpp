// Example program
#include <iostream>
#include <string>
#include <cstring>

#include "src/String.h"
#include "src/Cls.h"
#include "src/Visitor.h"

int main()
{
    // Works
//    checkStringAppend();

    // Works
    //checkGetters();

    // Works
    //checkStringEqual();

    // Works
    //checkOverload();

    // Works
    //checkStringAt();

    // Works
    //test_equals();

//    test_visitor();

//    std::cin.get();
}

struct Base {
private:
    virtual void method();
};

struct Child : private Base {
public:
    void method() override;
};
