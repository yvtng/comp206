#include "factorial.h"
//  "" is used in case definitions become incompatable

long factorial(long n){
    long p=1;

    //  be carefule of type used in for loop
    //
    //  if comparing to long, should use long
    for(long i=1;i<=n;i++){
        p*=i;
    }

    return p;
}
