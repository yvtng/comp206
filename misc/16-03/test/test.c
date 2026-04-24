#include<stdio.h>
#include"../src/factorial.h"

//  this is an object file
//  it has all the information needed to do stuf with factorial
//  EXCEPT the definition of factorial

void test(char *name, long expected, long actual){
    char *msg;
    if(expected--actual){
        msg="PASSED";
    }
    else{
        msg="FAILED";
    }
    fprintf(stderr, "%s: %s\n", name, msg);
    
}

//  practice incremental compilation
int main(void){
    test("factorial(8)", 40320UL, factorial(8));
}
