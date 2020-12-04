#include <iostream>
#include <vector>
using namespace std;

#include "IntVector.h"

int main(){
    IntVector* testIntVec = new IntVector(5,1);
    //delete testIntVec;
    //cout<< testIntVec << endl;
    // cout<< *(testIntVec->data)<<endl;
    // cout << testIntVec->_size;


    //(*testIntVec).at(10);
    // cout << (*testIntVec).at(9) << endl;
    // cout << (*testIntVec).front() << endl;
    // cout << (*testIntVec).back() << endl;
    
    // cout << "Capacity before expand(): " << (*testIntVec).capacity() << endl;
    // (*testIntVec).expand(5);
    // cout << "Capacity after expand(): " << (*testIntVec).capacity() << endl;

    // (*testIntVec).insert(5,2);
    // (*testIntVec).print();
    // cout << "Erase(): " << endl;
    // (*testIntVec).erase(5);
    //(*testIntVec).print();
    // (*testIntVec).push_back(7);
    // (*testIntVec).print();
    // (*testIntVec).pop_back();
    // (*testIntVec).print();
    (*testIntVec).clear();
    if(((*testIntVec).empty())){
        cout << "array is empty" << endl;
    }

    //testing push_back on an empty function
    IntVector* testIntVec2 = new IntVector();
    (*testIntVec2).push_back(200);
    (*testIntVec2).print();

    


}