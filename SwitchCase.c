#include <stdio.h>

int main() 
{
    int numero;

    while (1) 
	{
        // Exibe as opções para o usuário
        printf("Escolha um numero:\n"); 
        printf("1 - opção 1\n");
        printf("2 - opção 2\n");
        printf("3 - Sair\n");

        scanf("%d", &numero);// Lê a escolha do usuário

        // Inicia a estrutura switch-case para tratar a escolha do usuário
        switch (numero) 
		{
            case 1:
                printf("Voce escolheu a opção 1.\n");// Executa a ação para o numero 1
                break;
                
            case 2:
                printf("Voce escolheu a opção 2.\n");// Executa a ação para o numero 2
                break;
                
            case 3:
                printf("Saindo do programa.\n"); // Sai do programa
                return 0;
                
            default:
                printf("Numero invalido. Tente novamente.\n");// Trata uma escolha inválida
                break;
        }
    }

    return 0;
}