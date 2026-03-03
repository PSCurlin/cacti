LIBS = -lm
FLAGS = 

SRCS = main.c time.c area.c io.c

OBJS = main.o time.o area.o io.o

all: cacti

cacti : main.o time.o area.o io.o
	  gcc $(FLAGS) $(OBJS) -o cacti $(LIBS)

main.o : main.c def.h areadef.h
	  gcc $(FLAGS) -c main.c -o main.o

time.o :  time.c def.h areadef.h
	   gcc $(FLAGS) -c time.c -o time.o

area.o : area.c def.h areadef.h
	   gcc $(FLAGS) -c area.c -o area.o 

io.o : def.h io.c areadef.h
	  gcc $(FLAGS) -c io.c -o io.o

clean:
	  rm *.o cacti cache_params.aux core

