################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LibraryConfigure/EXTIConfigure/EXTI.c 

OBJS += \
./LibraryConfigure/EXTIConfigure/EXTI.o 

C_DEPS += \
./LibraryConfigure/EXTIConfigure/EXTI.d 


# Each subdirectory must supply rules for building sources it contributes
LibraryConfigure/EXTIConfigure/%.o LibraryConfigure/EXTIConfigure/%.su: ../LibraryConfigure/EXTIConfigure/%.c LibraryConfigure/EXTIConfigure/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DSTM32F103xB -c -I../Inc -I../LibraryConfigure/EXTIConfigure -I../LibraryConfigure/GPIOConfigure -I../LibraryConfigure/SystemConfigure -I../Drivers/CMSIS -I../Drivers/Devices -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-LibraryConfigure-2f-EXTIConfigure

clean-LibraryConfigure-2f-EXTIConfigure:
	-$(RM) ./LibraryConfigure/EXTIConfigure/EXTI.d ./LibraryConfigure/EXTIConfigure/EXTI.o ./LibraryConfigure/EXTIConfigure/EXTI.su

.PHONY: clean-LibraryConfigure-2f-EXTIConfigure

