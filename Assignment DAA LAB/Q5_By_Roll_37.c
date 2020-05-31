/*
Program: Write a program to compute y=x^n using recursion, consider x as double and y as integer
Programmer: Monish Kumar Bairagi
*/
#include<stdio.h>

double POWER(double x, int n){
    if(n == 0)
        return 1;
    else if(n > 0)
        return x * POWER(x, n - 1);
    else
        return 1 / POWER(x, -1*n);
}

void main(){
	int x,n;
	printf("Enter Number and Power: ");scanf("%d%d",&x,&n);
	printf("%d^%d = %f",x,n,POWER(x,n));
}
