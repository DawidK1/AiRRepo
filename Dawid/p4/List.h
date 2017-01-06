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


//void replace ( const DT &newDataItem ) throw ( logic_error );
//void clear ();
//bool isEmpty () const;
//void gotoBeginning () throw ( logic_error );
//void gotoEnd () throw ( logic_error );
//bool gotoNext () throw ( logic_error );
//bool gotoPrior () throw ( logic_error );
//DT getCursor () const throw ( logic_error );
//void showStructure () const;

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
    temp = new ListNode<DT>(newDataItem);
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


gotoNext();
size++;
};
///////////////////////////////////////////////////////////////
void remove () {

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
void clear(){
   while(current_node!=NULL)
       remove();
    size = 0;
    start_node = NULL;
    current_node = NULL;
}
//////////////////////////////////////////////////////////

bool isEmpty(){
    return size;
}
/////////////////////////////////////////

void gotoBeginning(){

    current_node = start_node;
}
//////////////////////////////////////////////
void gotoEnd() {
    try{
        if(start_node == NULL) throw logic_error("start_is_null");
         current_node = start_node->prior;
    }
     catch(logic_error &le){
          cerr << "gotoEnd"<< le.what() ;
          
    }
}
///////////////////////////////////////////////
void gotoNext() {
     try{
        if(current_node == NULL) throw logic_error("current_is_null");         
         current_node = current_node->next;
    }
     catch(logic_error &le ){
          cerr << "gotoNext" << le.what() ;
          
    }
}
///////////////////////////////////////////////
void gotoPrior(){
     try{
           if(current_node == NULL) throw logic_error("current_node_is_null");
           current_node = current_node->prior;
    }
     catch(logic_error &le ){
          cerr << "gotoPrior"<< le.what()  ;
          
    }
}
DT getCursor () const {

     try{
         
           if(current_node == NULL) throw logic_error("current_node_is_null");         
        DT data = current_node->dataItem;
        return data;
    }
     catch(logic_error &le ){
          cerr << "getCursor" << le.what() ;
     }     
}


//////////////////////////////////////////////////////
void showStructure () const{

ListNode<DT>* temp = start_node;

    do{
        try{
            if(temp->next == NULL) throw logic_error("next_is_null");
        cout <<  temp->dataItem;
        temp = temp->next;
        }
        catch(logic_error &le){
            cerr << "showStructure" << le.what();
        }
    }while(temp != start_node);

    }
////////////////////////////////////////////////////////

void replace ( const DT &newDataItem ) {
    try{
        if(current_node == NULL) throw logic_error("current_node_is_null");
        current_node->dataItem = newDataItem;

    }
    catch(logic_error &ba){
    cerr << "nie mozna zamienic" << ba.what() << endl;
    }
}
////////////////////////////////////////////////////////////

bool isEqual(const List<DT> &list2)const{

ListNode<DT>* temp = (*this).start_node;
ListNode<DT>* temp2 = list2.start_node;

if( (*this).size != list2.size)
    return false;

    do{
       if( ! (temp->dataItem == temp2->dataItem) )
            return false;

        temp = temp->next;
        temp2 = temp2->next;
    }while(temp != (*this).start_node);

return true;
}
////////////////////////////////////////////////////////

void shiftLeft(){
    start_node = start_node->next;
    current_node = current_node->next;
    }
void shiftRight(){
    start_node = start_node->prior;
    current_node = current_node->prior;
    }



 void   debugNext(int n){

for(int i = 0; i < n ; i++){
    cout<<current_node->dataItem;
    gotoNext();
    }

}

 void   debugPrior(int n){

for(int i = 0; i < n ; i++){
    cout<<current_node->dataItem;
    gotoPrior();
    }

}

    
};














template < class DT >
class ListNode{
  
private:

// Konstructor

ListNode ( const DT &data){
    dataItem = data;
    prior= NULL;
    next = NULL;
}

// Pola składowe

DT dataItem;

ListNode *prior, *next;

friend class List<DT>;

};


#endif