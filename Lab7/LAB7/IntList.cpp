#include <iostream>
#include <stdexcept>
using namespace std;

#include "IntList.h"
IntList::IntList(){
   head = nullptr;
   tail = nullptr;
}

IntList::~IntList(){
   //deleted each node in the linked list
   while(head){
      IntNode* next = head ->next;
      delete head;
      head = next;
   }
}

void IntList:: push_front(int val){
    if(head==nullptr){
        IntNode *tmp = new IntNode(val);
        tmp->next = head; //-> is deference operator
        head = tmp;
        tail = tmp;
    }else{
        IntNode *tmp = new IntNode(val);
        tmp->next = head; //-> is deference operator
        head = tmp;

    }
  
}

void IntList::pop_front(){
    //removes the node that contains the value at the front of the list
    //call delete on first address
       IntNode *tmp = head;
       head=head->next;
       delete[] tmp;
       if(head==nullptr){
           tail = nullptr;
       }
}

bool IntList::empty() const{
    if ((head == nullptr) && (tail == nullptr)){
        return true;
    }
    else{
        return false;
    }
}

const int&IntList::front() const{
    return head->value;
}

const int& IntList::back() const{
    return tail->value;   
}


ostream & operator<<(ostream &out, const IntList &listVal){
    //outputs all int values stored in the list
    IntNode *temp = listVal.head;

    if(temp!=nullptr){
        out << temp->value;
        temp = temp->next;
    }
    
    while(temp!=nullptr){
        out << " " << temp->value;
        temp = temp->next;
    }
    return out;
}