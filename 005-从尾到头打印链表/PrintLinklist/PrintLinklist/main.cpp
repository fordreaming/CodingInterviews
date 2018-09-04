#include <iostream>
#include <stack>
#include <vector>
#include <time.h>
#include <ctype.h>

using namespace std;
//定义链表结构体

#define FALSE 0;
#define TRUE 1;

#define OK 1;
#define ERROR 0;

//#define STATUS int;
//#define ElemType int;

//定义类型别名好于上面的#define
typedef int Status;
typedef int ElemType;

typedef struct _Node
{
	int data;
	struct _Node *next;
}Node;

typedef struct _Node *LinkList;

//*****************************************************************************
//产生头结点并使头结点的指针域置空
//
//*****************************************************************************
Status InitList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(Node));//产生头结点并使L指向头结点
	if (!(*L))//存储分配失败
	{
		return FALSE;
	}
	(*L)->next = NULL;//指针域为空
	return TRUE;
}

Status InitListByValue(LinkList L)
{
	L = (LinkList)malloc(sizeof(Node));//产生头结点并使L指向头结点
	if (!L)//存储分配失败
	{
		return FALSE;
	}
	L->next = NULL;//指针域为空
	return TRUE;
}



//反转链表,采用头插法进行反转
Node* ListRevert(Node* L)
{
	Node *pCurrent;
	Node *pNext;
	Node *pPre;
	if (L == NULL && L->next == NULL)
	{
		return L;
	}
	pCurrent = L->next;
	pNext = pCurrent->next;
	pCurrent->next = NULL;

	while(pNext)
	{
		pPre = pNext->next;
		pNext->next = pCurrent;
		pCurrent = pNext;
		pNext = pPre;
	}
	L->next = pCurrent;
	return L;
}

/*  随机产生n个元素的值，建立带表头结点的单链线性表L（头插法） */
void CreateListHead(LinkList *L, int n)
{
	LinkList p, r;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));//L为整个线性表
	(*L)->next = NULL;
	for(i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand()%100 + 1;
		p->next = (*L)->next;
		(*L)->next = p;
	}
}


/*  随机产生n个元素的值，建立带表头结点的单链线性表L（尾插法） */
void CreateListTail(LinkList *L, int n) 
{
	LinkList p, r;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));//L整个线性表
	r = *L;					//r指向尾部的结点
	for(i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand()%100 + 1;
		r->next = p;
		r = p;
	}
	r->next = NULL;
}

void CreateListTailByValue(LinkList L, int n) 
{
	LinkList p, r;
	int i;
	srand(time(0));
	L = (LinkList)malloc(sizeof(Node));//L整个线性表
	r = L;					//r指向尾部的结点
	for(i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand()%100 + 1;
		r->next = p;
		r = p;
	}
	r->next = NULL;
}

//*****************************************************************************
//
/* 初始条件：顺序线性表L已存在,1≤i≤ListLength(L)/
/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
//*****************************************************************************

Status ListInsert(LinkList *L, int i, int e)
{
	int j;
	LinkList p;//声明一结点p
	LinkList s;
	p = *L;
	
	j = 1;
	while (j < i && p != NULL)//寻找第i个结点
	{
		p = p->next;
		j++;
	}
	while (j > i || p == NULL)
	{
		return FALSE;//链表末尾p为空，则说明第i个元素不存在
	}
	s = (LinkList)malloc(sizeof(Node));//生成新的结点
	s->data = e;
	s->next = p->next;//将p的后继结点赋给s的后继
	p->next = s;//将s赋值给p的后继；
	return TRUE;
}

/* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
Status ListLength(LinkList L)
{
	int j = 0;
	LinkList p = (LinkList)malloc(sizeof(Node));
	p = L->next;
	while(p != NULL)
	{
		p = p->next;
		j++;
	}
	return j;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
Status ListTraverse(LinkList L)
{
	LinkList p;
	p = L;//头结点
	while (p->next != NULL)
	{
		p=p->next;
		printf("%5d", p->data);
	}
	printf("\n");
	return TRUE;
}


/* 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
Status ListEmpty(LinkList L)
{
	if (L->next)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
Status ListDelete(LinkList *L,int i,ElemType *e) 
{
	int j = 1;
	LinkList p, q;
	p = *L;
	
	while (j <i && p->next != NULL)//寻找第i个结点
	{
		p = p->next;
		j++;
	}
	while (j > i || p->next == NULL)//到链表末尾p为空，说明第i个元素不存在
	{
		return FALSE;
	}
	q = p->next;//预删除的结点赋值给q
	p->next = q->next;
	*e = q->data;
	free(q);
	return TRUE;

}

//反向打印链表
vector<int> PrintLinkListTailToHead(LinkList L)
{
	LinkList p = L;
	stack<int> st;
	int count = 0;
	//把节点进行压栈
	while (p != NULL)
	{
		cout << p->data << "in stack" << endl;
		st.push(p->data);
		count++;
		p = p->next;
	}
	vector<int> res(count);
	cout << "count = " << count << endl;
	//弹栈到vector中；
	for (int i = 0; i < count && st.empty() != true; i++)
	{
		res[i] = st.top();
		st.pop();
	}
	return res;
}

/* 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 */
Status ClearList(LinkList *L)
{
	LinkList p, q;
	p = (*L)->next;//第一个结点
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
	return TRUE;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：用e返回L中第i个数据元素的值 */
Status GetElem(LinkList L,int i,ElemType *e)
{
	int j = 1;
	LinkList p;
	p = L->next;
	while (j < i && p != NULL)
	{
		p = p->next;
		j++;
	}
	while (j > i || p == NULL)
	{
		return ERROR;
	}
	*e = p->data;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：返回L中第1个与e满足关系的数据元素的位序。 */
/* 若这样的数据元素不存在，则返回值为0 */
int LocateElem(LinkList L,ElemType e)
{
	int i = 0; 
	LinkList p = L->next;
	while(p)
	{
		i++;
		if (p->data == e)
		{
			return i;
		}
		p = p->next;
	}
	return true;
}

int main()
{
	int i;
	int e;
	int j = 0;
	LinkList L;
	//初始化单链表

	/*对于LinkList L: L是指向定义的node结构体的指针,可以用->运算符来访问结构体成员,即L->elem,而(*L)就是个Node型的结构体了,可以用点运算符访问该结构体成员,即(*L).elem;
	对于LinkList *L:L是指向定义的Node结构体指针的指针,所以(*L)是指向Node结构体的指针,可以用->运算符来访问结构体成员,即(*L)->elem,当然,(**L)就是Node型结构体了,所以可以用点运算符来访问结构体成员,即(**L).elem;

	准则是: 
	如果函数会改变指针L的值,而你希望函数结束调用后保存L的值,那你就要用LinkList *L,这样,向函数传递的就是指针的地址,结束调用后,自然就可以去改变指针的值; 
	而如果函数只会修改指针所指向的内容,而不会更改指针的值,那么用LinkList L就行了;*/
	//if (!InitListByValue(L))
	//{
	//	printf(" initial list failure");
	//}
	if (!InitList(&L))
	{
		printf(" initial list failure");
	}
	//
	printf("初始化L后：ListLength(L) = %d\n", ListLength(L));
	//为链表插入元素
	
	for (j = 1; j <=3; j++)
	{
		i = ListInsert(&L, 1, j);
	}
	printf("在L的表头依次插入1～5后：L.data=\n");
	ListTraverse(L);

	printf("ListLength(L)=%d \n",ListLength(L));
	
	ListDelete(&L, 3, &e);
	/*i = ListEmpty(L);*/

	Node list[4];//定义结点数组
	list[0].data = 1;
	list[0].next = &list[1];

	list[1].data = 2;
	list[1].next = &list[2];

	list[2].data = 3;
	list[2].next = &list[3];

	list[3].data = 4;
	list[3].next = NULL;
	
	vector<int> temp;
	temp = PrintLinkListTailToHead(list);

	//ClearList(&L);
	GetElem(L, 3, &e);
	LocateElem(L, 2);
	LinkList L1, LTail;
	LTail = (LinkList)malloc(sizeof(Node));
	LTail->next = NULL;
	CreateListHead(&L1, 3);
	/*CreateListTail(&LTail, 3);*/
	CreateListTailByValue(LTail, 3);
	return 0;
}


