#include <stdio.h> 
 
int main() 
{
	printf("\tPrograma C para calculo da area e da circunferencia \n\n"); 
	double raio, circunferencia, area; // Declara 3 variáveis em ponto flutuante 
	double pi = 3.14159265; // Declara e inicializa a variavel pi
  
	printf("Digite um valor para o raio: "); // Solicita o valor do raio ao usuario  
	scanf("%lf", &raio); // Lê a entrada na variável raio 
 
	area = raio * raio * pi; // Calcula a area 
	circunferencia = 2.0 * pi * raio; // Calcula a cicunferencia 
	
	printf("O valor do raio = %lf\n", raio); // Imprime o valor do raio escolhido
 	printf("A valor da area = %lf\n", area); // Imprime da area calculada 
	printf("O valor da circunferencia = %lf\n", circunferencia); // Imprime o valor da circunferencia calculada
 
	return 0; 
}
