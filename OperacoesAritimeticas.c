#include<stdio.h>

int main()
{
    printf("\tPrograma C para calculos aritmeticos basicos \n\n");
    int a, b, soma, subtracao, multiplicacao;
    float divisao, resto;

    printf("Escolha um numero inteiro: ");
    scanf("%d", &a );
    printf("\nEscolha mais um numero inteiro: ");
    scanf("%d", &b);

    soma = a+b;
    subtracao = a-b;
    multiplicacao = a*b;
    divisao = a/b;
    resto = a%b;

    printf("\nO valor de adicao dos numeros = %d\n\n", soma);
    printf("O valor da subtracao do segundo ao primeiro = %d\n\n", subtracao);
    printf("O valor de multiplicacao = %d\n\n", multiplicacao);
    printf("O valor de divisao do primeiro pelo segundo = %.2f\n\n", divisao);
    printf("O valor resto de divisao do primeiro pelo segundo = %.2f\n\n", resto);
    printf("\n\tMuito Bom !\n\n");
    return 0;
}