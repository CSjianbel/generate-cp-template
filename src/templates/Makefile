CC = clang++ 
FLAGS = -std=c++17 -Wshadow -Wall -Wno-unused-result 
OUT = "FILENAME"

$(OUT):

	$(CC) $(FLAGS) -O2 -o $(OUT) $(OUT).cpp

debug: 

	$(CC) $(FLAGS) -ggdb3 -O0 -o $(OUT) $(OUT).cpp

clean: 
	rm $(OUT)
