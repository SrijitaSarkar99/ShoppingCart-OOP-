#ifndef CHECKOUT_H
#define CHECKOUT_H

#include <bits/stdc++.h>
using namespace std;

void checkout()
{
    float totalPrice = 0;

    // Header Format
    cout << "\t";
    for (int d = 1; d <= 85; d++)
        cout << "-";
    cout << endl;
    cout << "\t|" << setw(42) << setfill(' ') << "BILL"
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
             << setw(10) << setfill(' ') << fixed << setprecision(2) << stof(row[5])
             << right << setw(4) << setfill(' ') << "|" << endl;

        totalPrice = totalPrice + (stoi(row[4])) * (stof(row[5]));
        ++i;
    }
    fin.close();

    remove("./database/cart.csv");

    // Display total Price
    cout << "\t";
    for (int d = 1; d <= 85; d++)
        cout << "-";
    cout << endl;
    cout << "\t|"
         << setw(40) << setfill(' ') << "||"
         << "Total Price:  "
         << fixed << setprecision(2) << totalPrice
         << right << setw(23) << setfill(' ') << "|" << endl;
    cout << "\t";
    for (int d = 1; d <= 85; d++)
        cout << "-";
    cout << endl;

    cout << "\n\t\tMessage: Thank You for shopping with us :)\n"
         << endl;
    exit(1);
}

#endif