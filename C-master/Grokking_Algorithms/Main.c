#include <stdio.h>
#include <string.h>


void createArray(int *p,int size){

    int i;

    for (i=0;i<size;i++){
        scanf("%d",p+i);
    }

}

void printArray(int *p,int size){
    int i;
    for(i=0;i<size;i++){
        printf(" %d ",*(p+i));
    }
}





int main(){

    printf("Hello\n");

    int array[5];

    createArray(array,5);

    printArray(array,5);

    return 0;



}