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
        tmp->next = head; 
        head = tmp;
        tail = tmp;
    }else{
        IntNode *tmp = new IntNode(val);
        tmp->next = head; 
        head = tmp;

    }
  
}

void IntList::pop_front(){
       if(head==nullptr){
           tail = nullptr;
       }
       else if(head == tail){
           delete head;
           head = nullptr;
           tail = nullptr;
       }
       else{
            IntNode *tmp = head;
            head=head->next;
            delete tmp;
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

IntList::IntList(const IntList &cpy){
    if(cpy.head == nullptr){
        head = nullptr;
        tail = nullptr;
    }
    else{
        IntNode* copy = cpy.head;
        head = nullptr;
        tail = nullptr; //create empty and then fill in
        while(copy!=nullptr){
            push_back(copy->value);
            copy = copy->next;
        }
    }
   
}

IntList& IntList::operator=(const IntList &rhs){
    if(this==&rhs){
        return *this; //this refers to calling object(list5)
    }
    else{
        IntNode* origList = rhs.head;
        if(rhs.head == nullptr){
            head = nullptr;
            tail = nullptr; 
        }
        else{
            head = nullptr;
            tail = nullptr; //make empty list and fill values
            while(origList != nullptr){
                this->push_back(origList->value);
                origList = origList->next;
            }
        }

    }
    return *this;
}

void IntList::push_back(int value){   
    if(head == nullptr){
        push_front(value);
        return;
    }
    else{
        IntNode* temp = new IntNode(value); //allocates new node
        tail->next = temp; //next tail value points to temp
        tail = temp; 
    }   
}

void IntList::clear(){
    if(head == nullptr){
        tail = nullptr;
    }
    else{
        IntNode* temp = head; //points to head
        while(temp!=nullptr){
            temp=temp->next;
            delete[] head;
            head = temp;
        }
    }
}

void IntList::selection_sort(){
    if(head == nullptr){
        tail = nullptr;
    }
    else{
        for(IntNode*i = head; i!=nullptr; i=i->next){
            for(IntNode*j = i->next; j!= nullptr; j = j->next){
                if(j->value < i->value){
                    swap(i->value, j->value);
                }
            }
        } 
    }
}

void IntList::insert_ordered(int value){
    if(head ==nullptr){
        push_front(value);
        return;
    }else if(head->value >= value){
        push_front(value); //insert value at the front if the first value is less than head value
    }else if(tail->value<=value){
        push_back(value); //insert value at the end if the last value is larger than tail
    }else{
        IntNode* prev = head;
        IntNode* next = head->next;
        int a = 0; //to ensure that if statement is only entered once
        while(next!=tail){
            if((value<=next->value) && (a==0)){  //case for if value is going to be inserted after first node
                IntNode* newNode = new IntNode(value); 
                prev->next = newNode;
                newNode->next = next;
                ++a;
            }
            prev= prev->next;
            next = next->next; //next goes to next values
            if((value<=next->value) && (a==0)){
                IntNode* newNode = new IntNode(value); 
                prev->next = newNode;
                newNode->next = next;
                ++a;
            }
        }
    }
}


void IntList::remove_duplicates(){
    if(head == nullptr){
        tail = nullptr;
    }
    else{
        IntNode *prev;
        IntNode *i;
        IntNode *curr;
        for(i = head; i != nullptr; i = i -> next) {
            prev = i;
            curr = prev -> next;
            while( curr != nullptr) {
                //when a duplicate is found
                if(curr -> value ==  i -> value) {
                    prev -> next = curr -> next;
                    if(curr == tail) {
                        tail = prev;
                    }
                    delete curr;
                    curr = prev -> next;
                }
                //when there's no duplicate
                else {
                    prev = prev -> next; 
                    curr = prev -> next;
                }
            }
        }
    }
}
