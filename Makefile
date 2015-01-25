CC=gcc
CFLAGS=-Wall -O3 -std=c++0x
LDFLAGS=
BIN_PATH=bin
SRC_PATH=src
ALGORITHMS=src/border.cpp src/period.cpp

all: dirs measure average

dirs:
	mkdir -p $(BIN_PATH)

average:
	$(CC) $(CFLAGS) $(ALGORITHMS) src/average.cpp $(LDFLAGS) -o $(BIN_PATH)/average

measure:
	$(CC) $(CFLAGS) $(ALGORITHMS) src/measure.cpp $(LDFLAGS) -o $(BIN_PATH)/measure

clean:
	rm -rf $(BIN_PATH)
