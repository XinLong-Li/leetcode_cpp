# makefile
CC=gcc
CFLAGS=-Wall -Wextra -pedantic
TARGET=floatcnv

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

clean:
	rm -f $(TARGET)