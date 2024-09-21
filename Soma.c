#include <stdio.h>
#include <stdlib.h>
int main ()
{
    int a, b, soma; //declaração de variáveis do tipo inteiro

    printf("Digite um numero inteiro: ");
    scanf("%d", &a); //recebe um inteiro e armazena na variável a
  
    printf("Digite um numero inteiro: ");
    scanf("%d", &b); //recebe um inteiro e armazena na variável b
    soma = a + b; //efetua adição de a com b e armazena na variável soma
  
    printf("O valor da soma = %d\n", soma); //imprime o resultado
  
    system ("pause");
    return(0);
}