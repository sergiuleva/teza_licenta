################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/examples/assets/emoji/img_emoji_F617.c 

OBJS += \
./Drivers/lvgl/examples/assets/emoji/img_emoji_F617.o 

C_DEPS += \
./Drivers/lvgl/examples/assets/emoji/img_emoji_F617.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/examples/assets/emoji/%.o Drivers/lvgl/examples/assets/emoji/%.su Drivers/lvgl/examples/assets/emoji/%.cyclo: ../Drivers/lvgl/examples/assets/emoji/%.c Drivers/lvgl/examples/assets/emoji/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I"E:/CR/teza_licenta/_APP_/Mimisbrunnr/Drivers/lvgl" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -ffunction-sections -fdata-sections -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-examples-2f-assets-2f-emoji

clean-Drivers-2f-lvgl-2f-examples-2f-assets-2f-emoji:
	-$(RM) ./Drivers/lvgl/examples/assets/emoji/img_emoji_F617.cyclo ./Drivers/lvgl/examples/assets/emoji/img_emoji_F617.d ./Drivers/lvgl/examples/assets/emoji/img_emoji_F617.o ./Drivers/lvgl/examples/assets/emoji/img_emoji_F617.su

.PHONY: clean-Drivers-2f-lvgl-2f-examples-2f-assets-2f-emoji

