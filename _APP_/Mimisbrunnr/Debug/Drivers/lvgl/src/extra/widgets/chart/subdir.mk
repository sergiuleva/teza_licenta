################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/extra/widgets/chart/lv_chart.c 

OBJS += \
./Drivers/lvgl/src/extra/widgets/chart/lv_chart.o 

C_DEPS += \
./Drivers/lvgl/src/extra/widgets/chart/lv_chart.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/extra/widgets/chart/%.o Drivers/lvgl/src/extra/widgets/chart/%.su Drivers/lvgl/src/extra/widgets/chart/%.cyclo: ../Drivers/lvgl/src/extra/widgets/chart/%.c Drivers/lvgl/src/extra/widgets/chart/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I"E:/CR/teza_licenta/_APP_/Mimisbrunnr/Drivers/lvgl" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -ffunction-sections -fdata-sections -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-extra-2f-widgets-2f-chart

clean-Drivers-2f-lvgl-2f-src-2f-extra-2f-widgets-2f-chart:
	-$(RM) ./Drivers/lvgl/src/extra/widgets/chart/lv_chart.cyclo ./Drivers/lvgl/src/extra/widgets/chart/lv_chart.d ./Drivers/lvgl/src/extra/widgets/chart/lv_chart.o ./Drivers/lvgl/src/extra/widgets/chart/lv_chart.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-extra-2f-widgets-2f-chart

