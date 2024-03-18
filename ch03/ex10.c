#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// 20214935 컴퓨터 공학과 정용헌, 3장 - 10번 


int delete(int array[],int loc){
    for(int i=loc;i<10;i++){
        array[i-1] = array[i];
    }
    array[9] = 0;   
}

void print_arr(int arr[],int s){
    for(int i=0;i<s;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    srand(time(NULL));

    int loc = (rand()%10+1);
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr)/sizeof(int);
    printf("loc : %d\n",loc);
    delete(arr,loc);
    print_arr(arr,size);
}