#include <iostream>
using namespace std;

#include "SortedSet.h"

int main(){
    IntList list1;

    list1.push_front(10);
    list1.push_front(12);
    list1.push_front(9);
    
    SortedSet set1 = SortedSet(list1);
    // cout << "set1: " << set1 << endl;

    // // if(set1.in(5)){
    // //     cout << "True" << endl;
    // // }else{
    // //     cout <<"false" << endl;
    // // }

    // cout << "Testing | when lhs is empty" << endl;
    // SortedSet set2 = SortedSet();
    // SortedSet set3 = SortedSet();
    // //set3 = set2|set1;
    // set2|=set1;
    // cout <<"set2: " << set2 << endl;

    // cout << "Testing | when rhs is empty" << endl;
    // SortedSet set4 = SortedSet();
    // // set4 = set3|set4;
    // // cout <<"set4: " << set4 << endl;
    // set2|=set4;
    // cout <<"set2: " << set2 << endl;

    // cout << "Testing | with two not empty sets" << endl;
    // IntList list2;
    // list2.push_front(7);
    // list2.push_front(16);
    // list2.push_front(9);
    // SortedSet set5 = SortedSet(list2);
    // // set1 = set5|set4;
    // // cout <<"set1: " << set1 << endl;
    // set5|=set2;
    // cout << "set5: " << set5 << endl;


    //Testing &operator
    // SortedSet set6 = SortedSet();
    // //set6 = set1&set5;
    // //cout <<"set 6: " << set6;
    // set1&=set6;
    // cout << "set1: " << set1 << endl;
    IntList a;
    IntList b;
    a.push_front(-36);
    a.push_front(58);
    b.push_front(65);
    b.push_front(137);

    SortedSet sset1 = SortedSet(a);
    //cout << "sset1: " << sset1 << endl;
    SortedSet sset2 = SortedSet();
    SortedSet sset3 = SortedSet();
    SortedSet sset4 = SortedSet(b);
    cout << "sset2: " << sset2 << endl;
    cout << "sset4: " << sset4 << endl;

    //sset3 = sset1 & sset2;
    sset4 &= sset2;
    //cout << "sset3: " << sset3 << endl;
    cout << "sset4: " << sset4 << endl;

    // cout << "sset3: " << sset3.empty() << endl;
    // cout << "sset3: " << sset3.empty() << endl;
    // sset4.push_front(7);
    // sset3.push_front(7);
    //  cout << "sset3: " << sset3 << endl;
    // cout << "sset4: " << sset4 << endl;




    // IntList test1 = IntList();
    // test1.push_back(-99);
    // test1.push_back(29);
    // IntList test2 = IntList();
    // test2.push_back(16);
    // test2.push_back(38);
    // SortedSet sset1 = SortedSet(test1);
    // cout << "set1: " << sset1 << endl;
    // SortedSet sset2 = SortedSet(test2);
    // cout << "set2: " << sset2 << endl;
    // SortedSet sset3 = SortedSet();
    // sset3 = sset1|sset2;
    // cout << "sset3: " << sset3;
    


   
    
    
    


} 