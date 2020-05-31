/*
Program: Strassens Matrix Multiplication
Programmer: Monish Kumar Bairagi
*/
#include<stdio.h>
#include<malloc.h>

int R[4][4];

void matmul(int A[][2], int B[][2]) {
	int a,b,c,d,e,f,g;
	
	a = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
	b = (A[1][0] + A[1][1]) * B[0][0];
	c = A[0][0] * (B[0][1] - B[1][1]);
	d = A[1][1] * (B[1][0] - B[0][0]);
	e = (A[0][0] + A[0][1]) * B[1][1];
	f = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);
	g = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);
	
	R[0][0]=a+d-e+g;
	R[0][1]=c+e;
	R[1][0]=b+d;
	R[1][1]=a-b+c+f;
	
}

void main(){
	int n,i,j,k;
	printf("Enter value of  N of NxN matrics: ");
	scanf("%d",&n);
	int a[n][n], b[n][n];
	for(k=0;k<2;k++){
		printf("\nEnter Elements of Matrix-%d:-\n",k+1);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(k==0)
					scanf("%d",&a[i][j]);
				else
					scanf("%d",&b[i][j]);
	}
	matmul(a,b);
	printf("\nThe Resultant Matrix will be:-\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%d  ",R[i][j]);
		printf("\n");
	}
}
