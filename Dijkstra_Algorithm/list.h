#pragma once

#include "list_element.h"

template <typename T>

class list
{
public:
	list() :head(0), cursor(0) {}
	void prepend(T n)
	{
		if (head == 0)
		{
			cursor = head = new list_element<T>(n, head);
		}
		else
		{
			head = new list_element<T>(n, head);
		}
	}
	int get_element() { return cursor->d; }
	void advance() { cursor = cursor->next; }

private:
	list_element<T>* head;
	list_element<T>* cursor;
};