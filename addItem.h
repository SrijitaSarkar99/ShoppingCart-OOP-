#ifndef ADDITEM_H
#define ADDITEM_H

#include <bits/stdc++.h>
#include "classCart.h"
#include "addtoCart.h"
using namespace std;

void displayStock(int);
void addGrocery();
void addStationary();
void updateGStore(Grocery);
void updateSStore(Stationary);

void addItem()
{
    int cch;
    cout << "\n\t\t\t\t"
         << "-------------------------"
         << "\n\t\t\t\t"
         << "|\tCATEGORIES\t|"
         << "\n\t\t\t\t"
         << "-------------------------";
    cout << "\n\t\t\t\t"
         << "| 1. Grocery\t\t|"
         << "\n\t\t\t\t"
         << "| 2. Stationary\t\t|";
    cout << "\n\t\t\t\t"
         << "-------------------------"
         << endl;
    cout << "Enter the category you want to buy: ";
    cin >> cch;
    switch (cch)
    {
    case 1:
        displayStock(cch);
        addGrocery();
        break;
    case 2:
        displayStock(cch);
        addStationary();
        break;
    default:
        cout << "Message: Wrong Choice.. Redirecting to Main Menu.." << endl;
        return;
    }
}

// To Display Items
void displayStock(int cch)
{
    // File Pointer
    fstream fin;
    int c;

    if (cch == 1)
    {
        // Opening groceries warehouse
        fin.open("./database/Grocery.csv", ios::in);
        c = 20;
    }
    else
    {
        // Opening Stationary warehouse
        fin.open("./database/Stationary.csv", ios::in);
        c = 15;
    }

    if (fin)
    {
        // Read the Data from the file
        // as String Vector
        vector<string> row;
        string line, word;
        int i = 1;

        for (int d = 1; d <= 60; d++)
            cout << "-";
        cout << endl;
        cout << "\t\t\tGROCERIES" << endl;
        for (int d = 1; d <= 60; d++)
            cout << "-";
        cout << endl;
        cout << right << setw(2) << setfill(' ') << "id"
             << ". "
             << left << setw(30) << setfill(' ') << "Item Name"
             << setw(15) << setfill(' ') << "Available"
             << "Price" << endl;
        for (int d = 1; d <= 60; d++)
            cout << "-";
        cout << endl;

        while (i <= c)
        {

            row.clear();

            // read an entire row and
            // store it in a string variable 'line'
            getline(fin, line);

            // used for breaking word
            stringstream s(line);

            // read every column data of a row and
            // store it in a string variable, 'word'
            while (getline(s, word, ','))
            {

                // add all the column data
                // of a row to a vector
                row.push_back(word);
            }
            cout << right << setw(2) << setfill(' ') << row[0] << ". "
                 << left << setw(30) << setfill(' ') << row[1]
                 << setw(15) << setfill(' ') << row[2]
                 << row[3] << endl;
            i++;
        }
        fin.close();
    }
    else
        cout << "Error in accessing Warehouse details.." << endl;
}

//-------------------------Add Grocery Items to the List-----------------
void addGrocery()
{
    vector<Grocery> GList;
    Grocery eachItem;
    vector<string> row; // Read the Data from the file as String Vector
    string line, word;
    int iid, count = 20, glen = 0;

    // File pointer
    fstream fin;

    // Open an existing file
    fin.open("./database/Grocery.csv", ios::in);

    if (!fin)
    {
        cout << "Error in accessing Warehouse details.." << endl;
        return;
    }

    while (true)
    {
        cout << "\nEnter id of the Item you want to buy\n(Enter '0' to go back to menu): " << flush;
        cin >> iid;

        if (!iid)
        {
            cout << "\nMessage: Redirecting to Main Menu.." << endl;
            fin.close();
            if (glen > 0)
                addGtoCart(GList, glen);
            return;
        }
        if (iid > count || iid < 0)
        {
            cout << "\nMessage: Invalid Input" << endl;
            continue;
        }

        int i = 1;

        while (i <= 20)
        {
            row.clear();

            // read an entire row and
            // store it in a string variable 'line'
            getline(fin, line);

            // used for breaking word
            stringstream s(line);

            // read every column data of a row and
            // store it in a string variable, 'word'
            while (getline(s, word, ','))
            {

                // add all the column data
                // of a row to a vector
                row.push_back(word);
            }

            if (stoi(row[0]) == iid)
            {
                int quantity;
                cout << "\nEnter the quantity you want to buy: ";
                cin >> quantity;
                if (quantity < 1)
                    cout << "\nMessage: Invalid Quantity";
                else
                {
                    if (stoi(row[2]) < quantity)
                    {
                        cout << "\nMessage: Out of Stock. " << row[2] << " piece(s) available." << endl;
                        break;
                    }

                    eachItem.setData(row, quantity);

                    // Update Store
                    updateGStore(eachItem);
                    // cout << "\n\nStore Updated\n\n";

                    //-- -- -- -- -Checking whether Item is already present in the cart-- -- -- -- -- -- -
                    // int present = 0;
                    // for (int gl = 0; gl < glen; gl++)
                    // {
                    //     cout << "\n"
                    //          << GList[gl].getId() << "TEST";
                    //     if (GList[gl].getId() == stoi(row[0]))
                    //     {
                    //         present = 1;
                    //         GList[gl].updateQuantity(stoi(row[3]));
                    //     }
                    // }

                    // // Item not present - new object will be added
                    // if (present = 0)
                    // {
                    ++glen;
                    GList.push_back(eachItem);
                    // cout << glen << ">>>";
                    // }
                }
            }
            i++;
        }
        fin.clear();
        fin.seekg(0);
    }
    fin.close();
}

//------------------------Add Stationary Items--------------------------
void addStationary()
{
    vector<Stationary> SList;
    Stationary eachItem;
    vector<string> row; // Read the Data from the file as String Vector
    string line, word;
    int iid, count = 20, slen = 0;

    // File pointer
    fstream fin;

    // Open an existing file
    fin.open("./database/Stationary.csv", ios::in);

    if (!fin)
    {
        cout << "Error in accessing Warehouse details.." << endl;
        return;
    }

    while (true)
    {
        cout << "\nEnter id of the Item you want to buy\n(Enter '0' to go back to menu): " << flush;
        cin >> iid;

        if (!iid)
        {
            cout << "\nMessage: Redirecting to Main Menu.." << endl;
            fin.close();
            if (slen > 0)
                addStoCart(SList, slen);
            return;
        }
        if (iid > count || iid < 0)
        {
            cout << "\nMessage: Invalid Input" << endl;
            continue;
        }

        int i = 1;

        while (i <= 15)
        {
            row.clear();

            // read an entire row and
            // store it in a string variable 'line'
            getline(fin, line);

            // used for breaking word
            stringstream s(line);

            // read every column data of a row and
            // store it in a string variable, 'word'
            while (getline(s, word, ','))
            {

                // add all the column data
                // of a row to a vector
                row.push_back(word);
            }

            if (stoi(row[0]) == iid)
            {
                int quantity;
                cout << "\nEnter the quantity you want to buy: ";
                cin >> quantity;
                if (quantity < 1)
                    cout << "\nMessage: Invalid Quantity";
                else
                {
                    if (stoi(row[2]) < quantity)
                    {
                        cout << "\nMessage: Out of Stock. " << row[2] << " piece(s) available." << endl;
                        break;
                    }

                    eachItem.setData(row, quantity);

                    // Update Store
                    updateSStore(eachItem);
                    // cout << "\n\nStore Updated\n\n";

                    ++slen;
                    SList.push_back(eachItem);
                    // cout << glen << ">>>";
                    // }
                }
            }
            i++;
        }
        fin.clear();
        fin.seekg(0);
    }
    fin.close();
}

// ------------Update Reduce Quantity in Store-------------------------//
void updateGStore(Grocery eachItem)
{
    fstream fin, fout;

    fin.open("./database/Grocery.csv", ios::in);
    fout.open("./database/temp.csv", ios::out);
    int count = 1;

    vector<string> nrow;
    string line, word;

    while (count <= 20)
    {

        nrow.clear();

        getline(fin, line);
        stringstream s(line);

        while (getline(s, word, ','))
        {
            nrow.push_back(word);
        }

        if (stoi(nrow[0]) == eachItem.getId())
        {
            stringstream convert;
            int newquantity = stoi(nrow[2]) - eachItem.getQuantity();

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

    remove("./database/Grocery.csv");
    rename("./database/temp.csv", "./database/Grocery.csv");

    return;
}

// ------------Update Reduce Stationary in Store-------------------------//
void updateSStore(Stationary eachItem)
{
    fstream fin, fout;

    fin.open("./database/Stationary.csv", ios::in);
    fout.open("./database/temp.csv", ios::out);
    int count = 1;

    vector<string> nrow;
    string line, word;

    while (count <= 15)
    {

        nrow.clear();

        getline(fin, line);
        stringstream s(line);

        while (getline(s, word, ','))
        {
            nrow.push_back(word);
        }

        if (stoi(nrow[0]) == eachItem.getId())
        {
            stringstream convert;
            int newquantity = stoi(nrow[2]) - eachItem.getQuantity();

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

    remove("./database/Stationary.csv");
    rename("./database/temp.csv", "./database/Stationary.csv");

    return;
}

#endif
