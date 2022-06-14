#ifndef ADDCART_H
#define ADDCART_H

#include <bits/stdc++.h>
#include "classCart.h"
using namespace std;

int cartNum = 0;

void addGtoCart(vector<Grocery> GList, int len)
{
    cout << "ADD TO CART";
    fstream fout;

    fout.open("./database/cart.csv", ios::out | ios::app);

    for (int i = 0; i < len; i++)
    {
        fout << ++cartNum << ","
             << GList[i].getId() << ","
             << GList[i].getName() << ","
             << GList[i].getCategory() << ","
             << GList[i].getQuantity() << ","
             << GList[i].getPrice() << "\n";
    }
    fout.close();
}

void addStoCart(vector<Stationary> SList, int len)
{
    cout << "ADD TO CART";
    fstream fout;

    fout.open("./database/cart.csv", ios::out | ios::app);

    for (int i = 0; i < len; i++)
    {
        fout << ++cartNum << ","
             << SList[i].getId() << ","
             << SList[i].getName() << ","
             << SList[i].getCategory() << ","
             << SList[i].getQuantity() << ","
             << SList[i].getPrice() << "\n";
    }
    fout.close();
}

#endif