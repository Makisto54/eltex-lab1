#include "mycomplex.h"

char stirng_ptr[12] = "sub";

void sub(struct mycomplex* a, struct mycomplex* b, struct mycomplex* c)
{
    c->real = a->real - b->real;
    c->img = a->img - b->img;
}
