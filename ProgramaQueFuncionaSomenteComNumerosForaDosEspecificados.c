#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    int i;
    int cont = 0;
    int parres = 0;
    int imparres = 1;
    printf("escreva um valor fora de 1 ate 1000 \n");
    scanf("%d",&i);
    if(i > 1000){
        while(cont != i){
            if(cont % 2 ==0){
                parres += cont;
            }
                printf("%i",imparres);
                if(cont != 0){
                imparres = imparres*cont;
                }
            
            cont++;
        }
    } else if(i< 1){
        while(cont != i){
            if(cont % 2 ==0){
                parres += cont;
                
            }
                if(cont != 0){
                imparres = imparres*cont;
                }
            
            cont--;
        }
    } else {
        printf("%i",i);
    }
    printf("\n");
    printf("soma dos pares %i",parres);
    printf("\n");
    printf("o produto dos impares %i",imparres);
    return 0;
}