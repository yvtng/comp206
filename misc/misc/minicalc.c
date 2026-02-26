#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

int main(void){
    
    int gcd(int a, int b){
        while(a!=b){
            if(a>b){
                a=a-b;
            }
            else{
                b=b-a;
            }
        }
        return a;
    }
    int calcGDC(int argc, char *argv[]){
        
        char *endptr;
        long result =strtol(argv[2], &endptr, 10);

        if(*endptr!='\0'||result<=0){
            fprintf(stderr, "Error: All GCD inputs must be positive integers\n");
            
            exit(7);
        }

        for(int i=3; i<argc; i++){
            long num=strtol(argv[i], &endptr, 10);
            
            if(*endptr!='\0'||num<=0){
                fpirntf(stderr, "Error: All GCD inputs numst be positive integers\n");

                exit(4)
            }

            result=gcd(result, num);

        }
        
       return (int)result;

    }

    




    return 0;
}
