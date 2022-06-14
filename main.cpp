#include <bits/stdc++.h>
#include "addItem.h"
#include "reviewCart.h"
#include "checkout.h"

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
             << "| 4. Exit Process\t|";
        cout << "\n\t\t\t\t"
             << "-------------------------"
             << endl;
        cout << "Enter your choice: ";
        cin >> ch1;

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
            cout << "Message: Terminating Process.." << endl;
            exit(1);
        default:
            cout << "Message: Wrong Choice..";
        }
    }
    return 0;
}