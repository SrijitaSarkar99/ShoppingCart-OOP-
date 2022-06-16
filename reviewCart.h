#ifndef REVIEW_H
#define REVIEW_H

#include <bits/stdc++.h>
#include "inputValidation.h"
#include "classCart.h"
using namespace std;

void updateStore(vector<string>, int, char);
void updateCart(vector<string>, int);

void reviewCart()
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

    // Header Format
    cout << "\t";
    for (int d = 1; d <= 100; d++)
        cout << "-";
    cout << endl;
    cout << "\t|" << right << setw(49) << setfill(' ') << "CART"
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
             << setw(15) << setfill(' ') << fixed << setprecision(2) << row[5]
             << setw(10) << setfill(' ') << fixed << setprecision(2) << (stof(row[5]) * stof(row[4]))
             << right << setw(4) << setfill(' ') << "|" << endl;
    }
    fin.close();

    cout << "\t";
    for (int d = 1; d <= 100; d++)
        cout << "-";
    cout << endl;

    int ch = 0;
    int no = 0, newq;

    while (true)
    {
        cout << "\nDo you want to reduce any item? (Enter 1 to edit): ";
        ch = input_valid();
        if (ch != 1)
        {
            cout << "\nRedirecting back to Menu..." << endl;
            break;
        }

        cout << "Enter the No.: ";
        no = input_valid();

        //-----
        if (no > cartNum)
        {
            cout << "Message: Item not present in Cart" << endl;
            continue;
        }

        cout << "Enter the new quantity(Enter 0 to delete the item): ";
        newq = input_valid();
        if (newq < 0)
        {
            cout << "Message: Invalid quantity" << endl;
            continue;
        }

        // read from Cart.csv
        fstream fin;

        fin.open("./database/cart.csv", ios::in);

        vector<string> row;
        string line, word;

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
            if (no == stoi(row[0]))
            {
                if (newq > stoi(row[4]))
                {
                    cout << "Message: Inavlid - Quantity exceeds Cart" << endl;
                    fin.close();
                    break;
                }

                // Match is found

                if (row[3] == "Grocery")
                    updateStore(row, newq, 'G');
                else
                    updateStore(row, newq, 'S');
                cout << "Store is Updated" << endl;

                updateCart(row, newq);
                cout << "\nMessage: Cart Updated" << endl;
                return;
            }
        }
        fin.close();
    }
}

void updateStore(vector<string> row, int newq, char cat)
{
    fstream fin, fout;
    int cc;

    if (cat == 'G')
    {
        fin.open("./database/Grocery.csv", ios::in);
        cc = 20;
    }
    else
    {
        fin.open("./database/Stationary.csv", ios::in);
        cc = 15;
    }
    fout.open("./database/temp.csv", ios::out);

    int count = 1;

    vector<string> nrow;
    string line, word;

    while (count <= cc)
    {

        nrow.clear();

        getline(fin, line);
        stringstream s(line);

        while (getline(s, word, ','))
        {
            nrow.push_back(word);
        }

        if (stoi(nrow[0]) == stoi(row[1]))
        {
            stringstream convert;
            int newquantity = stoi(nrow[2]) + (stoi(row[4]) - newq);

            convert << newquantity;

            nrow[2] = convert.str();

            fout << nrow[0] << ","
                 << nrow[1] << ","
                 << nrow[2] << ","
                 << nrow[3] << "\n";
        }
        else
        {
            fout << nrow[0] << ","
                 << nrow[1] << ","
                 << nrow[2] << ","
                 << nrow[3] << "\n";
        }

        count++;
    }

    fin.close();
    fout.close();

    if (cat == 'G')
    {
        remove("./database/Grocery.csv");
        rename("./database/temp.csv", "./database/Grocery.csv");
    }
    else
    {
        remove("./database/Stationary.csv");
        rename("./database/temp.csv", "./database/Stationary.csv");
    }

    return;
}

void updateCart(vector<string> row, int newq)
{
    fstream fin, fout;

    fin.open("./database/cart.csv", ios::in);
    fout.open("./database/temp.csv", ios::out);
    int count = 1;

    vector<string> nrow;
    string line, word;
    int flag = 0;

    while (getline(fin, line))
    {

        nrow.clear();

        stringstream s(line);

        while (getline(s, word, ','))
        {
            nrow.push_back(word);
        }

        if (stoi(nrow[0]) == stoi(row[0]))
        {
            stringstream convert;

            if (newq == 0)
            {
                flag = 1;
                --cartNum;
                continue;
            }

            convert << newq;

            nrow[4] = convert.str();
        }
        if (flag == 1)
        {

            fout << stoi(nrow[0]) - 1 << ","
                 << nrow[1] << ","
                 << nrow[2] << ","
                 << nrow[3] << ","
                 << nrow[4] << ","
                 << nrow[5] << "\n";
        }
        else
        {
            fout << nrow[0] << ","
                 << nrow[1] << ","
                 << nrow[2] << ","
                 << nrow[3] << ","
                 << nrow[4] << ","
                 << nrow[5] << "\n";
        }

        count++;
    }

    fin.close();
    fout.close();

    remove("./database/cart.csv");
    rename("./database/temp.csv", "./database/cart.csv");

    return;
}

#endif