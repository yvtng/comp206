
all: test

test: bin/test
	bin/test

bin/test: build.test.o build/factorial.o
	echo "Building the tests!"
	gcc -Wall -Werror build/text.o build/factorial.o -o bin/test

build/test.o: test/test.c src/factorial.h
	gcc _Wall -Werror test/test.c -c -o build/test.o

