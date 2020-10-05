#include<stdio.h>
int graph[20][20]={0},visited[20]={0},n;
int q[20],r=-1,f=-1;

void NQ(int x){
	if(f==-1 || f<r){
		r=0; f=-1;
	}
	q[++f]=x;
}

int DQ(){
	if(f==-1)
		return -1;
	return q[r++];
}

void bfs(int v){
	int i;
	NQ(v);
	visited[v]=1;
	do{
		v = DQ();
		printf("%d ",v);
		for(i=1;i<=n;i++){
			if(graph[v][i]==1 && visited[i]==0){
				NQ(i);
				visited[i]=1;
			}
		}
	}	
	while( !(f<r || f==-1) );
}

void main(){
	int m,i,j,k;
	printf("Enter total no of vertices: "); scanf("%d",&n);
	printf("Enter total no of Edges: "); scanf("%d",&m);
	printf("Enter connected vertices:-\n");
	for(k=0;k<m;k++){
		printf("Enter U V: "); scanf("%d%d",&i,&j);
		graph[i][j]=1; graph[j][i]=1;
	}
	printf("Enter Starting vertex: "); scanf("%d",&k);
	printf("The BFS Solution of the Graph will be: ");
	bfs(k); printf("\n");
}
