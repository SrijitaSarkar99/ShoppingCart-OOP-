#include <bits/stdc++.h>
#include "addItem.h"
#include "reviewCart.h"
#include "checkout.h"
#include "inputValidation.h"
#include "addToWishList.h"

using namespace std;

int main()
{
    int ch1;
    while (true)
    {
        cout << "\n\t\t\t\t"
             << "-------------------------"
             << "\n\t\t\t\t"
             << "|\tMAIN MENU\t|"
             << "\n\t\t\t\t"
             << "-------------------------";
        cout << "\n\t\t\t\t"
             << "| 1. Add Item\t\t|"
             << "\n\t\t\t\t"
             << "| 2. Review Cart\t|"
             << "\n\t\t\t\t"
             << "| 3. Checkout\t\t|"
             << "\n\t\t\t\t"
             << "| 4. Exit Process\t|"
             << "\n\t\t\t\t"
             << "| 5. WishList\t\t|";

        cout << "\n\t\t\t\t"
             << "-------------------------"
             << endl;
        cout << "Enter your choice: ";
        ch1 = input_valid();

        switch (ch1)
        {
        case 1:
            addItem(); // done
            break;
        case 2:
            reviewCart();
            break;
        case 3:
            checkout(); // done
            break;
        case 4:
        {
            cout << "Message: Terminating Process.." << endl;
            //-----------------Empty cart before Exiting------------
            ofstream ofs;
            ofs.open("./database/cart.csv", ofstream::out | ofstream::trunc);
            ofs.close();
            //------------------------------------------------------
            exit(1);
        }
        case 5:
            showWishlist();
            break;
        default:
            cout << "Message: Wrong Choice..";
        }
    }
    return 0;
}