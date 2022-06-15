#ifndef ADDCART_H
#define ADDCART_H

#include <bits/stdc++.h>
#include "classCart.h"
using namespace std;

int checkinCart(int, char, int);

int cartNum = 0;

void addGtoCart(vector<Grocery> GList, int len)
{
    fstream fout;

    fout.open("./database/cart.csv", ios::out | ios::app);

    for (int i = 0; i < len; i++)
    {
        int id = GList[i].getId();
        char cat = GList[i].getCategory()[0];
        int q = GList[i].getQuantity();
        if (checkinCart(id, cat, q) == 1)
            continue;
        fout << ++cartNum << ","
             << GList[i].getId() << ","
             << GList[i].getName() << ","
             << GList[i].getCategory() << ","
             << GList[i].getQuantity() << ","
             << GList[i].getPrice() << "\n";
    }
    fout.close();
    cout << "Message: Added to Cart";
}

void addStoCart(vector<Stationary> SList, int len)
{
    fstream fout;

    fout.open("./database/cart.csv", ios::out | ios::app);

    for (int i = 0; i < len; i++)
    {
        int id = SList[i].getId();
        char cat = SList[i].getCategory()[0];
        int q = SList[i].getQuantity();
        if (checkinCart(id, cat, q) == 1)
            continue;
        fout << ++cartNum << ","
             << SList[i].getId() << ","
             << SList[i].getName() << ","
             << SList[i].getCategory() << ","
             << SList[i].getQuantity() << ","
             << SList[i].getPrice() << "\n";
    }
    fout.close();
    cout << "Message: Added to Cart";
}

int checkinCart(int id, char cat, int q)
{
    int val = 0;
    fstream fin, fout;

    fin.open("./database/cart.csv", ios::in);
    fout.open("./database/temp.csv", ios::out);

    vector<string> row;
    string line, word;

    while (getline(fin, line))
    {
        row.clear();

        stringstream s(line);

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }
        if (stoi(row[1]) == id && row[3][0] == cat)
        {
            cout << "MAtch Found" << endl;
            val = 1;
            fout << row[0] << ","
                 << row[1] << ","
                 << row[2] << ","
                 << row[3] << ","
                 << (stoi(row[4]) + q) << ","
                 << row[5] << "\n";
        }
        fout << row[0] << ","
             << row[1] << ","
             << row[2] << ","
             << row[3] << ","
             << row[4] << ","
             << row[5] << "\n";
    }

    fin.close();
    fout.close();

    remove("./database/cart.csv");
    rename("./database/temp.csv", "./database/cart.csv");
    return val;
}
#endif