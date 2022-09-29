#by belal
CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m3  -mthumb 
INCS=-I
SRC= $(wildcard *.c) 
OBJ= $(SRC: .c=.o)
As= $(wildcard *.s)
AsOBJ= $(As: .s=.o)
project_name = learn-in-depth-cortex-m3

all: learn-in-depth-cortex-m3.hex
	

main.o: main.c
	$(CC)gcc.exe -c $(INCS) . $(CFLAGS) $< -o $@
 

startup.o: startup.c
	$(CC)gcc.exe -c $(INCS) . $(CFLAGS) $< -o $@	

learn-in-depth-cortex-m3.elf:  $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linkerScript.ld $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map


learn-in-depth-cortex-m3.hex: learn-in-depth-cortex-m3.elf
	$(CC)objcopy.exe -O binary $< $@  
	
clean:
	rm  *.o *.bin *.elf
	@echo "Everything clean"
