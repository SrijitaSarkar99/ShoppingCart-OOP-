#ifndef CHECKOUT_H
#define CHECKOUT_H

#include <bits/stdc++.h>
using namespace std;

void checkout()
{
    //-----------To Check whether file is empty---------------
    int length;
    ifstream filestr;

    filestr.open("./database/cart.csv", ios::binary); // open your file
    filestr.seekg(0, ios::end);                       // put the "cursor" at the end of the file
    length = filestr.tellg();                         // find the position of the cursor
    filestr.close();                                  // close your file

    if (length == 0)
    {
        cout << "Message: Empty Cart" << endl;
        return;
    }

    //---------------------------------

    float totalPrice = 0;

    // Header Format
    cout << "\t";
    for (int d = 1; d <= 100; d++)
        cout << "-";
    cout << endl;
    cout << "\t|" << setw(49) << setfill(' ') << "BILL"
         << setw(50) << setfill(' ') << "|" << endl;
    cout << "\t";
    for (int d = 1; d <= 100; d++)
        cout << "-";
    cout << endl;
    cout << "\t| "
         << right << setw(2) << setfill(' ') << "No"
         << ". "
         << left << setw(30) << setfill(' ') << "Item Name"
         << setw(20) << setfill(' ') << "Category"
         << setw(15) << setfill(' ') << "Quantity"
         << setw(15) << setfill(' ') << "Price(Rs.)"
         << setw(10) << setfill(' ') << "Total Price"
         << "  |" << endl;
    cout << "\t";
    for (int d = 1; d <= 100; d++)
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
             << setw(15) << setfill(' ') << fixed << setprecision(2) << stof(row[5])
             << setw(10) << setfill(' ') << fixed << setprecision(2) << (stof(row[5]) * stof(row[4]))
             << right << setw(4) << setfill(' ') << "|" << endl;

        totalPrice = totalPrice + (stoi(row[4])) * (stof(row[5]));
        ++i;
    }
    fin.close();

    // remove("./database/cart.csv");

    //-----------------Empty cart before Exiting------------
    ofstream ofs;
    ofs.open("./database/cart.csv", ofstream::out | ofstream::trunc);
    ofs.close();
    //------------------------------------------------------

    // Display total Price
    cout << "\t";
    for (int d = 1; d <= 100; d++)
        cout << "-";
    cout << endl;
    cout << "\t|"
         << setw(71) << setfill(' ') << "||"
         << "Total Price:  "
         << fixed << setprecision(2) << totalPrice
         << right << setw(8) << setfill(' ') << "|" << endl;
    cout << "\t";
    for (int d = 1; d <= 100; d++)
        cout << "-";
    cout << endl;

    cout << "\n\t\tMessage: Thank You for shopping with us :)\n"
         << endl;
    exit(1);
}

#endif