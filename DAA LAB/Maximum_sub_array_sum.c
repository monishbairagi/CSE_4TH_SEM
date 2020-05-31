#include<stdio.h>

int max(int a,int b,int c){ 
	if(a>b>c)
		return a;
	else if(b>c)
		return b;
	else 
		return c;
 }

int MaxSubArraySum(int a[],int l,int u){
	if(l<u){
		int m = (l+u)/2;
		int left = MaxSubArraySum(a,l,m);
		int right = MaxSubArraySum(a,m+1,u);
		int center = left + right;
		return max(left,right,center);
	}
	return a[l];
	
}

int main(){
	int i,u,a[20];
	printf("Enter total number of element:");
	scanf("%d",&u);
	printf("Enter elements: ");
	for(i=0;i<u;i++)
		scanf("%d",&a[i]);
	printf("Maximum Sub-Array Sum is %d.\n",MaxSubArraySum(a,0,u));
	return 0;
}
