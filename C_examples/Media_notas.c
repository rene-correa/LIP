/* Programa para uso de um vetor (array)
*
* Um vetor pode ser definido como uma sequência de dados 
* ocupando posições consecutivas de memória
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int notas[3]; // Declaração de um vetor com 3 elementos do tipo inteiro
    int datas[5] = {03,14,18,22,29}; // Declaração e inicialização de um vetor
	float media;

    printf("Entre com a nota do aluno 1\n");
    scanf("%d",&notas [0]);

    printf("Entre com a nota do aluno 2\n");
    scanf("%d",&notas [1]);

    printf("Entre com a nota do aluno 3\n");
    scanf("%d",&notas [2]);

    media = (notas[0] + notas[1] + notas[2]) / 3.0;
    printf ("A media de nota = %f\n\n", media);
    
    printf("Provas realizadas em novembro de 2022 no dia %d\n", datas[1]); // Posição ou índice do elemento no vetor (N-1)

    return 0;
}