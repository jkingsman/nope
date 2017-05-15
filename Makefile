SHELL=/bin/sh

CC=gcc
CFLAGS+=-O2 -Wall -Wextra

INSTALL=install -D
INSTALL_DATA=$(INSTALL) -m 644

BINDIR=$(DESTDIR)/usr/bin

STRIP=strip
ifeq ($(OS),Windows_NT)
 X = .exe
else
  ifeq ($(shell uname), SunOS)
    STRIP=gstrip
  endif
endif

PROG=nope$X

$(PROG): *.c
	$(CC) -o $@ $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $^
	-$(STRIP) -s $@


install: $(PROG)
	$(INSTALL) $(PROG) $(BINDIR)/$(PROG)

uninstall:
	rm -f $(BINDIR)/$(PROG)

.PHONY: clean install uninstall
clean:
	rm -f $(PROG)
