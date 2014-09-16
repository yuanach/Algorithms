

typedef int t_elem;

typedef struct LNode{
	int m_nValue;
	struct LNode *next;
}ListNode,LinkList;

ListNode *get_node(ListNode **,int);
void remove_node(ListNode **,int);
void insert_node(ListNode **,int,int);
void add_tail(ListNode **,int);
ListNode *locate_value(ListNode *,int);
void remove_value(ListNode **,int);
void remove_value(ListNode **,int);
