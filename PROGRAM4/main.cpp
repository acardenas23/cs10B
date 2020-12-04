#include <iostream>
#include <vector>
using namespace std;

#include "IntVector.h"

int main(){
    //IntVector* testIntVec = new IntVector(6,4);
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

    // (*testIntVec).print();
    // cout << "Erase(): " << endl;
    // (*testIntVec).erase(5);
    //(*testIntVec).print();
    // (*testIntVec).push_back(7);
    // (*testIntVec).print();
    // (*testIntVec).pop_back();
    // (*testIntVec).print();
    // (*testIntVec).clear();
    // if(((*testIntVec).empty())){
    //     cout << "array is empty" << endl;
    // }
    // (*testIntVec).push_back(400);
    // //(*testIntVec).print();
    // //(*testIntVec).clear();
    // (*testIntVec).push_back(4);
    // (*testIntVec).print();


    //testing push_back on an empty function
    //IntVector* testIntVec2 = new IntVector();
    // cout << "Capacity: " << (*testIntVec2).capacity() << endl;
    // (*testIntVec2).push_back(200);
    // (*testIntVec2).push_back(5);
    // (*testIntVec2).print();


    //insert function 
    //(*testIntVec).insert(3,2);
    // (*testIntVec2).insert(4,3);
    // (*testIntVec).insert(5,2);
    //(*testIntVec2).insert(0, 4);
    // vector<int> v;
    // v.insert(v.begin() + 0, -971);
    // cout << "v: " << endl;
    // cout << v.size() << endl;
    // cout << v.capacity() << endl;
    // cout << v.at(0) << endl;

    // IntVector* v2 = new IntVector(1);
    // cout << "v2:" << endl;
    // // cout << (*v2).size() << endl;
    // // cout << (*v2).capacity() << endl;
    
    // (*v2).insert(0, -971);
    // (*v2).print();
    // cout << (*v2).capacity() << endl; //1
    // cout << (*v2).size() << endl; //1
    // cout << (*v2).at(1) << endl; 

    // IntVector* erasevec = new IntVector(10,9);
    // (*erasevec).print();
    // (*erasevec).insert(4, 5);
    // (*erasevec).print();
    // (*erasevec).erase(4);
    // (*erasevec).print();



    /*resize
    (*testIntVec).resize(20);
    // cout << "Capacity: " << (*testIntVec).capacity() << endl;
    (*testIntVec).print();
    (*testIntVec2).resize(0);
    */
    // IntVector* testIntVecR = new IntVector;
    // (*testIntVecR).resize(15,-142);
    // (*testIntVecR).print();
    cout << "hello!\n";
    IntVector v1;
    // cout << "1: " << v1.size() << endl;
    // v1.insert(0,2);
    cout << "MAIN 2: " << v1.size()  << endl;
    v1.resize(40);
    cout << "MAIN 3: " << v1.size() << endl;
    v1.resize(100);
    cout << "MAINi: " << endl;
    for( unsigned i=0; i< v1.size(); ++i){
        cout << v1.at(i) << '(' << i << ')' << ' ';
    }
    cout << "\n MAIN: ";
    v1.print();


    

return 0;
}