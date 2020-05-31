/*
Program: Write a C program to find the Sum of Natural Numbers Using Recursion
Programmer: Monish Kumar Bairagi
*/
#include<stdio.h>

int recursiveSum(int n){
	if(n==0)
		return n;
	else
		return n + recursiveSum(n-1);
}

void main(){
	int n;
	printf("Enter Number: "); scanf("%d",&n);
	printf("The Sum of %d Numbers is %d.\n",n,recursiveSum(n));
}
