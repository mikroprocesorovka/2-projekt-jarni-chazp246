#include "stm8s.h"
#include "milis.h"

//#include "delay.h"
//#include <stdio.h>


#define _ISOC99_SOURCE
#define _GNU_SOURCE


#define POT_PORT GPIOC
#define POT_PIN  GPIO_PIN_5






void setup(void)
{
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);      // taktovani MCU na 16MHz
    init_milis();

}


int main(void)
{
    uint32_t time = 0;

    setup();

    if (milis() - time > 333) {
        time = milis();



    }
}

/*-------------------------------  Assert -----------------------------------*/
#include "__assert__.h"
