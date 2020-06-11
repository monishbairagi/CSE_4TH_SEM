/*
Program: Write a C program to solve single source shortest path problem using Dijkstra’s Algorithm
Programmer: Monish Kumar Bairagi
*/
#include<stdio.h>
#define INF 999

int d[20];
int Q[20],f=-1,r=-1;

void Qinsert(int x){
	if(f==-1 || f<r){
		r=0; f=-1;
	}
	Q[++f]=x;
}

void Qremove(int x){
	int i,j;
	for(i=r;i<=f;i++){
		if(Q[i]==x)
			break;
	}
	for(j=i;j<=f;j++){
		Q[j]=Q[j+1];
	}
	f--;
}

int isQempty(void){
	if(f==-1 || f<r)
		return 1;
	return 0;	
}

int isPresentInQ(int x){
	int i;
	for(i=r;i<=f;i++){
		if(Q[i]==x)
			return 1;
	}
	return 0;
}

int* Dijkstra(int s,int v,int G[][20]){
	int i,j,k,min;
	d[s]=0;
	for(i=0;i<v;i++){
		if(i!=s)
			d[i]=999;
		Qinsert(i);
	}
	
	while(!isQempty()){
		min=INF;
		for(i=0;i<v;i++){
			if(min>d[i] && isPresentInQ(i)){
				min=d[i];
				k=i;
			}
		}
		
		Qremove(k);
		
		for(i=0;i<v;i++){
			if(G[k][i]!=0){
				if(d[k]+G[k][i] < d[i]){
					d[i] = d[k]+G[k][i];
				}
			}
		}
	}
	return d;
}

void main(){
	int i,j,v,e,m,n,c,s,G[20][20];
	int *d;
	
	printf("Enter Total Number of Vertices and Edges: "); scanf("%d%d",&v,&e);
	
	for(i=0;i<v;i++){
		for(j=0;j<v;j++){
			G[i][j]=0;
		}
	}
	
	for(i=0;i<e;i++){
		printf("Edge-%d: Starting Vertex, Ending Vertex and Cost: ",i+1);
		scanf("%d%d%d",&m,&n,&c); G[m-1][n-1]=c;
	}
	
	printf("Enter Starting Vertex: "); scanf("%d",&s);
	
	d = Dijkstra(s-1,v,G);
	
	for(i=0;i<v;i++){
		if(i+1!=s && d[i]!=INF)
			printf("\nMinimum Cost From %d to %d is %d.\n",s,i+1,d[i]);
	}
	printf("\n");
}
