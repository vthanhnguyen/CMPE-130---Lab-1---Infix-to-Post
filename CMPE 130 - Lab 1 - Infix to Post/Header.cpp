//Definition file for Infix to postfix
#include "Header.h"


infixToPostfix::infixToPostfix(string data)
{
	infix = data;
}

void infixToPostfix::setInfix(string data)
{
	infix = data;
}

void infixToPostfix::showInfix()
{
	cout << "Infix: " << infix << endl;
}

void infixToPostfix::showPostfix()
{
	cout << "Postfix: " << postfix << endl;
}

bool infixToPostfix::precedence(char opr1, char opr2)
{
	int prec1, prec2;

	if (opr1 == '*' || opr1 == '/')
		prec1 = 2;
	else if (opr1 == '+' || opr1 == '-')
		prec1 = 1;
	else if (opr1 == '(')
		prec1 = 0;

	if (opr2 == '*' || opr2 == '/')
		prec2 = 2;
	else if (opr2 == '+' || opr2 == '-')
		prec2 = 1;

	return(prec1 >= prec2);
}

void infixToPostfix::converntToPostfix()
{
	int size = 0;
	postfix = "";
	size = infix.length();
	char opperandStack;
	stack<int> s;

	for (int i = 0; i < size; i++)
	{
		if (infix[i] >= 'A' && infix[i] <= 'Z') //if the next char read is a variable
		{
			postfix = postfix + infix[i]; //appened the char to the postfix string
		}
		else //else if the next char is not a variable
		{

		}


	}//end of for loop
} 

