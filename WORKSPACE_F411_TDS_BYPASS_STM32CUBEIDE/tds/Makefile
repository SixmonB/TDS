#PATH_TO_BIN = /home/kerhoas/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.externaltools.arm-none.linux64_1.17.0.201812190825/tools/compiler/bin/

TARGET  = $(PATH_TO_BIN)arm-none-eabi-
CC      = $(TARGET)gcc
OBJCOPY = $(TARGET)objcopy
AS      = $(TARGET)gcc -x assembler-with-cpp -c
SIZE    = $(TARGET)size
OBJDUMP = $(TARGET)objdump

PROJECT_NAME = template
PROJECT_SRC = .
STM_SRC = _Libraries/STM32F4xx_HAL_Driver/Src
USER_SRC=  src

vpath %.c $(PROJECT_SRC)
vpath %.c $(STM_SRC)
vpath %.c $(USER_SRC)
#======================================================================================
SRCS =   $(STM_SRC)/stm32f4xx_hal.c
SRCS +=  $(STM_SRC)/stm32f4xx_hal_rcc.c
SRCS +=  $(STM_SRC)/stm32f4xx_hal_gpio.c
SRCS +=  $(STM_SRC)/stm32f4xx_hal_cortex.c
SRCS +=  $(STM_SRC)/stm32f4xx_hal_pcd.c
SRCS +=  $(STM_SRC)/stm32f4xx_hal_pcd_ex.c
SRCS +=  $(STM_SRC)/stm32f4xx_hal_uart.c
SRCS +=  $(STM_SRC)/stm32f4xx_hal_usart.c
SRCS +=  $(STM_SRC)/stm32f4xx_hal_dma.c
SRCS +=  $(STM_SRC)/stm32f4xx_hal_tim.c
SRCS +=  $(STM_SRC)/stm32f4xx_hal_tim_ex.c
SRCS +=  $(STM_SRC)/stm32f4xx_hal_i2s.c
SRCS +=  $(STM_SRC)/stm32f4xx_hal_i2s_ex.c
SRCS +=  $(STM_SRC)/stm32f4xx_hal_i2c.c
SRCS +=  $(STM_SRC)/stm32f4xx_std_spi.c
SRCS +=  $(STM_SRC)/stm32f4xx_std_dma.c
#======================================================================================
SRCS += src/main_bypass.c
#======================================================================================
SRCS += Device/startup_stm32f411xe.s
SRCS += _Libraries/BSP/STM32F4xx-Nucleo/stm32f4xx_nucleo.c
SRCS += src/stm32f4xx_hal_msp.c
SRCS += src/stm32f4xx_it.c
SRCS += src/system_stm32f4xx.c
SRCS += src/SystemClock.c
SRCS += src/stm32_wm5102_init.c
SRCS += src/drv/drv_i2c.c
SRCS += src/drv/drv_uart.c
SRCS += src/drv/drv_gpio.c
SRCS += src/drv/drv_i2s.c


#======================================================================================
#		FREERTOS
#======================================================================================
#FREE_RTOS_SRC = FreeRTOS/Source
#SRCS += $(FREE_RTOS_SRC)/croutine.c $(FREE_RTOS_SRC)/list.c $(FREE_RTOS_SRC)/queue.c $(FREE_RTOS_SRC)/tasks.c 
#SRCS += $(FREE_RTOS_SRC)/portable/GCC/ARM_CM4F/port.c
#SRCS += $(FREE_RTOS_SRC)/portable/MemMang/heap_1.c
#INC_DIRS += $(FREE_RTOS_SRC)/include/
#INC_DIRS += $(FREE_RTOS_SRC)/portable/GCC/ARM_CM4F/
#======================================================================================
EXT_OBJ = $(EXT_SRCS:.c=.o)
#======================================================================================
#		INCLUDE DIRECTORIES
#======================================================================================
INC_DIRS += inc/
INC_DIRS += src/drv/
INC_DIRS += _Libraries/STM32F4xx_HAL_Driver/Inc/
INC_DIRS += _Libraries/STM32F4xx_StdPeriph_Driver/Inc/
INC_DIRS += _Libraries/CMSIS/Device/ST/STM32F4xx/Include/
INC_DIRS += _Libraries/CMSIS/Include/
INC_DIRS += _Libraries/BSP/STM32F4xx-Nucleo/
#======================================================================================
#		LIBRARIES
#======================================================================================
#ULIBS +=_Libraries/CMSIS/Lib/GCC/libarm_cortexM4lf_math.a
#ULIBS +=_Libraries/CMSIS/Lib/ARM/arm_cortexM4lf_math.lib

#LIBSPEC= -L ./_Libraries/CMSIS/Lib/ARM
#LIBSPEC+= -l:arm_cortexM4l_math.lib
#======================================================================================
LIBDIR  = $(patsubst %,-L%,$(DLIBDIR) $(ULIBDIR))
INCLUDE = $(addprefix -I,$(INC_DIRS))

DEFS = -DSTM32F411xE
#======================================================================================
#		COMPILATION FLAGS
#======================================================================================
CFLAGS  = -ggdb -o0 -fcommon	#-Ofast								# Debug / Niveau de compilation
CFLAGS += -D __FPU_PRESENT=1 -D ARM_MATH_CM4
CFLAGS += -mlittle-endian -mthumb -mcpu=cortex-m4 -mthumb-interwork -Wl,--gc-sections 
CFLAGS += -mfpu=fpv4-sp-d16 -mfloat-abi=hard -fsingle-precision-constant
#======================================================================================
#		WARNING FLAGS
#======================================================================================
WFLAGS += -Wall -Wextra -Warray-bounds -Wno-unused-parameter
#======================================================================================
#		LOAD FLAGS
#======================================================================================
LFLAGS = -TDevice/gcc.ld  -lc -lgcc -lgcov -lm  -mfloat-abi=hard -Wl,-Map=$@.map 
#======================================================================================	
.PHONY: all
all: $(PROJECT_NAME)

.PHONY: $(PROJECT_NAME)
$(PROJECT_NAME): $(PROJECT_NAME).elf

$(PROJECT_NAME).elf: $(SRCS) $(EXT_OBJ)
	$(CC) $(INCLUDE) $(DEFS) $(CFLAGS) $(WFLAGS) $(LFLAGS) $^ -o $@
	$(OBJCOPY) -O ihex $(PROJECT_NAME).elf   $(PROJECT_NAME).hex
	$(OBJCOPY) -O binary $(PROJECT_NAME).elf $(PROJECT_NAME).bin

%.o: %.c
	$(CC) -c -o $@ $(INCLUDE) $(DEFS) $(CFLAGS) $^

clean:
	rm -f *.o $(PROJECT_NAME).elf $(PROJECT_NAME).hex $(PROJECT_NAME).bin $(PROJECT_NAME).map
	
