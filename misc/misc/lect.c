#include<stdio.h>

long int factorial(int n){
    
    //  shift+j operation in vim combines line with one below it!!!

    //  go to fail bug
    //  just do the same writing style that Mrs. Morin taught you. #ICS3U
    if (n<=1){ 
        return 1;
    }
    return n*factorial(n-1);
}

    //  -Wall is Warnings, all; enable all warnings
    //  .exe is still produced and is still run but value does not mean anything
    //  outputs warnings
void foo(){}    //  it might take arguments, just not declared?? forward declarations??
int main(void){ //  this function has NO arguments, 

    signed char c1;
    unsigned char c2;

    c1++;   //  undefined behaviour
    c2++;   //  NOT undefined behaviour

    //  with the unsigned number, the C langauge guarantees that it will always be 0
    //  similarly, with the unsigned, max is 255? that is the max for all chars because 256 is 2^8
    
    //  how to get type error
    //
    //  between numeric types, C will trust you and try to convert as much as you can
    //  even with int that is so big it becomes a long int, C will trust you and do un definied behaviour
    //
    //
    return 0;
}
