#ifndef REVIEW_H
#define REVIEW_H

#include <bits/stdc++.h>
using namespace std;

void updateStore(vector<string>, int, char);
void updateCart(vector<string>, int);

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
    }
    fin.close();

    cout << "\t";
    for (int d = 1; d <= 85; d++)
        cout << "-";
    cout << endl;

    char ch = 'Y';
    int no = 0, newq;

    while (true)
    {
        cout << "Do you want to reduce any item? (Enter Y to edit): ";
        cin >> ch;
        if (ch != 'Y' && ch != 'y')
            break;

        cout << "Enter the No.: ";
        cin >> no;

        cout << "Enter the new quantity(Enter 0 to delete the item): ";
        cin >> newq;
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