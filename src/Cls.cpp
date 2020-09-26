#include "headers/Cls.h"

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