#ifndef VV_H
#define VV_H

#include <bits/stdc++.h>
using namespace std;

// function to input valid integer value
int input_valid()
{
    char num[20], ch;
    int number;
    while (1)
    {
        // clear the buffer
        fflush(stdin);
        // input the number/string in num char array
        fgets(num, 20, stdin);
        // remove the trailing newline char
        num[strcspn(num, "\n")] = 0;
        int i = 0, flag = 0;
        number = 0;
        // fetch the chars of num[] one by one
        while (num[i] != '\0')
        {
            ch = num[i];
            // if ch is not in the range of integers ascii value
            if (ch < 48 || ch > 57)
            {
                // print the message, set the flag value and break from the loop
                printf("Please input integer values only!!\n");
                flag = 1;
                break;
            }
            else
                // To make a digit
                number = number * 10 + (ch - 48);
            // increment i to access the next char of num[]
            i++;
        }
        // flag=0 means the number is valid integer so break from the loop and return the value
        if (flag == 0)
            break;
        // else ask the user to input again and continue the loop
        printf("\nEnter the number: ");
    }
    return number;
}

#endif