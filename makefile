OUTPUT = program

CC = g++

CFLAGS = -Wall -std=c++11

SRCS = main.cpp physicalMemory.cpp queue.cpp pageReplacementAlgorithm.cpp manager.cpp

HDRS = physicalMemory.h queue.h pageReplacementAlgorithm.h manager.h

OBJS = $(SRCS:.cpp=.o)

all: $(OUTPUT)

$(OUTPUT): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OUTPUT)
