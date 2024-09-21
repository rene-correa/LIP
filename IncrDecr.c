/**
 *  @ Author: Renê Corrêa
 *  @ Create Time: 21-09-24 09:43:40
 *  @ Description:
 */

#include <stdio.h> 

int main()
{
    printf("\tPrograma C para incremento (x) e decremento (y) de 1 \n\n");
    int x, y;

    printf("Escolha um numero inteiro para incremento em 5: ");
    scanf("%d", &x );
    printf("\nEscolha um numero inteiro para decremento em 5: ");
    scanf("%d", &y); 

 	printf("\n\tExemplo de incremento 1\n");
 	printf("Valor de x : %d \n", x++); 
 	printf("Valor de x : %d \n", x++); 
 	printf("Valor de x : %d \n", x++); 
 	printf("Valor de x : %d \n", x++); 
 	printf("Valor de x : %d \n", x++); 
 	printf("Valor of x : %d \n", x); 
 
 	printf("\n\tExemplo de decremento 1\n");
 	printf("Valor de y : %d \n", y--); 
 	printf("Valor de y : %d \n", y--);
	printf("Valor de y : %d \n", y--);
	printf("Valor de y : %d \n", y--);
	printf("Valor de y : %d \n", y--);    
 	printf("Valor de y : %d \n", y); 

 return 0;
}
