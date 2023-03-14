################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Device/startup_stm32f411xe.s 

O_SRCS += \
../Device/startup_stm32f411xe.o 

OBJS += \
./Device/startup_stm32f411xe.o 

S_DEPS += \
./Device/startup_stm32f411xe.d 


# Each subdirectory must supply rules for building sources it contributes
Device/%.o: ../Device/%.s Device/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -c -I"C:/Users/sbsim/Documents/ENIB Materias/TSI/WORKSPACE_F411_TDS_SYNTHESE_STM32CUBEIDE/tds/HAL_Driver/Inc/Legacy" -I"C:/Users/sbsim/Documents/ENIB Materias/TSI/WORKSPACE_F411_TDS_SYNTHESE_STM32CUBEIDE/tds/Utilities/STM32F4xx-Nucleo" -I"C:/Users/sbsim/Documents/ENIB Materias/TSI/WORKSPACE_F411_TDS_SYNTHESE_STM32CUBEIDE/tds/inc" -I"C:/Users/sbsim/Documents/ENIB Materias/TSI/WORKSPACE_F411_TDS_SYNTHESE_STM32CUBEIDE/tds/CMSIS/device" -I"C:/Users/sbsim/Documents/ENIB Materias/TSI/WORKSPACE_F411_TDS_SYNTHESE_STM32CUBEIDE/tds/CMSIS/core" -I"C:/Users/sbsim/Documents/ENIB Materias/TSI/WORKSPACE_F411_TDS_SYNTHESE_STM32CUBEIDE/tds/HAL_Driver/Inc" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Device

clean-Device:
	-$(RM) ./Device/startup_stm32f411xe.d ./Device/startup_stm32f411xe.o

.PHONY: clean-Device

