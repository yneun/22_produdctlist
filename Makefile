CC = gcc
CFLAGS = -W -Wall
TARGET = product
DTARGET= product_debug
OBJECTS = main.c product.o manager.c

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(DTARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -DDEBUG -o $@ $^

clean :
	rm *.o product_debug product


