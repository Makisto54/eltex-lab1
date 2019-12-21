#ifndef _MYCOMPLEX_
#define _MYCOMPLEX_

#include <stdio.h>
#include <stdlib.h>

struct mycomplex
{
    double real;
    double img;
};

void add(struct mycomplex *, struct mycomplex *, struct mycomplex *);
void sub(struct mycomplex *, struct mycomplex *, struct mycomplex *);
void mul(struct mycomplex *, struct mycomplex *, struct mycomplex *);
void divide(struct mycomplex *, struct mycomplex *, struct mycomplex *);
void input(struct mycomplex *, struct mycomplex *);
void print(struct mycomplex *);

#endif
