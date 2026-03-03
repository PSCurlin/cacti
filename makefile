LIBS = -lm
FLAGS = 
CC = gcc-9

SRCS = main.c time.c area.c io.c

OBJS = main.o time.o area.o io.o

all: cacti

cacti : main.o time.o area.o io.o
	  $(CC) $(FLAGS) $(OBJS) -o cacti $(LIBS)

main.o : main.c def.h areadef.h
	  $(CC) $(FLAGS) -c main.c -o main.o

time.o :  time.c def.h areadef.h
	   $(CC) $(FLAGS) -c time.c -o time.o

area.o : area.c def.h areadef.h
	   $(CC) $(FLAGS) -c area.c -o area.o 

io.o : def.h io.c areadef.h
	  $(CC) $(FLAGS) -c io.c -o io.o

clean:
	  rm *.o cacti cache_params.aux core

