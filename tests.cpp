// Example program
#include <iostream>
#include <string>
#include <cstring>

#include "src/String.h"
#include "src/Cls.h"
#include "src/Expression.h"
#include "src/visitor.h"

void checkStringAppend();

int **transpose(const int *const *m, unsigned rows, unsigned cols)
{
    int **m_t = new int *[cols];
    for (int i = 0; i < cols; ++i) {
        m_t[i] = new int[rows];
        for (int j = 0; j < rows; ++j) {
            m_t[i][j] = m[j][i];
        }
    }
    return m_t;
}

void swap_min(int *m[], unsigned rows, unsigned cols)
{
    /* ... */
    int row = 0;
    for (int min = m[0][0], i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; j++) 
        {
            if (m[i][j] < min)
            {
                min = m[i][j];
                row = i;
            }
        }
    }
    int *p = m[0];
    m[0] = m[row];
    m[row] = p;
}

void checkOverload();

int main()
{
    // Works
    //checkStringAppend();

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

    ns_visitor::test_visitor();

    std::cin.get();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

void foo(char) 
{ 
    std::cout << "char" << std::endl; 
}
void foo(signed char) 
{ 
    std::cout << "signed char" << std::endl; 
}
void foo(unsigned char) 
{ 
    std::cout << "unsigned char" << std::endl; 
}

void checkOverload()
{
    // Error
    //foo(97);
    foo('a');
}

struct Base {
private:
    virtual void method();
};

struct Child : private Base {
public:
    void method() override;
};
