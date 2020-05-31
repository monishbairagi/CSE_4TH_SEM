#include<stdio.h>
// this code is written by Monish Kumar Bairagi
struct knap{
	int p,w;
	float r,x;
};

void print(knap l[],int n){
	int i,j;
	printf("\n");
	for(i=0;i<n;i++)
		printf("|%d %d %.2f %.2f |",l[i].p,l[i].w,l[i].r,l[i].x);
}

float knapsack(int n,int m){
	int i,j; float profit = 0.0; knap k[10],t;

	for(i=0;i<n;i++){
		printf("Enter Pricr and Weight of Item-%d: ",i+1); 
		scanf("%d%d",&k[i].p,&k[i].w);
		k[i].r = float(k[i].p)/float(k[i].w);
		}
	
	print(k,n); printf(" ------>( At first the array look like )\n");
	
	for(i=0;i<n-1;i++)
		for(j=i;j<n;j++){
			if(k[i].r < k[j].r ){
				t = k[i]; k[i] = k[j]; k[j] = t;	
			}
		}
	
	print(k,n); printf(" ------>( After sorting the array w.r.t R )\n");

	for(i=0;i<n;i++){
		if(k[i].w < m){
			k[i].x = 1;
			m -= k[i].w;
			}
		else{
			k[i].x = float(m)/float(k[i].w);
			m = 0;
			
			}	
		profit += float(k[i].p)*k[i].x;
		}
		
	print(k,n); printf(" ------>( Finally the array look like )\n");
	
	return profit;
}
// this code is written by Monish Kumar Bairagi
int main()
{
 int  n,m;
 printf("Enter Total Item: "); scanf("%d",&n);   
 printf("Enter size of Knapsack: "); scanf("%d",&m); printf("\n");
 printf("\nMaximum Profit will be %.2f.\n",knapsack(n,m));
 return 0;
}
