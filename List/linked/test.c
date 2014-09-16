#include<stdio.h>
#include"linklist.h"

int main(){
	ListNode *L;
	add_tail(&L,0xff);
	insert_node(&L,2,0xee);
	printf("%x\n",L->m_nValue);
	remove_value(NULL,0xff);
	printf("%x\n",L->m_nValue);
	return 0;
}
