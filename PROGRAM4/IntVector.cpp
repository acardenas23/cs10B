#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

#include "IntVector.h"

IntVector::IntVector(){
    _size = 0;
    _capacity = 0;
    data = nullptr;  
}

IntVector::IntVector(unsigned size){
    _size = size;
    _capacity = size;
    
    data = new int[size];
    for(unsigned int i = 0; i < size; ++i){
        //data[i] = 0;
    }
}

IntVector::IntVector(unsigned size, int value){
    _size = size;
    _capacity = size;

    data = new int[size];
    for(unsigned int i = 0; i < size; ++i){
        data[i] = value;
    }
}

IntVector::~IntVector(){
    cout <<  "in IntVector deconstructor" << endl;
    delete data;
}

unsigned IntVector::size() const{
    return _size;
}

unsigned IntVector::capacity() const{
    return _capacity;
}

bool IntVector::empty() const{
    if(_size == 0){
        return true;
    }
    else{
        return false;
    }
}

const int& IntVector::at(unsigned index) const{
    if(index >= _size){
        throw out_of_range("IntVector::at_range_check");
    }
    else{
        return data[index];
    }
}

int& IntVector::at(unsigned index){
    if(index >= _size){
        throw out_of_range("IntVector::at_range_check");
    }
    else{
        return data[index];
    }
}

const int& IntVector::front() const{
    return data[0];
}

const int& IntVector::back() const{
    return data[_size-1];
}

void IntVector::expand(){
    int* newcaparray = nullptr;
    if(_capacity == 0){
        _capacity = 1;
        newcaparray = new int[_capacity];
        //newcaparray[0] = 0;
        delete[] data;
        data = newcaparray;
    } 
    else{
         newcaparray = new int[_capacity*2];

        for(unsigned int i = 0; i < (_capacity); ++i){
            newcaparray[i] = data[i];
            //newcaparray[i+_capacity] = 0;
        }
        delete[] data;
        data = newcaparray;
        _capacity = _capacity*2;

    }   
}

void IntVector::expand(unsigned amount){
    int* newcaparray = nullptr;
    newcaparray = new int[_capacity+amount];

    for(unsigned int i = 0; i < (_capacity); ++i){
        newcaparray[i] = data[i];
    }

    for(unsigned int i = _capacity; i < (_capacity+amount); ++i){
        //newcaparray[i] = 0;
    }

    delete[] data;

    data = newcaparray;
    _capacity = _capacity + amount;
}

void IntVector::insert(unsigned index, int value){
    _size++;
    if (index > --(_size)) {
        throw out_of_range("IntVector::insert_range_check");
    }           
    _size++;
                
    if (!(_capacity >= _size)) {
        expand();              
    }
               
    for (unsigned int i = _size - 1; i > index; i--) {
        data[i] = data[i-1];
    }
    data[index] = value; 
}

void IntVector::erase(unsigned index){
    //create new array, copy up to index, then skip index
    if(index>=(_size)){
        throw out_of_range("IntVector::erase_range_check");
    }

    for(unsigned int i = index; i < _size; ++i){
        data[i] = data[i+1];
    }
    --_size;
}

void IntVector::push_back(int value){ 
    if(_capacity == 0){
        expand(1);
    }
    else if((_size) >= _capacity){
        expand();
    }

    int* newArr = new int[_capacity];

    for(unsigned int i = 0; i < _size; ++i){
        newArr[i] = data[i];
    }

    newArr[_size] = value;
    ++_size;

    for(unsigned int i = _size; i < _capacity; ++i){
        //newArr[i] = 0;
    }
    delete[] data;
    data = newArr;
}

void IntVector::pop_back(){
    --_size;
}

void IntVector::clear(){
    _size = 0;
}

void IntVector::resize(unsigned size, int value){

    unsigned int currSize = _size;
    unsigned int i = 0;

    int* tempArr = nullptr;
    if (size <= currSize){
        _size = size;

        print(); cout << endl;
    }

    else if(currSize == 0){
        expand(size-_capacity); //expand the capacity to whatever the new size is
        tempArr = new int[_capacity];
        for(i = 0; i < _size; ++i){
            tempArr[i] = data[i];  //copies all of the values in size to temparr
        }
        for(i  = _size; i < size; ++i){
            tempArr[i] = value;
        }
        //delete[] data;
         _size = size; //current size is equal to the new size
        data = tempArr;
        data = tempArr;
    }

    else if( size > currSize){
        if(size>_capacity){
            if((_capacity*2) > (size)){
                expand();
            }
            else{
                expand(size-_capacity);
            }
        }
        //_capacity has been modified, insert elements at the end of the vector
        tempArr = new int[_capacity]; 
        for(i = 0; i < currSize; ++i){
            tempArr[i] = data[i];  //copies all of the values in size to temparr
        }
        for(i  = currSize; i < size; ++i){
            tempArr[i] = value;
        }
        _size = size;
            data = tempArr;
    }
    //delete[] data;

    // cout << "array right before ending: \n";
    // cout << "vector info - _size: " << _size << endl;
    // cout << "vector info - _capacity: " << _capacity << endl;
    // cout << "vector info - data arr: "; 
    // print(); cout << endl;

    cout << "resize one ended! " << size << endl;
}

void IntVector::resize(unsigned size){
    int value = 0;
    unsigned int currSize = _size;
    unsigned int i = 0;
    // cout << "vector info - _size: " << _size << endl;
    // cout << "vector info - _capacity: " << _capacity << endl;
    // cout << "vector info - data arr: "; 
    print(); cout << endl;
    int* tempArr = nullptr;
    if (size <= currSize){
        _size = size;
        print(); cout << endl;
    }

    else if(currSize == 0){
        expand(size-_capacity); //expand the capacity to whatever the new size is
        tempArr = new int[_capacity];
        for(i = 0; i < _size; ++i){
            tempArr[i] = data[i];  //copies all of the values in size to temparr
        }
        for(i  = _size; i < size; ++i){
            tempArr[i] = value;
        }
        //delete[] data;
         _size = size; //current size is equal to the new size
        data = tempArr;
        data = tempArr;
    }

    else if( size > currSize){
        if(size>_capacity){
            if((_capacity*2) > (size)){
                expand();
            }
            else{
                expand(size-_capacity);
            }
        }
        //_capacity has been modified, insert elements at the end of the vector
        tempArr = new int[_capacity]; 
        for(i = 0; i < currSize; ++i){
            tempArr[i] = data[i];  //copies all of the values in size to temparr
        }
        for(i  = currSize; i < size; ++i){
            tempArr[i] = value;
        }
        _size = size;
            data = tempArr;
    }
    //delete[] data;

    // cout << "array right before ending: \n";
    // cout << "vector info - _size: " << _size << endl;
    // cout << "vector info - _capacity: " << _capacity << endl;
    // cout << "vector info - data arr: "; 
    // print(); cout << endl;

    cout << "resize one ended! " << size << endl;
}


void IntVector::print(){
    //using for testing
    // cout << "array: " << endl;
    // for(unsigned int i  = 0; i < _capacity; ++i){
    //    cout << data[i] << '(' << i << ')' << ' ';
    // }
    if(_size>=_capacity){
        for(unsigned int i  = 0; i < _capacity; ++i){
            cout << data[i] << '(' << i << ')' << ' ';
        }
    }else if (_size < _capacity){
         for(unsigned int i  = 0; i < _size; ++i){
            cout << data[i] << '(' << i << ')' << ' ';
        }
    }
}


int& IntVector::front(){
    return data[0];
}

int& IntVector::back(){
    return data[_size-1];
}


void IntVector::reserve(unsigned n){
    cout << "reserve called! " << _capacity << endl;
    if(n >= _capacity){
        expand(n-_capacity);
    } else{
        cout << "nothing happens\n";
    }
    cout << "reserve ended! " << _capacity << endl;
}


void IntVector::assign(unsigned n, int value){
    // int* tempArr = nullptr;
   if(n>_capacity){
       if(_capacity*2 > n){
           expand();
       }
       else{
           expand(n-_capacity);
       }
    }
    //tempArr = new int[_capacity];
    _size = n;
    for(unsigned int i = 0; i < _size; ++i){
        data[i] = value;
    }
}