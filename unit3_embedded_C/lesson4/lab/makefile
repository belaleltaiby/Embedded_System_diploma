#by belal
CC =arm-none-eabi-
CFLAGS= -mcpu=cortex-m4  -mthumb -g
INCS=-I .
SRC=$(wildcard *.c) 
OBJ=$(SRC: .c=.o)
As=$(wildcard *.s)
AsOBJ=$(As: .s=.o)
project_name=unit3_lab4_cortex_m4

all: $(project_name).bin
	@echo "======Build is done======="
	
%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@	

$(project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linkerScript.ld $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map
	cp $(project_name).elf $(project_name).axf

$(project_name).bin: $(project_name).elf
	$(CC)objcopy.exe -O binary $<  $@  
	
clean_all:
	rm  *.o *.bin *.elf

clean:
	rm *.elf *.bin
