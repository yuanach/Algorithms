/*
 * sort.c
 *
 *  Created on: 2014��9��23��
 *      Author: Administrator
 */

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include"sort.h"

void
swap(int* a,int* b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void
InsertSort(int *A,const int length){
	int i,j;
	int key;
	for(i=1; i<length; i++)
		if(A[i] < A[i-1]){
			key=A[i];
			for(j=i-1; key<A[j]; --j)
				A[j+1]=A[j];
			A[j+1]=key;
		}
}

void
BinaryInsertSort(int *A,const int length){
	int i,j,low,high,mid;
	int key;
	for(i=1;i<length;i++){
		key=A[i];
		low=0;
		high=i-1;
		while(low <= high){
			mid=(low+high)/2;
			if(key < A[mid])
				high=mid-1;
			else
				low=mid+1;
		}
		for(j=i-1; j>=high+1; --j)
			A[j+1]=A[j];
		A[high+1]=key;
	}
}

void
ShellSort(int *A,const int length){
	int dk,i,j;
	int key;
	for(dk=length/2; dk>0; dk=dk/2)
		for(i=dk; i<length; ++i)
			if(A[i] < A[i-dk]){
				key=A[i];
				for(j=i-dk; j>=0 && key<A[j]; j-=dk)
					A[j+dk]=A[j];
				A[j+dk]=key;
			}//if
}

void
BubbleSort(int *A,const int length){
	int i,j,flag;
	int key;
	for(i=0; i<length-1; i++){
		flag=0;
		for(j=length-1; j>i; j--){
			if(A[j-1] > A[j]){
				swap(&A[j-1],&A[j]);
				flag=1;
			}
		}
		if(flag == 0)
			return;
	}
}


void
QuickSort(int *A,const int left,const int right){
	if(left < right){
		int pivotpos=Partition(A,left,right);
		QuickSort(A,left,pivotpos-1);
		QuickSort(A,pivotpos+1,right);
	}
}

#if !defined(_QUICK_SORT_PARTITION_TYPE_) \
	|| _QUICK_SORT_PARTITION_TYPE_ == 1

int
Partition(int *A,int left, int right){
	int pivot=A[left];
	while(left < right){
		while(left < right && A[right] > pivot) right--;
		while(left < right && A[left] < pivot) left++;
		if(left < right){
			swap(&A[left],&A[right]);
			left++;
			right--;
		}
	}
	A[left]=pivot;
	return left;
}

#endif
#if defined(_QUICK_SORT_PARTITION_TYPE_) \
	&& _QUICK_SORT_PARTITION_TYPE_ == 2

int
Partition(int *A, const int left,const int right){
	int pivot=A[right];
	int i,j;
	i=left-1;
	for(j=left; j<right; j++)
		if(A[j] <= pivot){
			i+=1;
			swap(&A[i],&A[j]);
		}
	swap(&A[i+1],&A[right]);
	return i+1;
}

#endif

void
SelectionSort(int *A,const int length){
	int i,j;
	int min;
	for(i=0; i<length-1; i++){
		min=i;
		for(j=i+1; j<length; j++)
			if(A[j] < A[min])
				min=j;
		if(min != i) swap(&A[i],&A[min]);
	}
}

void
max_heapify(Heap *H,const int i){
	int left = 2*i,
				right=2*i+1,
				largest;

		if( left < H->heap_size && H->L[left] > H->L[i])
			largest=left;
		else largest=i;
		if( right < H->heap_size && H->L[right] > H->L[largest])
			largest=right;

		if(i != largest){
			swap(&H->L[i],&H->L[largest]);
			max_heapify(H,largest);
		}
}

void
build_max_heap(Heap *H){
	int i;
	H->heap_size=H->length;
	for(i=(H->length-1)/2;i>=0;i--)
			max_heapify(H,i);
}

void
HeapSort(int *A,const int length){
	Heap *H=(Heap *)malloc(sizeof(Heap));
	H->L=A;
	H->length=length;

	int i;
	build_max_heap(H);
	for(i=H->length-1;i>0;i--){
		swap(&H->L[0],&H->L[i]);
		H->heap_size--;
		max_heapify(H,0);
	}
}

void
Merge(int *A,int *tmpArr,const int left,const int mid,const int right){
	int i,j,k;
	for(k=left; k<=right; k++)
		tmpArr[k]=A[k];
	i=left;
	j=mid+1;
	k=left;
	while(i<=mid&&j<=right)
		if(tmpArr[i] < tmpArr[j])
			A[k++]=tmpArr[i++];
		else
			A[k++]=tmpArr[j++];
	while(i <= mid)
		A[k++]=tmpArr[i++];
	while(j <= right)
		A[k++]=tmpArr[j++];
}

void
MergeSort(int *A,int *tmpArr,const int left,const int right){
	if(left < right){
		int mid=(left+right)/2;
		MergeSort(A,tmpArr,left,mid);
		MergeSort(A,tmpArr,mid+1,right);
		Merge(A,tmpArr,left,mid,right);
	}
}


int main(){

	int A[]={40,72,38,35,67,51,90,8,55,21};
	int i;


//    int *tmpArr=(int *)malloc(sizeof(A));
//	InsertSort(A,10);
//	BinaryInsertSort(A,10);
//	ShellSort(A,10);
//	BubbleSort(A,10);
	QuickSort(A,0,9);
//	SelectionSort(A,10);
//    HeapSort(A,10);
//	MergeSort(A,tmpArr,0,9);

	for(i=0;i<10;i++)
		printf("%d ",A[i]);
	printf("\n");
	return 0;
}
