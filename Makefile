CC = gcc
CFLAGS = -g -Wall
TARGET = mergesort
all: $(TARGET)
$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c -pthread
clean:
	$(RM) $(TARGET)
