CFLAGS = -Wall -Wextra -pedantic -lX11 -lXft -I/usr/include/freetype2 -pthread

PREFIX ?= /usr/local
CC ?= cc

all: herbe

herbe: ctimer.c
	$(CC) ctimer.c $(CFLAGS) -o ctimer

install: ctimer
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f ctimer ${DESTDIR}${PREFIX}/bin

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/ctimer

clean:
	rm -f ctimer

.PHONY: all install uninstall clean
