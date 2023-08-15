
#Set Compiler
CC = arm-none-eabi-
#Set Compiler Flags
CFLAGS = -mcpu=cortex-m3 -gdwarf-2 -mthumb 
#Set Includes
INCS = -I .
#Set Libraries
LIBS = 
#Set .c Wildcard
SRC = $(wildcard *.c)
#Set .c OBJ
OBJ = $(SRC:.c=.o)
#Set .s Wildcard
As = $(wildcard *.s)
#Set .s OBJ
AsOBJ = $(As:.s=.o)
#Set Project Name
Project_Name = pressure_detector

all: $(Project_Name).bin
	@echo "======Build Is Done======"


%.o: %.c
	$(CC)gcc -c $(CFLAGS) $(INCS) $< -o $@

$(Project_Name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linkerscript.ld $(OBJ) $(AsOBJ) -o $@ -Map=map_file.map

$(Project_Name).bin: $(Project_Name).elf
	$(CC)objcopy.exe -O binary $< $@

clean_all:
	rm *.o *.elf *.bin
	@echo "======Everything Cleaned======"

clean: 
	rm *.elf *.bin
	@echo "======Cleaned Executable Files======"

clean_obj:
	rm *.o
	@echo "======Cleaned Object Files======"