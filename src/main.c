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
            	input(a, b);
                add(a, b, c);
                printf("A + B = ");
                print(c);
                printf("Choose the operation:\n");
                break;
            case 50:
                input(a, b);
                sub(a, b, c);
                printf("A - B = ");
                print(c);
                printf("Choose the operation:\n");
                break;
            case 51:
                input(a, b);
                mul(a, b, c);
                printf("A * B = ");
                print(c);
                printf("Choose the operation:\n");
                break;
            case 52:
                input(a, b);
                if((b->real * b->real + b->img * b->img) == 0)
                {
                    printf("Wrong numbers!\n");
                    printf("Choose the operation:\n");
                    break;
                }
                divide(a, b, c);
                printf("A / B = ");
                print(c);
                printf("Choose the operation:\n");
                break;
            default:
                break;
        }
    }   

    return 0;
}
