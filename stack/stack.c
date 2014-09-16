#include<stdio.h>
#include"stack.h"

void init_sq_stack(SqStack *s){
	s->top=-1;
}

bool stack_empty(SqStack s){
	if(s.top == -1)
		return true;
	else 
		return false;
}

bool push(SqStack *s,int m_nValue){
	if(s == NULL || s->top == MAX_STACK_LENGTH -1)
		return false;
	s->nValue[++s->top]=m_nValue;
	return true;
}

bool pop(SqStack *s,int *m_nValue){
	if(s == NULL || s->top == -1)
		return false;
	*m_nValue= s->nValue[s->top];
	s->top-=1;
	return true;
}

bool get_top(SqStack s,int *m_nValue){
	if(s.top == -1)
		return false;
	*m_nValue=s.nValue[s.top];
	return true;		
}
