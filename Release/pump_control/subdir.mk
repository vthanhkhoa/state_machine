################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../pump_control/pump_module.c 

OBJS += \
./pump_control/pump_module.o 

C_DEPS += \
./pump_control/pump_module.d 


# Each subdirectory must supply rules for building sources it contributes
pump_control/%.o pump_control/%.su pump_control/%.cyclo: ../pump_control/%.c pump_control/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -DSTM32F103xB -DUSE_FULL_LL_DRIVER -DHSE_VALUE=8000000 -DHSE_STARTUP_TIMEOUT=100 -DLSE_STARTUP_TIMEOUT=5000 -DLSE_VALUE=32768 -DHSI_VALUE=8000000 -DLSI_VALUE=40000 -DVDD_VALUE=3300 -DPREFETCH_ENABLE=1 -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/ADMIN/STM32CubeIDE/tuan7_lthtn/pump_control" -I"C:/Users/ADMIN/STM32CubeIDE/tuan7_lthtn/module_led" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-pump_control

clean-pump_control:
	-$(RM) ./pump_control/pump_module.cyclo ./pump_control/pump_module.d ./pump_control/pump_module.o ./pump_control/pump_module.su

.PHONY: clean-pump_control

