//class definition
#include <iostream>
#include <string>
using namespace std;

#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase(){ //default constructor
    _name = "none";
    _price = 0;
    _quantity = 0;
    _description = "none";
}

ItemToPurchase::ItemToPurchase(string name, string description, int price, int quantity){ 
    _name = name;
    _price = price;
    _quantity = quantity;
    _description = description;
}

void ItemToPurchase::setName(string itemName){
    _name  = itemName;
}

void ItemToPurchase::setPrice(int itemPrice){
    _price = itemPrice;
}

void ItemToPurchase::setQuantity(int itemQuantity){
    _quantity = itemQuantity;
}

void ItemToPurchase::setDescription(string itemDescription){
    _description = itemDescription;
}

void ItemToPurchase::printItemCost()const{
    cout << _name << " " << _quantity << " @ $" << _price << " = $" << _quantity*_price << endl;
}

void ItemToPurchase::printItemDescription()const{
    cout << _name << ": " << _description << endl;
}

string ItemToPurchase::name() const{
    return _name;
}

int ItemToPurchase::quantity() const{
    return _quantity;
}

int ItemToPurchase::price() const{
    return _price;
}

string ItemToPurchase::description() const{
    return _description;
}
