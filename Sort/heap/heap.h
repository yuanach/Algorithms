/*
* 	HEAP_H
*	@Author yuanach
*	@Date	2014-08-30
*/


#define PARENT(i) int(i/2)
#define LEFT(i) 2*i
#define RIGHT(i) 2*i+1

#define HEAP_LENGTH 10

typedef struct {
	int length;
	int L[HEAP_LENGTH];
	int heap_size;
	int elem_size;
}Heap;

void max_heapify(int [],int);

/*
 * @pseudo code
 *
 *	MAX_HEAPIFY(A,i)
 *
 *	heap-size = A.length
 *	left = LEFT(i)
 *	right = RIGHT(i)
 *	if i <= heap-size and A[i] < A[left]
 *		  largest = left
 *	else largest = i
 *	if i <= heap-size and A[right] > A[largest]
 *		largest = right
 *	if i != largest
 *		exchange A[i] with A[largest]
 *		MAXHEAPIFY(A,largest)
 */
