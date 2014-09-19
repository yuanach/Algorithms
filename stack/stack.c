#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

void
init_sq_stack(SqStack *s){
	s->top=-1;
}

int
stack_empty(SqStack s){
	if(s.top == -1)
		return 1;
	else 
		return 0;
}

int
push(SqStack *s,int m_nValue){
	if(s == NULL || s->top == MAX_STACK_LENGTH -1)
		return 0;
	s->nValue[++s->top]=m_nValue;
	return 1;
}

int
pop(SqStack *s,int *m_nValue){
	if(s == NULL || s->top == -1)
		return 0;
	*m_nValue= s->nValue[s->top];
	s->top-=1;
	return 1;
}

int
get_top(SqStack s,int *m_nValue){
	if(s.top == -1)
		return 0;
	*m_nValue=s.nValue[s.top];
	return 1;
}
