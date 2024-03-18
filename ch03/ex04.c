#include <stdio.h>

// 20214935 컴퓨터 공학과 정용헌, 3장 - 04번 

void twofunc(int two[]){
 
    for(int i=0;i<10;i++){
        two[i] = 1;
        if(i==0){
                two[i] = 1;
                continue; 
        }
        for(int j=0;j<i;j++){
            two[i] *= 2;
        }
    }

}

void print_arr(int arr[],int s){
    for(int i=0;i<s;i++){
        printf("%d ",arr[i]);
    }
}
 
int main(){
    int two[10];
    int size = sizeof(two)/sizeof(int);
 
    twofunc(two);
    print_arr(two,size);
 }