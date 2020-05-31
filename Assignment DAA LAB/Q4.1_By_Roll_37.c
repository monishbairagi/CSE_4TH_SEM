/*
Program: Write a recursive function to reverse a string
Programmer: Monish Kumar Bairagi
*/
#include<stdio.h>

void revStr(char *k){
	if(*k!='\0'){
		revStr(k+1);
		printf("%c",*k);
	}
}

void main(){
	char str[10];
	printf("Enter a String: "); gets(str);
	printf("Reverse of the String is: "); revStr(str);
	printf("\n");
}
