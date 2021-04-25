CXX = g++
CXXFLAGS = -g -Wall -std=c++17
SRCS = $(wildcard *.cpp src/*.cpp)
BUILD = build
OUT = fetmworks
TESTS = $(wildcard test_files/*.fetm)

all: 
	$(MAKE) compile
	$(MAKE) run

compile: 
	mkdir -p $(BUILD)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(BUILD)/$(OUT)

run:
	./$(BUILD)/$(OUT) $(TESTS)

clean:
	rm -rf $(OUT)