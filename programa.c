#include <stdio.h>

int main()
{
    int i = 0;
    float nota1 = 0;
    float nota2 = 0;
    while(i < 5){
        printf("Digite a nota do aluno %i \n",i +1);
        scanf("%f %f",&nota1,&nota2);
        
        if(nota1 < 0 || nota1 > 10){
            printf("nota1 invalida \n");
            continue;
        } else if(nota2 < 0 || nota2 > 10){
            printf("nota2 invalida \n");
            continue;
        }
        float resultado = (nota1 + nota2)/2;
        printf("resultado é %f \n",resultado);
        i++;
    }

    return 0;
}