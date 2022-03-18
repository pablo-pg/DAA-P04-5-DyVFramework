
CXX		  := g++
CXX_FLAGS := -Wswitch -Wall -Wextra -std=c++17 -ggdb -Wno-return-type 

BIN		:= bin
SRC		:= src
INCLUDE	:= include

LIBRARIES	:= lib
EXECUTABLE	:= framework
ARGS  := test/cinta.in test/salida.out 2


all: $(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cc $(SRC)/instructions/*.cc
	$(CXX) $(CXX_FLAGS) -I $(INCLUDE) $^ -o $@ -L $(LIBRARIES)

build: clean all

one:
	./$(BIN)/$(EXECUTABLE) test/ejemplosRAM/test1.ram $(ARGS)




clean:
	-rm $(BIN)/simulador

clear: clean