#pragma once

#include <iostream>

class LinkedList
{
	struct Node
	{
		Node* pNext;
		int Data;

		Node() : pNext(nullptr), Data(0) {};
		Node(int _Data) : pNext(nullptr), Data(_Data) {};
	};

private:
	Node* m_pHead;
	Node* m_pTail;
	int m_Length;

public:
	LinkedList();
	~LinkedList();

	void LinkedList::Clear();

	void LinkedList::Push(int Data);
	void LinkedList::Pop();

	void LinkedList::Insert(int Index, int Data);
	void LinkedList::Delete(int Index);

	void LinkedList::Print() const;
};