################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/SystemClock.c \
../src/keyboard.c \
../src/main_synthese.c \
../src/midi.c \
../src/newlib_stubs.c \
../src/stm32_wm5102_init.c \
../src/stm32f4xx_hal_msp.c \
../src/stm32f4xx_it.c \
../src/system_stm32f4xx.c \
../src/timer_duree.c \
../src/util.c 

OBJS += \
./src/SystemClock.o \
./src/keyboard.o \
./src/main_synthese.o \
./src/midi.o \
./src/newlib_stubs.o \
./src/stm32_wm5102_init.o \
./src/stm32f4xx_hal_msp.o \
./src/stm32f4xx_it.o \
./src/system_stm32f4xx.o \
./src/timer_duree.o \
./src/util.o 

C_DEPS += \
./src/SystemClock.d \
./src/keyboard.d \
./src/main_synthese.d \
./src/midi.d \
./src/newlib_stubs.d \
./src/stm32_wm5102_init.d \
./src/stm32f4xx_hal_msp.d \
./src/stm32f4xx_it.d \
./src/system_stm32f4xx.d \
./src/timer_duree.d \
./src/util.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o src/%.su: ../src/%.c src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F411RETx -DNUCLEO_F411RE -DDEBUG -DSTM32F411xE -DUSE_HAL_DRIVER -c -I"C:/Users/sbsim/Documents/ENIB Materias/TSI/WORKSPACE_F411_TDS_SYNTHESE_STM32CUBEIDE/tds/_Libraries/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/sbsim/Documents/ENIB Materias/TSI/WORKSPACE_F411_TDS_SYNTHESE_STM32CUBEIDE/tds/_Libraries/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/sbsim/Documents/ENIB Materias/TSI/WORKSPACE_F411_TDS_SYNTHESE_STM32CUBEIDE/tds/src/drv" -I"C:/Users/sbsim/Documents/ENIB Materias/TSI/WORKSPACE_F411_TDS_SYNTHESE_STM32CUBEIDE/tds/_Libraries/BSP/STM32F4xx-Nucleo" -I"C:/Users/sbsim/Documents/ENIB Materias/TSI/WORKSPACE_F411_TDS_SYNTHESE_STM32CUBEIDE/tds/_Libraries/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/sbsim/Documents/ENIB Materias/TSI/WORKSPACE_F411_TDS_SYNTHESE_STM32CUBEIDE/tds/_Libraries/CMSIS/Include" -I"C:/Users/sbsim/Documents/ENIB Materias/TSI/WORKSPACE_F411_TDS_SYNTHESE_STM32CUBEIDE/tds/inc" -O0 -ffunction-sections -Wall -D __FPU_PRESENT=1 -D ARM_MATH_CM4 -mlittle-endian -mthumb -mcpu=cortex-m4 -mthumb-interwork -Wl,--gc-sections -mfpu=fpv4-sp-d16 -mfloat-abi=hard -fsingle-precision-constant -fcommon -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-src

clean-src:
	-$(RM) ./src/SystemClock.d ./src/SystemClock.o ./src/SystemClock.su ./src/keyboard.d ./src/keyboard.o ./src/keyboard.su ./src/main_synthese.d ./src/main_synthese.o ./src/main_synthese.su ./src/midi.d ./src/midi.o ./src/midi.su ./src/newlib_stubs.d ./src/newlib_stubs.o ./src/newlib_stubs.su ./src/stm32_wm5102_init.d ./src/stm32_wm5102_init.o ./src/stm32_wm5102_init.su ./src/stm32f4xx_hal_msp.d ./src/stm32f4xx_hal_msp.o ./src/stm32f4xx_hal_msp.su ./src/stm32f4xx_it.d ./src/stm32f4xx_it.o ./src/stm32f4xx_it.su ./src/system_stm32f4xx.d ./src/system_stm32f4xx.o ./src/system_stm32f4xx.su ./src/timer_duree.d ./src/timer_duree.o ./src/timer_duree.su ./src/util.d ./src/util.o ./src/util.su

.PHONY: clean-src

