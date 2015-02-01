CC=g++
CFLAGS=-Wall -O3 -std=c++0x
LDFLAGS=
BIN_PATH=bin
SRC_PATH=src
ALGORITHMS=src/border.cpp src/unbordered.cpp src/dbf.cpp src/etc.cpp

all: dirs compare_algorithms average

dirs:
	mkdir -p $(BIN_PATH)

average:
	$(CC) $(CFLAGS) $(ALGORITHMS) src/average.cpp $(LDFLAGS) -o $(BIN_PATH)/average

compare_algorithms:
	$(CC) $(CFLAGS) $(ALGORITHMS) src/compare_algorithms.cpp $(LDFLAGS) -o $(BIN_PATH)/compare_algorithms

clean:
	rm -rf $(BIN_PATH)
