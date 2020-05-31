#include<stdio.h>

void print(int r,int c,int res[][10]){
	int i,j;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			printf("%d ",res[i][j]);
		}
		printf("\n");
	}
}

void boolMul(int r1,int c1,int m1[][10],int r2,int c2,int m2[][10]){
	int res[10][10],i,j,k;
	for(i=0;i<r1;i++){
		for(j=0;j<c1;j++){
			for(k=0;k<c1;k++){
				if(m1[i][k]==1 && m2[k][j]==1){
					res[i][j]=1;
					break;
				}
				else{
					res[i][j]=0;
			 	}
			}
		}
	}
	printf("The Resultant Matrix is:-\n");
	print(r1,c2,res);
}

int main(){
	int m1[10][10],m2[10][10];
	int r1,c1,r2,c2,i,j;
	
	printf("Enter Total Number of Row and Column of Matrix-1: ");
	scanf("%d%d",&r1,&c1);
	printf("Enter The Boolean Matrix-1:-\n");
	for(i=0;i<r1;i++){
		for(j=0;j<c1;j++){
			scanf("%d",&m1[i][j]);
		}
	}
	
	printf("Enter Total Number of Row and Column of Matrix-2: ");
	scanf("%d%d",&r2,&c2);
	printf("Enter The Boolean Matrix-2:-\n");
	for(i=0;i<r2;i++){
		for(j=0;j<c2;j++){
			scanf("%d",&m2[i][j]);
		}
	}
	boolMul(r1,c1,m1,r2,c2,m2);
}
