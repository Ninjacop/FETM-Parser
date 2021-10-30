CXX = g++
CXXFLAGS = -g -Wall -std=c++17
SRCS = $(wildcard *.cpp src/fetm/*.cpp src/gui/*.cpp)
BUILD = build
OUT = fetmworks
TESTS = $(wildcard test_files/*.fetm)

all: 
	$(MAKE) clean
	$(MAKE) compile
	$(MAKE) run

compile: 
	mkdir -p $(BUILD)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(BUILD)/$(OUT) $(GTK)

run:
	./$(BUILD)/$(OUT) $(TESTS)

clean:
	rm -rf $(OUT)