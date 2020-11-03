//class declaration
#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

#include <string>

class ItemToPurchase{
    public:
        ItemToPurchase(); //default constructor
        ItemToPurchase(string name, string description, int price, int quantity);
        void setName(string itemName);
        void setPrice(int itemPrice);
        void setQuantity(int itemQuantity);
        void setDescription(string itemDescription);
        void printItemCost()const;
        void printItemDescription()const;
        string name() const;
        int quantity() const;
        int price() const;
        string description() const;

    private:
        string _name;
        int _price;
        int _quantity;
        string _description;
};

#endif