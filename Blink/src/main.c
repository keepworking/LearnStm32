#include "stm32f7xx_hal.h"

#define LED_PIN                                GPIO_PIN_1
#define SWITCH_PIN                             GPIO_PIN_11
#define MY_GPIO_PORT                          GPIOI
#define LED_GPIO_CLK_ENABLE()                  __HAL_RCC_GPIOI_CLK_ENABLE()

int main(void)
{
  HAL_Init();

  LED_GPIO_CLK_ENABLE();

  GPIO_InitTypeDef GPIO_InitStruct;

  GPIO_InitStruct.Pin = LED_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;

  HAL_GPIO_Init(MY_GPIO_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = SWITCH_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;

  HAL_GPIO_Init(MY_GPIO_PORT, &GPIO_InitStruct);

  GPIO_PinState OldState,NewState;

  OldState = NewState = HAL_GPIO_ReadPin(MY_GPIO_PORT,SWITCH_PIN);

  while (1)
  {
    NewState = HAL_GPIO_ReadPin(MY_GPIO_PORT,SWITCH_PIN);
    if(NewState != OldState&&NewState == GPIO_PIN_SET){
      HAL_GPIO_TogglePin(MY_GPIO_PORT,LED_PIN);
    }
    OldState = NewState;
  }
}

void SysTick_Handler(void)
{
  HAL_IncTick();
}

void NMI_Handler(void)
{
}

void HardFault_Handler(void)
{
  while (1) {}
}


void MemManage_Handler(void)
{
  while (1) {}
}

void BusFault_Handler(void)
{
  while (1) {}
}

void UsageFault_Handler(void)
{
  while (1) {}
}

void SVC_Handler(void)
{
}


void DebugMon_Handler(void)
{
}

void PendSV_Handler(void)
{
}
