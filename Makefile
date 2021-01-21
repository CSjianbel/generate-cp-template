CC = clang++
FLAGS = -Wall -Werror -std=c++17 
FILE = ccpt

ccpt: 
	$(CC) $(FLAGS) -O2 -o $(FILE) $(FILE).cpp

debug:
	$(CC) $(FLAGS) -O0 -ggdb3 -o $(FILE) $(FILE).cpp
