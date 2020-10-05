#include <stdio.h>

#define max 10

int a[11], b[10];

void merge(int l, int m, int h) {
   int l1, l2, i;

   for(l1 = l, l2 = m + 1, i = l; l1 <= m && l2 <= h; i++) {
      if(a[l1] <= a[l2])
         b[i] = a[l1++];
      else
         b[i] = a[l2++];
   }
   
   while(l1 <= m)    
      b[i++] = a[l1++];

   while(l2 <= h)   
      b[i++] = a[l2++];

   for(i = l; i <= h; i++)
      a[i] = b[i];
}

void m_s(int l, int h) {
   int m;
   
   if(l < h) {
      m = (l + h) / 2;
      m_s(l, m);
      m_s(m+1, h);
      merge(l, m, h);
   } else { 
      return;
   }   
}

void main(){
	int n,i;
	printf("Enter the size of the array: "); scanf("%d",&n);
	printf("Enter %d elements: ",n); 
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	m_s(0,n-1);
	printf("Array after sorting:-\n");
	for(i=0;i<n;i++)
		printf("%d ",b[i]);
	printf("\n");
}
