#include <stdio.h>

int main(){
    int a[2][3];
    
    printf("a[1] : %p, a base : %p\n",a[1],a); // 12바이트 만큼 증가
    printf("a[1] : %p, a[1] + 1 : %p\n",a[1],a[1]+1); // 4바이트 만큼 증가
    
}