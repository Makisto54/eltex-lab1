#include <stdio.h>
#include <stdlib.h>
#include "mycomplex.h"

int main(int argc, char* argv[])
{
    struct mycomplex* a = malloc(sizeof(struct mycomplex));
    struct mycomplex* b = malloc(sizeof(struct mycomplex));
    struct mycomplex* c = malloc(sizeof(struct mycomplex));
    system("clear");
    printf("1 - Add\n");
    printf("2 - Sub\n");
    printf("3 - Mul\n");
    printf("4 - Divide\n");
    printf("5 - Quit\n");
    printf("Choose the operation:\n");
    char ch;
    while(ch != '5')
    {
        ch = getchar(); 
        switch(ch)
        {
            case 49:
                printf("Input A and B\n");
                scanf("%lf %lf %lf %lf", &a->real, &a->img, &b->real, &b->img);
                printf("A + B = "); 
                add(a, b, c);
                printf("(%lf, %lf)\n", c->real, c->img);
                printf("Choose the operation:\n");
                break;
            case 50:
                printf("Input A and B\n");
                scanf("%lf %lf %lf %lf", &a->real, &a->img, &b->real, &b->img);
                printf("A - B = ");
                sub(a, b, c);
                printf("(%lf, %lf)\n", c->real, c->img);
                printf("Choose the operation:\n");
                break;
            case 51:
                printf("Input A and B\n");
                scanf("%lf %lf %lf %lf", &a->real, &a->img, &b->real, &b->img);
                printf("A * B = ");
                mul(a, b, c);
                printf("(%lf, %lf)\n", c->real, c->img);
                printf("Choose the operation:\n");
                break;
            case 52:
                printf("Input A and B\n");
                scanf("%lf %lf %lf %lf", &a->real, &a->img, &b->real, &b->img);
                if((b->real * b->real + b->img * b->img) == 0)
                {
                    printf("Wrong numbers!\n");
                    printf("Choose the operation:\n");
                    break;
                }
                printf("A / B = ");
                divide(a, b, c);
                printf("(%lf, %lf)\n", c->real, c->img);
                printf("Choose the operation:\n");
                break;
            default:
                break;
        }
    }   

    return 0;
}
