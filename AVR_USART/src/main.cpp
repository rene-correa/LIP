/**
 *  @ Author: Renê Corrêa
 *  @ Create Time: 14-09-24 09:46:55
 *  @ Description:
 */

#ifdef F_CPU
#undef F_CPU
#define F_CPU 16000000UL 
#endif

#include <avr/io.h>      
#include <util/delay.h>  

#define TAXA_DADOS 9600 // Definição da taxa de dados
#define VALOR_UBRR0 (((F_CPU / (16UL * TAXA_DADOS))) - 1) //registrador do baudrate

#define ASSINCRONO (0<<UMSEL00) // Seleção de modo assíncrono 

#define DESABILITADO    (0<<UPM00)
#define PARIDADE_PAR    (2<<UPM00)
#define PARIDADE_IMPAR  (3<<UPM00)
#define MODO_PARIDADE   DESABILITADO // Seleção modo sem paridade

#define UM_BIT      (0<<USBS0)
#define DOIS_BITS   (1<<USBS0)
#define BIT_PARADA  UM_BIT      // Seleção modo de parada um bit

#define CINCO_BITS  (0<<UCSZ00)
#define SEIS_BITS   (1<<UCSZ00)
#define SETE_BITS   (2<<UCSZ00)
#define OITO_BITS   (3<<UCSZ00)
#define BIT_DADOS   OITO_BITS  // Seleção do modo oito bits de dados 

void SendMessage(char* ptr);
void USART_Init();
void USART_TransmitPolling(uint8_t BYTE_DE_DADOS);

char string[10] = {'R','a','t','a','n','k','y','\n','\0'};

int main()
{
	USART_Init(); // Inicializa a USART 
	while (1)
	{
		// Transmisão de dados 
		SendMessage(string);
		
		_delay_ms(1000); // Intervalo de transmissão
	}
	return 0;
}

void SendMessage(char* ptr){
  while(*ptr != '\0'){
    USART_TransmitPolling(*ptr);
    ptr++;
  }
}

void USART_Init()
{
	// Ajuste da taxa de dados
	UBRR0H = VALOR_UBRR0 >> 8;
	UBRR0L = VALOR_UBRR0;
	
	// Ajuste do formato do quadro
	UCSR0C = ASSINCRONO | MODO_PARIDADE | BIT_PARADA | BIT_DADOS;
	
	// Habilitação de recepção e transmissão
	UCSR0B = (1<<RXEN0) | (1<<TXEN0);
}

void USART_TransmitPolling(uint8_t BYTE_DE_DADOS)
{
	while (( UCSR0A & (1<<UDRE0)) == 0) {}; // Aguarda o UDRE estar pronto
	UDR0 = BYTE_DE_DADOS;
}