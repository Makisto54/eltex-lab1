#ifndef _MYCOMPLEX_
#define _MYCOMPLEX_

struct mycomplex
{
    double real;
    double img;
};

void add(struct mycomplex *, struct mycomplex *, struct mycomplex *);
void sub(struct mycomplex *, struct mycomplex *, struct mycomplex *);
void mul(struct mycomplex *, struct mycomplex *, struct mycomplex *);
void divide(struct mycomplex *, struct mycomplex *, struct mycomplex *);

#endif
