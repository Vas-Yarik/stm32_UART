################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../VasLib/InitSystems/Src/Vas_rcc.cpp \
../VasLib/InitSystems/Src/Vas_uart.cpp 

OBJS += \
./VasLib/InitSystems/Src/Vas_rcc.o \
./VasLib/InitSystems/Src/Vas_uart.o 

CPP_DEPS += \
./VasLib/InitSystems/Src/Vas_rcc.d \
./VasLib/InitSystems/Src/Vas_uart.d 


# Each subdirectory must supply rules for building sources it contributes
VasLib/InitSystems/Src/%.o VasLib/InitSystems/Src/%.su VasLib/InitSystems/Src/%.cyclo: ../VasLib/InitSystems/Src/%.cpp VasLib/InitSystems/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../VasLib/InitSystems/Inc -I../VasLib/Common/Inc -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-VasLib-2f-InitSystems-2f-Src

clean-VasLib-2f-InitSystems-2f-Src:
	-$(RM) ./VasLib/InitSystems/Src/Vas_rcc.cyclo ./VasLib/InitSystems/Src/Vas_rcc.d ./VasLib/InitSystems/Src/Vas_rcc.o ./VasLib/InitSystems/Src/Vas_rcc.su ./VasLib/InitSystems/Src/Vas_uart.cyclo ./VasLib/InitSystems/Src/Vas_uart.d ./VasLib/InitSystems/Src/Vas_uart.o ./VasLib/InitSystems/Src/Vas_uart.su

.PHONY: clean-VasLib-2f-InitSystems-2f-Src

