#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <string>
#include <vector>
#include "ItemToPurchase.h"

class ShoppingCart{
    public:
    ShoppingCart();
    ShoppingCart(string name, string date);
    string customerName() const; //accessor
    string date() const; //accessor
    void addItem(ItemToPurchase newItem);
    void removeItem();
    void modifyItem();
    int numItemsInCart()const;
    int costOfCart() const;
    void printTotal() const;
    void printDescriptions();
    char printMenu(ShoppingCart mycart);
    void outputShoppingCart() const;
    void outputItemsDescription() const;

    private:
    string _customerName;
    string _currentDate;
    vector<ItemToPurchase> _cartItems;
};

#endif