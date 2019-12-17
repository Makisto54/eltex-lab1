#include "mycomplex.h"

struct mycomplex* add(struct mycomplex* a, struct mycomplex* b)
{
    struct mycomplex* c = malloc(sizeof(struct mycomplex));
    c->real = a->real + b->real;
    c->img = a->img + b->img;
    return c;
}

struct mycomplex* sub(struct mycomplex* a, struct mycomplex* b)
{
    struct mycomplex* c = malloc(sizeof(struct mycomplex));
    c->real = a->real - b->real;
    c->img = a->img - b->img;
    return c;
}

struct mycomplex* mul(struct mycomplex* a, struct mycomplex* b)
{
    struct mycomplex* c = malloc(sizeof(struct mycomplex));
    c->real = a->real * b->real - a->img * b->img;
    c->img = a->real * b->img + a->img * b->real;
    return c;
}

struct mycomplex* divide(struct mycomplex* a, struct mycomplex* b)
{
    struct mycomplex* c = malloc(sizeof(struct mycomplex));
    c->real = (a->real * b->real + a->img * b->img) / (b->real * b->real + b->img * b->img);
    c->img = (b->real * a->img - b->img * a->real) / (b->real * b->real + b->img * b->img);
    return c;
}

void print(struct mycomplex* a)
{
    printf("(%lf, %lf)\n", a->real, a->img);
}
