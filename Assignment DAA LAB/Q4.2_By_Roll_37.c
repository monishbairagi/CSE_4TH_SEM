/*
Program: Write a recursive function to reverse the words in a string
Programmer: Monish Kumar Bairagi
*/
#include<stdio.h>
#include<string.h>
void reverseSentence(char* start, char* begin ,char* end,int n){
	char t, *e; int i;
    if(*end=='\0'){
        e=end-1;
        while (begin < e) { 
        	t = *begin; *begin++ = *e; *e-- = t; 
    	}
    	for(i=n-1;i>=0;i--)printf("%c",start[i]);
        return;
    }
    if(*end==' '){
        e = end-1;
        while (begin < e) { 
        	t = *begin; *begin++ = *e; *e-- = t; 
    	}
        begin = end+1;
    }
    reverseSentence(start,begin,end+1,n);
}
  
void main() 
{ 
    char s[50]; gets(s); 
    reverseSentence(s,s,s,strlen(s));  
} 
