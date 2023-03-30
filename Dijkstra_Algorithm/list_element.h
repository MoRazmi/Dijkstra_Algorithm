#pragma once

template <typename T>

class list_element
{
public:
	list_element(T n = 0, list_element* ptr = 0) :
		d(n), next(ptr) {}
	T d;
	list_element* next;
};
