#include "LinkedList.h"

int main()
{
	LinkedList myLinkedList;

	myLinkedList.Push(1);
	myLinkedList.Push(3);
	myLinkedList.Push(5);
	myLinkedList.Push(7);
	myLinkedList.Push(9);
	myLinkedList.Push(11);
	
	myLinkedList.Pop();
	myLinkedList.Pop();

	myLinkedList.Insert(0, 0);
	myLinkedList.Insert(2, 2);

	myLinkedList.Delete(3);

	myLinkedList.Print();

	system("pause");
	return 0;
}