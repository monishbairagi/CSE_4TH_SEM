#include<stdio.h>
main()
{
	int a[10][10],v,e,i,j,k=0,min,vis[10]={0},m,n,c=0;
	printf("Enter the no of vertex: ");
	scanf("%d",&v);
	printf("The no of edges: ");
	scanf("%d",&e);
	for(i=1;i<=v;i++)
	{
		for(j=1;j<=v;j++)
		a[i][j]=99;
	}
	for(i=1;i<=e;i++)
	{
		printf("Enter u,v & w: ");
		scanf("%d%d%d",&m,&n,&min);
		a[m][n]=a[n][m]=min;
	}
	printf("\n");
	for(i=1;i<=v;i++)
	{
		for(j=1;j<=v;j++){
			if(a[i][j]==99) printf("~  ");
			else printf("%d  ",a[i][j]);	
		}
		
		printf("\n");
	}
	printf("\nPath:-\n");
	vis[1]=1;
	while(k<v-1)
	{
		min=99;
		for(i=1;i<=v;i++)
		{
			for(j=1;j<=v;j++)
			{
				if(a[i][j]<min&&vis[i]==1&&vis[j]==0)
				{
					min=a[i][j];
					m=i;n=j;
				}
			}
		}
		printf("%d %d\n",m,n);
		vis[n]=1;
		c+=min;
		k++;
	}
	printf("\nCost is %d.",c);
}
