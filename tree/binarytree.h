
typedef int ElemType;

typedef struct BNode{
	ElemType m_nValue;
	struct BNode *lchild;
	struct BNode *rchild;
}BinaryTreeNode,BinaryTree;

typedef struct StackNode{
	struct BNode *tree;
	struct StackNode *next;
}SNode,TreeStack;

typedef struct QueueNode{
	struct BNode *tree;
	struct QueueNode *next;
}QNode;

typedef struct{
	struct QueueNode *front;
	struct QueueNode *rear;
}TreeQueue;