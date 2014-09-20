/*
 * binarytreelib.c
 *
 *  Created on: 2014Äê9ÔÂ21ÈÕ
 *      Author: Administrator
 */

#include<stdio.h>
#include"binarytree.h"



BSTNode
*bst_search(BinaryTree *T,const int key,BSTNode *p){
	p=NULL;
	BinaryTreeNode *q;
	q=T;
	while(q != NULL && key != q->m_nValue){
		if(key < q->m_nValue)
			p=q, q=q->lchild;
		else if(key > q->m_nValue)
			p=q, q=q->rchild;
		else break;
	}
	return q;
}

int
bst_insert(BinaryTree **T,const int value){
	if(*T == NULL){
		*T=(BinaryTree *)malloc(sizeof(struct BNode));
		(*T)->m_nValue=value;
		(*T)->lchild=(*T)->rchild=NULL;
		return 1;
	}
	else if(value == (*T)->m_nValue)
		return 0;
	else if(value < (*T)->m_nValue)
		return bst_insert(&((*T)->lchild),value);
	else
		return bst_insert(&((*T)->rchild),value);
}

void
create_bst(BinaryTree **T,const int *A,const int n){
	*T=NULL;
	int i;
	for(i=0;i<n;i++)
		bst_insert(T,A[i]);
}

