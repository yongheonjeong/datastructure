#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// 20214935 컴퓨터 공학과 정용헌, 3장 - 08번 


void insert(int array[],int loc,int value){
    for(int i=9;i>loc-1;i--){
        array[i] = array[i-1]; 
    }
    array[loc-1] = value;
}

void print_arr(int arr[],int s){
    for(int i=0;i<s;i++){
        printf("%d ",arr[i]);
    }
}
void init_arr(int arr[],int s){
       for(int i=0;i<s;i++) arr[i] = i+1;
}
int main(){
    srand(time(NULL));
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr)/sizeof(int);
    char response;

    while(1){
    int loc = (rand()%10)+1;
    int value = rand()%100;
    insert(arr,loc,value);

    printf("loc : %d, value: %d\n",loc,value);
    print_arr(arr,size);
    printf("\ncontinue...? (y/n)");

    init_arr(arr,size);
    
    if( (response=getchar()) != 'y'){ 
        puts("end--");
        break;
        }
    fflush(stdin);
    }

}