CC=gcc
CFLAGS=-O2 -std=c99 -Wall -Wextra -pedantic
RM=rm -f

.PHONY: all

surveyor: ; $(CC) src/surveyor/surveyor.c -o libsurveyor.so $(CFLAGS) -fPIC -shared

testapp: surveyor ; $(CC) test/app/main.c -o testapp $(CFLAGS) -L. -lsurveyor -Wl,-rpath=.

all: testapp

clean: ; $(RM) testapp libsurveyor.so
