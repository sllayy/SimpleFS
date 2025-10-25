# Makefile for SimpleFS

CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = simplefs
OBJS = main.o fs.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

fs.o: fs.c fs.h
	$(CC) $(CFLAGS) -c fs.c

main.o: main.c fs.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f $(OBJS) $(TARGET) disk.sim log.txt

