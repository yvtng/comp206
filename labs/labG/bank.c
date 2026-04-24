#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<errno.h>
#include<limits.h>

struct BANK_ACCOUNT{
    char type;  // 'S'=savings, 'C'=chequing
    double balance;
};

long valid_times(const char *str){
    char *endptr;
    errno=0;
    
    long value=strtol(str, &endptr, 10);

    if(errno==ERANGE&&(value=LONG_MAX||value==LONG_MIN)||endptr==str||*endptr!='\0'||value<=0){
        fprintf(stderr, "Error: number must be a positive integer.\n";
        return 0;
    }
    return value;
}

int main(void){
    struct BANK_ACCOUNTS accounts[100];
    int nextSpot=0, times;
    char input[128];
    do{
        times=valid_times(input);
        printf("number of accounts to create: ");
        if(fgets(input, sizeof(input), stdin)==NULL){
            continue;
        }
        times=valid_times(input);
    }while(!times);

    for(int i=0;i<times;i++){
    }
    
    return 0;
}
