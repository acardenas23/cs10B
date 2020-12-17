#include "IntList.h"
#include <iostream>

void IntList::removeOdds() {
    IntNode *prev;
    IntNode *i=head;
    IntNode *curr=head;  
    //if head is odd
    if(curr!=nullptr){
        while(((head->value)%2!=0) &&(i!=nullptr)){
            i=i->next;
            delete head;
            if(i!=nullptr){
            head = i;
            curr=head;
            }else{
                head = nullptr;
                return;
            }
        }
    }
    //if value after head is odd
    if(curr!=nullptr){
        for(i=head; i!=nullptr; i = i->next){
            prev= i;
            curr = prev->next;
            while(curr!=nullptr){
                if((curr->value)%2!=0){
                    prev->next=curr->next;
                    delete curr;
                    curr = prev->next;
                }else{
                    prev = prev->next;
                    curr = prev->next;
                }
            }
        }
    }
}