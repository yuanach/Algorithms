#include"heap.h"

void
swap(int* a,int* b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void
max_heapify(Heap *A,int i){
	int left = 2*i,
			right=2*i+1,
			largest;

	if( left < A->heap_size && A->L[left] > A->L[i])
		largest=left;
	else largest=i;
	if( right < A->heap_size && A->L[right] > A->L[largest])
		largest=right;

	if(i != largest){
		swap(&A->L[i],&A->L[largest]);
		max_heapify(A,largest);
	}
}

void
build_max_heap(Heap *A){
	int i;
	A->heap_size=A->length;
	for(i=(A->length-1)/2;i>=0;i--)
			max_heapify(A,i);
}

void
heap_sort(Heap *A){
	int i;
	build_max_heap(A);
	for(i=A->length-1;i>0;i--){
		swap(&A->L[0],&A->L[i]);
		A->heap_size--;
		max_heapify(A,0);
	}
}
