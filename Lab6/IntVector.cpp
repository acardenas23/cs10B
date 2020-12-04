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
        data[i] = 0;
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

const int& IntVector::front() const{
    return data[0];
}

const int& IntVector::back() const{
    return data[_size-1];
}

void IntVector::expand(){
    /*double capacity of the vector, reallocate memory for the dynamically 
    allocated array and update the value of capacity*/
    int* newcaparray = new int[_capacity*2];

    for(unsigned int i = 0; i < (_capacity); ++i){
        newcaparray[i] = data[i];
        newcaparray[i+_capacity] = 0;
    }
    _capacity = _capacity*2;
    //currently data pointer is pointing to data[0].
    //but i dont want it anymore
    //i want data pointer to point the new array we just created.
    data = newcaparray;
}

void IntVector::expand(unsigned amount){
    int* newcaparray = new int[_capacity+amount];

    for(unsigned int i = 0; i < (_capacity); ++i){
        newcaparray[i] = data[i];
    }

    for(unsigned int i = _capacity; i < (_capacity+amount); ++i){
        newcaparray[i] = 0;
    }

    _capacity = _capacity + amount;

    data = newcaparray;
}

void IntVector::insert(unsigned index, int value){
    //create new array
    //copy values then insert new value at index
    //copy the rest of the array
    //increase size
    //if size> _capacity, double capacity first

    ++_size;
    if (_size>_capacity){
        expand(); //double capacity
    }

    if(index >= _size){
        throw out_of_range("IntVector::insert_range_check");
    }

    int* newArr = new int[_capacity]; //creates a dynamically allocated array

    for(unsigned int i = 0; i < index-1; ++ i){
        newArr[i] = data[i];
    }
    newArr[index-1] = value;

    for(unsigned int i = index; i < _capacity; ++i){
        newArr[i] = data[i-1];
    }

    data = newArr; //now points to newArr
}

void IntVector::erase(unsigned index){
    //create new array, copy up to index, then skip index
    int* newArr = new int[_capacity];

    for(unsigned int i = 0; i < (index-1); ++i){ //should stop before index
        newArr[i] = data[i];
    }

    for(unsigned int i  = index-1; i < _capacity; ++i){
        newArr[i] = data[i+1];
    }
    newArr[_capacity-1] = 0;
    --_size;
    data = newArr;
}

void IntVector::push_back(int value){ //capacity incorrectly set to 0 after calling on an empty vector
    int* newArr = new int[_capacity];

    if(empty()){
        _capacity = 1;
        _size = 0;
    }

    if((_size+1) >_capacity){
        expand();
    }

    for(unsigned int i = 0; i < _size; ++i){
        newArr[i] = data[i];
    }

    newArr[_size] = value;
    ++_size;

    for(unsigned int i = _size; i < _capacity; ++i){
        newArr[i] = data[i];
    }

    data = newArr;
}

void IntVector::pop_back(){
    unsigned int i;
    int* newArr = new int[_capacity];

    --_size;
    for(i = 0; i < _size; ++i){
        newArr[i] = data[i];
    }

    for(i = _size; i<_capacity; ++i){
        newArr[i] = 0;
    }

    data = newArr;

}

void IntVector::clear(){
    _size = 0;
    int* tempArr = new int[_capacity];
    for (unsigned int i = 0; i < _capacity; i++)
    {
        tempArr[i] = 0;
    }
    data = tempArr;   
}
void IntVector::resize(unsigned size, int value){
    //resizes vector to contain size elements
}

void IntVector::print(){
    //using for testing
    cout << "array: " << endl;
    for(unsigned int i  = 0; i < _capacity; ++i){
        cout << data[i] << endl;
    }
}

