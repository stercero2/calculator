//Author: Samuel Tercero
//Date: 10/4/2017
//Project 2 Calculator

#include <iostream>
#include <string>
#include "Calculator.h"
using namespace std;

int main()
{
	char ans = 'Y';
	while (ans == 'Y' || ans == 'y')
	{
		string input;
		cin >> input;
		Calculator *c = new Calculator(input);
		c->in_PostFix();
		c->displayPostFix();
		cout <<" = " << c->calculate() << endl;
		cout << "Do you wish to continue? (Y/N)";
		cin >> ans;
		if (!(ans == 'Y' || ans == 'y'))
		{
			ans = false;
		}
		delete c;
	}
	return 0;
}
