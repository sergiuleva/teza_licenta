################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/demos/widgets/lv_demo_widgets.c 

OBJS += \
./Drivers/lvgl/demos/widgets/lv_demo_widgets.o 

C_DEPS += \
./Drivers/lvgl/demos/widgets/lv_demo_widgets.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/demos/widgets/%.o Drivers/lvgl/demos/widgets/%.su Drivers/lvgl/demos/widgets/%.cyclo: ../Drivers/lvgl/demos/widgets/%.c Drivers/lvgl/demos/widgets/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I"E:/CR/teza_licenta/_APP_/Mimisbrunnr/Drivers/lvgl" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -ffunction-sections -fdata-sections -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-demos-2f-widgets

clean-Drivers-2f-lvgl-2f-demos-2f-widgets:
	-$(RM) ./Drivers/lvgl/demos/widgets/lv_demo_widgets.cyclo ./Drivers/lvgl/demos/widgets/lv_demo_widgets.d ./Drivers/lvgl/demos/widgets/lv_demo_widgets.o ./Drivers/lvgl/demos/widgets/lv_demo_widgets.su

.PHONY: clean-Drivers-2f-lvgl-2f-demos-2f-widgets

