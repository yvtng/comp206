#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

/*
 *  error messages must be:
 *      "error: [explanation]"
 *
 *              - "invalid input"
 *              - "wrong count of inputs"
 *              - "to [command name]"
 *              
 *  if user inputs an empty string, no error should be printed
 *  prompt should print again
 *
 *  exit command takes no arguments, exits with code 0
 *
 * */

int is_anagram(char *s1, char *s2){
	
    size_t len =strlen(s1);    
    if(len!=strlen(s2)){
        return 0;
    }
    
    int freq[26]={0};
    
    for (int i=0; s1[i]!='\0'; i++){
        freq[s1[i]-'a']++;
        freq[s2[i]-'a']--;
    }

    for(int i=0; i<26; i++){
        if(freq[i]!=0){
            return 0;
        }
    }

    return 1;
}

int is_all_lowercase(char *s){
	if(*s=='\0'){
        return 0;
    }
    
    for(char *p=s; *p!='\0'; p++){
    
        if (!islower((unsigned char)*p)){
            return 0;
        }
    }

    return 1;
}

long gcd(long n1, long n2){
	//  handle negative arguments
    n1=labs(n1);
    n2=labs(n2);
    
    //  handle zero cases
    if(n1==0){
        return n2;
    }
    if(n2==0){
        return n1;
    }

    //  Euclidian algorithm w/ modulo
    long temp;
    while(n2!=0){
        temp=n2;
        n2=n1%n2;
        n1=temp;
    }

    return n1;
}

long gcd_many(int n, long ns[]){
	//  set temp div long variable for previous value and function call 
    long div=ns[0];

    for(int i=1; i<n; i++){

        div=gcd(div, ns[i]);
    }

    return div;
}

int handle_sqrt(int argc, char *argv[]){
	if(argc!=2){
        fprintf(stderr, "error: wrong count of inputs to %s\n", argv[0]);
        return 2;
    }

    char *end;
    double num=strtod(argv[1], &end);
    
    if(num<0||end==argv[2]||*end!='\0'){
        fprintf(stderr, "error: invalid input to %s\n", argv[0]);
        return 3;
    }

    printf( "%.2f\n", sqrt(num));

    return 0;
}

int handle_anagram(int argc, char *argv[]){
	if(argc!=3){
        fprintf(stderr, "error: wrong count of inputs to %s\n", argv[0]);
        return 2;
    }
    char *s1=argv[1], *s2=argv[2];
    if(!is_all_lowercase(s1)||!is_all_lowercase(s2)){
        fprintf(stderr, "error: invalid input to %s\n", argv[0]);
        return 3;
    }
    
    printf("%s\n", is_anagram(s1, s2) ? "true" : "false");
    return 0;
}

int handle_gcd(int argc, char *argv[]){
	if(argc<2){
        fprintf(stderr, "error: wrong count of inputs to %s\n", argv[0]);
        return 2;
    }
    
    long ns[argc-1];
    for(int i=1; i<argc; i++){
        
        char *end;
        long num=strtol(argv[i], &end, 10);
        if(end==argv[i]||*end!='\0'||num<=0){

            fprintf(stderr, "error: invalid input to %s\n", argv[0]);
            return 3;
        }

        ns[i-1]=num;
    }

    printf( "%ld\n", gcd_many(argc-1, ns));
    return 0;
}

int handle_cmd(int argc, char *argv[]){
    if(strcmp(argv[0], "exit")==0){
        if(argc!=1){
            fprintf(stderr, "error: wrong count of inputs to %s\n", argv[0]);
            return 2;
        }
        return 1;
             
    }
    else if(strcmp(argv[0], "sqrt")==0){
        return handle_sqrt(argc, argv);
    }
    else if(strcmp(argv[0], "anagram")==0){
        return handle_anagram(argc, argv);
    }
    else if(strcmp(argv[0], "gcd")==0){
        return handle_gcd(argc, argv);
    }
    else{
        fprintf(stderr, "error: unknown command %s\n", argv[0]);
        return 0;
    }
}

int main(){
    char line[128];

    while(1){
        printf("> ");

        if(fgets(line, sizeof(line), stdin )==NULL){
            break;
        }

        char *argv[20];
        int argc=0;
        
        char *tok=strtok(line, " \n");

        while(tok!=NULL){
            argv[argc]=tok;
            argc++;
            tok=strtok(NULL," \n"); 
        }
        
        if(argc==0){
            continue;
        }
        else if(handle_cmd(argc, argv)==1){
            break;
        }
    }
    return 0;
}
