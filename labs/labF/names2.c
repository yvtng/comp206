#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
    
    char name [30], multipleNames[1000];
    int numberOfTimes;

    if(argc==2){
        numberOfTimes=atoi(argv[1]);
    }
    else{
        numberOfTimes=2;
    }
    

    printf("Enter a name: ");
    //scanf("%s", name);
    int n=-1;
    do{
        n++;
        name[n]=getc(stdin);
    }while(name[n]!='\n');
    name[n]='\0';
    //   Copy the word in the array name into the array
    //   multipleNames for numberOfTimes
    //
    //
    //
    int ssize=0;
    char *ptr=name;
    
    while(*ptr++!='\0'){
        ssize++;
    }

    for(int i=0;i<numberOfTimes;i++){
        for(int j=0;j<ssize;j++){
            multipleNames[(i*ssize)+j]=name[j];
        }
    }
    multipleNames[numberOfTimes*ssize]='\0';
    printf("%s\n", multipleNames);
    return 0;
}
