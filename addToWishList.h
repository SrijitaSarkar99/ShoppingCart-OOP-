
#ifndef WW
#define WW

#include <bits/stdc++.h>
#include "inputValidation.h"
using namespace std;

void addtoWishList(char c)
{
    fstream fout;

    fout.open("./database/wishList.csv", ios::out | ios::app);

    vector<string> row; // Read the Data from the file as String Vector
    string line, word;

    fstream fin;

    // Open an existing file
    if (c == 'G')
        fin.open("./database/Grocery.csv", ios::in);
    else
        fin.open("./database/Stationary.csv", ios::in);

    if (!fin)
    {
        cout << "Error in accessing Warehouse details.." << endl;
        return;
    }

    cout << "\nEnter the id of the Item you want to wishList: ";
    int ch = input_valid();

    while (getline(fin, line))
    {
        row.clear();

        // read an entire row and
        // store it in a string variable 'line'

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

        if (stoi(row[0]) == ch)
        {
            fout << row[0] << ","
                 << row[1] << ","
                 << row[3] << "\n";
        }
    }

    fin.close();
    fout.close();
    cout << "Message: Added to WishList" << endl;
}

void showWishlist()
{
    int length;
    ifstream filestr;

    filestr.open("./database/wishList.csv", ios::binary); // open your file
    filestr.seekg(0, ios::end);                           // put the "cursor" at the end of the file
    length = filestr.tellg();                             // find the position of the cursor
    filestr.close();                                      // close your file

    if (length == 0)
    {
        cout << "Message: Empty Wishlist" << endl;
        return;
    }

    fstream fin;

    fin.open("./database/wishList.csv", ios::in);

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
             << setw(2) << setfill(' ') << i << ". "
             << left << setw(30) << setfill(' ') << row[1] << endl;

        i++;
    }
    fin.close();
}

#endif