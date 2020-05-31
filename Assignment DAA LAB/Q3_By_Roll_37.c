/*
Program: Write a C program to solve the Tower of Hanoi problem using recursion
Programmer: Monish Kumar Bairagi
*/
#include<stdio.h>

int count=0;
void towerOfHanoi(int d,char a,char b,char c){
	if(d!=1){
		towerOfHanoi(d-1,a,c,b);
		printf("Step-%d: Move Disk %d from %c to %c.\n",++count,d,a,c);
		towerOfHanoi(d-1,b,a,c);
	}
	else
		printf("Step-%d: Move Disk %d from %c to %c.\n",++count,d,a,c);
}

void main(){
	int d;
	printf("Enter Total Number of Disks: "); scanf("%d",&d);
	towerOfHanoi(d,'A','B','C');
}
