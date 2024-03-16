#include <stdio.h>

/*
 // 07
int sum(int n)
{
    printf("%d\n",n);
    if(n<1) return 1;
    else return ( n+sum(n-1));
}
*/

// 08
/*
int recursive(int n)
{
    printf("%d\n",n);
    if(n<1) return 2;
    else return(2*recursive(n-1)+1);
}
*/

/*
09
int recursive(int n)
{
    printf("%d\n",n);
    if(n<1) return -1;
    else return (recursive(n-3)+1);
}
*/


/*
int recursive(int n)
{
    if(n != 1) recursive(n-1);
    printf("%d\n",n);
}
*/

/*
void asterisk(int i)
{
    printf("%d",i);
    if(i>1){
        asterisk(i/2);
        asterisk(i/2);
    }
    printf("*");
}
*/


/*
void unknown()
{
    int ch;
    if((ch=getchar()) != '\n')
        unknown();
    putchar(ch);
}
*/

int Ackermann(int m,int n){

    if(m==0 && n>=1) return n+1;
    else if(n==0 && m>=1) return Ackermann(m-1,1);
    else return Ackermann(m-1,Ackermann(m,n-1));
     
}
 
int main(){
   // printf("sum : %d",sum(5));
   //printf("recursive(5) : %d",recursive(5));
   //printf("recursive(10) : %d",recursive(10));
   //recursive(5);
   //asterisk(5);
   //unknown();
   printf("%d",Ackermann(3,2));
   printf("%d",Ackermann(2,3));
}