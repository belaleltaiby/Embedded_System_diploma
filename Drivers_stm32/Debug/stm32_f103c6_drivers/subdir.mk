################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../stm32_f103c6_drivers/stm32_f103c6_drivers_EXTI.c \
../stm32_f103c6_drivers/stm32_f103c6_drivers_gpio.c \
../stm32_f103c6_drivers/stm32_f103c6_drivers_timers.c 

OBJS += \
./stm32_f103c6_drivers/stm32_f103c6_drivers_EXTI.o \
./stm32_f103c6_drivers/stm32_f103c6_drivers_gpio.o \
./stm32_f103c6_drivers/stm32_f103c6_drivers_timers.o 

C_DEPS += \
./stm32_f103c6_drivers/stm32_f103c6_drivers_EXTI.d \
./stm32_f103c6_drivers/stm32_f103c6_drivers_gpio.d \
./stm32_f103c6_drivers/stm32_f103c6_drivers_timers.d 


# Each subdirectory must supply rules for building sources it contributes
stm32_f103c6_drivers/stm32_f103c6_drivers_EXTI.o: ../stm32_f103c6_drivers/stm32_f103c6_drivers_EXTI.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"G:/STMWORKSPACE/Drivers/HAL/Includes" -I"G:/STMWORKSPACE/Drivers/stm32_f103c6_drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32_f103c6_drivers/stm32_f103c6_drivers_EXTI.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32_f103c6_drivers/stm32_f103c6_drivers_gpio.o: ../stm32_f103c6_drivers/stm32_f103c6_drivers_gpio.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"G:/STMWORKSPACE/Drivers/HAL/Includes" -I"G:/STMWORKSPACE/Drivers/stm32_f103c6_drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32_f103c6_drivers/stm32_f103c6_drivers_gpio.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32_f103c6_drivers/stm32_f103c6_drivers_timers.o: ../stm32_f103c6_drivers/stm32_f103c6_drivers_timers.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"G:/STMWORKSPACE/Drivers/HAL/Includes" -I"G:/STMWORKSPACE/Drivers/stm32_f103c6_drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32_f103c6_drivers/stm32_f103c6_drivers_timers.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

