
//Header file for Infix to postfix

#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
#include <sstream>
using namespace std;

class infixToPostfix
{
public:
	infixToPostfix(string = "");	//default constructor

	void converntToPostfix();
	void setInfix(string);
	void showInfix();
	void showPostfix();
	bool precedence(char opr1, char opr2);


private:
	string infix;
	string postfix;
	
};

