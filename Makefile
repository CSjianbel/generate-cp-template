CC = clang++
FLAGS = -std=c++17 -Wshadow -Wall -Wno-unused-result 
FILE = ccpt

ccpt: 
	$(CC) $(FLAGS) -O2 -o $(FILE) $(FILE).cpp

debug:
	$(CC) $(FLAGS) -O0 -ggdb3 -o $(FILE) $(FILE).cpp
