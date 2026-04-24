#include "ringbuffer.h"

#include <stdio.h>
#include <stdlib.h>
#include<errno.h>

int main(int argc, char *argv[]){
    char *endptr;
    long n;
    FILE *fp;
    struct ringbuffer rb;

    char line[LINE_LENGTH+1];
    char out[LINE_LENGTH+1];

    if(argc<3){
        fprintf(stderr, "Error: not enough arguments\n");
        return 1;
    }

    errno=0;
    n=strtol(argv[1], &endptr, 10);

    if(errno!=0||*endptr!='\0'||n<0){
        fprintf(stderr, "Error: invalid number\n");
        return 1;
    }

    fp=fopen(argv[2], "r");
    if(fp==NULL){
        fprintf(stderr, "Error: cannot open file");
        return 3;
    }

    if(n==0){
        fclose(fp);
        return 0;
    }

    rb=rb_init((int)n);
    while(fgets(line, LINE_LENGTH+1, fp)!=NULL){
        rb_push(&rb, line);
    }
    while(rb_pop(&rb, out)){
        printf("%s", out);
    }
    rb_destroy(&rb);
    fclose(fp);


    return 0;

}
