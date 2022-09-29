#include <stdint.h>
#define STACK_START_SP 0x20001000
extern int main(void);
void REST_HANDLER(void);

void DEFAULT_HANDLER(void){
	REST_HANDLER();
}


void NMI_HANDLER(void) __attribute__ ((weak,alias("DEFAULT_HANDLER")));;
void H_Fault_HANDLER(void) __attribute__ ((weak,alias("DEFAULT_HANDLER")));;
void MM_Fault_HANDLER(void) __attribute__ ((weak,alias("DEFAULT_HANDLER")));;
void BUS_Fault(void) __attribute__ ((weak,alias("DEFAULT_HANDLER")));;
void USAGE_Fault_HANDLER(void) __attribute__ ((weak,alias("DEFAULT_HANDLER")));;

uint32_t vectors[] __attribute__((sction(".vectors"))) ={
STACK_START_SP,
(uint32_t) &REST_HANDLER,
(uint32_t) &NMI_HANDLER,
(uint32_t) &H_Fault_HANDLER,
(uint32_t) &MM_Fault_HANDLER,
(uint32_t) &BUS_Fault,
(uint32_t) &USAGE_Fault_HANDLER
};	

void REST_HANDLER(void){
	main();
}