#ifndef LIST
#define LIST
#include "ListNode.h"
using namespace std;


template <class DT>
class List
{
	ListNode<DT>* cursor;
	ListNode<DT>* head;
public:
	List ();
	~List ();
	void insert ( const DT &newDataItem );
	void remove ();
	void replace ( const DT &newDataItem );
	void clear ();
	bool isEmpty () const;
	bool isFull () const;
	void gotoBeginning (); 
	void gotoEnd ();
	void gotoNext ();
	void gotoPrior ();
	DT getCursor () const ;
	void showStructure () const;
};

template <class DT>
List<DT>::List()
{
	cursor = NULL;
	head = NULL;
}

template <class DT>
List<DT>::~List()
{
	if(head!=NULL)
	{
		ListNode<DT>* ptr, *p;
		p=head;
		while(ptr!=head)
		{
			ptr=p->next;
			delete p;
			p=ptr;
		}
	}
}

template <class DT>
void List<DT>::insert(const DT &newDataItem)
{
	if (head == NULL)
	{
		ListNode<DT> * n,*p;
		p=NULL;
		n=NULL;
		head = new ListNode<DT>(newDataItem,p,n);
		if(head == NULL)
		{
			throw bad_alloc();
		}
		p=head;
		n=head;
		cursor = head;
		head->prior=p;
		head->next = n;
	}
	else 
	{
		ListNode<DT> * ptr;
		ptr = new ListNode<DT>(newDataItem,cursor,cursor->next);
		if(ptr == NULL)
		{
			throw bad_alloc();
		}
		cursor->next->prior=ptr;		
		cursor->next=ptr;
		cursor = ptr;
	}
	return;
}


template <class DT>
void List<DT>::remove()
{
	if(head!=NULL)
	{
		int x=0;
		ListNode<DT>* ptr, *p;
		p=cursor->prior;
		if(cursor==head)
			x=1;
		ptr=cursor->next;
		cursor->next->prior=p;
		cursor->prior->next=ptr;
		delete cursor;
		if(x==1)
			head=ptr;
		cursor=ptr;
	
	}
	else
		throw logic_error();
	
	return;
}

template <class DT>
void List<DT>::replace ( const DT &newDataItem )
{
	if (cursor == NULL)
		throw logic_error("logic error");
	cursor->dataItem = newDataItem;
	return;
}




template <class DT>
void List<DT>::clear()
{
	if(head!=NULL)
	{
		ListNode<DT>* ptr, *p;
		p=head;
		while(ptr!=head)
		{
			ptr=p->next;
			delete p;
			p=ptr;
		}
	}
	head=NULL;
	return;
}



template <class DT>
bool List<DT>::isEmpty() const
{
	if (head == NULL)
		return true;
	else
		return false;
}


template <class DT>
bool List<DT>::isFull() const
{
	if (cursor == head)
		return true;
	else if (cursor == head->prior)
		return true;
	else
		return false;
}


template <class DT>
void List<DT>::gotoBeginning ()
{
	if (cursor == NULL)
		throw logic_error("logic error");
	cursor = head;
	return;
}


template <class DT>
void List<DT>::gotoEnd ()
{
	if (cursor == NULL)
		throw logic_error("logic error");
	cursor = head->prior;
	return;
}


template <class DT>
void List<DT>::gotoNext ()
{
	if (cursor == NULL)
		throw logic_error("logic error");
	cursor=cursor->next;
	return;
}


template <class DT>
void List<DT>::gotoPrior ()
{
	if (cursor == NULL)
		throw logic_error("logic error");
		cursor=cursor->prior;
	return;
}



template <class DT>
DT List<DT>::getCursor () const
{
	if (cursor == NULL)
		throw logic_error("logic error");
	return cursor->dataItem;
}


template <class DT>
void List<DT>::showStructure () const
{
	ListNode<DT>* ptr;
	ptr = head;
	for(ptr=head;ptr!=head->prior ;ptr=ptr->next)
	{	
		cout<<ptr->dataItem;
	}
	cout<<ptr->dataItem<<endl;
	return;
}


#endif
