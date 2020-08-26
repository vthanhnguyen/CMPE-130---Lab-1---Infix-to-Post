//Definition file for Infix to postfix
#include "Header.h"

infixToPostfix::infixToPostfix(string data)
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

string infixToPostfix::converntToPostfix(string data)
{
	infix = data;
	int size = 0;
	int i = 0;
	postfix = "";
	size = infix.length();
	char nextChar; // we will use this variable to represent the top of the stack
	stack<int> opperandStack;
	/*
	*	stack STL:
	*	push, pop, top
	*	first in last out
	*/

	for(int i = 0; i<size; i++)
	{
		if (infix[i] >= 'A' && infix[i] <= 'Z') //if the next char read is a variable
		{
			postfix = postfix + infix[i]; //appened the char to the postfix string
		}
		else //else if the next char is not a variable
		{
			switch (infix[i])
			{


			case '(': //push this to the stack and break out of switch
				opperandStack.push(infix[i]);
				break;

			case ')':
				nextChar = opperandStack.top();
				opperandStack.pop();
				while (nextChar != '(')
				{
					postfix = postfix + nextChar;
					if (!opperandStack.empty())
					{
						nextChar = opperandStack.top();
						opperandStack.pop();
					}
					else
						break;
				}
				break;
			//the next 2 lines are just in case if we add a space on accident
			case' ':
				break;

			default://the default case means it will deal ith any cases differ from above. (operands)
				if (opperandStack.empty())
					opperandStack.push(infix[i]);
				else
				{
					nextChar = opperandStack.top();
					opperandStack.pop();
					while (precedence(nextChar, infix[i]))
					{
						postfix += nextChar;
						if (!opperandStack.empty())
						{
							nextChar = opperandStack.top();
							opperandStack.pop();
						}
						else
							break;
					}
					if (!precedence(nextChar, infix[i]))
					{
						opperandStack.push(nextChar);
					}
					opperandStack.push(infix[i]);
				}

			}//end of switch
			
		}//end of else
	}//end of for loop
	while (!opperandStack.empty())
	{
		postfix += opperandStack.top();
		opperandStack.pop();
	}
	return postfix;
} 

