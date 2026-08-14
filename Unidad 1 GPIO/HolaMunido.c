#include "LPC17XX.h";

#define PINSEL_LED = ~(3<<0)
#define PINMODE_LED = ~(2<<0)


void configPCB();
void blinkLED();
void delay();

int main(){
    configPCB();

    blinkLED();
}

void configPCB(){
    //CONFIGURO EL PIN 0 DEL PUERTO 0
    LPC_PINCON -> PINSEL(0) &= PINSEL_LED; //PINSEL0[1:0] = 11
    //LPC_GPIO0 -> PINMODE(0) &= PINMODE_LED; //PINMODE0[1:0] = 10
    LPC_GPIO0 -> FIODIR |= (1<<0); //F
}

void blinkLED(){
    while(1){
        LPC_GPIO0 -> FIOSET |= (1<<0); //ENCENDER LED
        delay(); //DELAY
        LPC_GPIO0 -> FIOCLR |= (1<<0); //APAGAR LED
        delay(); //DELAY
    }
}

/*
@brief: Function to generate a delay
@detailed: This function generates a delay by executing a loop that runs for a specified number of iterations. The __NOP instruction is used to create a no-operation delay, allowing the processor to wait without performing any other operations. The delay duration can be adjusted by changing the loop count.

*/

void delay(){
    for(int i=0; i<1000000; i++){
        __NOP;
    } //DELAY
}