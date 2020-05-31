#include<stdio.h>
// this code is written by Monish Kumar Bairagi
struct knap{
	int p,w,x;
};

void print(knap l[],int n){
	int i,j;
	printf("\n");
	for(i=0;i<n;i++)
		printf("|%d %d %d |",l[i].p,l[i].w,l[i].x);
}

int knapsack(struct knap k[],int n,int m){
	int i,j,profit; 
	struct knap t;
	print(k,n); printf(" ------>( At first the array )\n");
	
	for(i=0;i<n-1;i++){
		for(j=i;j<n;j++){
			if(float(k[i].p)/float(k[i].w) < float(k[j].p)/float(k[j].w)){
				t = k[i]; k[i] = k[j]; k[j] = t;	
			}
		}
	}
	print(k,n); printf(" ------>( After sorting the array )\n");

	for(i=0;i<n;i++){
		if(k[i].w < m){
			k[i].x = 1; m -= k[i].w;
		}
		else{
			k[i].x = 0; continue;
		}	
		profit += k[i].p*k[i].x;
	}
	print(k,n); printf(" ------>( Finally the array )\n");
	return profit;
}
// this code is written by Monish Kumar Bairagi
int main(){
	struct knap k[20];
 	int  n,m,i;
 	
 	printf("Enter Total Item: "); scanf("%d",&n);   
 	printf("Enter size of Knapsack: "); scanf("%d",&m); printf("\n");
 	
	for(i=0;i<n;i++){
		printf("Enter Price and Weight of Item-%d: ",i+1); 
		scanf("%d%d",&k[i].p,&k[i].w); k[i].x=0;
	}
		
 	printf("\nOptimal Profit will be %d.\n",knapsack(k,n,m));
 	return 0;
}
