################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../VasLib/Src/Vas_uart.cpp 

OBJS += \
./VasLib/Src/Vas_uart.o 

CPP_DEPS += \
./VasLib/Src/Vas_uart.d 


# Each subdirectory must supply rules for building sources it contributes
VasLib/Src/%.o VasLib/Src/%.su VasLib/Src/%.cyclo: ../VasLib/Src/%.cpp VasLib/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../VasLib/Inc -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-VasLib-2f-Src

clean-VasLib-2f-Src:
	-$(RM) ./VasLib/Src/Vas_uart.cyclo ./VasLib/Src/Vas_uart.d ./VasLib/Src/Vas_uart.o ./VasLib/Src/Vas_uart.su

.PHONY: clean-VasLib-2f-Src

