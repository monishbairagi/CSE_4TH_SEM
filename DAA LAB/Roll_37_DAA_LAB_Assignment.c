#include<stdio.h>

int x[10];  
int max(int,int);
int Knapsack(int,int[],int[],int); 
void NumToWord(int);
void PrintInWord(int[],int); 
  
void main(){	
	int n,m,w[10],v[10],i;
	printf("Number of items, n=");
	scanf("%d",&n);
	
	printf("\nWeight of items, w[]="); 
	for(i=0;i<n;i++){
		scanf("%d",&w[i]);	
	}
	
	printf("Value of items, v[]=");
	for(i=0;i<n;i++){
		scanf("%d",&v[i]);	
	}
	
	printf("\nCapacity of knapsack, M=");
	scanf("%d",&m);
	
	printf("\nMaximum attainable value of items=%d\n",Knapsack(n,w,v,m));
	printf("by collecting "); PrintInWord(x,n); printf(" item in the knapsack\n");
}

int max(int a, int b) { return (a > b)? a : b; }
 
int Knapsack(int n, int w[],int v[],int m){
   int i, j;
   int k[n+1][m+1];
   for (i = 0; i <= n; i++){
       for (j = 0; j <= m; j++){
           if (i==0 || j==0)
               k[i][j] = 0;
           else if (w[i-1] <= j)
                 k[i][j] = max(v[i-1] + k[i-1][j-w[i-1]],  k[i-1][j]);
           else
                 k[i][j] = k[i-1][j];
       }
   }
	i=n; j=m;
   	while(i>0&&j>0){
   		if(k[i][j]==k[i-1][j])
   			x[i-1]=0;
   		else{
   			x[i-1]=1; j-=w[i-1];
   		}
   	i--;
   }
   return k[n][m];
}
//this code is written by Monish Kumar Bairagi
void NumToWord(int i){
	switch(i){
		case 1: printf("first"); break;
		case 2: printf("second"); break;
		case 3: printf("third"); break;
		case 4: printf("fourth"); break;
		case 5: printf("fifth"); break;
		case 6: printf("sixth"); break;
		case 7: printf("seventh"); break;
		case 8: printf("eighth"); break;
		case 9: printf("ninth"); break;
		default:break;
	}
}
void PrintInWord(int x[],int n){
	int i,j,m=0;
	for(i=0;i<n;i++){ if(x[i]==1) m++; }
	if(m>1){
		for(i=0;i<n;i++){
			if(x[i]==1 && m>2){
				NumToWord(i+1);
				printf(", "); 
				m--;
			}
			else if(x[i]==1){
				if(m==2){
					NumToWord(i+1);
					printf(" and ");
					m--;
				}
				else{
					NumToWord(i+1); 
					m--;
					break;
				}
			}
		}
	}
	else{
		for(i=0;i<n;i++){
			if(x[i]==1)
				NumToWord(i+1);
		}
	}
}
