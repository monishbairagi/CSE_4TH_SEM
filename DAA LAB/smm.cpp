#include<stdio.h>

void matmul(int *A, int *B, int *R, int n) {
	if (n == 1) {
		(*R) += (*A) * (*B);
	} 
	else {
		matmul(A, B, R, n/4);
		matmul(A, B+(n/4), R+(n/4), n/4);
		matmul(A+2*(n/4), B, R+2*(n/4), n/4);
		matmul(A+2*(n/4), B+(n/4), R+3*(n/4), n/4);
		matmul(A+(n/4), B+2*(n/4), R, n/4);
		matmul(A+(n/4), B+3*(n/4), R+(n/4), n/4);
		matmul(A+3*(n/4), B+2*(n/4), R+2*(n/4), n/4);
		matmul(A+3*(n/4), B+3*(n/4), R+3*(n/4), n/4);
	}
}

void main(){
	int n,i,j,k;
	printf("Enter value of  N of NxN matrics: ");
	scanf("%d",&n);
	int a[n*n], b[n*n], c[n*n];
	for(k=0;k<2;k++){
		printf("Enter Elements of Matrix-%d:-\n",k+1);
		for(i=0;i<n*n;i++)
			if(k==0)
				scanf("%d",&a[i]);
			else
				scanf("%d",&b[i]);
	}
	matmul(a,b,c);
	printf("\nThe Resultant Matrix will be:-\n");
	for(i=0;i<n*n;i++){
		if((i+1)%n==0)
			printf("\n");
		else
			printf("%d  ",c[i]);
	}
}
