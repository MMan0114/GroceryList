//
//  GrItem.cpp
//  Grocery
//
//  Created by MMan on 7/21/16.
//  Copyright © 2016 MananKothari. All rights reserved.
/*
The implentation file for the GrItem class. This file defines the functions for the GrItem class and sets the tax rates as well. Includes the definitions for the three constructors, mutator and accessor functions and the friend function. 
*/

#include "GrItem.h"

#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

//Set the value of the tax rate for the item categories
const float GrItem::alcoholRate = .08;
const float GrItem::foodRate = .05;
const float GrItem::generalMerchRate = .07;
const float GrItem::medicineRate = .04;

//Default constructor, sets all values to blank and on sale to no, sets the default tax category
GrItem::GrItem(){
    name = "";
    quantity = 0;
    regPrice = 0;
    salePrice = 0;
    onSale = false;
    TaxCategory = ALCOHOL;
}
//Constructor with parameters for each member variable for the object
GrItem::GrItem(string itemName, int itemQuantity, float price, float priceSale, bool sale, Tax TaxRate){
    name = itemName;
    quantity = itemQuantity;
    regPrice = price;
    salePrice = priceSale;
    onSale = sale;
    TaxCategory = TaxRate;
}
//Copy constructor, takes one GrItem object and copies the attributes to another GrItem object
GrItem::GrItem(const GrItem &obj){
    name = obj.name;
    quantity = obj.quantity;
    regPrice = obj.regPrice;
    salePrice = obj.salePrice;
    onSale = obj.onSale;
    TaxCategory = obj.TaxCategory;
}


//The setName function sets the name member variable of the object
void GrItem::setName(string n){
    name = n;
}
//The setQuantity function sets the quantity member variable of the object
void GrItem::setQuantity(int quant){
    quantity = quant;
}
//The setRegPrice function sets the regular price member variable of the object
void GrItem::setRegPrice(float price){
    regPrice = price;
}
//The setSalePrice function sets the sale price member variable of the object
void GrItem::setSalePrice(float price){
    salePrice = price;
}
//The setSale function sets the sale member variable to true or false based on whether the item is on sale or not
void GrItem::setSale(bool sale){
    onSale = sale;
}
//The setTax function takes an int and based on the arguement sets the category for the tax rate
void GrItem::setTax(int tax){
    if (tax == 1)
        TaxCategory = ALCOHOL;
    else if(tax == 2)
        TaxCategory = FOOD;
    else if (tax == 3)
        TaxCategory = GENERAL_MERCHANDISE;
    else if (tax == 4)
        TaxCategory = MEDICINE;
}
//The getName function returns the objects name
string GrItem::getName() const{
    return name;
}
//The getQuantity function returns the quantity of the object
int GrItem::getQuantity() const{
    return quantity;
}
//The getRegPrice function returns the regular price of the object
float GrItem::getRegPrice() const{
    return regPrice;
}
//The getSalePrice function returns the sale price of the object
float GrItem::getSalePrice() const{
    return salePrice;
}
//The getSale function returns whether the object is on sale or not
bool GrItem::getSale() const{
    return onSale;
}
//The getTax function returns the tax category
int GrItem::getTax() const{
    int taxCat;
    switch (TaxCategory) {
        case ALCOHOL:
            taxCat = 1;
            break;
        case FOOD:
            taxCat = 2;
            break;
        case GENERAL_MERCHANDISE:
            taxCat = 3;
            break;
        case MEDICINE:
            taxCat = 4;
            break;
    }
    return taxCat;
}
//The getTaxRate function takes the tax category and assigns the tax rate based on the category
float GrItem::getTaxRate() const{
    float temp;
    switch (TaxCategory) {
        case ALCOHOL:
            temp = alcoholRate;
            break;
        case FOOD:
            temp = foodRate;
            break;
        case GENERAL_MERCHANDISE:
            temp = generalMerchRate;
            break;
        case MEDICINE:
            temp = medicineRate;
            break;
    }
    return temp;
}
//Overloaded = operator, assigns the values of the object on the right to the object on the left 
GrItem GrItem::operator =(const GrItem &right){
    name = right.name;
    quantity = right.quantity;
    regPrice = right.regPrice;
    salePrice = right.salePrice;
    onSale = right.onSale;
    TaxCategory = right.TaxCategory;
    return *this;
}

//The displayReceipt is a friend function which takes an array of GrItem objects and the size of that array. It calculates the total cost of the items with sale prices, regular prices, tax included and displays a receipt of the items with an indication of whether the item was on sale and individual item cost as well as total cost, total cost with tax, total amount saved, and how much tax was paid for each category
void displayReceipt(GrItem arrayName[], int maxArraySize){
    float cost;
    float regCost;
    float itemPrice;
    float taxCost = 0;
    float totalCost = 0;
    float regTotal = 0;
    char sale = ' ';
    float alcoholTax = 0;
    float generalMerchTax = 0;
    float foodTax = 0;
    float medicineTax = 0;
    cout << setw(40) << "Jewel Osco\n" << setw(41)<<"123 95th St\n" << setw(45) << "Naperville, IL 60564\n" << endl;
    cout << setw(30) << left << "Item Name:" << right <<  setw(10) << "Quantity:" << setw(10) << "Price:" <<setw(7) <<"Sale:" << setw(10) << "Cost:" << endl;
    for(int i = 0; i < maxArraySize; i++){
        //Calculate the cost of each item based on sale price or not
        if (arrayName[i].onSale)
        {
            sale = 'y';
            itemPrice = arrayName[i].salePrice;
            cost = arrayName[i].quantity*arrayName[i].salePrice;
            //Get the regular cost of the items on sale as well to calculate total savings
            regCost = arrayName[i].quantity*arrayName[i].regPrice;
            //Calculate the tax cost for each item based on its tax category and increment the amount for each item in the list
            if(arrayName[i].TaxCategory == ALCOHOL)
                alcoholTax += cost*arrayName[i].alcoholRate;
            else if(arrayName[i].TaxCategory == FOOD)
                foodTax += cost*arrayName[i].foodRate;
            else if(arrayName[i].TaxCategory == GENERAL_MERCHANDISE)
                generalMerchTax += cost*arrayName[i].generalMerchRate;
            else
                medicineTax += cost*arrayName[i].medicineRate;
            
        }
        else
        {
            sale = ' ';
            itemPrice = arrayName[i].regPrice;
            cost = arrayName[i].quantity*arrayName[i].regPrice;
            regCost = arrayName[i].quantity*arrayName[i].regPrice;
            //Calculate the tax cost for each item based on its tax category and increment the amount for each item in the list
            if(arrayName[i].TaxCategory == ALCOHOL)
                alcoholTax += cost*arrayName[i].alcoholRate;
            else if(arrayName[i].TaxCategory == FOOD)
                foodTax += cost*arrayName[i].foodRate;
            else if(arrayName[i].TaxCategory == GENERAL_MERCHANDISE)
                generalMerchTax += cost*arrayName[i].generalMerchRate;
            else
                medicineTax += cost*arrayName[i].medicineRate;
            
        }
        //Calculate the total cost for all items, and the total amount of tax on all items
        totalCost = totalCost + cost;
        //total cost of all items at regular price
        regTotal = regTotal + regCost;
        //total cost of tax on items based on sale price and regular price
        taxCost += arrayName[i].getTaxRate()*cost;
        cout << fixed << setprecision(2);
        cout << left << setw(30) << arrayName[i].name << right <<setw(10) << arrayName[i].quantity << setw(10) << itemPrice << setw(7) << sale << setw(10) << cost << endl;
    }
    cout << endl;
    cout <<"Total (before tax): $" << totalCost << endl;
    cout <<"Alcohol tax: $" << alcoholTax << "\nFood tax: $" <<foodTax << "\nGeneral Merchandise Tax: $" << generalMerchTax << "\nMedicine Tax: $" << medicineTax << endl;
    cout <<"Total (tax included): $" << totalCost+taxCost << endl;
    cout <<"You saved: $" << regTotal - totalCost << endl;
}
