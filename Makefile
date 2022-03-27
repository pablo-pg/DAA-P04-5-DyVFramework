
CXX		  := g++
CXX_FLAGS := -Wswitch -Wall -Wextra -std=c++17 -ggdb -Wno-return-type 

BIN		:= bin
SRC		:= src
INCLUDE	:= include

LIBRARIES	:= lib
EXECUTABLE	:= framework


all: $(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cc 
	$(CXX) $(CXX_FLAGS) -I $(INCLUDE) $^ -o $@ -L $(LIBRARIES)

build: clean all

run: build
	./$(BIN)/$(EXECUTABLE)

clean:
	-rm $(BIN)/framework

clear: clean