CC=gcc
CFLAGS=-O2 -std=c99 -Wall -Wextra -pedantic
RM=rm -f
CWD=.
INCPATH=$(CWD)/include
LIBPATH=$(CWD)

browser.o :
	$(CC) -c -fPIC -I$(INCPATH) src/browser/browser.c

surveyor.so : browser.o
	$(CC) $(CFLAGS) -fPIC -shared src/surveyor/surveyor.c -o libsurveyor.so

testapp : surveyor.so
	$(CC) $(CFLAGS) test/app/main.c -L$(LIBPATH) -lsurveyor -Wl,-rpath=$(CWD) -o testapp

all: testapp

clean:
	$(RM) testapp libsurveyor.so browser.o


