#include<stdio.h>
#include<stdlib.h>
#include"stringbuilder.h"

int main(void){
    struct string_builder sb=sb_init(8);
    char buffer[100];
    while(scanf("%99s", buffer)==1){
        sb_append(&sb, buffer);
        sb_append(&sb, " ");
    }

    char *result=sb_build(&sb);

    if(result!=NULL){
        printf("%s\n", result);
        free(result);
    }

    sb_destroy(&sb);

    return 0;
}
