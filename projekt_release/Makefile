CXX = g++
CXXFLAGS := -pthread -g -Wpedantic -Wall -std=c++17
OUT = projekt

SRC = $(wildcard *.cpp)
INC = $(wildcard *.h)

$(OUT): $(SRC) $(INC)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(SRC)

clean:
	rm -f $(OUT)