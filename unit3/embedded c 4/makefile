
CC = arm-none-eabi-
CFLAGS = -mcpu=cortex-m4 -gdwarf-2 -mthumb
INCS = -I .
LIBS =
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)
Project_Name = cortex_m4_lab4

all: $(Project_Name).bin
	@echo "======Build Is Done======"



%.o: %.c
	$(CC)gcc -c $(CFLAGS) $(INCS) $< -o $@

$(Project_Name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(OBJ) $(AsOBJ) -o $@

$(Project_Name).bin: $(Project_Name).elf
	$(CC)objcopy.exe -O binary $< $@
	cp $(Project_Name).elf $(Project_Name).axf 

clean_all:
	rm *.o *.elf *.bin
	@echo "======Everything Cleaned======"

clean: 
	rm *.elf *.bin
	@echo "======Cleaned Executable Files======"

clean_obj:
	rm *.o
	@echo "======Cleaned Object Files======"