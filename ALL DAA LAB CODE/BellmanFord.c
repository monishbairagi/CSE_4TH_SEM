#include<stdio.h>
#define INF 999

int d[20];

int bellmanFord(int G[][20],int v,int e,int s){
	int i,j,k;
	for(i=1;i<=v;i++)
		d[i]=INF;
	d[s]=0;
	
	for(i=1;i<=v-1;i++){
		for(j=1;j<=v;j++){
			for(k=1;k<=v;k++){
				if(d[j]+G[j][k]<d[k] && G[j][k]!=INF && G[j][k]!=0){
					d[k] = d[j]+G[j][k];
				}
			}
		}
	}
	for(j=1;j<=v;j++){
			for(k=1;k<=v;k++){
				if(d[j]+G[j][k]<d[k] && G[j][k]!=INF && G[j][k]!=0){
					return 0;
				}
			}
		}
	return 1;
}

void main(){
	int i,j,k,s,v,e,G[20][20];
	printf("Enter Number of Vertices and Edges: ");
	scanf("%d%d",&v,&e);
	
	for(i=1;i<=v;i++){
		for(j=1;j<=v;j++){
			if(i==j)
				G[i][j]=0;
			else
				G[i][j]=INF;
		}
	}
	
	for(i=0;i<e;i++){
		printf("Enter Starting Vertex, Ending Vertex and Weight of Edge-%d: ",i+1);
		scanf("%d%d%d",&j,&k,&s); G[j][k]=s;
	}
	printf("Enter Starting Vertex: "); scanf("%d",&s); printf("\n");
	if(bellmanFord(G,v,e,s)){
		for(i=1;i<=v;i++){
				printf("Cost from vertex %d to %d is %d.\n",s,i,d[i]);
		}
	}
	else
		printf("\nNegative Cost Cycle present.\n");
}
