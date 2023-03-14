################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/drv/drv_gpio.c \
../src/drv/drv_i2c.c \
../src/drv/drv_i2s.c \
../src/drv/drv_uart.c 

OBJS += \
./src/drv/drv_gpio.o \
./src/drv/drv_i2c.o \
./src/drv/drv_i2s.o \
./src/drv/drv_uart.o 

C_DEPS += \
./src/drv/drv_gpio.d \
./src/drv/drv_i2c.d \
./src/drv/drv_i2s.d \
./src/drv/drv_uart.d 


# Each subdirectory must supply rules for building sources it contributes
src/drv/%.o src/drv/%.su: ../src/drv/%.c src/drv/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F411RETx -DNUCLEO_F411RE -DDEBUG -DSTM32F411xE -DUSE_HAL_DRIVER -c -I"C:/Users/sbsim/Documents/ENIB Materias/TSI/WORKSPACE_F411_TDS_SYNTHESE_STM32CUBEIDE/tds/_Libraries/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/sbsim/Documents/ENIB Materias/TSI/WORKSPACE_F411_TDS_SYNTHESE_STM32CUBEIDE/tds/_Libraries/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/sbsim/Documents/ENIB Materias/TSI/WORKSPACE_F411_TDS_SYNTHESE_STM32CUBEIDE/tds/src/drv" -I"C:/Users/sbsim/Documents/ENIB Materias/TSI/WORKSPACE_F411_TDS_SYNTHESE_STM32CUBEIDE/tds/_Libraries/BSP/STM32F4xx-Nucleo" -I"C:/Users/sbsim/Documents/ENIB Materias/TSI/WORKSPACE_F411_TDS_SYNTHESE_STM32CUBEIDE/tds/_Libraries/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/sbsim/Documents/ENIB Materias/TSI/WORKSPACE_F411_TDS_SYNTHESE_STM32CUBEIDE/tds/_Libraries/CMSIS/Include" -I"C:/Users/sbsim/Documents/ENIB Materias/TSI/WORKSPACE_F411_TDS_SYNTHESE_STM32CUBEIDE/tds/inc" -O0 -ffunction-sections -Wall -D __FPU_PRESENT=1 -D ARM_MATH_CM4 -mlittle-endian -mthumb -mcpu=cortex-m4 -mthumb-interwork -Wl,--gc-sections -mfpu=fpv4-sp-d16 -mfloat-abi=hard -fsingle-precision-constant -fcommon -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-src-2f-drv

clean-src-2f-drv:
	-$(RM) ./src/drv/drv_gpio.d ./src/drv/drv_gpio.o ./src/drv/drv_gpio.su ./src/drv/drv_i2c.d ./src/drv/drv_i2c.o ./src/drv/drv_i2c.su ./src/drv/drv_i2s.d ./src/drv/drv_i2s.o ./src/drv/drv_i2s.su ./src/drv/drv_uart.d ./src/drv/drv_uart.o ./src/drv/drv_uart.su

.PHONY: clean-src-2f-drv

