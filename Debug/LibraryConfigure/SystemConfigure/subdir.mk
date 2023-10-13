################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LibraryConfigure/SystemConfigure/SYS.c 

OBJS += \
./LibraryConfigure/SystemConfigure/SYS.o 

C_DEPS += \
./LibraryConfigure/SystemConfigure/SYS.d 


# Each subdirectory must supply rules for building sources it contributes
LibraryConfigure/SystemConfigure/%.o LibraryConfigure/SystemConfigure/%.su: ../LibraryConfigure/SystemConfigure/%.c LibraryConfigure/SystemConfigure/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DSTM32F103xB -c -I../Inc -I../LibraryConfigure/EXTIConfigure -I../LibraryConfigure/GPIOConfigure -I../LibraryConfigure/SystemConfigure -I../Drivers/CMSIS -I../Drivers/Devices -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-LibraryConfigure-2f-SystemConfigure

clean-LibraryConfigure-2f-SystemConfigure:
	-$(RM) ./LibraryConfigure/SystemConfigure/SYS.d ./LibraryConfigure/SystemConfigure/SYS.o ./LibraryConfigure/SystemConfigure/SYS.su

.PHONY: clean-LibraryConfigure-2f-SystemConfigure

