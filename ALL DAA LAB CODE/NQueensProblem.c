#include<stdio.h>
#include<math.h>
       
int x[20],c=1;

void printBoard(int n){
 int i,j;
 printf("\nSolution %d:",c++);
 for(i=1;i<=n;i++){
  	printf("\n");
  	for(j=1;j<=n;j++){
   		if(x[i]==j) printf(" Q ");
   		else printf(" - ");
  		}
  	printf("\n");
 	}
 printf("\n");
}

int place(int k,int i){
 int j;
 for(j=1;j<k;j++)
	  if((x[j]==i)||(abs(x[j]-i)==abs(j-k)))
	  		return 0;
 return 1;
}

void NQueen(int k,int n){
 int i;
 for(i=1;i<=n;i++){
  	if(place(k,i)){
   		x[k]=i;
   		if(k==n)
		   printBoard(n); 
   		else
		   NQueen(k+1,n);
  		}
 	}
}
 
void main(){
 int n,i,j;
 printf("Enter number of Queens:");
 scanf("%d",&n);
 NQueen(1,n);
}
