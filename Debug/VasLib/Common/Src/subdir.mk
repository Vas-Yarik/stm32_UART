################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../VasLib/Common/Src/Vas_common.cpp 

OBJS += \
./VasLib/Common/Src/Vas_common.o 

CPP_DEPS += \
./VasLib/Common/Src/Vas_common.d 


# Each subdirectory must supply rules for building sources it contributes
VasLib/Common/Src/%.o VasLib/Common/Src/%.su VasLib/Common/Src/%.cyclo: ../VasLib/Common/Src/%.cpp VasLib/Common/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../VasLib/InitSystems/Inc -I../VasLib/Common/Inc -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-VasLib-2f-Common-2f-Src

clean-VasLib-2f-Common-2f-Src:
	-$(RM) ./VasLib/Common/Src/Vas_common.cyclo ./VasLib/Common/Src/Vas_common.d ./VasLib/Common/Src/Vas_common.o ./VasLib/Common/Src/Vas_common.su

.PHONY: clean-VasLib-2f-Common-2f-Src

