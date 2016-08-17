//
//  GrItem.h
//  Grocery
//
//  Created by MMan on 7/21/16.
//  Copyright © 2016 MananKothari. All rights reserved.
/* 
 Specification file for the GrItem class, The GrItem class has member variables for a GrItem object including the
 name, quantity, reg price, sale price, an on sale flag, tax category, and tax rates. The class has functions to both
 access and mutate the member variables, as well as a default constructor, a parameter constructor and a copy
 constructor. The class also has an overloaded = operator function and a friend function to display a receipt. These
 functions are defined in GrItem.cpp
*/

#ifndef GrItem_h
#define GrItem_h

#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

enum Tax {ALCOHOL = 1, FOOD = 2, GENERAL_MERCHANDISE = 3, MEDICINE = 4};

class GrItem
{
private:
    string name;
    int quantity;
    float regPrice;
    float salePrice;
    bool onSale;
    Tax TaxCategory;
    static const float alcoholRate;
    static const float foodRate;
    static const float generalMerchRate;
    static const float medicineRate;
    
public:
    //Default constructor
    GrItem();
    //Constructor with parameters for each member variable for the object
    GrItem(string itemName, int itemQuantity, float price, float priceSale, bool sale, Tax TaxRate);
    //Copy constructor
    GrItem(const GrItem &obj);
    
    //Mutator functions
    void setName(string);
    void setQuantity(int);
    void setRegPrice(float);
    void setSalePrice(float);
    void setSale(bool);
    void setTax(int);
    
    //Accessor functions
    string getName() const;
    int getQuantity() const;
    float getRegPrice() const;
    float getSalePrice() const;
    bool getSale() const;
    int getTax() const;
    float getTaxRate() const;
    
    //Overloaded =operator function
    GrItem operator = (const GrItem &);
    
    //Friend function
    friend void displayReceipt(GrItem[], int);
    
};
#endif /* GrItem_h */
