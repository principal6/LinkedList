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

	myLinkedList.InsertAt(0, 0);
	myLinkedList.InsertAt(2, 2);

	myLinkedList.RemoveAt(3);

	myLinkedList.Print();

	int findByID = 3;
	std::cout << "# Data at ID " << findByID << ": <" << myLinkedList.GetDataAt(findByID) << ">" << std::endl;

	int findByData = 5;
	std::cout << "# ID with <" << findByData << "> : " << myLinkedList.GetIDWith(findByData) << std::endl;

	system("pause");
	return 0;
}