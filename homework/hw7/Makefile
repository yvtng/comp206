all: sb_test

sb_test: main.o stringbuilder.o
	gcc -Wall -Werror main.o stringbuilder.o -o sb_test

main.o: main.c stringbuilder.h
	gcc -Wall -Werror -c main.c

stringbuilder.o: stringbuilder.c stringbuilder.h
	gcc -Wall -Werror -c stringbuilder.c

clean:
	rm -f *.o sb_test
