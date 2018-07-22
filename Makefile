CC=gcc
CFLAGS=-O2 -std=c99 -Wall -Wextra -pedantic
RM=rm -f
CWD=.
INC=-I$(CWD)/include -I$(CWD)/src
LIB=-L$(CWD)
OBJ=browser.o

browser.o :
	$(CC) -c -fPIC $(INC) src/browser/browser.c

surveyor.so : browser.o
	$(CC) $(CFLAGS) -fPIC -shared $(INC) src/surveyor/surveyor.c $(OBJ) -o libsurveyor.so

testapp : surveyor.so
	$(CC) $(CFLAGS) $(INC) test/app/main.c $(LIB) -lsurveyor -Wl,-rpath=$(CWD) -o testapp

all: testapp

clean:
	$(RM) testapp libsurveyor.so browser.o


