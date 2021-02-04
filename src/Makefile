CC = clang++
FLAGS = -std=c++17 -Wshadow -Wall -Wno-unused-result 
OUT = gcpt

gcpt:
	$(CC) $(FLAGS) -O2 -o $(OUT) $(OUT).cpp

debug:
	$(CC) $(FLAGS) -O0 -ggdb3 -o $(OUT) $(OUT).cpp