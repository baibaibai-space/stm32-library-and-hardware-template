#include "stm32f10x.h"                  // Device header

/**
	* @brief 	函数功能简介
	* @param 	函数参数简介
	* @retval 返回值简介
	*/
	
	
/**
  * @brief  LED初始化函数（针对GPIOA_Pin_0) 低电平有效
  * @param  无
  * @retval 无
  */
void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);		//开启挂载在APB2时钟线上的GPIOA外设时钟
	
	GPIO_InitTypeDef GPIO_InitStructure1;
	GPIO_InitStructure1.GPIO_Mode	=GPIO_Mode_Out_PP;
	GPIO_InitStructure1.GPIO_Pin		=GPIO_Pin_0;
	GPIO_InitStructure1.GPIO_Speed =GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure1);								//将PA0引脚初始化为推挽输出
	
	GPIO_SetBits(GPIOA,GPIO_Pin_0);
}


/**
  * @brief  LED开启函数（针对GPIOA_Pin_0)
  * @param  无
  * @retval 无
  */

void LED_ON(void)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_0);				//设置PA0引脚为低电平
}


/**
  * @brief  LED关闭函数（针对GPIOA_Pin_0) 
  * @param  无
  * @retval 无
  */
void LED_OFF(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_0);				//设置PA0引脚为高电平
}


/**
  * @brief  LED状态翻转函数（针对GPIOA_Pin_0) 
  * @param  无
  * @retval 无
  */
void LED_Turn(void)
{
	if (GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_0) == 0)		//获取输出寄存器的状态，如果当前引脚输出低电平
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_0);										//则设置PA0引脚为高电平
	}
	else																									//否则，即当前引脚输出高电平
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_0);									//则设置PA0引脚为低电平
	}
}

