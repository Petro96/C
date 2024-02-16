
#include <stdio.h>




void checkFunction(int number);

void checkOperation(char c){

    switch(c){
        case '+':
            printf("Its + \n");
            break;
        case '-':
            printf("its - \n");
            break;
        default:
            printf("Enter the correct char");
            break;
    }

}


int main(){

    // int number,a,b,max;
    // char operator;

    // printf("Hello World");

    // if-else
    // printf("Enter the number");
    // scanf("%d", &number);
    // checkFunction(number);

    // switch
    // printf("Enter char");
    // scanf("%c",&operator);
    // checkOperation(operator);

    // ternary
    // printf("Enter numbers");
    // scanf("%d%d ",&a,&b );
    // max = (a>b) ? a:b;
    // printf("Max : %d \n",max);

    // for loops

    // pointers

    //int n = 10;
    //int *p = &n;

    //printf(" %d \n",p); // reference
    //printf("%d",*p); // dereference

    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    int *ptr;
    ptr = array;

    for(int i = 0;i<10;i++){
        printf("Value of *ptr : %d\n",*ptr+i);
        printf("Address of ptr : %p\n",ptr+i);
        
    }

    // escape sequence
    // \a , \b - backspace , \n, \t , \v - vertical , \\ - backslash , \\', \\" , \\? 

    // functions

    //void swap(int a,int b);

    // -- data structure

    // primitive
    // abstract

    // linear
    // non-linear
    // (tree,graph)
    // homogeneous(array)
    // non homogeneous(structures)
    // static(static array)
    // dynamic(linked list)

    // linked list
    // linked values throught memory not ordered structure of list => head(start) - nodes - tail(end)
    // single - travel in one direction, double - travel both directions , circular linked in circle

    







    return 0;
}


void checkFunction(int number){

    if(number%2==0){
        printf("Your number is an even number. \n");
    }
    else{
        printf("Number is not even.");
    }


}

// ---- variables

// local
// external
// global
// auto
// static

// ---- preprocessor directives

// preprocessor(high level language) -> compiler -> assembler -> loader/linker(pure machine language)

// #include <filename>
// #define value
// #undef value

// #ifdef MACRO(if its define something)
// #endif
// #ifndef MACRO(if its not define)
// #endif
// #if
// #endif
// #if, #elif, #endif

// #error 
// #pragma - information to compiler








