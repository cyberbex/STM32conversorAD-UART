#include "adc_drive.h"
#include "help_func.h"
#include "uart_drive.h"

char num[10];
int analog_rx = 0;
int unidade=0;
int decimal=0;
float fator= 11.4;
float tensaoPlaca =0.0;
int main(void)
{
// Initialize the ADC
	systick_init();
	UART_init(2,9600);
	adc_init(adc1, PA, 1);
	
while(1)
{
	if(adc_check(adc1, PA, 1))
	{
		analog_rx = adc_rx(adc1, PA, 0);
		UART_SEND(2,"ADC1: ");
		tensaoPlaca = analog_rx * 3.3/4096;
		tensaoPlaca = tensaoPlaca * fator;
		
	
		
		unidade = tensaoPlaca;
		decimal = (tensaoPlaca * 100);
		decimal = decimal%100;
		
		UART_SEND(2,"tensao placa: ");
		int2char(unidade,num);
		UART_SEND(2,num);
		UART_SEND(2,",");
		int2char(decimal,num);
		UART_SEND(2,num);
		str_empty(num);
		
	}
	DelayMs(1000);
}
}
