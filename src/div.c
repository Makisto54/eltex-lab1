#include "mycomplex.h"

void divide(struct mycomplex* a, struct mycomplex* b, struct mycomplex* c)
{
    c->real = (a->real * b->real + a->img * b->img) / (b->real * b->real + b->img * b->img);
    c->img = (b->real * a->img - b->img * a->real) / (b->real * b->real + b->img * b->img);
}
