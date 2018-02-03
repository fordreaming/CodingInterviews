
#include <iostream>

using namespace std;

//  调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain

struct RandomListNode
{
	int label;
	struct RandomListNode *next, *random;
};


//brute force
class Solution
{
public:
	///  找到newHead指向的新链表中与原来链表oldHead的randNode节点对应的那个节点
	///
	///  复制的链表newHead与原链表oldHead存在一一对应的关系
	///  因此使用两个指针(一个指向原来链表一个指向新链表)同步移动
	///  即可找到newHead指向的新链表中与原来链表oldHead的randNode节点对应的那个节点
	RandomListNode* FindInNew(RandomListNode *oldHead, RandomListNode *newHead, RandomListNode *randNode)
	{
		RandomListNode *currNode = oldHead;
		RandomListNode *newNode = newHead;

		while(currNode != NULL && newNode != NULL)
		{
			if(randNode == currNode)
			{
				return newNode;
			}
			currNode = currNode->next;
			newNode = newNode->next;
		}

		return NULL;
	}

	///  复制操作
	RandomListNode* Clone(RandomListNode* pHead)
	{
		if(pHead == NULL)
		{
			return NULL;
		}

		RandomListNode *currNode = pHead;
		RandomListNode *newHead = NULL, *preNode = NULL, *newNode = NULL;

		///  首先复制原链表的普通指针域, 一次遍历即可完成
		while(currNode != NULL)
		{
			newNode = new RandomListNode;
			newNode->label = currNode->label;
			currNode = currNode->next;

			if(preNode == NULL)
			{
				newHead = newNode;
			}
			else
			{
				preNode->next = newNode;
			}

			preNode = newNode;
		}

		//  接着复制随机指针域, 需要两次遍历
		currNode = pHead;
		newNode = newHead;
		while(currNode != NULL && newNode != NULL)
		{
			RandomListNode *randNode = currNode->random;                        ///  随机指针域randNode
			RandomListNode *newRandNode = FindInNew(pHead, newHead, randNode);  ///  查找到新链表中与randNode对应的指针域
			newNode->random = newRandNode;

			///  链表同步移动
			currNode = currNode->next;
			newNode = newNode->next;
		}

		return newHead;
	}

};



int __tmain( )
{

	RandomListNode list[4];
	list[0].label = 1;
	
	list[0].next = &list[1];
	list[0].random = list + 2;
	list[1].label = 2;
	list[1].next = &list[2];
	list[1].random = list + 1;
	list[2].label = 3;
	list[2].next = &list[3];
	list[2].random = &list[2];
	list[3].label = 4;
	list[3].next = NULL;
	list[3].random = list;

	Solution solu;
	RandomListNode *head = solu.Clone(list);
	return 0;
}
