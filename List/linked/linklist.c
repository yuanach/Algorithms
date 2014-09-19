#include<stdio.h>
#include<malloc.h>
#include"linklist.h"

ListNode
*get_node(ListNode **list,int n){
	int i=1;
	ListNode *p=*list;
	if(n<1) return NULL;
	while(p != NULL && i++ < n)
		p=p->next;
	return p;
}

void
remove_node(ListNode **list,int i){
	int j=1;
	ListNode *p=*list;
	ListNode *pDeleted=NULL;
	if(i<1 || p == NULL) 
		return;
	while(p->next != NULL && j++ < i-1)
		p=p->next;
	pDeleted=p->next;
	p->next=p->next->next;
	free(pDeleted);
}

void
insert_node(ListNode **list,int i,int value){
	ListNode *pNew=(ListNode *)malloc(sizeof(ListNode));
	pNew->m_nValue=value;
	pNew->next=NULL;
	int j=1;
	if(i<1) return;
	if(*list == NULL)
		*list=pNew;
	else{
		ListNode *p=*list;
		while(p->next != NULL && j++ < i-1)
			p=p->next;
		pNew->next=p->next;
		p->next=pNew;
	}
}

void
add_tail(ListNode **list,int value){
	printf("here\n");
	ListNode *pNew=(ListNode *)malloc(sizeof(ListNode));
	pNew->m_nValue=value;
	pNew->next=NULL;

	printf("here\n");
	if(*list == NULL)
		*list=pNew;
	else{
		ListNode *p=*list;
		while(p->next != NULL)
			p=p->next;
		p->next=pNew;
	}
}

ListNode
*locate_value(ListNode *list,int value){
	ListNode *p=list;
	while(p && p->m_nValue != value)
		p=p->next;
	return p;
}

void
remove_value(ListNode **list,int value){
	if(list == NULL || *list == NULL)
		return;
	ListNode *pDeleted=NULL;
	if((*list)->m_nValue == value){
		pDeleted=*list;
		*list=(*list)->next;
	}
	else{
		ListNode *p=*list;
		while(p && p->m_nValue != value)
			p=p->next;
		if(p->next != NULL && p->m_nValue == value){
			pDeleted=p->next;
			p->next=p->next->next;
		}
	}
	if(pDeleted != NULL)
		free(pDeleted);
}

