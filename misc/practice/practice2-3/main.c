#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	if (2 != argc) {
		fprintf(stderr, "usage: ./meow LIMIT\n");
		return 1;
	}

	char *endptr;
	
    long limit = strtol(argv[1], &endptr, 10);
	
    if (endptr == argv[1]) {
		fprintf(stderr, "fatal: LIMIT not a number\n");
		return 1;
	}

	char buf[256];

	// YOUR CODE BELOW HERE //
	// You're given some lines to do particular things.
	// You'll need to reassemble them and introduce control structures to
	// accomplish the task described below.

	// This reads a line from stdin, storing it in buf.
	//fgets(buf, sizeof(buf), stdin);
	// The call to `fgets` returns the special value `NULL` in case reading
	// fails or there is no more input to read.

	// This prints the string `buf` to stdout.
	//printf("%s", buf);

	// YOUR TASK:
	// 1. Use a loop to read lines from stdin until either there is nothing
	//    left to read, or the program has performed `limit` iterations of
	//    the loop.
	// 2. If the program ran out of input to read BEFORE reaching the limit
	//    it should print out "Meow~" followed by a newline character
	//    before exiting.
    
    for(long int i=0; i<limit; i++){
        
        if(fgets(buf, sizeof(buf), stdin)==NULL){
            printf("Meow~\n");
            break;
        }

        printf("%s", buf);

    }

    return 0;

}
