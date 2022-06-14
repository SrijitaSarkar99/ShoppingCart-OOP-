#ifndef REVIEW_H
#define REVIEW_H

#include <bits/stdc++.h>
using namespace std;

void reviewCart()
{
    // Header Format
    cout << "\t";
    for (int d = 1; d <= 85; d++)
        cout << "-";
    cout << endl;
    cout << "\t|" << setw(42) << setfill(' ') << "CART"
         << setw(42) << setfill(' ') << "|" << endl;
    cout << "\t";
    for (int d = 1; d <= 85; d++)
        cout << "-";
    cout << endl;
    cout << "\t| "
         << right << setw(2) << setfill(' ') << "No"
         << ". "
         << left << setw(30) << setfill(' ') << "Item Name"
         << setw(20) << setfill(' ') << "Category"
         << setw(15) << setfill(' ') << "Quantity"
         << "Price(Rs.)"
         << right << setw(4) << setfill(' ') << "|" << endl;
    cout << "\t";
    for (int d = 1; d <= 85; d++)
        cout << "-";
    cout << endl;

    // read from Cart.csv
    fstream fin;

    fin.open("./database/cart.csv", ios::in);

    vector<string> row;
    string line, word;

    int i = 1;

    while (getline(fin, line))
    {

        row.clear();

        // used for breaking words
        stringstream s(line);

        // read every column data of a row and
        // store it in a string variable, 'word'
        while (getline(s, word, ','))
        {

            // add all the column data
            // of a row to a vector
            row.push_back(word);
        }

        cout << "\t| "
             << right << setw(2) << setfill(' ') << row[0] << ". "
             << left << setw(30) << setfill(' ') << row[2]
             << setw(20) << setfill(' ') << row[3]
             << setw(15) << setfill(' ') << row[4]
             << setw(10) << setfill(' ') << fixed << setprecision(2) << row[5]
             << right << setw(4) << setfill(' ') << "|" << endl;

        ++i;
    }
    fin.close();

    cout << "\t";
    for (int d = 1; d <= 85; d++)
        cout << "-";
    cout << endl;

    char ch;
    cout << "Do you want to edit? (Enter Y to edit): ";
    cin >> ch;
}

#endif