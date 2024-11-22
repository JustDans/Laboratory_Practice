#include <stdint.h>
#include <init.h>

uint32_t led_bits[]={
    GPIO_BSRR_BS9, //PB9
    GPIO_BSRR_BS8, //PB8
    GPIO_BSRR_BS6, //PC6
    GPIO_BSRR_BS15,//PB15
    GPIO_BSRR_BS13,//PB13
    GPIO_BSRR_BS12 //PB12
    };

uint8_t mass[6] = {0,0,0,0,0,0};

void turn_leds(void){// включение определенного числа светодиодов
    for (int i =0;i<6;i++){
        if (i==2){
            SET_BIT(GPIOC->BSRR,led_bits[i]*mass[i]);
        }
        else{
            SET_BIT(GPIOB->BSRR,led_bits[i]*mass[i]);
        }
    }
}

void reset_all_leds(void){//выключение всех светодиодов
    for (int i = 0;i<6;i++){
        if (i==2){
            SET_BIT(GPIOC->BSRR,led_bits[i]<<16);
        }
        else{
            SET_BIT(GPIOB->BSRR,led_bits[i]<<16);
        }
    }
}

int main(void){
    GPIO_INi();
    uint8_t led_number = 0;//заданое кол-во светодиодов первой кнопкой
    uint8_t led_ind =0;
    uint8_t turned_leds=0;
    uint8_t flag1 = 1;//флаги овечающие за состояние кнопки
    uint8_t flag2 = 1;

    while(1){


        if((READ_BIT(GPIOB->IDR,GPIO_IDR_IDR_5)!=0) & (flag1)){
            flag1 = 0;
            if (led_number<6){led_number++;}
            else{led_number = 0;}
        }
        else if ((READ_BIT(GPIOB->IDR,GPIO_IDR_IDR_5)==0)&(!flag1)){
            flag1 = 1;

        }

        if ((READ_BIT(GPIOC->IDR,GPIO_IDR_IDR_7))!=0 & (flag2)){
            if (turned_leds==6){//если выключены 6 светодиодов то просто выключаются
                reset_all_leds();
                turned_leds=0;
                memset(mass,0,6);
                led_ind=0;
                }
            else if (led_number+turned_leds>6){//если нунжо включить больше светодиодов, чем есть выключенных
                reset_all_leds();
                turned_leds=led_number;
                memset(mass,0,6);
                for (int i = 0;i<led_number;i++){
                    if (led_ind==6){led_ind=0;}
                    mass[led_ind]=1;
                    led_ind++;
                }
                turn_leds();
            }
            else if(led_number==6 & turned_leds!=0){//если первой кнопкой было установлено 6 светодиодов и включен хотя бы один, то включаеся 6
                for(int i = 0;i=6;i++){
                    mass[i]=1;
                }
                turn_leds();
                turned_leds=6;
                led_ind=6;
            }
            else { //если нужно включить несколько светодиодов и для них есть место
                turned_leds+=led_number;
                for (int i = 0;i<led_number;i++){
                    if (led_ind==6){led_ind=0;}
                    mass[led_ind]=1;
                    led_ind++;
                }
                turn_leds();
            }
            flag2 = 0;
        }
        else if ((READ_BIT(GPIOC->IDR,GPIO_IDR_IDR_7)==0)&(!flag2)){
            flag2 = 1;
        }
    }
}