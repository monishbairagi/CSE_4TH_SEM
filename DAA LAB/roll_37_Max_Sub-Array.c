#include <stdio.h>

int max(int a, int b, int c){ return (a>b>c)?a:(b>c)?b:c; }

int maxCrossing(int a[], int l, int m, int u){
  int i,l_s = -1000000,r_s = -1000000,s = 0;
  for (i=m; i>=l; i--){
    s = s+a[i];
    if (s>l_s)
      l_s = s;
  }
  s = 0;
  for (i=m+1; i<=u; i++){
    s=s+a[i];
    if (s>r_s)
      r_s = s;
  }
  return (l_s+r_s);
}

int maxSubarray(int a[], int l, int u){
  int m,left,right,cross;
  if (u == l) 
    return a[u];
  m = (u+l)/2;
  left = maxSubarray(a, l, m);
  right = maxSubarray(a, m+1, u);
  cross = maxCrossing(a, l, m, u);
  return max(left, right, cross);
}

void main(){
  int i,n,a[20];
  printf("Enter total elements: "); scanf("%d",&n);
  printf("Enter elements: "); for(i=0;i<n;i++)scanf("%d",&a[i]);
  printf("The maximum sub-array sum is %d.\n", maxSubarray(a, 0, n-1));
}

