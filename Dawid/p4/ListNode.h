#ifndef _LISTNODE_H_
#define _LISTNODE_H_

#include <iostream>



template < class DT >
class ListNode{
  
private:

// Konstructor

ListNode ( const DT &data,ListNode *priorPtr, ListNode *nextPtr );

// Pola składowe

DT dataItem;

ListNode *prior, *next;

friend class List<DT>;

};

















#endif
