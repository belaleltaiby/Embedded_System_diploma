#by belal
CC= arm-none-eabi-
CFLAGS=-mcpu=cortex-m3 -mthumb   
INCS= -I
SRC= $(wildcard *.c) 
OBJ= $(SRC:.c=.o)
As= $(wildcard *.s)
AsOBJ= $(As:.s=.o)

all: learn-in-depth-cortex-m3.bin

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@ 

%.o: %.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@	

learn-in-depth.elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linkerScript.ld $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map

learn-in-depth-cortex-m3.bin: learn-in-depth.elf
	$(CC)objcopy.exe -O binary $< $@  
	
clean:
	rm -rf *.o *.elf *.bin