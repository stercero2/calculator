#ifndef STACK_H
#define STACK_H

#include <iostream>

template <class X>
class Stack
{
private:
	X arr[10];
	int tos;
public:

	Stack()
	{
		tos = 0;
	}
	bool isEmpty()
	{
		return tos == 0;
	}
	void push(X e)
	{
		arr[tos] = e;
		tos++;
	}
	void pop()
	{
		if (!isEmpty())
		{
			tos--;
		}
		else
		{
			cout << "stack is empty!\n";
		}
	}
	bool isfull()
	{
		return (tos == 5);
	}
	X top()
	{
		return arr[tos - 1];
	}
	int cur()
	{
		return tos;
	}

};
#endif
