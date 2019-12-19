#ifndef _MYCOMPLEX_
#define _MYCOMPLEX_

#include <stdio.h>
#include <stdlib.h>

struct mycomplex
{
    double real;
    double img;
};

struct mycomplex* add(struct mycomplex *, struct mycomplex *);
struct mycomplex* sub(struct mycomplex *, struct mycomplex *);
struct mycomplex* mul(struct mycomplex *, struct mycomplex *);
struct mycomplex* divide(struct mycomplex *, struct mycomplex *);
void print(struct mycomplex*);

#endif
