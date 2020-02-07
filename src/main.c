#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "mycomplex.h"

int main(int argc, char* argv[])
{                      
    system("clear");
    int n = 0;
    int op[4];
    int ab[4] = {0};
    struct mycomplex* a = malloc(sizeof(struct mycomplex));
    struct mycomplex* b = malloc(sizeof(struct mycomplex));
    struct mycomplex* c = malloc(sizeof(struct mycomplex));
    void* handle1;
    void* handle2;
    void* handle3;
    void* handle4;
    void* (*func)(struct mycomplex *, struct mycomplex *, struct mycomplex *);
    char* error;
    char* string_ptr;
    printf("Choose the operation\n1 - Add\n2 - Sub\n3 - Mul\n4 - Div\n");
    for(int i = 0; i < 4; i++)
    {
        scanf("%d", &op[i]);
        switch(op[i])
        {
            case 1:
                handle1 = dlopen("libadd.so", RTLD_LAZY);
                if(!handle1) 
                {
                    fputs(dlerror(), stderr);
                    exit(1);
                }
                break;
            case 2:
                handle2 = dlopen("libsub.so", RTLD_LAZY);
                if(!handle2) 
                {
                    fputs(dlerror(), stderr);
                    exit(1);
                }
                break;
            case 3:
                handle3 = dlopen("libmul.so", RTLD_LAZY);
                if(!handle3) 
                {
                    fputs(dlerror(), stderr);
                    exit(1);
                }
                break;
            case 4:
                handle4 = dlopen("libdiv.so", RTLD_LAZY);
                if(!handle4) 
                {
                    fputs(dlerror(), stderr);
                    exit(1);
                }
                break;
            default:
                break; 
        }
    }
    system("clear");
    for(int i = 0; i < 4; i++)
    {
        switch(op[i])
        {
            case 1:
                if(ab[0] == 1)
                {
                    break;
                }
                ab[0] = 1;
                printf("1 - Add\n");
                break;
            case 2:
                if(ab[1] == 1)
                {
                    break;
                }
                ab[1] = 1;
                printf("2 - Sub\n");
                break;
            case 3:
                if(ab[2] == 1)
                {
                    break;
                }
                ab[2] = 1;
                printf("3 - Mul\n");
                break;
            case 4:
                if(ab[3] == 1)
                {
                    break;
                }
                ab[3] = 1;
                printf("4 - Div\n");
                break;
            default:
                break;
        }
    }
    printf("5 - Quit\n");
    while(n != 5)
    {
        printf("Choose the operation:\n");
        scanf("%d", &n);
        switch(n)
        {
            case 1:
                if(ab[0] == 0)
                {
                    break;
                }
                printf("Input A and B\n");
                scanf("%lf %lf %lf %lf", &a->real, &a->img, &b->real, &b->img);
                string_ptr = dlsym(handle1, "stirng_ptr");
                func = dlsym(handle1, string_ptr);
                if((error = dlerror()) != NULL)  
                {
                    fprintf (stderr, "%s\n", error);
                    exit(1);
                }
                (*func)(a, b, c);
                printf("(%lf, %lf)\n", c->real, c->img);
                break;
            case 2:
                if(ab[1] == 0)
                {
                    break;
                }
                printf("Input A and B\n");
                scanf("%lf %lf %lf %lf", &a->real, &a->img, &b->real, &b->img);
                string_ptr = dlsym(handle2, "stirng_ptr");
                func = dlsym(handle2, string_ptr);
                if((error = dlerror()) != NULL)  
                {
                    fprintf (stderr, "%s\n", error);
                    exit(1);
                }
                (*func)(a, b, c);
                printf("(%lf, %lf)\n", c->real, c->img);
                break;
            case 3:
                if(ab[2] == 0)
                {
                    break;
                }
                printf("Input A and B\n");
                scanf("%lf %lf %lf %lf", &a->real, &a->img, &b->real, &b->img);
                string_ptr = dlsym(handle3, "stirng_ptr");
                func = dlsym(handle3, string_ptr);
                if((error = dlerror()) != NULL)  
                {
                    fprintf (stderr, "%s\n", error);
                    exit(1);
                }
                (*func)(a, b, c);
                printf("(%lf, %lf)\n", c->real, c->img);
                break;
            case 4:
                if(ab[3] == 0)
                {
                    break;
                }
                printf("Input A and B\n");
                scanf("%lf %lf %lf %lf", &a->real, &a->img, &b->real, &b->img);
                if((b->real * b->real + b->img * b->img) == 0)
                {
                    printf("Wrong numbers!\n");
                    break;
                }
                printf("A / B = ");
                string_ptr = dlsym(handle4, "stirng_ptr");
                func = dlsym(handle4, string_ptr);
                if((error = dlerror()) != NULL)  
                {
                    fprintf (stderr, "%s\n", error);
                    exit(1);
                }
                (*func)(a, b, c);
                printf("(%lf, %lf)\n", c->real, c->img);
                break;
            default:
                break;
        }
    }

    for(int i = 0; i < 4; i++)
    {
        if(ab[i] == 1)
        {
            switch(i)
            {
                case 0:
                    dlclose(handle1);
                    break;
                case 1:
                    dlclose(handle2);
                    break;
                case 2:
                    dlclose(handle3);
                    break;
                case 3:
                    dlclose(handle4);
                    break;
            }
        }
    }

    return 0;
} 
