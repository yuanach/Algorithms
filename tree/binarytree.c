#include<stdio.h>
#include<malloc.h>
#include"binarytree.h"

void // initiate treestack
init_stack(TreeStack **ts){
	*ts=(TreeStack *)malloc(sizeof(struct StackNode));
	(*ts)->next=NULL;
	(*ts)->tree=NULL;
}

int 
stackEmpty(TreeStack *ts){
	if(ts == NULL || 
		(ts->tree == NULL && ts->next == NULL))
		return 1;
	else
		return 0;
}

void //push
push(TreeStack **ts,BinaryTreeNode *p){
	struct StackNode *pNew;
	pNew=(SNode *)malloc(sizeof(SNode));
	pNew->tree=p;
	pNew->next=*ts;
	*ts=pNew;
}

void //pop
pop(TreeStack **ts,BinaryTreeNode **p){
	if(*ts == NULL)
		return;
	
	struct StackNode *d;
	*p=(*ts)->tree;
	d=*ts;
	
	*ts=(*ts)->next;
	if(*ts == NULL) 
		init_stack(ts);

	free(d);
}

int //get top treenode
GetTop(TreeStack *T,BinaryTreeNode **p){
	if(!stackEmpty(T))
		*p=T->tree;
	else{
		*p=NULL;
		return 0;
	}
	return 1;
}

void //initiate treequeue
init_queue(TreeQueue **tq){
	*tq=(TreeQueue*)malloc(sizeof(TreeQueue));
	(*tq)->front=NULL;
	(*tq)->rear=NULL;
}

int
queueEmpty(TreeQueue *tq){
	if(tq == NULL || 
		(tq->front == NULL && tq->rear == NULL))
		return 1;
	else 
		return 0;
}

void //in
enQueue(TreeQueue **tq,BinaryTreeNode *p){
	if(tq == NULL) return;
	QNode *qn=(QNode*)malloc(sizeof(struct QueueNode));
	qn->tree=p;
	qn->next=NULL;

	if(queueEmpty(*tq)){ // TreeQueue is empty
		(*tq)->rear=qn;
		(*tq)->front=(*tq)->rear;
	}
	else{
		(*tq)->rear->next=qn;
		(*tq)->rear=qn;
	}
}

void //out
deQueue(TreeQueue **tq,BinaryTreeNode **p){
	if(queueEmpty(*tq))
		return;
	struct QueueNode *d;
	
	*p=(*tq)->front->tree;
	d=(*tq)->front;
	(*tq)->front=(*tq)->front->next;
	
	if((*tq)->front == NULL) // set TreeQueue empty
		(*tq)->rear=NULL;
		
	free(d);
}

int
CreateBinaryTree(BinaryTree **T){
	ElemType value;
	scanf("%d",&value);
	if(value == -1)
		*T=NULL;
	else{
		*T=(BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
		if(*T == NULL) return 0;
		(*T)->m_nValue=value;
		CreateBinaryTree(&((*T)->lchild));
		CreateBinaryTree(&((*T)->rchild));
	}	
	return 1;
}

void
visit(BinaryTree *T){
	printf("%x",T->m_nValue);
}

void
PreOrder(BinaryTree *T){
	if(T != NULL){
		visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

void
InOrder(BinaryTree *T){
	if(T != NULL){
		InOrder(T->lchild);
		visit(T);
		InOrder(T->rchild);
	}
}

void
PostOrder(BinaryTree *T){
	if(T != NULL){
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		visit(T);
	}
}

void //non-recursive traversing
PreOrderTraverse(BinaryTree *T){
	TreeStack *ts;
	BinaryTreeNode *p;
	init_stack(&ts);
	p=T;
	while(p!=NULL || !stackEmpty(ts)){
		while(p!=NULL){
			visit(p);
			push(&ts,p);
			p=p->lchild;
		}
		if(!stackEmpty(ts)){
			pop(&ts,&p);
			p=p->rchild;	
		}
	}
}

void 
InOrderTraverse1(BinaryTree *T){
	TreeStack *ts;
	BinaryTreeNode *p;
	init_stack(&ts);
	push(&ts,T);
	while(!stackEmpty(ts)){
		while(GetTop(ts,&p) && p != NULL)
			push(&ts,p->lchild);
		pop(&ts,&p);
		if(!stackEmpty(ts)){
			pop(&ts,&p);
			visit(p);
			push(&ts,p->rchild);
		}
	}
}

void 
InOrderTraverse2(BinaryTree *T){
	TreeStack *ts;
	BinaryTreeNode *p;
	init_stack(&ts);
	p=T;
	while(p != NULL || !stackEmpty(ts)){
		if(p != NULL) {
			push(&ts,p);
			p=p->lchild;
		}else{
			pop(&ts,&p);
			visit(p);
			p=p->rchild;
		}
	}
}

void 
PostOrderTraverse(BinaryTree *T){
	TreeStack *ts;
	BinaryTreeNode *p,*r;
	init_stack(&ts);
	p=T;
	r=NULL;
	while(p != NULL || !stackEmpty(ts)){
		if(p != NULL){
			push(&ts,p);
			p=p->lchild;
		}
		else{
			GetTop(ts,&p);
			if(p->rchild != NULL 
				&& p->rchild != r){
				p=p->rchild;
				push(&ts,p);
				p=p->lchild;
			}
			else{
				pop(&ts,&p);
				visit(p);
				r=p;
				p=NULL;
			}//else
		}//else
	}//while
}

void 
LevelOrderTraverse(BinaryTree *T){
	BinaryTreeNode *p;
	TreeQueue *tq;
	init_queue(&tq);
	
	enQueue(&tq,T);
	while(!queueEmpty(tq)){
		deQueue(&tq,&p);
		visit(p);
		if(p->lchild != NULL)
			enQueue(&tq,p->lchild);
		if(p->rchild != NULL)
			enQueue(&tq,p->rchild);
	}
}

int main(){
	BinaryTree *t;
	BinaryTreeNode *p;
	CreateBinaryTree(&t);
/*
	t=(BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	t2=(BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	t3=(BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	t->lchild=t2;
	t->rchild=t3;
	t->m_nValue=0xff;
	t2->lchild=NULL;t2->rchild=NULL;
	t3->lchild=NULL;t3->rchild=NULL;
	t2->m_nValue=0xee; t3->m_nValue=0xdd;
/*
	TreeStack *ts;
	init_stack(&ts);
	push(&ts,t);push(&ts,t2);push(&ts,t3);
	while(!stackEmpty(ts)){
		pop(&ts,&p);
		printf("%x\n",p->m_nValue);	
	}
*/
/*
	TreeQueue *tq;
	
	init_queue(&tq);
	enQueue(&tq,t);enQueue(&tq,t->lchild);enQueue(&tq,t->rchild);
	while(!queueEmpty(tq)){
		deQueue(&tq,&p);
		printf("%x\n",p->m_nValue);	
	}
*/
//	CreateBinaryTree(&t);
//	PreOrderTraverse(t);
//	InOrderTraverse2(t);
//	PostOrderTraverse(t);
	LevelOrderTraverse(t);
return 0;
}
