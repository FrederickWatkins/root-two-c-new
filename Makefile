all: build

build: ./src/main.c
	mkdir build
	gcc ./src/main.c ./src/ArbPreInt.c ./src/DynamicArray.c -o ./build/root-two-c-new -Wall -Wextra -Werror -g

run: build
	./build/root-two-c-new

clean:
	rm -rf build
