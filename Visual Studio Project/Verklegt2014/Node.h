#pragma once

#ifndef NULL
#define NULL 0
#endif

// Definition in header file because of template

template <class T>
class Node
{
public:
	Node()
	{
		next = NULL;
	}
	Node(T d)
	{
		data = d;
		next = NULL;
	}

	T data;
	Node<T>* next;
};