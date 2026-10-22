CC = gcc
CPP = g++
CFLAGS = -Wall -Werror -c -g -std=c11 -I. -I/cluster/pixstor/class/cscore/include 
CPPFLAGS = -Wall -Werror -c -g -I. -I/cluster/pixstor/class/cscore/include
LDFLAGS = -lm -L. -L/cluster/pixstor/class/cscore/lib 

default: prelab8

%.o : %.c 
	@echo Compiling $^ 
	@$(CC) $(CFLAGS) $^

prelab8 : prelab8main.o prelab8.o
	@echo Linking $@ 
	@$(CC) $^ $(LDFLAGS) -o $@

clean : 
	@rm -rf *.o
	@rm -rf prelab8
	@echo All Clean!
