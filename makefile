# Name of the output
OUTPUT = program

# Compiler to use
CC = g++

# Compiler flags
CFLAGS = -Wall -std=c++11

# Source files
SRCS = main.cpp physicalMemory.cpp queue.cpp pageReplacementAlgorithm.cpp manager.cpp

# Header files (not strictly necessary in the Makefile but added for clarity)
HDRS = physicalMemory.h queue.h pageReplacementAlgorithm.h manager.h

# Object files
OBJS = $(SRCS:.cpp=.o)

all: $(OUTPUT)

$(OUTPUT): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OUTPUT)
