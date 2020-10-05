#include<stdio.h>
int a[20];

void print(int l,int u){
	int i;
	for(i=l;i<u;i++)printf("%d ",a[i]);
	printf("\n");
}

int partition(int l,int u){ 
	int x,i,j,t; x=a[u]; i=l-1;
  	for(j=l;j<u;j++)
  	{
  		if(a[j]<=x)
  		{
  			i++;
  			t=a[i]; a[i]=a[j]; a[j]=t;
		}
  	}
  	t=a[i+1]; a[i+1]=a[u]; a[u]=t;
  	return i+1;
}

int quick_sort(int l,int u){
	int q;
	if(l<u)
	{
		q=partition(l,u);
		quick_sort(l,q-1);
		quick_sort(q+1,u);
	}
}

void main(){
	int n,i;
	printf("Enter the size of the array: "); scanf("%d",&n);
	printf("Enter %d elements: ",n); for(i=0;i<n;i++)scanf("%d",&a[i]);
	quick_sort(0,n-1);
	printf("Array after sorting:-\n");
	print(0,n);
}
