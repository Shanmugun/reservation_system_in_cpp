CC=g++
#-I for include directory path
INC=../inc
INCLUDE=-I $(INC)
OBJ=../obj
SRC=../src
BIN=../bin
CFLAGS=-c -g -Wall
VFLAGS = --tool=memcheck --leak-check=yes --show-reachable=yes

#update flag below to include library if any
LFLAGS=-l

#all target generates the executable
all: $(OBJ)/utility.o $(OBJ)/reservation_prg.o
	$(CC) $(OBJ)/utility.o $(OBJ)/reservation_prg.o -o $(BIN)/myprogram

$(OBJ)/utility.o: $(SRC)/utility.cpp $(INC)/utility.h
	$(CC) $(INCLUDE) $(CFLAGS) $(SRC)/utility.cpp
	mv -f *.o $(OBJ)

$(OBJ)/reservation_prg.o: $(SRC)/reservation_prg.cpp $(INC)/utility.h
	$(CC) $(INCLUDE) $(CFLAGS) $(SRC)/reservation_prg.cpp
	mv -f *.o $(OBJ)

valgrind: $(BIN)/myprogram
	valgrind $(VFLAGS) $(BIN)/myprogram


#clean target removes the *.o and executable
clean:
	rm -f $(OBJ)/*.o
	rm -f $(BIN)/myprogram