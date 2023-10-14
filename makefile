# Name of the output
OUTPUT = program

# Compiler to use
CC = g++

# Compiler flags
CFLAGS = -Wall -std=c++11

# Source files
SRCS = main.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

all: $(OUTPUT)

$(OUTPUT): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OUTPUT)
