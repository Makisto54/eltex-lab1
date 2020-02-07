#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "mycomplex.h"

int main(int argc, char* argv[])
{
    system("clear");
    int n = 0;
    struct mycomplex* a = malloc(sizeof(struct mycomplex));
    struct mycomplex* b = malloc(sizeof(struct mycomplex));
    struct mycomplex* c = malloc(sizeof(struct mycomplex));
    while(n != 5)
    {
        void* handle;
        void* (*func)(struct mycomplex *, struct mycomplex *, struct mycomplex *);
        char* error;
        printf("Choose the operation\n1 - Add\n2 - Sub\n3 - Mul\n4 - Div\n5 - Quit\n");
        scanf("%d", &n);
        switch(n)
        {
            case 1:
                printf("Input A and B\n");
                scanf("%lf %lf %lf %lf", &a->real, &a->img, &b->real, &b->img);
                handle = dlopen("libadd.so", RTLD_LAZY);
                if(!handle) 
                {
                    fputs (dlerror(), stderr);
                    exit(1);
                }
                func = dlsym(handle, "add");
                if((error = dlerror()) != NULL)  
                {
                    fprintf (stderr, "%s\n", error);
                    exit(1);
                }
                (*func)(a, b, c);
                printf("(%lf, %lf)\n", c->real, c->img);
                dlclose(handle);
                break;
            case 2:
                printf("Input A and B\n");
                scanf("%lf %lf %lf %lf", &a->real, &a->img, &b->real, &b->img);
                handle = dlopen("libsub.so", RTLD_LAZY);
                if(!handle) 
                {
                    fputs (dlerror(), stderr);
                    exit(1);
                }
                func = dlsym(handle, "sub");
                if((error = dlerror()) != NULL)  
                {
                    fprintf (stderr, "%s\n", error);
                    exit(1);
                }
                (*func)(a, b, c);
                printf("(%lf, %lf)\n", c->real, c->img);
                dlclose(handle);
                break;
            case 3:
                printf("Input A and B\n");
                scanf("%lf %lf %lf %lf", &a->real, &a->img, &b->real, &b->img);
                handle = dlopen("libmul.so", RTLD_LAZY);
                if(!handle) 
                {
                    fputs (dlerror(), stderr);
                    exit(1);
                }
                func = dlsym(handle, "mul");
                if((error = dlerror()) != NULL)  
                {
                    fprintf (stderr, "%s\n", error);
                    exit(1);
                }
                (*func)(a, b, c);
                printf("(%lf, %lf)\n", c->real, c->img);
                dlclose(handle);
                break;
            case 4:
                printf("Input A and B\n");
                scanf("%lf %lf %lf %lf", &a->real, &a->img, &b->real, &b->img);
                if((b->real * b->real + b->img * b->img) == 0)
                {
                    printf("Wrong numbers!\n");
                    break;
                }
                printf("A / B = ");
                handle = dlopen("libdiv.so", RTLD_LAZY);
                if(!handle) 
                {
                    fputs (dlerror(), stderr);
                    exit(1);
                }
                func = dlsym(handle, "divide");
                if((error = dlerror()) != NULL)  
                {
                    fprintf (stderr, "%s\n", error);
                    exit(1);
                }
                (*func)(a, b, c);
                printf("(%lf, %lf)\n", c->real, c->img);
                dlclose(handle);
                break;
            default:
                break;
        }
    }
    return 0;
} 
