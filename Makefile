all: build

build: ./src/main.c
	gcc ./src/main.c ./src/ArbPreInt.c ./src/DynamicArray.c -o ./build/root-two-c-new -Wall -Wextra -Werror -g

run: build
	./build/root-two-c-new
