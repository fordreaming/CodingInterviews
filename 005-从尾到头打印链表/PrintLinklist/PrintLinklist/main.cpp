#include <iostream>
#include <stack>
#include <vector>
#include <time.h>
#include <ctype.h>

using namespace std;
//��������ṹ��

#define FALSE 0;
#define TRUE 1;

#define OK 1;
#define ERROR 0;

//#define STATUS int;
//#define ElemType int;

//�������ͱ������������#define
typedef int Status;
typedef int ElemType;

typedef struct _Node
{
	int data;
	struct _Node *next;
}Node;

typedef struct _Node *LinkList;

//*****************************************************************************
//����ͷ��㲢ʹͷ����ָ�����ÿ�
//
//*****************************************************************************
Status InitList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(Node));//����ͷ��㲢ʹLָ��ͷ���
	if (!(*L))//�洢����ʧ��
	{
		return FALSE;
	}
	(*L)->next = NULL;//ָ����Ϊ��
	return TRUE;
}

Status InitListByValue(LinkList L)
{
	L = (LinkList)malloc(sizeof(Node));//����ͷ��㲢ʹLָ��ͷ���
	if (!L)//�洢����ʧ��
	{
		return FALSE;
	}
	L->next = NULL;//ָ����Ϊ��
	return TRUE;
}



//��ת����,����ͷ�巨���з�ת
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

/*  �������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L��ͷ�巨�� */
void CreateListHead(LinkList *L, int n)
{
	LinkList p, r;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));//LΪ�������Ա�
	(*L)->next = NULL;
	for(i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand()%100 + 1;
		p->next = (*L)->next;
		(*L)->next = p;
	}
}


/*  �������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L��β�巨�� */
void CreateListTail(LinkList *L, int n) 
{
	LinkList p, r;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));//L�������Ա�
	r = *L;					//rָ��β���Ľ��
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
	L = (LinkList)malloc(sizeof(Node));//L�������Ա�
	r = L;					//rָ��β���Ľ��
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
/* ��ʼ������˳�����Ա�L�Ѵ���,1��i��ListLength(L)/
/* �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1 */
//*****************************************************************************

Status ListInsert(LinkList *L, int i, int e)
{
	int j;
	LinkList p;//����һ���p
	LinkList s;
	p = *L;
	
	j = 1;
	while (j < i && p != NULL)//Ѱ�ҵ�i�����
	{
		p = p->next;
		j++;
	}
	while (j > i || p == NULL)
	{
		return FALSE;//����ĩβpΪ�գ���˵����i��Ԫ�ز�����
	}
	s = (LinkList)malloc(sizeof(Node));//�����µĽ��
	s->data = e;
	s->next = p->next;//��p�ĺ�̽�㸳��s�ĺ��
	p->next = s;//��s��ֵ��p�ĺ�̣�
	return TRUE;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
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

/* ��ʼ������˳�����Ա�L�Ѵ��� */
/* ������������ζ�L��ÿ������Ԫ����� */
Status ListTraverse(LinkList L)
{
	LinkList p;
	p = L;//ͷ���
	while (p->next != NULL)
	{
		p=p->next;
		printf("%5d", p->data);
	}
	printf("\n");
	return TRUE;
}


/* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE */
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

/* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1 */
Status ListDelete(LinkList *L,int i,ElemType *e) 
{
	int j = 1;
	LinkList p, q;
	p = *L;
	
	while (j <i && p->next != NULL)//Ѱ�ҵ�i�����
	{
		p = p->next;
		j++;
	}
	while (j > i || p->next == NULL)//������ĩβpΪ�գ�˵����i��Ԫ�ز�����
	{
		return FALSE;
	}
	q = p->next;//Ԥɾ���Ľ�㸳ֵ��q
	p->next = q->next;
	*e = q->data;
	free(q);
	return TRUE;

}

//�����ӡ����
vector<int> PrintLinkListTailToHead(LinkList L)
{
	LinkList p = L;
	stack<int> st;
	int count = 0;
	//�ѽڵ����ѹջ
	while (p != NULL)
	{
		cout << p->data << "in stack" << endl;
		st.push(p->data);
		count++;
		p = p->next;
	}
	vector<int> res(count);
	cout << "count = " << count << endl;
	//��ջ��vector�У�
	for (int i = 0; i < count && st.empty() != true; i++)
	{
		res[i] = st.top();
		st.pop();
	}
	return res;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������L����Ϊ�ձ� */
Status ClearList(LinkList *L)
{
	LinkList p, q;
	p = (*L)->next;//��һ�����
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
	return TRUE;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* �����������e����L�е�i������Ԫ�ص�ֵ */
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

/* ��ʼ������˳�����Ա�L�Ѵ��� */
/* �������������L�е�1����e�����ϵ������Ԫ�ص�λ�� */
/* ������������Ԫ�ز����ڣ��򷵻�ֵΪ0 */
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
	//��ʼ��������

	/*����LinkList L: L��ָ�����node�ṹ���ָ��,������->����������ʽṹ���Ա,��L->elem,��(*L)���Ǹ�Node�͵Ľṹ����,�����õ���������ʸýṹ���Ա,��(*L).elem;
	����LinkList *L:L��ָ�����Node�ṹ��ָ���ָ��,����(*L)��ָ��Node�ṹ���ָ��,������->����������ʽṹ���Ա,��(*L)->elem,��Ȼ,(**L)����Node�ͽṹ����,���Կ����õ�����������ʽṹ���Ա,��(**L).elem;

	׼����: 
	���������ı�ָ��L��ֵ,����ϣ�������������ú󱣴�L��ֵ,�����Ҫ��LinkList *L,����,�������ݵľ���ָ��ĵ�ַ,�������ú�,��Ȼ�Ϳ���ȥ�ı�ָ���ֵ; 
	���������ֻ���޸�ָ����ָ�������,���������ָ���ֵ,��ô��LinkList L������;*/
	//if (!InitListByValue(L))
	//{
	//	printf(" initial list failure");
	//}
	if (!InitList(&L))
	{
		printf(" initial list failure");
	}
	//
	printf("��ʼ��L��ListLength(L) = %d\n", ListLength(L));
	//Ϊ�������Ԫ��
	
	for (j = 1; j <=3; j++)
	{
		i = ListInsert(&L, 1, j);
	}
	printf("��L�ı�ͷ���β���1��5��L.data=\n");
	ListTraverse(L);

	printf("ListLength(L)=%d \n",ListLength(L));
	
	ListDelete(&L, 3, &e);
	/*i = ListEmpty(L);*/

	Node list[4];//����������
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


