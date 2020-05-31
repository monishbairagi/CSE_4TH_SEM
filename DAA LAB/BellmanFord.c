/*
Program  : Bellman-Ford Algorithm
Developer: Monish Kumar Bairagi
*/

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

/************************************************************************
                              -:INPUT:-                                 *
*************************************************************************
 5 8
 1 2 -1
 1 3 4
 2 3 3
 2 4 2
 2 5 2
 4 2 1
 4 3 5
 5 4 -3
 1
************************************************************************* 
                              -:OUTPUT:-                                *
*************************************************************************
 Enter Number of Vertices and Edges:  5 8                               
 Enter Starting Vertex, Ending Vertex and Weight of Edge-1:  1 2 -1     
 Enter Starting Vertex, Ending Vertex and Weight of Edge-2:  1 3 4      
 Enter Starting Vertex, Ending Vertex and Weight of Edge-3:  2 3 3      
 Enter Starting Vertex, Ending Vertex and Weight of Edge-4:  2 4 2      
 Enter Starting Vertex, Ending Vertex and Weight of Edge-5:  2 5 2      
 Enter Starting Vertex, Ending Vertex and Weight of Edge-6:  4 2 1      
 Enter Starting Vertex, Ending Vertex and Weight of Edge-7:  4 3 5      
 Enter Starting Vertex, Ending Vertex and Weight of Edge-8:  5 4 -3     
 Enter Starting Vertex:  1                                              
                                                                        
 Cost from vertex 1 to 1 is 0.                                                                       
 Cost from vertex 1 to 2 is -1.                                         
 Cost from vertex 1 to 3 is 2.                                          
 Cost from vertex 1 to 4 is -2.                                         
 Cost from vertex 1 to 5 is 1.                                          
*************************************************************************/
