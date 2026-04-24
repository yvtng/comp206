#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

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

    if(argc!=3){
        fprintf(stderr, "Error: \n");
        return 2;
    }

    char *end;
    double num=strtod(argv[2], &end);

    if(end==argv[2]||*end!='\0'||num<0){
        fprintf(stderr, "Error: \n");
        return 3;
    }

    printf("%.2f\n", sqrt(num));

    return 0;
}

int handle_anagram(int argc, char *argv[]){
	if(argc!=4){
        fprintf(stderr, "Error: \n");
        return 2;
    }
    char *s1=argv[2], *s2=argv[3];
    if(!is_all_lowercase(s1)||!is_all_lowercase(s2)){
        fprintf(stderr, "Error: \n");
        return 3;
    }
    
    printf("%s\n", is_anagram(s1, s2) ? "true" : "false");
    return 0;
}

int handle_gcd(int argc, char *argv[]){
    if(argc<3){
        fprintf(stderr, "Error: \n");
        return 2;
    }
    
    long ns[argc-2];
    for(int i=2; i<argc; i++){
        
        char *end;
        long num=strtol(argv[i], &end, 10);
        
        if(end==argv[i]||*end!='\0'||num<=0){
            fprintf(stderr, "Error: \n");
            return 3;
        }

        ns[i-2]=num;
    }

    printf("%ld\n", gcd_many(argc-2, ns));
    return 0;
}

int main(int argc, char *argv[]){
    
    if(argc<2){
        fprintf(stderr, "Error: \n");
        return 1;
    }

    if(strcmp(argv[1], "sqrt")==0){
        return handle_sqrt(argc, argv);
    }
    if(strcmp(argv[1], "anagram")==0){
        return handle_anagram(argc, argv);
    }
    if(strcmp(argv[1], "gcd")==0){
        return handle_gcd(argc, argv);
    }

    fprintf(stderr, "Error: \n");
    return 1;
    
}
