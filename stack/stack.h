
#define MAX_STACK_LENGTH 0x0010

typedef struct{
	int m_nValue;
	struct LinkNode *next;
}LinkNode;

typedef struct{
	int nValue[MAX_STACK_LENGTH];
	int top;
}SqStack;

typedef struct{
	int m_nValue;
	struct LinkNode *next;
}LinkedStack;
