#include "headers/Cls.h"
#include <iostream>

char &get_c(Cls &cls)
{
    void *p = &cls;
    return *((char *)p);
}

double &get_d(Cls &cls)
{
    void *p = &cls;
    return *((double *)p + 1);
}

int &get_i(Cls &cls)
{
    void *p = &cls;
    return *((int *)p + 4);
}

// FIXME move to Unit test
//void checkGetters()
//{
//    char c_exp = 'n';
//    double d_exp = 2.5;
//    Cls cls(c_exp, d_exp, i_exp);
//    char c = get_c(cls);
//    double d = get_d(cls);
//
//    std::cout << "Cls size: " << sizeof(cls) << std::endl;
//    if (c != c_exp)
//    {
//        std::cout << "c: " << c << std::endl;
//    }
//    if (d != d_exp)
//    {
//        std::cout << "d: " << d << std::endl;
//    }
//}
