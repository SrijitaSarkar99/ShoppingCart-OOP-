#ifndef ADDCART_H
#define ADDCART_H

#include <bits/stdc++.h>
#include "classCart.h"
using namespace std;

int incrementGCart(vector<Grocery>, int);
int incrementSCart(vector<Stationary>, int);

int cartNum = 0;

void addGtoCart(vector<Grocery> GList, int l)
{
    //------To check if element already present
    int len = incrementGCart(GList, l);

    fstream fout;

    fout.open("./database/cart.csv", ios::out | ios::app);

    for (int i = 0; i < len; i++)
    {
        int id = GList[i].getId();
        char cat = GList[i].getCategory()[0];
        int q = GList[i].getQuantity();
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

void addStoCart(vector<Stationary> SList, int l)
{
    int len = incrementSCart(SList, l);
    fstream fout;

    fout.open("./database/cart.csv", ios::out | ios::app);

    for (int i = 0; i < len; i++)
    {
        int id = SList[i].getId();
        char cat = SList[i].getCategory()[0];
        int q = SList[i].getQuantity();
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

int incrementGCart(vector<Grocery> GList, int len)
{

    fstream fin, fout;
    fin.open("./database/cart.csv", ios::in);
    fout.open("./database/temp.csv", ios::out);

    if (fin)
    {
        vector<string> row;
        string line, word;

        while (getline(fin, line))
        {
            row.clear();

            stringstream s(line);

            // Cart details is stored in vector row
            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            int alexist = -1;
            for (int i = 0; i < len; i++)
            {
                if (stoi(row[1]) == GList[i].getId() && GList[i].getCategory() == "Grocery")
                {
                    stringstream newquan;
                    int nq = GList[i].getQuantity() + stoi(row[4]);
                    newquan << nq;

                    row[4] = newquan.str();
                    alexist = i;
                    break;
                }
            }

            if (alexist > -1)
            {
                auto it = GList.begin() + alexist;
                GList.erase(it);
                --len;
            }
            fout << row[0] << ","
                 << row[1] << ","
                 << row[2] << ","
                 << row[3] << ","
                 << row[4] << ","
                 << row[5] << "\n";
        }
    }
    fin.close();
    fout.close();

    remove("./database/cart.csv");
    rename("./database/temp.csv", "./database/cart.csv");

    return len;
}

int incrementSCart(vector<Stationary> SList, int len)
{

    fstream fin, fout;
    fin.open("./database/cart.csv", ios::in);
    fout.open("./database/temp.csv", ios::out);

    if (fin)
    {
        vector<string> row;
        string line, word;

        while (getline(fin, line))
        {
            row.clear();

            stringstream s(line);

            // Cart details is stored in vector row
            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            int alexist = -1;
            for (int i = 0; i < len; i++)
            {
                if (stoi(row[1]) == SList[i].getId() && SList[i].getCategory() == "Stationary")
                {
                    stringstream newquan;
                    int nq = SList[i].getQuantity() + stoi(row[4]);
                    newquan << nq;

                    row[4] = newquan.str();
                    alexist = i;
                    break;
                }
            }

            if (alexist > -1)
            {
                auto it = SList.begin() + alexist;
                SList.erase(it);
                --len;
            }
            fout << row[0] << ","
                 << row[1] << ","
                 << row[2] << ","
                 << row[3] << ","
                 << row[4] << ","
                 << row[5] << "\n";
        }
    }
    fin.close();
    fout.close();

    remove("./database/cart.csv");
    rename("./database/temp.csv", "./database/cart.csv");

    return len;
}

#endif