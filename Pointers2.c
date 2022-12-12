#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    
    printf("\n a pointer is: %p \n", &a);
    
    //----------------------------------//
    
    int* p;
    
    int* q;
    
    p = (int*)malloc(sizeof(int));
    
    *p = 10;
    
    q = p;
    
    free(p);
    
    p = (int*)malloc(sizeof(int));
    
    *p = 20;
    
    printf("\naddress %p with value %d\n", p,*p);
    printf("\naddress %p with value %d\n", q,*q);
    
    //----------------------------------//
    
    int* r;
    
    r = (int*)malloc(5*sizeof(int));
    
    *r = 0;
    *(r+1) = 1;
    *(r+2) = 8;
    *(r+3) = 4;
    *(r+4) = 20;
    
    for(int i = 0; i<5; i++){
        printf("\n r%d: %d",i, *(r+i));
    }

    return 0;
}
