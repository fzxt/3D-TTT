CXX := clang++
CXX_FLAGS := -g -std=c++11 -Wall
SRC_DIR := src

build:
	$(CXX) $(CXX_FLAGS) $(SRC_DIR)/*.cpp -o 3d_ttt

.PHONY: clean
clean: 
	rm -f *.o 3d_ttt 
