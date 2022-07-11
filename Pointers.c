#include <stdio.h>

int main()
{
    int x = 4;
    int *pointerOfX = &x;
    int y = *pointerOfX;
    
    printf("pointer : %d",pointerOfX);
    printf(",value : %d",y);

    return 0;
}
