################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../_Libraries/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_pid_init_f32.c \
../_Libraries/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_pid_init_q15.c \
../_Libraries/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_pid_init_q31.c \
../_Libraries/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_pid_reset_f32.c \
../_Libraries/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_pid_reset_q15.c \
../_Libraries/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_pid_reset_q31.c 

OBJS += \
./_Libraries/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_pid_init_f32.o \
./_Libraries/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_pid_init_q15.o \
./_Libraries/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_pid_init_q31.o \
./_Libraries/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_pid_reset_f32.o \
./_Libraries/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_pid_reset_q15.o \
./_Libraries/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_pid_reset_q31.o 

C_DEPS += \
./_Libraries/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_pid_init_f32.d \
./_Libraries/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_pid_init_q15.d \
./_Libraries/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_pid_init_q31.d \
./_Libraries/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_pid_reset_f32.d \
./_Libraries/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_pid_reset_q15.d \
./_Libraries/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_pid_reset_q31.d 


# Each subdirectory must supply rules for building sources it contributes
_Libraries/CMSIS/DSP_Lib/Source/ControllerFunctions/%.o _Libraries/CMSIS/DSP_Lib/Source/ControllerFunctions/%.su: ../_Libraries/CMSIS/DSP_Lib/Source/ControllerFunctions/%.c _Libraries/CMSIS/DSP_Lib/Source/ControllerFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F411RETx -DNUCLEO_F411RE -DDEBUG -DSTM32F411xE -DUSE_HAL_DRIVER -c -I"/home/casa/kerhoas/Desktop/TDS/WORKSPACE_F411_TDS_SYNTHESE_STM32CUBEIDE/tds/_Libraries/STM32F4xx_HAL_Driver/Inc" -I"/home/casa/kerhoas/Desktop/TDS/WORKSPACE_F411_TDS_SYNTHESE_STM32CUBEIDE/tds/_Libraries/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/casa/kerhoas/Desktop/TDS/WORKSPACE_F411_TDS_SYNTHESE_STM32CUBEIDE/tds/src/drv" -I"/home/casa/kerhoas/Desktop/TDS/WORKSPACE_F411_TDS_SYNTHESE_STM32CUBEIDE/tds/_Libraries/BSP/STM32F4xx-Nucleo" -I"/home/casa/kerhoas/Desktop/TDS/WORKSPACE_F411_TDS_SYNTHESE_STM32CUBEIDE/tds/_Libraries/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/casa/kerhoas/Desktop/TDS/WORKSPACE_F411_TDS_SYNTHESE_STM32CUBEIDE/tds/_Libraries/CMSIS/Include" -I"/home/casa/kerhoas/Desktop/TDS/WORKSPACE_F411_TDS_SYNTHESE_STM32CUBEIDE/tds/inc" -O0 -ffunction-sections -Wall -D __FPU_PRESENT=1 -D ARM_MATH_CM4 -mlittle-endian -mthumb -mcpu=cortex-m4 -mthumb-interwork -Wl,--gc-sections -mfpu=fpv4-sp-d16 -mfloat-abi=hard -fsingle-precision-constant -fcommon -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-_Libraries-2f-CMSIS-2f-DSP_Lib-2f-Source-2f-ControllerFunctions

clean-_Libraries-2f-CMSIS-2f-DSP_Lib-2f-Source-2f-ControllerFunctions:
	-$(RM) ./_Libraries/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_pid_init_f32.d ./_Libraries/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_pid_init_f32.o ./_Libraries/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_pid_init_f32.su ./_Libraries/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_pid_init_q15.d ./_Libraries/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_pid_init_q15.o ./_Libraries/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_pid_init_q15.su ./_Libraries/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_pid_init_q31.d ./_Libraries/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_pid_init_q31.o ./_Libraries/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_pid_init_q31.su ./_Libraries/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_pid_reset_f32.d ./_Libraries/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_pid_reset_f32.o ./_Libraries/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_pid_reset_f32.su ./_Libraries/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_pid_reset_q15.d ./_Libraries/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_pid_reset_q15.o ./_Libraries/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_pid_reset_q15.su ./_Libraries/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_pid_reset_q31.d ./_Libraries/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_pid_reset_q31.o ./_Libraries/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_pid_reset_q31.su

.PHONY: clean-_Libraries-2f-CMSIS-2f-DSP_Lib-2f-Source-2f-ControllerFunctions

