#include "mycomplex.h"

void add(struct mycomplex* a, struct mycomplex* b, struct mycomplex* c)
{
    c->real = a->real + b->real;
    c->img = a->img + b->img;
}

void sub(struct mycomplex* a, struct mycomplex* b, struct mycomplex* c)
{
    c->real = a->real - b->real;
    c->img = a->img - b->img;
}

void mul(struct mycomplex* a, struct mycomplex* b, struct mycomplex* c)
{
    c->real = a->real * b->real - a->img * b->img;
    c->img = a->real * b->img + a->img * b->real;
}

void divide(struct mycomplex* a, struct mycomplex* b, struct mycomplex* c)
{
    c->real = (a->real * b->real + a->img * b->img) / (b->real * b->real + b->img * b->img);
    c->img = (b->real * a->img - b->img * a->real) / (b->real * b->real + b->img * b->img);
}

void input(struct mycomplex* a, struct mycomplex* b)
{
    printf("Input A and B\n");
    scanf("%lf %lf %lf %lf", &a->real, &a->img, &b->real, &b->img);	
}

void print(struct mycomplex* c)
{
	printf("(%lf, %lf)\n", c->real, c->img);
}
