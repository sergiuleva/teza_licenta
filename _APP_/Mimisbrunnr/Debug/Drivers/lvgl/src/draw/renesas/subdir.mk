################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/draw/renesas/lv_gpu_d2_draw_label.c \
../Drivers/lvgl/src/draw/renesas/lv_gpu_d2_ra6m3.c 

OBJS += \
./Drivers/lvgl/src/draw/renesas/lv_gpu_d2_draw_label.o \
./Drivers/lvgl/src/draw/renesas/lv_gpu_d2_ra6m3.o 

C_DEPS += \
./Drivers/lvgl/src/draw/renesas/lv_gpu_d2_draw_label.d \
./Drivers/lvgl/src/draw/renesas/lv_gpu_d2_ra6m3.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/draw/renesas/%.o Drivers/lvgl/src/draw/renesas/%.su Drivers/lvgl/src/draw/renesas/%.cyclo: ../Drivers/lvgl/src/draw/renesas/%.c Drivers/lvgl/src/draw/renesas/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I"E:/CR/teza_licenta/_APP_/Mimisbrunnr/Drivers/lvgl" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -ffunction-sections -fdata-sections -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-draw-2f-renesas

clean-Drivers-2f-lvgl-2f-src-2f-draw-2f-renesas:
	-$(RM) ./Drivers/lvgl/src/draw/renesas/lv_gpu_d2_draw_label.cyclo ./Drivers/lvgl/src/draw/renesas/lv_gpu_d2_draw_label.d ./Drivers/lvgl/src/draw/renesas/lv_gpu_d2_draw_label.o ./Drivers/lvgl/src/draw/renesas/lv_gpu_d2_draw_label.su ./Drivers/lvgl/src/draw/renesas/lv_gpu_d2_ra6m3.cyclo ./Drivers/lvgl/src/draw/renesas/lv_gpu_d2_ra6m3.d ./Drivers/lvgl/src/draw/renesas/lv_gpu_d2_ra6m3.o ./Drivers/lvgl/src/draw/renesas/lv_gpu_d2_ra6m3.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-draw-2f-renesas

