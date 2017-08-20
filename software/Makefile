### Default settings
# For Arduino SDK
#export PATH := /pool/arduino/arduino-1.6.13/hardware/tools/avr/bin:$(PATH)
# For self build toolchain
export PATH := /pool/avr/toolchain/root/bin:$(PATH)
CC := avr-gcc
OBJDUMP := avr-objdump
F_CPU ?= 16000000UL
OBJCOPY ?= avr-objcopy
AVRDUDE ?= /usr/local/bin/avrdude
PROGRAMMER ?= ft232r
MCU ?= atmega328p
AVRDUDE_MCU ?= ATMEGA328P
C_OPT ?= -Os
CFLAGS ?= $(C_OPT) -DF_CPU=$(F_CPU) -mmcu=$(MCU)
### Default settings end

MCU := attiny85
AVRDUDE_MCU := t85
F_CPU := 8000000UL
#C_OPT := -O2 -v

all: three-min-timer.hex
three-min-timer.hex: three-min-timer
	$(OBJCOPY) -O ihex $< $@
three-min-timer: three-min-timer.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<
three-min-timer.o: three-min-timer.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: install
install: all
	avrdude -F -V -c $(PROGRAMMER) -p $(AVRDUDE_MCU) -U flash:w:three-min-timer.hex

.PHONY: clean
clean:
	rm -f three-min-timer.hex three-min-timer three-min-timer.o *~
