################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/KeyPad.c \
../HAL/LCD.c 

OBJS += \
./HAL/KeyPad.o \
./HAL/LCD.o 

C_DEPS += \
./HAL/KeyPad.d \
./HAL/LCD.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/KeyPad.o: ../HAL/KeyPad.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"G:/STMWORKSPACE/Drivers/HAL/Includes" -I"G:/STMWORKSPACE/Drivers/stm32_f103c6_drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/KeyPad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/LCD.o: ../HAL/LCD.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"G:/STMWORKSPACE/Drivers/HAL/Includes" -I"G:/STMWORKSPACE/Drivers/stm32_f103c6_drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

