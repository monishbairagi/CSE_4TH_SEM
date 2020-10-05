#include<Stdio.h>

int binarySearch(int arr[], int l, int r, int x) { 
   if (r >= l) { 
        int mid = l + (r - l)/2;  
        if (arr[mid] == x)  return mid; 
        if (arr[mid] > x) return binarySearch(arr, l, mid-1, x); 
        return binarySearch(arr, mid+1, r, x); 
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
