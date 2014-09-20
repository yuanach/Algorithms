
typedef int ElemType;

/*
 * 	Binary tree node struct
 */
typedef struct BNode{
	ElemType m_nValue;
	struct BNode *lchild;
	struct BNode *rchild;
}BinaryTreeNode,BinaryTree;

/*
 * 	Thread Binary tree struct
 */
typedef struct ThreadNode{
	ElemType m_nValue;
	struct ThreadNode *lchild;
	struct ThreadNode *rchild;
	int ltag,rtag;
}ThreadTreeNode,ThreadTree;

/*
 * 	Stack node struct for Binary tree
 */
typedef struct StackNode{
	struct BNode *tree;
	struct StackNode *next;
}SNode,TreeStack;

/*
 * Queue node struct for binary tree
 */
typedef struct QueueNode{
	struct BNode *tree;
	struct QueueNode *next;
}QNode;

/*
 * Queue for Binary tree
 */
typedef struct{
	struct QueueNode *front;
	struct QueueNode *rear;
}TreeQueue;

typedef struct BNode BSTNode;

void // initiate treestack
init_stack(TreeStack **ts);

int
stackEmpty(const TreeStack *ts);

void //push
push(TreeStack **ts,BinaryTreeNode *p);

void //pop
pop(TreeStack **ts,BinaryTreeNode **p);

int //get top treenode
GetTop(const TreeStack *T,BinaryTreeNode **p);

void //initiate treequeue
init_queue(TreeQueue **tq);

int
queueEmpty(const TreeQueue *tq);

void //in
enQueue(TreeQueue **tq,BinaryTreeNode *p);

void //out
deQueue(TreeQueue **tq,BinaryTreeNode **p);

int
CreateBinaryTree(BinaryTree **T);

void
visit(const BinaryTree *T);

void
PreOrder(BinaryTree *T);

void
InOrder(BinaryTree *T);

void
PostOrder(BinaryTree *T);

void //non-recursive traversing
PreOrderTraverse(BinaryTree *T);

void
InOrderTraverse1(BinaryTree *T);

void
InOrderTraverse2(BinaryTree *T);

void
PostOrderTraverse(BinaryTree *T);

void
LevelOrderTraverse(BinaryTree *T);

/***************************Thread BinaryTree***********************************/
void
CreateInThread(ThreadTree *T);

void
InThread(ThreadTree *p,ThreadTreeNode *pre);


/**************BST************************************************/
BSTNode
*bst_search(BinaryTree *T,const int key,BSTNode *p);

int
bst_insert(BinaryTree **T,const int value);

void
create_bst(BinaryTree **T,const int *A,const int n);

