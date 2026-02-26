#include<stdio.h>

void foo(int a);

void add_points(int x1, int y1, int x2, int y2, int *rx, int *ry){
    //  this puts results in the pointer address
    //  this means that you can add things later on?? yes??
    //
    //  if *rx is inside parentheses, you can do math things to it
    //  such as: (*rx)++, (*rx)*=10
    //  this changes the address??
    //

    *rx=x1+x2;
    *ry=y1+y2;
}

void array_sum(void){
    
    //myarray is the same as &myarray
    //must say length in declaration
    int myarray[10]={1, 2, 3, 4, 5, 6, ,7, 8, 9, 10};    // just semi-colon means uninitialized array
                        // or you can do array-initializer
                    //myarray== &myarray==&myarray[0] are all the same
                    //
                    //future dynamic memory allocation and more stuff to follow, vecotors??
                    //
    int *p=myarray; 

    int sum =0;
    for (int i=0;i<10;i++){
        sum+=i[p];  //*(p+i)==p[i]==myarray[i];
                    //
                    //this means point to first num[add what is in here]
                    //dereference the sum of p+i. or dereference the sum of i+p
    }
    printf("%d\n", sum);
}

void take_array(int arr_len, int arr[]){
    //it is on you the programmer to make sure the length is there;
}

int main(void){
   
    array_sum();

    //in other languages, going out of bounds of array will raise an error
    //C trusts you
    //C knows there is not index 10 and it still trusts you
    //even with Walll
    // stack smashing detected thing
    //
    // array is only given lenth of given type of data 
    // stored next to each other in the array
    //
    // 10th index does not exist but it tries to do something 
    // to the memory address of what would be there
    //
    // if you use myarray[-1]=123456; this turns into a bug??? look further
    //
    // when passing arrays around, usually passed with lenght
    // they are copied, 
    //
    // automatically, myarray is the same as &myarray because myarray becomes a pointer to the first element
    // C does not care, you can do smht freaky
    
    /* 
    int point_x, point_y;
    
    //more on valgrind later, memory detection software error thing???
    //
    //include debug info can also be used
    //
    //program is run VERY differently when using valgrind
    //very difficult with memory bugs
    //heisenbugs
    //they happen but you can't see them
    // debugging tools

    //  changed the values of above vars within functions because it is their address that is taken
    //
    add_points(15, 32, 67, 420, &point_x, &point_y);

    printf("(%d, %d)\n", point_x, point_y);
    //  pointer to int is ok
    //  int to pointer is NOT
    //  "please dereference!"
    //  C: no
    //

    //int a;
    //int b;

    //  dont do this, * is a modifier on the name, not the type
    //int* pa=&a;
    //  do this to not forget when declaring multiple variables
    //int *pa, *pb;
    //pa=&a;

    //int *p;
    //p=&b;

    //from last week:
    //  scanf("%d", &a);
    //  &a is a reference to a
    //  this is a pointer
    //
    //  when declared as a pointer, you can do:
    //  this is how you get to a
    //  
    //  why the order you write type modifiers matter
    //
    //scanf("%d", pa);

    //printf("%d\n", a);
    //

    //scanf("%d", p);

    //printf("%d\n", b);

    // dereferencing
    //  when you try and make something that is 
    //  type pointer to do int things
    //
    //  POINTERS ARE NOT INTS, no matter if whatever they are pointing at is an in or not
    //
    //
    
    //int a =123;
    //int b= 245;

    //int *p, *q;
    //p=&b;
    //q=p; // <-- focus on what this will do
         // This means they point to the same place
         // assignment q and making it the SAME as p
         //     this does not mean that q points to p
         // q is set to b
         // p is changed on next line
         // q changed but p is unchanged
    //p=&a;

    //scanf("%d", q);

    //printf("%d (a = %d, b = %d)", *q, a, b);
    //int *p;
    //p=&a;   //  reads as, the address of a in scanf
            //
    //scanf("%d", p);

    //printf("%d (a = %d, b = %d)\n", *p, a, b);

    //  what if:
    //p=&b;
    //scanf("%d", p);

    //printf("%d (a = %d, b = %d)\n", *p, a, b);
    
    //  how to get a type error:
    //foo(p); //unlike numeric error, you almost never want this

    //there is a command to make all warnings error, review lecture recording
    //
    //
    //
    //otherwise, 
    //! gcc -Wall 

*/

}

