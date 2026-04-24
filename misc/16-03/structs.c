#include<stdio.h>
#include<stdlib.h>

struct FOO{
    int n;

    
    //  char str[];
    //  this will not work when you are
    //  assigning like: mystr.str= "hello world"
    //  cannot modify
    //  But can work with 
    char *str;
};

char msg[30]="hello, world?";

struct FOO *mk_FOO(void){
    struct FOO *my_foo=malloc(sizeof(struct FOO));
    
    my_foo->n=15;
    my_foo->str="hello, world!";

    return my_foo;  
}

struct FOO modify1(struct FOO f){
    f->n=30;
    f->str[0]='H';

    return f;

}

struct FOO modify2(struct FOO f){
    f->n=0;
    f->str[12]='!';
    return f;
}

int main(void){
    struct FOO f=mk_FOO();
    struct FOO *f1=modify1(f);
    struct FOO *f2=modify2(f);
    
    printf("f1.n: %d\tf1.str: %d\n",f1->n, f1->str);
    printf("f2.n: %d\tf2.str: %d\n",f2->n, f2->str);
    //  why doesnn't n change but str does?
    //      when passed, the struct has no connnection to original value,
    //      it is only a copy
    //
    //      when f is passed to modify1(), 
    //      it is only returning a copy
    //      this copy has its own field .n and own .str
    //      this is not copying the data that it points to
    //      but rather the address that it points to
    //
    //      therefore when it is modified, the same string is modified
    //
    //      f was never seen by the modify functions, 
    //      only copies were seem
    //
    //

    return 0;
}
