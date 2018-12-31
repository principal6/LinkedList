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

void LinkedList::Insert(int Index, int Data)
{
	if (Index == 0)
	{
		// If the index is 0, then the head gets shifted a block to the right and a new head is inserted
		Node* tempNode = m_pHead;
		m_pHead = new Node(Data);
		m_pHead->pNext = tempNode;
		m_Length++;
		return;
	}

	if ((Index > 0) && (Index < m_Length))
	{
		Node* iterator = m_pHead;
		int iterator_count = 0;

		while (iterator)
		{
			if ((iterator_count + 1) == Index)
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

void LinkedList::Delete(int Index)
{
	if (Index == 0)
	{
		// Delete the head
		Node* tempNode = m_pHead->pNext;
		delete m_pHead;
		m_pHead = tempNode;
		m_Length--;
		return;
	}

	if ((Index > 0) && (Index < m_Length))
	{
		Node* iterator = m_pHead->pNext;
		Node* iterator_prev = m_pHead;
		int iterator_id = 1;

		while (iterator)
		{
			if (iterator_id == Index)
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

	std::cout << "LinkedList (Length = ";
	std::cout << m_Length;
	std::cout << "): ";
	while (iterator)
	{
		std::cout << "<" << iterator->Data << "> ";
		iterator = iterator->pNext;
	}
	std::cout << std::endl;
}