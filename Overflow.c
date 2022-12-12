#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    
    int* p;
    
    p = (int*)malloc(sizeof(int));
    
    *p = 10000000000000000000;
    
    printf("\naddress %p", p);
    printf(" with value ");
    printf("%d\n", *p);

    return 0;
}