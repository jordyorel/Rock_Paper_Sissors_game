CC = gcc
CFLAGS = -Wall

TARGET = main

all: $(TARGET)

$(TARGET): main.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

.PHONY: clean
clean:
	rm -f $(TARGET) *.o