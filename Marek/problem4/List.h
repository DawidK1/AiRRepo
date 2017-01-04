#ifndef LIST
#define LIST
#include "ListNode.h"
using namespace std;

template <class DT>
class List
{
	ListNode<DT>* head;
	ListNode<DT>* cursor;

public:
	List();
	~List();
	void insert(const DT &newDataItem);
	void remove();
	void replace(const DT &newDataItem);
	void clear();
	bool isEmpty() const;
	bool isFull() const;
	void gotoBeginning();
	void gotoEnd();
	void gotoNext();
	void gotoPrior();
	DT getCursos() const;
	void showStructure() const;
};

template <class DT>
List<DT> :: List()
{
	cursor = NULL;
	head = NULL;
}

template <class DT>
List<DT> :: ~List()
{
	if(head != NULL)
	{
		ListNode<DT> *ptr, *p;
		p = head;
		while(ptr != head)
		{
			ptr = p->next;
			delete p;
			p = ptr;
		}
	}
}

template <class DT>
void List<DT> :: insert(const DT &newDataItem)
{
	if(head == NULL)
	{
		ListNode<DT> *n, *p;
		p = NULL;
		n = NULL;
		head = new ListNode<DT>(newDataItem, p, n);
		
		if(head == NULL)
			throw bad_alloc();

		p = head;
		n = head;
		cursor = head;
		head->prior = p;
		head->next = n;
	}
	else
	{
		ListNode<DT> *ptr;
		ptr = new ListNode<DT>(newDataItem, cursor, cursor->next);

		if(ptr == NULL)
			throw bad_alloc();
		
		cursor->next->prior = ptr;
		cursor->next = ptr;
		cursor = ptr;
	}
	
}


#endif
