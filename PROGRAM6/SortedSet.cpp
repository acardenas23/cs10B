#include <iostream>
using namespace std;

#include "SortedSet.h"
#include "IntList.h"

SortedSet::SortedSet(): IntList(){}

SortedSet::SortedSet(const SortedSet &cpy) :IntList(cpy){}

SortedSet::SortedSet(const IntList &list) :IntList(list){ 
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

    for(IntNode*i = head; i!=nullptr; i=i->next){
        for(IntNode*j = i->next; j!= nullptr; j = j->next){
            if(j->value < i->value){
                swap(i->value, j->value);
            }
        }
    } 
}

SortedSet::~SortedSet(){}

bool SortedSet::in(int num){
    IntNode* temp = head;
    while(temp!=nullptr){
        if(temp->value==num){
            return true;
        }
        temp=temp->next;
    }
    return false;
}

SortedSet &SortedSet::operator|(SortedSet& rhs){
    SortedSet *set = new SortedSet();
    if(rhs.head == nullptr){
        IntNode* a = head;
        while(a!=nullptr){
            set -> add(a->value);
            a = a->next;
        }
    }else if(head == nullptr){
        IntNode* b = rhs.head;
        while(b!=nullptr){
            set -> add(b->value);
            b = b->next;
        }
    }else{
        IntNode* c = head;
        IntNode* d = rhs.head;
        while(c!=nullptr){
            set->add(c->value);
            c = c->next;
        }
        while(d!=nullptr){
            set->add(d->value);
            d = d->next;
        }
    }
    return *set;
}

SortedSet & SortedSet::operator&(SortedSet& rhs){
    SortedSet *set = new SortedSet();
    IntNode*a = head;
    IntNode*b = rhs.head;
    while(a!=nullptr){
        if(rhs.in(a->value)){
            set->add(a->value);
        }
        a = a->next;
    }
    while(b!=nullptr){
        if(in(b->value) && (!set->in(b->value))){
            set->add(b->value);
        }
        b = b->next;
    }
    return *set;
}


void SortedSet::add(int value){
    if(!in(value)){
        if(head==nullptr){
            IntNode *tmp = new IntNode(value);
            tmp->next = head; 
            head = tmp;
            tail = tmp;
        }else{
            IntNode *tmp = new IntNode(value);
            tmp->next = head; 
            head = tmp;
        }
    }

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

void SortedSet::push_front(int value){
    add(value);
}

void SortedSet::push_back(int value){
    add(value);
}

void SortedSet::insert_ordered(int value){
    add(value);
}

SortedSet SortedSet::operator|=(SortedSet& rhs){
   if(rhs.head == nullptr){
        SortedSet *set = new SortedSet();
        IntNode* b = head;
        while(b!=nullptr){
            set->add(b->value);
            b = b->next;
        }
        this->clear();
        IntNode* temp = set->head;
        while(temp!=nullptr){
            this->add(temp->value);
            temp=temp->next;
        }
   }
   else{
       SortedSet *set = new SortedSet();
       set = &(*this|rhs);
       this->clear();
        IntNode* temp = set->head;
        while(temp!=nullptr){
            this->add(temp->value);
            temp=temp->next;
        }
    }
   return *this;
}

SortedSet SortedSet::operator&=(SortedSet& rhs){
    IntNode* a = this->head;
    IntNode* b = rhs.head;
    IntNode* temp = a;

    head = nullptr;
    tail = nullptr;
    while(b!=nullptr){
        while(a!=nullptr){
            if(b->value == a->value){
                add(b->value);
            }
            a = a->next;
        }
        if(a == nullptr){
            a = temp;
        }
        b = b->next;
    }
    return *this;
}

