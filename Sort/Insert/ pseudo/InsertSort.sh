//Iteration
## iter_InsertSort()
for i=2 to A.length
	key=A[i]
	j=i-1
	while j>0 and A[j]>key
		A[j+1]=A[j]
		j=j-1
	A[j+1]=key
	
//recursion
## rec_InsertSort()
for i=2 to A.length
	Insert(A,i)

## Insert(A,p)
j=p-1
if j>1 and A[j]>=key
	Insert(A,j)
else
	A[j+1]=A[j]
	A[j]=k;

		