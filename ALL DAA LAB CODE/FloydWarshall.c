#include<stdio.h>
#define INF 9999
int a[20][20];
void print(int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(a[i][j]<999)
				printf("%d    ",a[i][j]);
			else
				printf("INF  ");
			if(j==n-1)
				printf("\n");
		}
	}
}

void floyid_warsal(int n){
	int i,j,k;
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(a[i][j]>a[i][k]+a[k][j])
					a[i][j]=a[i][k]+a[k][j];
}

void main(){
	int n,i,j;
	printf("Enter the no of Nodes: "); scanf("%d",&n);
	printf("Enter Values:-\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j){
					a[i][j]=0;
			}
			else{
				printf("A(%d,%d)= ",i+1,j+1);
				scanf("%d",&a[i][j]);
			}
		}
	}
	printf("\nThe cost matrix of the graph:-\n");
	print(n);
	floyid_warsal(n);
	printf("\nMatrix of all pair shortest path:-\n");
	print(n);
}
