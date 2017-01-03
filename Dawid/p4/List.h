#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>
#include <new>
#include <stdexcept>






using namespace std;

template < class DT >
class ListNode;

template <class DT>
class List{

public:

//void insert ( const DT &newDataItem ) throw ( bad_alloc );


void replace ( const DT &newDataItem ) throw ( logic_error );
void clear ();
bool isEmpty () const;
bool isFull () const;
void gotoBeginning () throw ( logic_error );
void gotoEnd () throw ( logic_error );
bool gotoNext () throw ( logic_error );
bool gotoPrior () throw ( logic_error );
DT getCursor () const throw ( logic_error );
void showStructure () const;

int size;



ListNode<DT>* start_node;
ListNode<DT>* current_node;
/////////////////////////////////////////////////////////////////

List(){
    size = 0;
    start_node = NULL;
    current_node = NULL;
}
///////////////////////////////////////////////////////////////////
void insert ( const DT &newDataItem ) throw ( bad_alloc ){

ListNode<DT>* temp;

try{
    temp = new ListNode<DT>;
    }
    catch(bad_alloc &ba){
    cerr << "nie mozna zaalokowac pamieci!" << ba.what() << endl;
    }


if(current_node == NULL){
    current_node = temp;
    start_node = current_node;
    current_node ->prior = current_node;
    current_node ->next = current_node;
    }

    else{
    temp->prior = current_node;
    temp->next = current_node->next;
    current_node->next = temp;
    (temp->next)->prior = temp;
    } 
size++;
};
///////////////////////////////////////////////////////////////
void remove () throw ( logic_error ){


if(current_node != NULL){
    ListNode<DT>* new_current_node = current_node->next;
    ListNode<DT>* old_current_node = current_node;

    if(current_node->next == current_node){
        delete current_node;
        current_node = NULL;
        start_node = NULL;
        }

    else{
        (current_node->next)->prior = current_node->prior;
        (current_node->prior)->next = current_node->next;
        delete current_node;
        current_node = new_current_node;
        }

    if(old_current_node == start_node)
        start_node = current_node;

    size--;    
}

else{
    ;////zrob cos smiesznego
}
}
////////////////////////////////////////////////////////////////////////
~List(){
    while(current_node!=NULL)
        remove();
}
////////////////////////////////////////////////////////////////////////////



};

















template < class DT >
class ListNode{
  
private:

// Konstructor

ListNode ( const DT &data,ListNode *priorPtr, ListNode *nextPtr ){
    next = nextPtr;
    prior = priorPtr;
    dataItem = data;
}

// Pola składowe

DT dataItem;

ListNode *prior, *next;

friend class List<DT>;

};


#endif