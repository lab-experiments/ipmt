##########################################
#               ipmt make                 #
##########################################

# Compiler options
CC=g++
CFLAGS=-c -Wall
EXECUTABLE_NAME=pmt

# Folders
BIN=../bin
OBJ=$(BIN)/obj

# Files
SRC=$(wildcard *.cpp)

EXECUTABLE_FILES = $(EXECUTABLE_NAME:%=$(BIN)/%)
OBJECT_FILES     = $(SRC:%.cpp=$(OBJ)/%.o)

# Commands
# refs http://www.gnu.org/software/make/manual/make.html
build: $(EXECUTABLE_FILES)

clean:
		m -r -f $(BIN)

.PHONY: build clean

$(EXECUTABLE_FILES): $(OBJECT_FILES)
		    @$(CC) -o $@ $^
		    @echo "Build successful!"

$(OBJECT_FILES): $(OBJ)/%.o: %.cpp
		    @echo Compiling $<
		    @mkdir -p $(@D)
		    @$(CC) $(CFLAGS) -o $@ $<
