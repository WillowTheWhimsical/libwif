CC=gcc
CFLAGS=-Wall -Werror -O3
LDFLAGS=-shared

SRC=wif.c
TARGET=libwif.so

all:
	$(CC) $(CFLAGS) $(SRC) $(LDFLAGS) -o $(TARGET)

install:
	cp $(TARGET) /usr/local/lib/
	cp wif.h /usr/local/include

uninstall:
	rm -f /usr/local/lib/$(TARGET)
	rm -f /usr/local/include/wif.h
