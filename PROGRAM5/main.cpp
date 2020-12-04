#include <iostream>
using namespace std;

#include "IntList.h"

int main() {

  //tests constructor, destructor, push_front, pop_front, display

   
      cout << "\nlist1 constructor called" << endl;
      IntList list1;
      //cout << "pushfront 10" << endl;
      list1.push_front(10);
     // cout << "pushfront 20" << endl;
      list1.push_front(20);
      //cout << "pushfront 30" << endl;
      list1.push_front(30);
      cout << "list1: " << list1 << endl;
      //cout << "pop" << endl;
      // list1.pop_front();
      // cout << "list1: " << list1 << endl;
      // cout << "pop" << endl;
      // list1.pop_front();
      // cout << "list1: " << list1 << endl;
      // cout << "pop" << endl;
      // list1.pop_front();
      // cout << "list1: " << list1 << endl;
      // cout << "pushfront 100" << endl;
      // list1.push_front(100);
      // cout << "pushfront 200" << endl;
      // list1.push_front(200);
      // cout << "pushfront 300" << endl;
      // list1.push_front(300);

      cout << "pushback 60" << endl;
      list1.push_back(60);
      cout << "list1: " << list1 << endl;
      list1.selection_sort();
      cout << "list1 after selection_sort(): " << list1 << endl;
      list1.insert_ordered(70);
      //cout << "list1 after instert_ordered(70): " << list1 << endl;
      cout << "insert_ordered(40): " << endl;
      list1.insert_ordered(40);
      cout << "list1 after instert_ordered(40): " << list1 << endl;
      list1.insert_ordered(10);
      cout << "list1 after instert_ordered(10): " << list1 << endl;
      list1.clear();
      cout << "list1: " << list1 << endl;

      IntList list3;
      list3 = list1;

   //    cout << "front: " << list1.front() << endl;
   //    cout << "back: " <<list1.back() << endl;

   //    cout << "list1: " << list1 << endl;
   //    cout << endl;
   //    cout << "Calling list1 destructor..." << endl;
   //    cout << "list1 destructor returned" << endl;
   
   // // Test destructor on empty IntList
   // {
   //    IntList list2;
   //    cout << "Calling list2 destructor..." << endl;
   // }
   // cout << "list2 destructor returned" << endl;
   cout << "list4 constructor called" << endl;
   IntList list4;
   //cout << "insert 20" << endl;
   list4.push_front(10);
   //cout << "insert 10" << endl;
   list4.push_front(20);
   //list4.insert_ordered(30);
   //cout << "insert 50" << endl;
   list4.push_front(10);
   //cout << "list4: " << list4 << endl;
   //cout << "insert 40" << endl;
   // list4.insert_ordered(40);
   // cout << "list4: " << list4 << endl;
   //list4.insert_ordered(11);
   //cout << "list4: " << list4 << endl;
   list4.push_front(30);
   //cout << "list4: " << list4 << endl;
   // list4.insert_ordered(11);
   // cout << "list4: " << list4 << endl;
   list4.push_front(30);
   cout << "list4: " << list4 << endl;
   list4.remove_duplicates();
   cout << "list4: " << list4 << endl;

   IntList list5;
   list5 = list4;
   cout << "list5: " << list5 << endl;

   
   return 0;
}
