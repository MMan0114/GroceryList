//
//  MKProgrammingProject.cpp
//  Grocery
//
//  Created by MMan on 7/21/16.
//  Copyright © 2016 MananKothari. All rights reserved.
/*
This program uses the GrItem class which is defined in GrItem.h. This program asks the user to enter the location of the file in which the grocery list resides, then that file is passed to a function which reads in the data and enters it into an array of GrItem objects. The array of objects is then sorted by the item name and a receipt is shown.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "GrItem.h"

using namespace std;

const int GROCERY_LIST_SIZE = 20;
int filetoArray(ifstream &, GrItem[]);
void sortObjectArray(GrItem [], int);

int main() {
    string filePath;
    ifstream dataFile;
    //Ask user to enter the filepath for the grocery list
    cout << "What is the filepath? ";
    cin >> filePath;
    GrItem grocery[GROCERY_LIST_SIZE];
    
    dataFile.open(filePath);
    //check if file opened succesfully
    if(dataFile){
        //Get the number of items in the list
        int arraySize = filetoArray(dataFile, grocery);
        //sort the array of objects
        sortObjectArray(grocery, arraySize);
        //Display the sorted array of objects
        displayReceipt(grocery, arraySize);
    }
    //close the file
    dataFile.close();
}

//Function to read data from file, and store the data into the member variables for the GrItem Object. The function will use a while loop to read through the file until it reaches the end of the file. After it gets each input the value is stored into the GrItem object array, the function also keeps track of the number of items in the list and returns that value.
int filetoArray(ifstream &refFile, GrItem array[]){
    string itemName;
    string quantity;
    string itemPrice;
    string itemSalePrice;
    string onSale;
    string taxCategory;
    int quant;
    float price;
    float salePrice;
    int tax;
    bool saleorno;
    int count = 0;
    while(getline(refFile, itemName, ','))
    {
        //Set the member attributes (name, quantity, regular price, sale price, onSale, and tax category) of the GrItem object at index count
        array[count].setName(itemName);
        
        getline(refFile, quantity, ',');
        quant = stoi(quantity);
        array[count].setQuantity(quant);
        
        
        getline(refFile, itemPrice, ',');
        price = stof(itemPrice);
        array[count].setRegPrice(price);
        
        getline(refFile, itemSalePrice, ',');
        salePrice = stof(itemSalePrice);
        array[count].setSalePrice(salePrice);
        
        getline(refFile, onSale, ',');
        if(onSale == " 1")
             saleorno = true;
        else
            saleorno = false;
        array[count].setSale(saleorno);
        
        getline(refFile, taxCategory);
        tax = stoi(taxCategory);
        array[count].setTax(tax);
        
        //Iterate through the array of GrItem objects and keep track of how many items there are total
        count ++;
    }
    return count;
}

//This is a bubblesort function which takes the array of GrItem objects and sorts the array by the name of the item stored in GrItem.name in ascending order. It uses the overloaded= operator function created in the GrItem class to assign the temp object to the object at index count+1
void sortObjectArray(GrItem arrayName[], int arraySize){
    GrItem temp;
    for(int i = 0; i < arraySize; i++)
        for(int j = 0; j < arraySize-i-1;j++)
            if(arrayName[j].getName() > arrayName[j+1].getName())
            {
                temp.setName(arrayName[j].getName());
                temp.setQuantity(arrayName[j].getQuantity());
                temp.setRegPrice(arrayName[j].getRegPrice());
                temp.setSalePrice(arrayName[j].getSalePrice());
                temp.setSale(arrayName[j].getSale());
                temp.setTax(arrayName[j].getTax());
                arrayName[j] = arrayName[j+1];
                arrayName[j+1] = temp;
            }
}

/*Sample output
 What is the filepath? grocerylist.txt
                                Jewel Osco
                                123 95th St
                            Naperville, IL 60564
 
 Item Name:                     Quantity:    Price:  Sale:     Cost:
 Alkaline Batteries (8pk AA)            1      7.99             7.99
 All-Natural Yogurt                    12      0.59      y      7.08
 Apples (3 lb bag)                      1      4.25      y      4.25
 Cherry Soda                            6      0.89      y      5.34
 Draft Beer 12-pack                     2     13.49            26.98
 First Aid Ointment                     2      4.79             9.58
 Full Body Shampoo                      3      3.19      y      9.57
 Golden Tequila (1.75L)                 1     24.99      y     24.99
 Ibuprofen                              1      4.49      y      4.49
 Laundry Detergent                      1     12.59            12.59
 Notebook Paper                         2      1.29             2.58
 Oat Cereal                             1      4.99             4.99
 
 Total (before tax): $120.43
 Alcohol tax: $4.16
 Food tax: $1.08
 General Merchandise Tax: $2.29
 Medicine Tax: $0.56
 Total (tax included): $128.52
 You saved: $21.90
 Program ended with exit code: 0
 */
