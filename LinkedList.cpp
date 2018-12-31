#include "LinkedList.h"

LinkedList::LinkedList()
{
	Clear();
}

LinkedList::~LinkedList()
{
	// Delete all the nodes
	Node* iterator = m_pHead;
	Node* iterator_next = nullptr;

	while (iterator)
	{
		iterator_next = iterator->pNext;
		delete iterator;
		iterator = iterator_next;
	}
}

void LinkedList::Clear()
{
	m_pHead = nullptr;
	m_pTail = nullptr;
	m_Length = 0;
}

void LinkedList::Push(int Data)
{
	if (m_pTail)
	{
		m_pTail->pNext = new Node(Data);
		m_pTail = m_pTail->pNext;
	}
	else
	{
		// No tail, no head
		m_pHead = new Node(Data);
		m_pTail = m_pHead;
	}
	m_Length++;
}

void LinkedList::Pop()
{
	if (m_pHead == m_pTail)
	{
		// Our last survivor says goodbye here
		delete m_pHead;
		Clear();
		return;
	}

	Node* iterator = m_pHead;
	while (iterator)
	{
		if (iterator->pNext == m_pTail)
		{
			delete iterator->pNext;
			iterator->pNext = nullptr;
			m_pTail = iterator;
			m_Length--;
		}
		iterator = iterator->pNext;
	}
}

void LinkedList::InsertAt(int ID, int Data)
{
	if (ID == 0)
	{
		// Insert a node before the former head
		Node* tempNode = m_pHead;
		m_pHead = new Node(Data);
		m_pHead->pNext = tempNode;
		m_Length++;
		return;
	}

	if ((ID > 0) && (ID < m_Length))
	{
		Node* iterator = m_pHead;
		int iterator_count = 0;

		while (iterator)
		{
			if ((iterator_count + 1) == ID)
			{
				Node* tempNode = iterator->pNext;
				iterator->pNext = new Node(Data);
				iterator->pNext->pNext = tempNode;
				m_Length++;
				return;
			}
			iterator = iterator->pNext;
			iterator_count++;
		}
	}
}

void LinkedList::RemoveAt(int ID)
{
	if (ID == 0)
	{
		// Remove the head
		Node* tempNode = m_pHead->pNext;
		delete m_pHead;
		m_pHead = tempNode;
		m_Length--;
		return;
	}

	if ((ID > 0) && (ID < m_Length))
	{
		Node* iterator = m_pHead->pNext;
		Node* iterator_prev = m_pHead;
		int iterator_id = 1;

		while (iterator)
		{
			if (iterator_id == ID)
			{
				Node* tempNode = iterator->pNext;
				delete iterator;
				iterator_prev->pNext = tempNode;
				m_Length--;
				return;
			}

			iterator_prev = iterator;
			iterator = iterator->pNext;
			iterator_id++;
		}
	}
}

void LinkedList::Print() const
{
	Node* iterator = m_pHead;

	std::cout << "# LinkedList (Length = " << m_Length << ") ";
	while (iterator)
	{
		std::cout << "<" << iterator->Data << "> ";
		iterator = iterator->pNext;
	}
	std::cout << std::endl;
}

bool LinkedList::IsEmpty() const
{
	// Returns true if the list is empty
	return m_pHead == nullptr;
}

int LinkedList::GetIDWith(int Value) const
{
	// Returns the node's ID that has a specific value
	Node* iterator = m_pHead;
	int iterator_id = 0;

	while (iterator)
	{
		if (iterator->Data == Value)
		{
			return iterator_id;
		}
		iterator = iterator->pNext;
		iterator_id++;
	}

	return -1;
}

int LinkedList::GetDataAt(int ID) const
{
	// Returns the node's data that has a specific index
	Node* iterator = m_pHead;
	int iterator_id = 0;

	while (iterator)
	{
		if (iterator_id == ID)
		{
			return iterator->Data;
		}
		iterator = iterator->pNext;
		iterator_id++;
	}

	return -1;
}