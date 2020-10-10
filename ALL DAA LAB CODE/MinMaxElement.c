#include<stdio.h>

int min = 9999, max = -9999;

void findMinAndMax(int arr[], int low, int high){
	int mid;
	
	if (low == high){
		if (max < arr[low])
			max = arr[low];
		if (min > arr[high])
			min = arr[high];
		return;
	}
	if (high - low == 1){
		if (arr[low] < arr[high]){
			if (min > arr[low])	
				min = arr[low];
			if (max < arr[high])
				max = arr[high];
		}
		else{
			if (min > arr[high])	
				min = arr[high];
			if (max < arr[low])	
				max = arr[low];
		}
		return;
	}
	mid = (low + high) / 2;
	findMinAndMax(arr, low, mid);
	findMinAndMax(arr, mid + 1, high);
}

void main(){
	int arr[25], n, i;
	printf("Enter Size of the array: ");
	scanf("%d",&n);
	printf("Enter array Elements: ");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}

	findMinAndMax(arr, 0, n - 1);

	printf("The minimum element in the array is %d\n",min);
	printf("The maximum element in the array is %d\n",max);
}
