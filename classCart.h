#ifndef CLASSES_H
#define CLASSES_H

#include <bits/stdc++.h>
using namespace std;

class Item
{
protected:
    int item_id;
    string item_name;
    int item_quantity;
    float item_price;

public:
    // Constructor
    Item()
    {
        item_id = 0;
        item_name = "item name";
        item_quantity = 0;
        item_price = 0;
    }
};

// Child class - Inherited Item Class
class Grocery : public Item
{
    // Private member
    string item_category;

public:
    // Constructor
    Grocery()
    {
        item_category = "Grocery";
    }
    void setData(vector<string> itemData, int quantity)
    {
        item_id = stoi(itemData[0]);
        item_name = itemData[1];
        item_quantity = quantity;
        item_price = stof(itemData[3]);
    }
    int getId()
    {
        return item_id;
    }
    string getName()
    {
        return item_name;
    }
    int getQuantity()
    {
        return item_quantity;
    }
    string getCategory()
    {
        return item_category;
    }
    float getPrice()
    {
        return item_price;
    }
    void addQuantity(int n)
    {
        item_quantity = item_quantity + n;
    }
};

class Stationary : public Item
{
    // Private member
    string item_category;

public:
    // Constructor
    Stationary()
    {
        item_category = "Stationary";
    }
    void setData(vector<string> itemData, int quantity)
    {
        item_id = stoi(itemData[0]);
        item_name = itemData[1];
        item_quantity = quantity;
        item_price = stof(itemData[3]);
    }
    int getId()
    {
        return item_id;
    }
    string getName()
    {
        return item_name;
    }
    int getQuantity()
    {
        return item_quantity;
    }
    string getCategory()
    {
        return item_category;
    }
    float getPrice()
    {
        return item_price;
    }

    void addQuantity(int n)
    {
        item_quantity = item_quantity + n;
    }
};

#endif