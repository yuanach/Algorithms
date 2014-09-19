//Iteration
## iter_InsertSort(A)
for i=2 to A.length
	key=A[i]
	j=i-1
	while j>0 and A[j]>key
		A[j+1]=A[j]
		j=j-1
	A[j+1]=key
	
//recursion
## rec_InsertSort(A)
for i=2 to A.length
	Insert(A,i)

## Insert(A,p)
j=p-1
if j>1 and A[j]>=key
	Insert(A,j)
else
	A[j+1]=A[j]
	A[j]=k;

//Binary
##bin_InsertSort(A)
for i=2 to A.length
	key=A[i]
	low=1
	high=i-1
	while high >= low 
		mid=(low+high)/2
		if key < A[mid]
			high=mid-1
		else
			low=mid+1
	for j=i-1 downto high+1
		A[j+1]=A[j]
	A[high+1]=key













		