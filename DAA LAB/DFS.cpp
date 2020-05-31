#include<stdio.h>
int graph[20][20]={0},visited[20]={0},n;
//this code is written by Monish Kumar Bairagi
void dfs(int v){
	int i;
	visited[v]=1;
	printf("%d ",v);
	for(i=1;i<=n;i++){
		if(graph[v][i]==1 && visited[i]==0){
			dfs(i);
		}
	}
}
//this code is written by Monish Kumar Bairagi
int main()
{
	int m,i,j,k;
	printf("Enter total no of vertices: "); scanf("%d",&n);
	printf("Enter total no of Edges: "); scanf("%d",&m);
	printf("Enter connected vertices:-\n");
	for(k=0;k<m;k++){
		printf("Enter U V: "); scanf("%d%d",&i,&j);
		graph[i][j]=1; graph[j][i]=1;
	}
	printf("Enter Starting vertex: "); scanf("%d",&k);
	printf("The DFS Solution of the Graph will be: ");
	dfs(k); printf("\n");
	return 0;
}
