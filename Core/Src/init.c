#include "init.h"

void GPIO_INi(void){
    SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOBEN+RCC_AHB1ENR_GPIOCEN);//включение тактирования RCC для GPIOB и GPIOC


    //используемые для светодиодов пины :PB9,PB8,PC6,PB15,PB13,PB12
    //используемые для кнопок пины:PA15,PC7

    //прямое обращение
    *(uint32_t*)(0x40020400UL+0x00UL)|=(0x01<<18);//настройка PB9 на выход
    *(uint32_t*)(0x40020400UL+0x08UL)|=(0x01<<18);//настройка скорости
    
    //использование своих макросов
    SET_BIT_CUSTOM(GPIOB_MODER_CUSTOM,GPIOB_MODER_PB8_OUT_CUSTOM);//настройка PB8 на выход
    SET_BIT_CUSTOM(GPIOB_OSPEEDR_CUSTOM,GPIOB_OPSEEDR_PB8_MID_CUSTOM);//настройка скорости

    SET_BIT(GPIOC->MODER,GPIO_MODER_MODER6_0);//настройка PC6 на выход
    SET_BIT(GPIOC->OSPEEDR,GPIO_OSPEEDER_OSPEEDR6_0);//настройка скорости
    
    SET_BIT(GPIOB->MODER,GPIO_MODER_MODER15_0);//настройка PB15 на выход
    SET_BIT(GPIOB->OSPEEDR,GPIO_OSPEEDER_OSPEEDR15_0);//настройка скорости

    SET_BIT(GPIOB->MODER,GPIO_MODER_MODER13_0);//настройка PB13 на выход
    SET_BIT(GPIOB->OSPEEDR,GPIO_OSPEEDER_OSPEEDR13_0);//настройка скорости

    SET_BIT(GPIOB->MODER,GPIO_MODER_MODER12_0);//настройка PB12 на выход
    SET_BIT(GPIOB->OSPEEDR,GPIO_OSPEEDER_OSPEEDR12_0);//настройка скорости
}