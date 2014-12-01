#pragma once
#include "Node.h"

// Definition in header file because of template

template <class T>
class List
{
public:
	List()
	{
		head=NULL;
		count=0;
	}

	void add(T d)
	{
		Node<T>* n = new Node<T>(d);
		if(!head) head = n;
		else
		{
			Node<T>* c = head;
			while(c->next) c = c->next;
			c->next = n;
		}
		count++;
	}

	bool remove(T d)
	{
		Node<T>* n = head;
		Node<T>* p = NULL;
		while(n && n->data != d)
		{
			p = n;
			n = n->next;
		}
		if(n)
		{
			if(p) p->next = n->next;
			else head = n->next;
			n->next = NULL;
			delete n;
			count--;
			return true;
		}
		return false;
	}

	bool removeAt(int i)
	{
		int j = 0;
		Node<T>* n = head;
		Node<T>* p = NULL;
		while(j < i && n)
		{
			p = n;
			n = n->next;
			j++;
		}
		if(n)
		{
			if(p) p->next = n->next;
			else head = n->next;
			n->next = NULL;
			delete n;
			count--;
			return true;
		}
		return false;
	}

	T get(int i)
	{
		int j = 0;
		Node<T>* n = head;
		while(j < i && n)
		{
			n = n->next;
			j++;
		}
		if(n) return n->data;
		return T();
	}

	int indexOf(T d)
	{
		int j = 0;
		Node<T>* n = head;
		while(n && n.data != d)
		{
			n = n->next;
			j++;
		}
		if(n) return j;
		return -1;
	}
private:
	Node<T>* head;
	int count;
};