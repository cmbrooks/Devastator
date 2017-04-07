CC=avr-gcc
INCLUDE=./inc
SRC=./src
OBJ=./obj
MCU_FLAG=-mmcu=atmega328p
CFLAGS+=-DF_CPU=16000000UL
CFLAGS+= -Os
CFLAGS+= -c
CFLAGS+= -I $(INCLUDE)/
CFLAGS+= -Wall
CFLAGS+= -Werror
CFLAGS+= -ggdb

all: hex

hex: $(OBJ)/main.o $(OBJ)/gpio.o $(OBJ)/pwm.o $(OBJ)/move.o
	$(CC) $(MCU_FLAG) $(OBJ)/main.o $(OBJ)/gpio.o $(OBJ)/pwm.o $(OBJ)/move.o -o out.elf
	avr-objcopy -O ihex out.elf out.hex

$(OBJ)/main.o: $(SRC)/main.c
	$(CC) $(MCU_FLAG) $(CFLAGS) $(SRC)/main.c -o $(OBJ)/main.o

$(OBJ)/gpio.o: $(SRC)/gpio.c
	$(CC) $(MCU_FLAG) $(CFLAGS) $(SRC)/gpio.c -o $(OBJ)/gpio.o

$(OBJ)/pwm.o: $(SRC)/pwm.c
	$(CC) $(MCU_FLAG) $(CFLAGS) $(SRC)/pwm.c -o $(OBJ)/pwm.o

$(OBJ)/move.o: $(SRC)/move.c
	$(CC) $(MCU_FLAG) $(CFLAGS) $(SRC)/move.c -o $(OBJ)/move.o

flash:
	avrdude -c arduino -p atmega328p -P /dev/ttyACM0 -U flash:w:out.hex

.PHONY: clean

clean:
	rm $(OBJ)/*.o out.elf out.hex 
