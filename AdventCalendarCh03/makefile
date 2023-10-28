# Makefile for compiling and running a C++ program

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Source file
SOURCE = main.cpp

# Executable file
EXECUTABLE = program

# Default target
all: $(EXECUTABLE)

# Compile the source code
$(EXECUTABLE): $(SOURCE)
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(EXECUTABLE) -lstdc++

# Clean up the executable and any object files
clean:
	rm -f $(EXECUTABLE)

# Run the program
run: $(EXECUTABLE)
	./$(EXECUTABLE)

.PHONY: all clean run
