#include "IntList.h"

#include <iostream>

using namespace std;

IntList::IntList() : head(nullptr) {}


void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

ostream & operator << (ostream &out, const IntList & rhs){
   if(rhs.head == nullptr){
      return out;
   }else{
      operator<<(out,rhs.head);
      return out;
   }
}

ostream & operator<<(ostream&out, IntNode *rhs){
   if(rhs == nullptr){
      return out;
   }else{
      out << rhs->value;
      if(rhs->next != nullptr){
         out << " ";
      }
      operator<<(out,rhs->next); //output next value
      return out;
   }
}

bool IntList::exists(int num) const{
   if(head == nullptr){
      return false;
   }else if(head->value == num){
      return true;
   }else{
      IntNode*temp = head->next; //temp points to next value
      return exists(temp, num); //checks if next value in list exists
   }
}

bool IntList::exists(IntNode *temp, int num)const{
      if(temp == nullptr){ //if at the end
         return false;
      }else if(temp->value == num){
         return true;
      }else{
         bool ex = exists(temp->next,num);
         return ex;
      }
}
