#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "Stack.h"
#include <string>
using namespace std;

bool CharisNum(const char& a)	//Function that returns whether char represents a number between 0 and 9
{
	return (a >= 48 && a <= 57);
}

class Calculator
{
private:
	Stack<char> postfix; //a char Stack is used to manage the order of the symbols
	Stack<int> calc;	
	string output[30];	//string array is used so that numbers and symbols can both be added.
	int outCur;
	string infix;		
public:
	Calculator(string i)
	{
		outCur = 0;
		infix = i;
	};
	void in_PostFix()	//member function converts a string math equation into postfix notation
	{
		int const SIZE = infix.length();
		for (int i = 0; i < SIZE; i++)	//for statement garantees it goes through the entire string statement once
		{
			if (CharisNum(infix[i]))	
			{
				int n = infix[i] - 48;
				while (i + 1 != SIZE&&CharisNum(infix[i + 1]))	//this is for values with multiple digits
				{
					i++;		//ensures it is moving through the string
					n *= 10;	//each value is multiplied by 10
					n += infix[i] - 48;		//and it is added the next in line
				}
				output[outCur] = to_string(n);	//value is being added into the string array
				outCur++;
			}
			else if (infix[i] == '(')
			{
				postfix.push(infix[i]);
			}
			else if (infix[i] == ')')
			{
				while (!(postfix.top() == '('))
				{
					output[outCur] = postfix.top();
					outCur++;
					postfix.pop();
				}
				postfix.pop();
			}
			else if (infix[i] == '^')
			{
				postfix.push(infix[i]);
			}
			else if (infix[i] == '*' || infix[i] == '/')		//this chunk of code ensures it has higher priority to + or -
			{
				while (postfix.top() == '^')
				{
					output[outCur] = postfix.top();
					outCur++;
					postfix.pop();
				}
				postfix.push(infix[i]);

			}
			else if (infix[i] == '+' || infix[i] == '-')
			{
				while (postfix.top() == '^' || postfix.top() == '*' || postfix.top() == '/')
				{
					output[outCur] = postfix.top();
					outCur++;
					postfix.pop();
				}

				postfix.push(infix[i]);
			}
		}
		while (!postfix.isEmpty()) //this empties the entire stack of char into the post fix string array
		{
			output[outCur] = postfix.top();
			postfix.pop();
			outCur++;
		}
	}
	int calculate()
	{
		for (int i = 0; i < outCur; i++)
		{
			if (!(output[i] == "*" || output[i] == "/" || output[i] == "+" || output[i] == "-" || output[i] == "^" || output[i] == "(" || output[i] == ")"))
			{
				int n = stoi(output[i]);
				calc.push(n);
			}
			else
			{
				int v1;
				int v2;
				if (output[i] == "^")
				{
					v1 = calc.top();
					calc.pop();
					v2 = calc.top();
					calc.pop();
					int temp = v2;
					for (int j = 0; j < v1 - 1; j++)
					{
						v2 *= temp;
					}
					calc.push(v2);
				}
				if (output[i] == "*")
				{
					v1 = calc.top();
					calc.pop();
					v2 = calc.top();
					calc.pop();
					v2 = v2*v1;
					calc.push(v2);
				}
				if (output[i] == "+")
				{
					v1 = calc.top();
					calc.pop();
					v2 = calc.top();
					calc.pop();
					v2 = v2 + v1;
					calc.push(v2);
				}
				if (output[i] == "-")
				{
					v1 = calc.top();
					calc.pop();
					v2 = calc.top();
					calc.pop();
					v2 = v2 - v1;
					calc.push(v2);
				}
				if (output[i] == "/")
				{
					v1 = calc.top();
					calc.pop();
					v2 = calc.top();
					calc.pop();
					v2 = v2 / v1;
					calc.push(v2);
				}
			}
		}
		return calc.top();
	}
	void displayPostFix()
	{
		for (int i = 0; i < outCur; i++)
		{
			cout << output[i] << " ";
		}
	}

};
#endif
