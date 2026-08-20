/*
 * Directivas de inclusion
 */
#include "LPC17xx.h"

/*
 * Definiciones y Macros
 */
#define LED (1<<22)

/*
 * Prototipos de funciones
 */
void configPCB(void);
void delay(void);
void blinkLED(void);

int main(void){
	configPCB();
	while(1){
		blinkLed();
		delay();
	}
}

/*
 * @brief Configura el pin P0.22 como salida digital
 *
 * @details Selecciona la funcion GPIO para p0.22, configura el pin como
 * 			salida digital y habilita su acceso mediante el registro FIOMASK
 */
void configPCB(void){
	LPC_PINCON->PINSEL1 &= ~(0b11<<12);//p0.22 GPIO Function
	//no utilizamos pinMode ya que es solo para cuando usamos el pin como entrada
	LPC_GPIO0->FIODIR |= (1<<22);//p0.22 Como salida al poner 1 logico en el pin 22
	LPC_GPIO0->FIOMASK |= (1<<22);//coloco un un 1 logicoara que no cambie el estado de FIO set,clr,pin
	return;
}

/*
 * @brief Genera un retardo bloqueante mediante instruciones NOP.
 *
 * @details La espera se ejecuta mediante un ciclo for y el tiempo depende de la frecuencia del CPU y
 * 			de la cantidad de
 */
void delay(){
	for(int i = 0; i<4000000; i++){
		__NOP();
	}
}

/*
 * @brief Cambia el estado del pin, de uno a cero y de cero a uno haciendo l lectura del pin mediante
 * 		  mediante el registro FIOSET.
 * @details Leemos el estado del pin 22 en el puerto 0, si esta encendido lo apagamos, si esta apagado lo encendemos
 */
void blinkLed(){
	uint32_t estadoPin = (LPC_GPIO0->FIOSET & (1<<22));
	if(estadoPin == 0){
		LPC_GPIO0->FIOSET |= (1<<22);
	}else{
		LPC_GPIO0->FIOCLR |= (1<<22);
	}
}
