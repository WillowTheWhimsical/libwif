CC=gcc
CFLAGS=-Wall -O3
LDFLAGS=-shared

all:
	$(CC) $(CFLAGS) libwif.c $(LDFLAGS) -o libwif.so

install:
	cp libwif.so /usr/local/lib/
	cp libwif.h /usr/local/include

uninstall:
	rm -f /usr/local/lib/libwif.so
	rm -f /usr/local/include/libwif.h
