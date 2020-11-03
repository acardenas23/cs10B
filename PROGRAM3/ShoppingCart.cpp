#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "ShoppingCart.h"
#include "ItemToPurchase.h"

ShoppingCart::ShoppingCart(){
    _customerName = "none";
    _currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string name, string date){
    _customerName = name;
    _currentDate = date;

    cout << endl << "Customer name: " << _customerName << endl;
    cout << "Today's date: " << _currentDate <<  endl;
}

string ShoppingCart::customerName() const{
    return _customerName;
}

string ShoppingCart::date() const{
    return _currentDate;
}

int ShoppingCart::numItemsInCart() const{
    int vecsize = _cartItems.size();
    int b = 0;

    for (int i = 0; i < vecsize; ++i){
        b+=_cartItems.at(i).quantity();
    } 

    return b;
}

int ShoppingCart::costOfCart() const{
    int vecsize = _cartItems.size();
    int b = 0;

    for (int i = 0; i < vecsize; ++i){
        b+=(_cartItems.at(i).price())*(_cartItems.at(i).quantity()); 
    }
 
    return b;
}

void ShoppingCart::printTotal() const{
    cout << endl << "Total: $" << costOfCart() << endl ;
}

char ShoppingCart::printMenu(ShoppingCart mycart){
    cout << endl << "MENU" << endl;
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl;
    cout << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout << "q - Quit" << endl << endl;

    cout << "Choose an option: " << endl;
    char choice;
    cin >> choice;

    while((choice != 'a' ) && (choice != 'd') && (choice != 'c') && (choice != 'i') && (choice != 'o') && (choice != 'q')){
        cout << "Choose an option: " << endl;
        cin >> choice;
    }

    return choice;    
}

void ShoppingCart::outputShoppingCart() const{
    int i;
    int vecsize = _cartItems.size();
    cout << endl << "OUTPUT SHOPPING CART" << endl;
    
    cout << _customerName << "'s Shopping Cart - " << _currentDate << endl;
    
    int b = numItemsInCart();
    cout << "Number of Items: " << b << endl << endl;

    if(b == 0){
        cout << "SHOPPING CART IS EMPTY" << endl;
    }

     for (i = 0; i < vecsize; ++i){
        _cartItems.at(i).printItemCost(); 
    } 

    printTotal();   
}

void ShoppingCart::outputItemsDescription() const{
    cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
    cout << _customerName << "'s Shopping Cart - " << _currentDate << endl << endl;
    cout << "Item Descriptions" << endl;

    int i;
    int vecsize = _cartItems.size();
    for(i = 0; i <vecsize; ++i){
        _cartItems.at(i).printItemDescription();
    }
}

void ShoppingCart::addItem(ItemToPurchase newItem){
    _cartItems.push_back(newItem);   
}

void ShoppingCart::removeItem(){
    int i;
    string delItem;
    int vecsize;
    cin.clear();
    cin.ignore(100, '\n');

    cout << "REMOVE ITEM FROM CART"<< endl;
    cout << "Enter name of item to remove: " << endl;
    getline(cin, delItem);

    int a = 0;

    vecsize = _cartItems.size();
    for (i = 0; i < vecsize; ++i){
        if(_cartItems.at(i).name() == delItem){
            _cartItems.erase(_cartItems.begin()+i);
            vecsize = _cartItems.size();
            ++a;
        }
    }

    if(a == 0){
        cout << "Item not found in cart. Nothing removed." << endl;
    }
}

void ShoppingCart::modifyItem(){
    int i;
    string currName;
    int newquant;
    int vecsize;
    cin.clear();
    cin.ignore(100, '\n');
    
    cout << endl << "CHANGE ITEM QUANTITY" << endl;

    cout << "Enter the item name: " << endl;
    getline(cin, currName);
    cout << "Enter the new quantity: " << endl;
    cin >> newquant;

    int k = 0;

    vecsize = _cartItems.size();
    for(i = 0; i < vecsize; ++i){
        if(_cartItems.at(i).name() == currName){
            _cartItems.at(i).setQuantity(newquant);
            ++k;
        }
    }

    if(k == 0){
        cout << "Item not found in cart. Nothing modified." << endl;
    }

}


