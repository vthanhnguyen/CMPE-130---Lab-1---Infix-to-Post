
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

    cout << "Please enter the infix equation to be converted to postfix: \n";
    cin >> data;            // get data from user

    cout << "\n\n";         // just makine some new lines 

    infix.setInfix(data);   // set the string entered to the objects infix string

    infix.converntToPostfix();
    infix.showInfix();
    infix.showPostfix();
   
    return 0;
}

