#include <stdio.h>

int main()
{
    int n;
    
    printf("Enter size of array\n");
    scanf("%d",&n);
    
    int *A = (int*)malloc(n*sizeof(int));
    //int *A = (int*)calloc(n,sizeof(int));
    
    for(int i = 0;i<n;i++){
        A[i] = i+1;
    }
    
    //free(A);
    //A[1] = 12;
    
    int *B = (int*)realloc(A,2*sizeof(int));
    
    printf("Preview block address = %d, new address = %d\n",A,B);
    
    for(int i = 0;i<n;i++){
        printf("%d ",B[i]);
    }
    
    return 0;
}