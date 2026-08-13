#include "LPC17XX.h";

#define PINSEL_LED = ~(3<<0)

void configPCB();

int main(){
    configPCB();


}

void configPCB(){
    //CONFIGURO EL PIN 0 DEL PUERTO 0
    LPC_PINCON -> PINSEL(0) &= PINSEL_LED; //PINSEL0[1:0] = 11
    LPC_GPIO0 -> PINMODE(0) &= ~(2<<0); //PINMODE0[1:0] = 10
}