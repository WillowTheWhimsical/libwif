CC = gcc
CFLAGS = -Wall -O3
LDFLAGS = -shared

target = libwif.so

all:
	$(CC) $(CFLAGS) libwif.c $(LDFLAGS) -o $(target)

install:
	cp libwif.so /usr/lib/
	cp libwif.h /usr/include/

uninstall:
	rm -f /usr/lib/libwif.so
	rm -f /usr/include/libwif.h
