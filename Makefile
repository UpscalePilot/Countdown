# Makefile for Ben Morley/3142870

# C compiler
CC:= gcc

# C Flags
CFLAGS:=-std=c11 -Wall

# V Path
VPATH:= src bin obj

countdown: main.o		# create  app
	$(CC) -o $@ $(CFLAGS) $^
	mv *.o obj	

#main.o: main.c main.h 
#	$(CC) $(CFLAGS) -c $^
#	mv src/*.gch obj

%.o: %.c			# compile .c files
	$(CC) -c $(CFLAGS) $^


.PHONY: clean, run
clean:				# removes all .o and app files
	rm -f *.o countdown obj/*.o obj/*.gch


run:				# runs countdown application
	./countdown


