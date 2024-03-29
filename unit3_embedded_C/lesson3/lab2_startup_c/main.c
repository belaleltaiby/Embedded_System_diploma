#include "Platform_types.h"

#define RCC_base 0x40021000
#define GPIO_base 0x40010800
#define RCC_APB2ENR	  *(volatile uint32 *) (RCC_base     +0x18)
#define RCC_IOPAEN (1<<2)

typedef volatile unsigned int vuint32_t;
typedef union{
	vuint32_t All_Ports;
	struct{
		vuint32_t reserved : 13;
		vuint32_t p_13 : 1;
	}Pin;

}R_ODR_t;

typedef union{
	vuint32_t All_Ports;
	struct{
		vuint32_t reserved : 20;
		vuint32_t p_13 : 4;
	}mode;

}R_CRH_t;

volatile R_ODR_t *R_ODR = (volatile R_ODR_t *)(GPIO_base + 0x0C);
volatile R_CRH_t *R_CRH = (volatile R_CRH_t *)(GPIO_base +0x04);
int main(void)
{
	int i;
	RCC_APB2ENR |= (1<<2);
	R_CRH->mode.p_13 = 2;
	while(1){
	   R_ODR->Pin.p_13 = 1;
	   for(i=0 ; i< 5000;i++);
	 R_ODR->Pin.p_13 = 0;
	 for(i=0 ; i< 5000;i++);

   }
}