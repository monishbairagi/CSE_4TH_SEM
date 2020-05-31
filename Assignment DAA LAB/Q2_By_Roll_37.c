/*
Program: Given a weighing pan, n weights and a destination weight D, 
  		 print “YES” or “NO” depending whether you can weight D using
		 other weights given.
Programmer: Monish Kumar Bairagi
*/
#include <stdio.h> 
int weight(int n,int w[],int D){
	int i, j, s=0;
	for(i=0;i<n;i++)s+=w[i];
	
	if(D==s){ return 1;}
	
	for(i=0;i<n;i++){
		if(w[i]==D){
			return 1;
		}
	}
	
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(D+w[i]==w[j]){
				return 1;
			}
		}
	}
	
	for(i=0;i<n;i++){
		s=0;
		for(j=0;j<i;j++)s+=w[j];
		for(j=i+1;j<n;j++)s+=w[j];
		if(D+w[i]==s){
			return 1;
		}
	}
	return 0;
}
 
void main() { 
	int n, w[10], D, i;
	printf("INPUT: "); scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&w[i]); scanf("%d",&D);
	if(weight(n,w,D))
		printf("OUTPUT: YES\n");
	else
		printf("OUTPUT: NO\n");
} 

