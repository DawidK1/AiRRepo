#ifndef LISTNODE
#define LISTNODE
#include "List.h"
using namespace std;

template <class DT>
class ListNode 
{
	ListNode(const DT &data, ListNode *priorPtr, ListNode *nextPtr);
	DT dataItem;
	ListNode *prior, *next;
	friend class List<DT>;
};

template <class DT>
ListNode<DT> :: ListNode(const DT &data, ListNode *priorPtr, ListNode *nextPtr)
{
	dataItem = data;
	prior = priorPtr;
	next = nextPtr;
}

#endif
