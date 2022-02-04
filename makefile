PREFIX ?= /usr/local
CC ?= cc

all: ctimer

ctimer: ctimer.c util.c
	$(CC) ctimer.c util.c -o ctimer

install: ctimer
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f ctimer ${DESTDIR}${PREFIX}/bin

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/ctimer

clean:
	rm -f ctimer

.PHONY: all install uninstall clean
