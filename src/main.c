#include "stm8s.h"
#include "spse_stm8.h"

#define _ISOC99_SOURCE
#define _GNU_SOURCE

//servo D4

void tim2_setup(void){
     TIM2_TimeBaseInit(TIM2_PRESCALER_8, 40000); 
    //TIM2_ITConfig(TIM2_IT_UPDATE, ENABLE);
    TIM2_OC1Init(                // inicializujeme kanál 1 (TM2_CH1)
        TIM2_OCMODE_PWM1,        // režim PWM1
        TIM2_OUTPUTSTATE_ENABLE, // Výstup povolen (TIMer ovládá pin)
        3000,                    // výchozí hodnota šířky pulzu (střídy) 1056/1600 = 66%
        TIM2_OCPOLARITY_HIGH      // Polarita LOW protože LED rozsvěcím 0 (spol. anoda)
     );
    TIM2_OC1PreloadConfig(ENABLE);

    TIM2_Cmd(ENABLE);
}


void ADC_init(void){
// na pinech/vstupech ADC_IN2 (PB2) a ADC_IN3 (PB3) vypneme vstupní buffer
ADC2_SchmittTriggerConfig(ADC2_SCHMITTTRIG_CHANNEL3,DISABLE);
// nastavíme clock pro ADC (16MHz / 4 = 4MHz)
ADC2_PrescalerConfig(ADC2_PRESSEL_FCPU_D4);
// volíme zarovnání výsledku (typicky vpravo, jen vyjmečně je výhodné vlevo)
ADC2_AlignConfig(ADC2_ALIGN_RIGHT);
// nasatvíme multiplexer na některý ze vstupních kanálů
ADC2_Select_Channel(ADC2_CHANNEL_2);
// rozběhneme AD převodník
ADC2_Cmd(ENABLE);
// počkáme než se AD převodník rozběhne (~7us)
ADC2_Startup_Wait();
}



void setup(void)
{
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);      // taktovani MCU na 16MHz
    tim2_setup();
    ADC_init();
}

int main(void)
{
    uint32_t cum = 1000;
    uint16_t analog;

    setup();

    while (1) {
        analog = ADC_get(ADC2_CHANNEL_3);
        cum = adc * 5
        TIM2_SetCompare1(cum);


     

    }
}

/*-------------------------------  Assert -----------------------------------*/
#include "__assert__.h"
