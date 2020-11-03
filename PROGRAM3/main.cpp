//test functions
#include <iostream>
#include <string>
using namespace std;

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

int main(){

    cout << "Enter customer's name: " << endl;
    string name;
    getline(cin, name);
    cout << "Enter today's date: " << endl;
    string date;
    getline(cin, date);

    ShoppingCart mycart1(name, date);
    ItemToPurchase item1;
    
    char a = mycart1.printMenu(mycart1); 
    while(a != 'q'){
        if(a == 'a'){   
            string newname;
            string newdescription;
            int newprice;
            int newquant;

            cin.clear();
            cin.ignore(100, '\n');
            cout << "ADD ITEM TO CART" << endl;

            cout << "Enter the item name: " << endl;
            getline(cin, newname);
            item1.setName(newname);

            cout << "Enter the item description: " << endl;
            getline(cin, newdescription);
            item1.setDescription(newdescription);

            cout << "Enter the item price: " << endl;
            cin >> newprice;
            item1.setPrice(newprice);

            cout << "Enter the item quantity: " << endl;
            cin >> newquant;
            item1.setQuantity(newquant);
            mycart1.addItem(item1);

    
        }
        if(a == 'd'){
            mycart1.removeItem();
        }
        if(a == 'c'){
            mycart1.modifyItem();
        }
        if(a == 'i'){
            mycart1.outputItemsDescription();
        }
 
        if(a == 'o'){
            mycart1.outputShoppingCart();
            
        }
        
    a = mycart1.printMenu(mycart1);
    }
    
    
    if(a == 'q'){
        return 0;
    }


   return 0; 
}