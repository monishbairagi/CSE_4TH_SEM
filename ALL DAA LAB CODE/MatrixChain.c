#include<stdio.h>
#define MAX 10
#define INF 999

int m[MAX][MAX], s[MAX][MAX];

void matrixChain(int p[], int n){
	int i, j, l, k, q;
	for(i = 1; i <= n; i++)
		m[i][i] = 0;
	for(l = 1; l < n; l++){
		for(i = 1; i < n; i++){
			j = i + l;
			m[i][j] = INF;
			for(k = i; k < j; k++){
				q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
				if(q < m[i][j]){
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
}
void optimalParen(int i, int j){
	if(i == j)
		printf(" A%d ", i);
	else{
		printf("(");
		optimalParen(i, s[i][j]);
		optimalParen(s[i][j]+1, j);
		printf(")");
	}
}
void main(){
	int n, p[MAX], i;
	printf("Enter the number of matrices: ");
	scanf("%d", &n);
	printf("\nEnter the matrix dimensions: ");
	for(i = 0; i <= n; i++)
		scanf("%d", &p[i]);
	matrixChain(p, n);
	printf("\nMinimum number of multiplications required: %d\n", m[1][n]);
	printf("\nOptimal order of multiplications required: ");
	optimalParen(1, n);
	printf("\n");
}
