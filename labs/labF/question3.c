#include<stdio.h>
#include<string.h>

int main(){
    
    char *str= "Hello World!";
    char *p;
    p=str;

    printf("First character is: %c\n", *p);
    
    p=p+1;

    printf("Next character is: %c\n", *p);
    
    printf("Printing all the characters in the string:\n");
    p=str;  //reset the pointer
            
    for(int i=0;i<strlen(str);i++){
        printf("%c\n", *p);
        p++;
    }
    
    return 0;
}
