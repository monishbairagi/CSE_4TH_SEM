#include<Stdio.h>

int binarySearch(int arr[], int l, int r, int x) { 
  while (l <= r) { 
    int m = l + (r-l)/2; 
    if (arr[m] == x){
    	return m;
	}  
    if (arr[m] < x){
    	l = m + 1;
	} 
    else{
    	r = m - 1;
	} 
  } 
  return -1;  
}

void main() {
   int arr[25], n, i, x, result; 
   
   printf("Enter Size of the array: ");
   scanf("%d",&n);
   
   printf("Enter array Elements: ");
   for(i=0;i<n;i++){
   		scanf("%d",&arr[i]);
   }
   
   printf("Enter element to search: ");
   scanf("%d",&x);
   
   result = binarySearch(arr, 0, n-1, x); 
   
   if (result == -1){
   		printf("Element is not present in the array.\n");
	} 
	else {
		printf("Element is present at position %d.\n", result+1);	
	} 
}
