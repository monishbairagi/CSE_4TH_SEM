/*
Program: Write a C program to sort a sequence of elements using Heap Sort method
Programmer: Monish Kumar Bairagi
*/
#include<stdio.h>

void maxHeapify(int* a, int size, int i) {
        int t, largest = i, left  = (2*i)+1, right  = (2*i)+2;

        if (left<size && *(a+left) > *(a+largest)){
        	largest = left;	
		}

        if (right  < size && *(a+right) > *(a+largest)){
        	largest = right;	
		}

        if (largest != i) {
            t = *(a+i); *(a+i) = *(a+largest); *(a+largest) = t;
            maxHeapify(a, size, largest);
        }
    }

 void heapSort(int* a, int n) {
 	int i,t;
 	
    for (i = n/2 - 1; i >= 0; i--){
    	maxHeapify(a, n, i);	
	}
	
    for (i = n - 1; i >= 0; i--) {
      t = *a; *a = *(a+i); *(a+i) = t;
      maxHeapify(a, i, 0);
    }
  }

void main(){
	int size,i,array[20];
	
	printf("Enter size of the array: "); scanf("%d",&size);
	printf("Enter array elements: ");
	for(i=0;i<size;i++)
		scanf("%d",&array[i]);
		
	heapSort(array,size);
	
	printf("\nArray after sorting: ");
	for(i=0;i<size;i++){
		printf("%d ",array[i]);
	}
	printf("\n");
}
