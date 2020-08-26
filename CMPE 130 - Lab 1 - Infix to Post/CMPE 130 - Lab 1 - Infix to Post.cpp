
/**
*   Author:         Thanh Nguyen
*   Student ID:     009220354
*   Date:           Aug 25, 2020
*   Assignment:     Lab #1 - Infix to PostFix 
*/
 
#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
    string data;            // create memory for the infix string
    infixToPostfix infix;   // create the object
    bool flag = false;
    while (flag == false)
    {
        cout << "Please enter the infix equation to be converted to postfix: \n";
        cin >> data;            // get data from user

        string postfix = infix.converntToPostfix(data);

        infix.showInfix();
        infix.showPostfix();

        cout << "Would you like to enter another infix expression to be converted ?\n"
             << "Enter 1 for yes or any number for no" << endl;
        int choice;
        cin >> choice;

        if (choice == 1)
            flag = false;
        else
            flag = true;
    }
    return 0;
}

