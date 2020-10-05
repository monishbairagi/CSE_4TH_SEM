#include<stdio.h>

int m, n, c=0, g[25][25], x[25],count=0;

void NextValue(int k){
 	int j;
 	while(1){
  		x[k]=(x[k]+1)%(m+1);
  		if(x[k]==0)
   			return;
  		for(j=1;j<=n;j++){
   			if(g[k][j]==1&&x[k]==x[j])
    				break;
  		}
  		if(j==(n+1))
   			return;
 	}
}

void mcoloring(int k){
	int i;
 	while(1){
  		NextValue(k);
  		if(x[k]==0)
   			return;
 		if(k==n){
  			c=1;
  			for(i=1;i<=n;i++){
   				printf("%d ", x[i]);
  			}
  			count++;
  			printf("\n");
 		}
 		else
  			mcoloring(k+1);
 	}
}

void main(){
	int i, u, v, e;
 	printf("Enter the number of Vertices and Edges: " );
 	scanf("%d%d", &n,&e);
    	printf("\n");

	for(u=0;u<n;u++)
		for(v=0;v<n;v++)
			g[u][v]=0;			

	for(i=1;i<=e;i++){
    		printf("Enter Vertices of Edge-%d: ",i);
    		scanf("%d%d",&u,&v);
    		g[u][v]=1; g[v][u]=1;
 	}

	printf("\nThe Solutions are:-\n");
 	for(m=1;m<=n;m++){
  		if(c==1)
   			break;
  		mcoloring(1);
 	}

	printf("\nThe Total Number of Solution is %d.\n",count);
	printf("The Chromatic Number is %d.\n", m-1);
}


/*

--------------------------OUTPUT-------------------------


Enter the number of Vertices and Edges: 6 8

Enter Vertices of Edge-1: 1 2
Enter Vertices of Edge-2: 2 3
Enter Vertices of Edge-3: 3 4
Enter Vertices of Edge-4: 4 5
Enter Vertices of Edge-5: 5 6
Enter Vertices of Edge-6: 6 1
Enter Vertices of Edge-7: 2 6
Enter Vertices of Edge-8: 3 5

The Solutions are:-
1 2 1 3 2 3
1 2 3 1 2 3
1 2 3 2 1 3
1 3 1 2 3 2
1 3 2 1 3 2
1 3 2 3 1 2
2 1 2 3 1 3
2 1 3 1 2 3
2 1 3 2 1 3
2 3 1 2 3 1
2 3 1 3 2 1
2 3 2 1 3 1
3 1 2 1 3 2
3 1 2 3 1 2
3 1 3 2 1 2
3 2 1 2 3 1
3 2 1 3 2 1
3 2 3 1 2 1

The Total Number of Solution is 18,
The Chromatic Number is 3.



*/
