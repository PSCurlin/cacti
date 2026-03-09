LIBS = -lm
CXX = g++

SRC_EXTENSIONS = .cpp .h
SRC := $(foreach ext, $(SRC_EXTENSIONS), $(shell find . -name '*$(ext)'))

OBJS = main.o time.o area.o io.o leakage.o basic_circuit.o

all: cacti

pythonlib : time.o area.o io.o leakage.o basic_circuit.o cacti_wrap.o
	$(CXX) -shared $(FLAGS) area.o time.o leakage.o basic_circuit.o io.o cacti_wrap.o -L /usr/lib/python2.4/config -lpython2.4 -o _cacti.so

cacti : main.o time.o area.o io.o leakage.o basic_circuit.o
	$(CXX) $(FLAGS) $(OBJS) -o cacti $(LIBS)

main.o : main.cpp def.h areadef.h leakage.h basic_circuit.h
	$(CXX) $(FLAGS) -c main.cpp -o main.o

leakage.o : leakage.h leakage.cpp
	$(CXX) $(FLAGS) -c leakage.cpp -o leakage.o

time.o :  time.cpp def.h areadef.h leakage.h basic_circuit.h cacti_interface.h
	$(CXX) $(FLAGS) -c time.cpp -o time.o

area.o : area.cpp def.h areadef.h cacti_interface.h
	$(CXX) $(FLAGS) -c area.cpp -o area.o 

io.o : def.h io.cpp areadef.h cacti_interface.h
	$(CXX) $(FLAGS) -c io.cpp -o io.o

basic_circuit.o : basic_circuit.h basic_circuit.cpp
	$(CXX) $(FLAGS) -c basic_circuit.cpp -o basic_circuit.o 

cacti_wrap.o :  cacti_wrap.cpp
	$(CXX) -c io.cpp area.cpp time.cpp \
		basic_circuit.cpp leakage.cpp cacti_wrap.cpp \
		-I /usr/include/python2.4 \
		-I /usr/lib/python2.4/config

cacti_wrap.cpp: cacti.i
	swig -python cacti.i

.PHONY: format
format:
	@echo "Running clang-format"
	@clang-format -i $(SRC)

clean:
	rm -rf *.o cacti cache_params.aux core

